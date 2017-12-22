#include "GOA_DFPlayerMini.hpp"

// https://forum.banggood.com/forum-topic-59997.html

#if ESP32
#include <HardwareSerial.h>
HardwareSerial Serial1(2);
#endif

void GOA_DFPlayerMini::sendCommand(uint8_t command, uint8_t parameter1, uint8_t parameter2)
{
#define START_BYTE 0x7E
#define VERSION_BYTE 0xFF
#define COMMAND_LENGTH 0x06
#define ACKNOWLEDGE 0x00
#define END_BYTE 0xEF
	// Calculate the checksum (2 bytes)
	uint16_t checksum = -(VERSION_BYTE + COMMAND_LENGTH + command + ACKNOWLEDGE + parameter1 + parameter2);
	// Send the command to DFPlayer
	Serial1.write(START_BYTE);
	Serial1.write(VERSION_BYTE);
	Serial1.write(COMMAND_LENGTH);
	Serial1.write(command);
	Serial1.write(ACKNOWLEDGE);
	Serial1.write(parameter1);
	Serial1.write(parameter2);
	Serial1.write(highByte(checksum));
	Serial1.write(lowByte(checksum));
	Serial1.write(END_BYTE);
}

void GOA_DFPlayerMini::doReceiveData()
{
	if (DFPLAYER_MINI_SERIAL.available() >= 10)
	{
		// There is at least 1 returned message (10 bytes each)
		byte returned[10];
		for (byte k = 0; k < 10; k++)
			returned[k] = DFPLAYER_MINI_SERIAL.read();
		#if DEBUG
		_debug("Returned: ");
		_debug(String(returned[3]));
		_debug("; Parameter: ");
		_debug(String(returned[5]));
		_debug(", ");
		_debug(String(returned[6]));
		_debug("\n");
		#endif
	}
}

void GOA_DFPlayerMini::setup()
{
	pinMode(DFPLAYER_MINI_BUSY, INPUT);
	DFPLAYER_MINI_SERIAL.begin(9600);
	sendCommand(0x3F, 0x00, 0x00); // [DH]=0, [DL]= 0 ~ 0x0F Initialization parameters
	delay(30); // have >20ms delays between commands
	while (DFPLAYER_MINI_SERIAL.available() < 10) // Wait until initialization parameters are received (10 bytes)
		delay(30);
	setVolume(AUDIO_STARTING_VOLUME);
	delay(30);
	sendCommand(0x07, 0x00, 0x00); // [DH]=X, [DL]= EQ(0/1/2/3/4/5) [Normal/Pop/Rock/Jazz/Classic/Base]
	delay(30);
}

void GOA_DFPlayerMini::loop()
{
	doReceiveData();
}

void GOA_DFPlayerMini::volumeUp()
{
	if (volume < VOLUME_MAX)
	{
		volume++;
		setVolume(volume);
	}
}

void GOA_DFPlayerMini::volumeDown()
{
	if (volume > VOLUME_MIN)
	{
		volume--;
		setVolume(volume);
	}
}

void GOA_DFPlayerMini::setVolume(uint8_t value)
{
	// set volume DL=0x00-0x30
	uint8_t res = uint8_t(1.0 * value * 0x30 / VOLUME_MAX);
	sendCommand(0x06, 0x00, res); // [DH]=X, [DL]= Volume (0-0x30) Default=0x30
	#if DEBUG
	_debug("Volume: " + String(res) + "\n");
	#endif
}