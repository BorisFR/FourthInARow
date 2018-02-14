
// Module names are of the form poly_<inkscape-path-id>().  As a result,
// you can associate a polygon in this OpenSCAD program with the corresponding
// SVG element in the Inkscape document by looking for the XML element with
// the attribute id="inkscape-path-id".

// fudge value is used to ensure that subtracted solids are a tad taller
// in the z dimension than the polygon being subtracted from.  This helps
// keep the resulting .stl file manifold.
fudge = 0.1;

module logo_man(h)
{
  scale([25.4/90, -25.4/90, 1]) union()
  {
    linear_extrude(height=h)
      polygon([[-69.974416,492.826079],[-72.900530,491.778174],[-75.741231,490.586009],[-78.488229,489.257309],[-81.133235,487.799799],[-83.667957,486.221205],[-86.084107,484.529251],[-88.373393,482.731662],[-90.527526,480.836164],[-92.538216,478.850482],[-94.397173,476.782341],[-96.096107,474.639466],[-97.626728,472.429582],[-98.980745,470.160414],[-100.149869,467.839688],[-101.125809,465.475128],[-101.900276,463.074459],[-102.158911,460.938052],[-102.400159,456.443117],[-102.830937,440.310146],[-103.193481,414.540499],[-103.488666,378.999129],[-103.880453,278.061037],[-104.013286,136.415499],[-104.024486,-182.674811],[-112.039316,-182.674811],[-120.054146,-182.674811],[-120.054146,-62.224281],[-120.130342,6.545059],[-120.294116,28.199600],[-120.602588,43.245422],[-121.101444,53.091051],[-121.436543,56.503957],[-121.836370,59.145011],[-122.306636,61.190280],[-122.853052,62.815829],[-124.197176,65.512029],[-126.210062,68.757988],[-128.342289,71.586083],[-130.652538,74.039370],[-133.199486,76.160903],[-136.041813,77.993736],[-139.238196,79.580923],[-142.847314,80.965520],[-146.927846,82.190579],[-150.148364,82.893476],[-153.386494,83.293898],[-156.622342,83.401137],[-159.836013,83.224481],[-163.007614,82.773223],[-166.117251,82.056652],[-169.145028,81.084059],[-172.071053,79.864736],[-174.875429,78.407971],[-177.538264,76.723057],[-180.039663,74.819284],[-182.359731,72.705942],[-184.478575,70.392322],[-186.376300,67.887714],[-188.033012,65.201410],[-189.428816,62.342699],[-189.820289,60.652698],[-190.184902,57.537943],[-190.833945,47.408952],[-191.376727,32.705290],[-191.814032,14.176519],[-192.375343,-31.358092],[-192.524144,-83.198374],[-192.266698,-135.347822],[-191.609272,-181.809927],[-191.132523,-201.034317],[-190.558129,-216.588182],[-189.886873,-227.721958],[-189.515165,-231.397073],[-189.119536,-233.686081],[-187.029216,-240.656474],[-184.449208,-247.443793],[-181.403913,-254.024337],[-177.917731,-260.374407],[-174.015063,-266.470305],[-169.720309,-272.288330],[-165.057871,-277.804783],[-160.052149,-282.995966],[-154.727543,-287.838178],[-149.108455,-292.307720],[-143.219285,-296.380894],[-137.084433,-300.033999],[-130.728301,-303.243337],[-124.175288,-305.985207],[-117.449797,-308.235912],[-110.576226,-309.971751],[-105.115334,-310.698531],[-96.357725,-311.329545],[-84.774455,-311.864660],[-70.836579,-312.303742],[-37.781233,-312.893277],[-0.960133,-313.097086],[35.858277,-312.914102],[68.905550,-312.343262],[82.837371,-311.912063],[94.413240,-311.383500],[103.162103,-310.757440],[108.612904,-310.033751],[115.908630,-308.210732],[122.952236,-305.885723],[129.753512,-303.053259],[136.322245,-299.707876],[142.668225,-295.844110],[148.801241,-291.456496],[154.731081,-286.539571],[160.467534,-281.087871],[165.897583,-275.320168],[170.629110,-269.697730],[174.737315,-264.088070],[178.297397,-258.358704],[181.384557,-252.377147],[184.073995,-246.010912],[186.440911,-239.127515],[188.560504,-231.594471],[189.809334,-226.158547],[190.764583,-219.875122],[191.465417,-211.257156],[191.951000,-198.817608],[192.260499,-181.069437],[192.433079,-156.525603],[192.524144,-81.102781],[192.418054,-10.417982],[192.252992,13.652958],[191.984406,31.542072],[191.590663,44.248720],[191.050129,52.772264],[190.341171,58.112064],[189.916772,59.900359],[189.442154,61.267479],[187.869628,64.747722],[186.225560,67.778382],[184.449707,70.422471],[182.481829,72.742999],[180.261682,74.802977],[177.729025,76.665416],[174.823616,78.393327],[171.485214,80.049719],[168.472387,81.272785],[165.381116,82.221172],[162.233430,82.900001],[159.051360,83.314391],[155.856937,83.469463],[152.672190,83.370339],[149.519151,83.022138],[146.419848,82.429981],[143.396312,81.598988],[140.470573,80.534280],[137.664663,79.240978],[135.000610,77.724202],[132.500446,75.989073],[130.186200,74.040711],[128.079902,71.884236],[126.203584,69.524769],[121.392544,62.779229],[120.846814,-59.947811],[120.301064,-182.674851],[112.331054,-182.674851],[104.361034,-182.674851],[104.361034,137.982599],[104.370941,253.027922],[104.291184,337.751563],[103.957544,396.973072],[103.644199,418.526637],[103.205801,435.511999],[102.621823,448.531604],[101.871737,458.187894],[100.935016,465.083313],[100.390252,467.683960],[99.791132,469.820306],[99.135089,471.567655],[98.419558,473.001315],[97.641973,474.196589],[96.799767,475.228784],[94.911232,477.105158],[92.733424,479.232879],[89.031837,482.813715],[85.236602,485.821412],[81.272245,488.285464],[77.063293,490.235367],[72.534272,491.700615],[67.609709,492.710703],[62.214130,493.295126],[56.272064,493.483379],[50.330000,493.295126],[44.934423,492.710703],[40.009861,491.700615],[35.480840,490.235367],[31.271888,488.285464],[27.307531,485.821412],[23.512297,482.813715],[19.810714,479.232879],[17.672757,477.035108],[15.813799,475.021417],[14.214376,472.841930],[12.855023,470.146769],[11.716276,466.586059],[10.778669,461.809922],[10.022738,455.468482],[9.429019,447.211863],[8.978046,436.690187],[8.650355,423.553578],[8.286959,388.036055],[8.183115,337.860280],[8.183104,270.227239],[8.183104,81.814489],[0.168274,81.814489],[-7.846556,81.814489],[-7.846556,270.227279],[-7.959090,364.711738],[-8.371807,423.266143],[-8.725944,441.608870],[-9.197379,454.016238],[-9.800195,461.503965],[-10.155272,463.720375],[-10.548476,465.087769],[-12.276237,468.684663],[-14.398343,472.214263],[-16.864311,475.621967],[-19.623655,478.853178],[-22.625890,481.853294],[-25.820530,484.567717],[-29.157090,486.941845],[-32.585086,488.921079],[-36.400741,490.502373],[-41.003511,491.827937],[-46.122411,492.869469],[-51.486459,493.598667],[-56.824670,493.987229],[-61.866060,494.006853],[-66.339647,493.629237],[-68.278832,493.282620],[-69.974446,492.826079]]);
    linear_extrude(height=h)
      polygon([[-24.904196,-332.435341],[-29.338653,-334.113436],[-33.563419,-335.907683],[-37.585640,-337.824446],[-41.412461,-339.870089],[-45.051026,-342.050977],[-48.508481,-344.373474],[-51.791969,-346.843945],[-54.908636,-349.468754],[-57.865627,-352.254267],[-60.670086,-355.206846],[-63.329158,-358.332858],[-65.849989,-361.638666],[-68.239722,-365.130635],[-70.505503,-368.815129],[-72.654476,-372.698513],[-74.693786,-376.787151],[-76.647901,-381.015487],[-78.150632,-384.636964],[-79.260798,-387.982290],[-80.037219,-391.382169],[-80.538713,-395.167311],[-80.824100,-399.668420],[-80.981826,-412.141371],[-80.829385,-424.694157],[-80.544142,-429.176647],[-80.035380,-432.921049],[-79.239971,-436.270748],[-78.094788,-439.569131],[-76.536702,-443.159582],[-74.502586,-447.385488],[-71.473787,-453.020679],[-68.128394,-458.293193],[-64.487521,-463.202994],[-60.572287,-467.750043],[-56.403807,-471.934306],[-52.003197,-475.755746],[-47.391575,-479.214326],[-42.590057,-482.310010],[-37.619759,-485.042762],[-32.501797,-487.412544],[-27.257289,-489.419322],[-21.907350,-491.063057],[-16.473098,-492.343714],[-10.975647,-493.261257],[-5.436116,-493.815649],[0.124380,-494.006853],[5.684724,-493.834833],[11.223800,-493.299553],[16.720491,-492.400976],[22.153681,-491.139065],[27.502253,-489.513786],[32.745091,-487.525100],[37.861078,-485.172971],[42.829099,-482.457364],[47.628036,-479.378242],[52.236773,-475.935567],[56.634193,-472.129305],[60.799181,-467.959417],[64.710619,-463.425869],[68.347392,-458.528623],[71.688382,-453.267644],[74.712474,-447.642894],[76.808966,-443.297296],[78.408129,-439.631490],[79.577093,-436.274534],[80.382986,-432.855485],[80.892938,-429.003400],[81.174077,-424.347338],[81.318434,-411.139511],[81.167227,-398.273248],[80.903650,-393.666369],[80.448474,-389.868817],[79.751985,-386.574459],[78.764470,-383.477163],[77.436217,-380.270797],[75.717514,-376.649231],[72.280105,-370.267865],[68.449535,-364.327180],[64.219377,-358.820713],[59.583204,-353.742004],[54.534589,-349.084593],[49.067105,-344.842017],[43.174325,-341.007817],[36.849824,-337.575531],[32.198782,-335.328834],[28.224650,-333.566052],[24.656888,-332.221621],[21.224959,-331.229979],[17.658324,-330.525563],[13.686445,-330.042808],[9.038784,-329.716152],[3.444804,-329.480031],[-5.734058,-329.361254],[-9.586186,-329.493916],[-13.061124,-329.766532],[-16.244634,-330.188042],[-19.222475,-330.767387],[-22.080409,-331.513506],[-24.904196,-332.435341]]);
  }
}

logo_man(1);
