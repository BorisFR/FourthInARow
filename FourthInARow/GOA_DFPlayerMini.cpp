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
	DFPLAYER_MINI_SERIAL.write(START_BYTE);
	DFPLAYER_MINI_SERIAL.write(VERSION_BYTE);
	DFPLAYER_MINI_SERIAL.write(COMMAND_LENGTH);
	DFPLAYER_MINI_SERIAL.write(command);
	DFPLAYER_MINI_SERIAL.write(ACKNOWLEDGE);
	DFPLAYER_MINI_SERIAL.write(parameter1);
	DFPLAYER_MINI_SERIAL.write(parameter2);
	DFPLAYER_MINI_SERIAL.write(highByte(checksum));
	DFPLAYER_MINI_SERIAL.write(lowByte(checksum));
	DFPLAYER_MINI_SERIAL.write(END_BYTE);
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
		_debug("DFPlayer Mini - command: " + String(returned[3]) + "; parameters: " + String(returned[5]) + ", " + String(returned[6]) + "\n");
		#endif
	}
}

void GOA_DFPlayerMini::playSongInFolder(uint8_t file, uint8_t folder)
{
	if(playing)
	{
		sendCommand(0x16, 0x00, 0x00); // [DH]=X, [DL]=X, Stop playing current track
#if DEBUG
		_debug(F("Stop audio\n"));
#endif
		delay(30);
	}
	else
	{
		playing = true;
	}
	sendCommand(0x0F, folder, file); // play (0x0F) file "005.mp3" or "005.wav" from folder "01"
									 // [DH]=Folder, [DL]=File - Specify folder and file to playback
#if DEBUG
	_debug("Play: " + String(folder) + "/" + String(file) + ".mp3\n");
#endif
}

void GOA_DFPlayerMini::playRandomSongInFolder(uint8_t folder)
{
	uint8_t number = 1;
	switch(folder)
	{
		case 1:
			number = 2;
			break;
		case 2:
			number = 4;
			break;
		case 3:
			number = 7;
			break;
		case 4:
			number = 4;
			break;
		case 5:
			number = 10;
			break;
		case 6:
			number = 9;
			break;
		case 7:
			number = 12;
			break;
		case 8:
			number = 9;
			break;
		case 9:
			number = 7;
			break;
		case 10:
			number = 5;
			break;
	}
	uint8_t file = random(1, number + 1);
	playSongInFolder(file, folder);
}

void GOA_DFPlayerMini::setup()
{
#if DEBUG
	_debug("DFPlayer mini: ");
#endif
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
	playing = false;
#if DEBUG
	_debug("ready\n");
#endif
}

void GOA_DFPlayerMini::loop()
{
	doReceiveData();
	if (playing)
	{
		if(digitalRead(DFPLAYER_MINI_BUSY) == HIGH)
		{
			// no playing file
			playing = false;
		}
	}
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

void GOA_DFPlayerMini::playPowerOn() { playRandomSongInFolder(1); }
void GOA_DFPlayerMini::playReset() {}

void GOA_DFPlayerMini::playQuestion() {}
void GOA_DFPlayerMini::playBadChoice() { playRandomSongInFolder(2); }
void GOA_DFPlayerMini::playGoodChoice() { playRandomSongInFolder(3); }
void GOA_DFPlayerMini::playStartGame() { playRandomSongInFolder(4); }
void GOA_DFPlayerMini::playToken() {}
void GOA_DFPlayerMini::playIAThinking() { playRandomSongInFolder(5); }
void GOA_DFPlayerMini::playLoosingAlert() { playRandomSongInFolder(6); }
void GOA_DFPlayerMini::playWinningTeasing() { playRandomSongInFolder(7); }
void GOA_DFPlayerMini::playLoose() { playRandomSongInFolder(9); }
void GOA_DFPlayerMini::playWin() { playRandomSongInFolder(10); }
void GOA_DFPlayerMini::playDraw() {}
