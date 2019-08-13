#ifndef __DM_DELTA_UT_HH__
#define __DM_DELTA_UT_HH__


/********************************************************************
**
** File Name:       dm_delta_ut.h
**
** Purpose:         delta-UT = UT1-UTC
**
**                  http://maia.usno.navy.mil/search/search.html
**
**                  Input Date range:
**                  From:    1-1-2010   [MJD = 55197.00]
**                            12-31-2010   [MJD = 55561.00]
**                                 1-1-2011   [MJD = 55562.00]
**                            12-31-2011   [MJD = 55926.00]
**                  To  :     8-11-2012   [MJD = 56150.00]
**                  [Check] Bull. A UT1-UTC (sec. of time) 
**
** Author:          
**
** Date:            06/02/2010
**
** Comment:
**
**
*********************************************************************/

#define Max_DM_UT1_UT_Index 954

const double DM_UT1_UT[Max_DM_UT1_UT_Index] = {
         0.1140706,  0.1134314,  0.1125158,  0.1113605,  0.1100133,  /* 2010/01/01*/
         0.1086211,  0.1073421,  0.1062552,  0.1053910,  0.1048044,
         0.1044138,  0.1041330,  0.1038800,  0.1036401,  0.1033218,
         0.1028539,  0.1021974,  0.1013628,  0.1004158,  0.0994192,
         0.0984120,  0.0973919,  0.0964003,  0.0954977,  0.0947213,
         0.0940864,  0.0935337,  0.0929264,  0.0920993,  0.0909971,
         0.0895823,  0.0878631,  0.0859812,  0.0841183,  0.0824214,
         0.0810017,  0.0798463,  0.0789089,  0.0781567,  0.0775369,
         0.0769796,  0.0763752,  0.0756484,  0.0747531,  0.0736731,
         0.0724270,  0.0710435,  0.0695783,  0.0680584,  0.0665752,
         0.0651938,  0.0639447,  0.0628220,  0.0618155,  0.0608571,
         0.0597782,  0.0584610,  0.0568892,  0.0550325,  0.0529818,
         0.0509194,  0.0490368,  0.0473883,  0.0460167,  0.0449325,
         0.0440362,  0.0432616,  0.0424575,  0.0415498,  0.0406061,
         0.0395897,  0.0384792,  0.0373784,  0.0362511,  0.0350494,
         0.0338151,  0.0325921,  0.0314871,  0.0305659,  0.0298127,
         0.0292016,  0.0286544,  0.0280625,  0.0272723,  0.0261349,
         0.0246647,  0.0229450,  0.0210309,  0.0190503,  0.0172218,
         0.0157239,  0.0145610,  0.0136460,  0.0128555,  0.0120654,
         0.0112003,  0.0102328,  0.0091343,  0.0078710,  0.0065068,
         0.0050550,  0.0035141,  0.0019552,  0.0003961, -0.0010995,
        -0.0024703, -0.0036784, -0.0047729, -0.0058056, -0.0068518,
        -0.0080082, -0.0093800, -0.0109777, -0.0127416, -0.0146115,
        -0.0164869, -0.0183010, -0.0199326, -0.0212811, -0.0223472,
        -0.0231656, -0.0238168, -0.0243854, -0.0249140, -0.0254684,
        -0.0261010, -0.0268378, -0.0277142, -0.0287541, -0.0299198,
        -0.0311480, -0.0323371, -0.0333998, -0.0342927, -0.0350032,
        -0.0356508, -0.0363459, -0.0371715, -0.0382234, -0.0395190,
        -0.0410169, -0.0426769, -0.0443682, -0.0459177, -0.0472336,
        -0.0482878, -0.0491018, -0.0497546, -0.0502788, -0.0507246,
        -0.0511774, -0.0517169, -0.0523748, -0.0531419, -0.0540002,
        -0.0549111, -0.0558354, -0.0567209, -0.0575425, -0.0582425,
        -0.0587963, -0.0592204, -0.0595398, -0.0598233, -0.0601617,
        -0.0606449, -0.0613300, -0.0621914, -0.0631283, -0.0640195,
        -0.0647652, -0.0653010, -0.0656005, -0.0656749, -0.0655602,
        -0.0653169, -0.0650267, -0.0647636, -0.0645858, -0.0645259,
        -0.0645897, -0.0647566, -0.0649923, -0.0652558, -0.0654972,
        -0.0656654, -0.0657178, -0.0656336, -0.0654095, -0.0650648,
        -0.0646620, -0.0642978, -0.0640836, -0.0641005, -0.0643619,
        -0.0648008, -0.0652997, -0.0657296, -0.0659829, -0.0659981,
        -0.0657751, -0.0653584, -0.0648185, -0.0642331, -0.0636763,
        -0.0632091, -0.0628748, -0.0626893, -0.0626422, -0.0627009,
        -0.0628201, -0.0629496, -0.0630430, -0.0630642, -0.0629875,
        -0.0628036, -0.0625267, -0.0622028, -0.0619155, -0.0617711,
        -0.0618689, -0.0622580, -0.0629102, -0.0637227, -0.0645443,
        -0.0652264, -0.0656717, -0.0658528, -0.0658072, -0.0656094,
        -0.0653439, -0.0650880, -0.0649047, -0.0648395, -0.0649188,
        -0.0651439, -0.0654955, -0.0659351, -0.0664119, -0.0668748,
        -0.0672778, -0.0675866, -0.0677864, -0.0678875, -0.0679275,
        -0.0679760, -0.0681279, -0.0684833, -0.0691198, -0.0700566,
        -0.0712335, -0.0725215, -0.0737589, -0.0748056, -0.0755868,
        -0.0761292, -0.0764752, -0.0767172, -0.0769457, -0.0772322,
        -0.0776245, -0.0781486, -0.0788103, -0.0795953, -0.0804704,
        -0.0813887, -0.0822981, -0.0831501, -0.0839079, -0.0845534,
        -0.0850912, -0.0855519, -0.0859932, -0.0864953, -0.0871491,
        -0.0880352, -0.0891971, -0.0906173, -0.0922107, -0.0938411,
        -0.0953615, -0.0966603, -0.0976951, -0.0984963, -0.0991450,
        -0.0997379, -0.1003586, -0.1010642, -0.1018851, -0.1028298,
        -0.1038883, -0.1050339, -0.1062254, -0.1074134, -0.1085487,
        -0.1095908, -0.1105148, -0.1113180, -0.1120236, -0.1126818,
        -0.1133653, -0.1141564, -0.1151294, -0.1163306, -0.1177608,
        -0.1193670, -0.1210483, -0.1226785, -0.1241419, -0.1253674,
        -0.1263485, -0.1271384, -0.1278250, -0.1284993, -0.1292319,
        -0.1300633, -0.1310072, -0.1320566, -0.1331888, -0.1343685,
        -0.1355511, -0.1366900, -0.1377445, -0.1386873, -0.1395102,
        -0.1402299, -0.1408917, -0.1415657, -0.1423357, -0.1432791,
        -0.1444446, -0.1458364, -0.1474092, -0.1490759, -0.1507267,
        -0.1522544, -0.1535798, -0.1546715, -0.1555521, -0.1562883,
        -0.1569667, -0.1576671, -0.1584418, -0.1593094, -0.1602595,
        -0.1612633, -0.1622819, -0.1632743, -0.1642007, -0.1650253,
        -0.1657186, -0.1662624, -0.1666567, -0.1669291, -0.1671380,
        -0.1673680, -0.1677101, -0.1682327, -0.1689561, -0.1698433,
        -0.1708103, -0.1717538, -0.1725910, -0.1732810, -0.1738103, /* 2010/12/31*/
        -0.1405572, -0.1407862, -0.1409704, -0.1411339, -0.1413425, /* 2011/01/01*/
        -0.1416425, -0.1420699, -0.1425759, -0.1431293, -0.1437319,
        -0.1443277, -0.1449085, -0.1454644, -0.1459521, -0.1463234,
        -0.1466331, -0.1468977, -0.1471776, -0.1475606, -0.1480809,
        -0.1488020, -0.1497110, -0.1508181, -0.1519964, -0.1530892,
        -0.1540126, -0.1547226, -0.1552255, -0.1555841, -0.1558922,
        -0.1562060, -0.1565721, -0.1570425, -0.1576720, -0.1584162,
        -0.1592375, -0.1600013, -0.1607583, -0.1614625, -0.1620680,
        -0.1626236, -0.1630893, -0.1634721, -0.1638157, -0.1641764,
        -0.1646609, -0.1653714, -0.1663640, -0.1676592, -0.1691440,
        -0.1707662, -0.1723893, -0.1738311, -0.1749978, -0.1758566,
        -0.1764789, -0.1769531, -0.1773905, -0.1778458, -0.1784500,
        -0.1791967, -0.1800865, -0.1811599, -0.1823238, -0.1835345,
        -0.1846974, -0.1857526, -0.1867359, -0.1876191, -0.1884057,
        -0.1891176, -0.1896992, -0.1902941, -0.1910279, -0.1919964,
        -0.1932201, -0.1946551, -0.1962157, -0.1978114, -0.1993497,
        -0.2007263, -0.2018458, -0.2027546, -0.2035636, -0.2044239,
        -0.2053199, -0.2063373, -0.2075238, -0.2088430, -0.2102399,
        -0.2117112, -0.2131982, -0.2146846, -0.2160607, -0.2172843,
        -0.2183379, -0.2192299, -0.2199863, -0.2207248, -0.2214925,
        -0.2223362, -0.2233124, -0.2244729, -0.2257966, -0.2273007,
        -0.2289283, -0.2305801, -0.2321180, -0.2334577, -0.2345645,
        -0.2354477, -0.2361754, -0.2368923, -0.2376851, -0.2385604,
        -0.2395270, -0.2405621, -0.2416373, -0.2427721, -0.2438717,
        -0.2449045, -0.2458913, -0.2468447, -0.2477060, -0.2485632,
        -0.2493987, -0.2502156, -0.2510871, -0.2521041, -0.2533307,
        -0.2547990, -0.2564228, -0.2581674, -0.2599858, -0.2618035,
        -0.2634453, -0.2648417, -0.2660015, -0.2669779, -0.2677927,
        -0.2685744, -0.2693853, -0.2702144, -0.2711018, -0.2719754,
        -0.2728913, -0.2739003, -0.2748687, -0.2757583, -0.2765661,
        -0.2772618, -0.2778790, -0.2784173, -0.2789050, -0.2794132,
        -0.2800668, -0.2808865, -0.2818617, -0.2829921, -0.2841736,
        -0.2853074, -0.2863496, -0.2872594, -0.2879515, -0.2884482,
        -0.2887850, -0.2889872, -0.2891856, -0.2894217, -0.2897180,
        -0.2900715, -0.2904736, -0.2908935, -0.2912483, -0.2915190,
        -0.2916757, -0.2917243, -0.2917062, -0.2916101, -0.2914157,
        -0.2911626, -0.2908884, -0.2906499, -0.2905344, -0.2906806,
        -0.2910639, -0.2915642, -0.2920716, -0.2924899, -0.2927763,
        -0.2928694, -0.2927530, -0.2924896, -0.2921613, -0.2918373,
        -0.2915728, -0.2913811, -0.2913298, -0.2914246, -0.2916256,
        -0.2918574, -0.2920291, -0.2921551, -0.2922200, -0.2921960,
        -0.2920784, -0.2918720, -0.2915697, -0.2912227, -0.2909258,
        -0.2907401, -0.2907800, -0.2911091, -0.2916604, -0.2923214,
        -0.2929631, -0.2934608, -0.2937377, -0.2937806, -0.2936395,
        -0.2933863, -0.2930906, -0.2928216, -0.2926473, -0.2926125,
        -0.2927398, -0.2929937, -0.2933230, -0.2936681, -0.2939635,
        -0.2941568, -0.2942494, -0.2942687, -0.2942390, -0.2941837,
        -0.2941458, -0.2941914, -0.2943846, -0.2947947, -0.2954583,
        -0.2963548, -0.2974048, -0.2984859, -0.2994698, -0.3002543,
        -0.3008146, -0.3011880, -0.3014457, -0.3016714, -0.3019464,
        -0.3023282, -0.3028453, -0.3035003, -0.3042722, -0.3051196,
        -0.3059913, -0.3068432, -0.3076408, -0.3083612, -0.3089984,
        -0.3095655, -0.3100893, -0.3106114, -0.3111846, -0.3118775,
        -0.3127632, -0.3138998, -0.3153061, -0.3169394, -0.3186946,
        -0.3204350, -0.3220341, -0.3234135, -0.3245675, -0.3255497,
        -0.3264468, -0.3273463, -0.3283115, -0.3293735, -0.3305346,
        -0.3317761, -0.3330673, -0.3343644, -0.3356198, -0.3367941,
        -0.3378638, -0.3388209, -0.3396739, -0.3404514, -0.3411970,
        -0.3419633, -0.3428099, -0.3437979, -0.3449785, -0.3463791,
        -0.3479872, -0.3497403, -0.3515314, -0.3532388, -0.3547600,
        -0.3560503, -0.3571351, -0.3580907, -0.3590125, -0.3599791,
        -0.3610309, -0.3621722, -0.3633837, -0.3646345, -0.3658890,
        -0.3671077, -0.3682515, -0.3692906, -0.3702097, -0.3710123,
        -0.3717203, -0.3723705, -0.3730117, -0.3737012, -0.3744956,
        -0.3754428, -0.3765737, -0.3778891, -0.3793523, -0.3809671,
        -0.3825561, -0.3840190, -0.3852888, -0.3863545, -0.3872643,
        -0.3881035, -0.3889604, -0.3898948, -0.3909252, -0.3920347,
        -0.3931863, -0.3943372, -0.3954471, -0.3964799, -0.3974069,
        -0.3982110, -0.3988921, -0.3994682, -0.3999748, -0.4004604,
        -0.4009809, -0.4015922, -0.4023419, -0.4032584, -0.4043417,
        -0.4055597, -0.4068499, -0.4081297, -0.4093142, -0.4103396,
        -0.4111823, -0.4118683, -0.4124653, -0.4130588, -0.4137223,
        -0.4144941, -0.4153707, -0.4163166, -0.4172825, -0.4182199, /* 2011/12/31*/
        -0.4190888, -0.4198585, -0.4205103, -0.4210406, -0.4214637, /* 2012/01/01*/
        -0.4218113, -0.4221307, -0.4224791, -0.4229167, -0.4234976,
        -0.4242578, -0.4252021, -0.4262980, -0.4274786, -0.4286573,
        -0.4297497, -0.4306942, -0.4314671, -0.4320875, -0.4326125,
        -0.4331209, -0.4336898, -0.4343730, -0.4351869, -0.4361101,
        -0.4370962, -0.4380901, -0.4390416, -0.4399128, -0.4406802,
        -0.4413354, -0.4418868, -0.4423609, -0.4428002, -0.4432598,
        -0.4438015, -0.4444854, -0.4453583, -0.4464388, -0.4477034,
        -0.4490845, -0.4504832, -0.4517961, -0.4529447, -0.4538960,
        -0.4546676, -0.4553174, -0.4559240, -0.4565658, -0.4573024,
        -0.4581636, -0.4591456, -0.4602165, -0.4613275, -0.4624269,
        -0.4634698, -0.4644224, -0.4652639, -0.4659882, -0.4666065,
        -0.4671487, -0.4676631, -0.4682158, -0.4688868, -0.4697581,
        -0.4708858, -0.4722731, -0.4738626, -0.4755492, -0.4772056,
        -0.4787060, -0.4799620, -0.4809727, -0.4818091, -0.4825518,
        -0.4833165, -0.4841751, -0.4851342, -0.4862294, -0.4874526,
        -0.4887683, -0.4900717, -0.4912990, -0.4924641, -0.4934627,
        -0.4944028, -0.4952418, -0.4959687, -0.4965892, -0.4972041,
        -0.4979003, -0.4987315, -0.4997430, -0.5009054, -0.5023023,
        -0.5038995, -0.5055369, -0.5070946, -0.5084360, -0.5095760,
        -0.5105729, -0.5114453, -0.5123346, -0.5133440, -0.5144884,
        -0.5157149, -0.5170105, -0.5183241, -0.5196009, -0.5207917,
        -0.5219059, -0.5229319, -0.5238602, -0.5246677, -0.5253622,
        -0.5260458, -0.5267077, -0.5273496, -0.5280557, -0.5289100,
        -0.5299509, -0.5311601, -0.5325239, -0.5339730, -0.5354462,
        -0.5368640, -0.5380939, -0.5391506, -0.5400317, -0.5408131,
        -0.5415655, -0.5423216, -0.5431322, -0.5440048, -0.5449535,
        -0.5459728, -0.5469585, -0.5479162, -0.5487745, -0.5494625,
        -0.5499931, -0.5504001, -0.5506737, -0.5508671, -0.5510168,
        -0.5512039, -0.5514936, -0.5519257, -0.5525407, -0.5533046,
        -0.5541717, -0.5550782, -0.5559595, -0.5567238, -0.5573476,
        -0.5578255, -0.5581735, -0.5585179, -0.5589176, -0.5594456,
        -0.5601230, -0.5608403, -0.5615864, -0.5622570, -0.5628242,
        -0.5632550, -0.5635043, -0.5636078, -0.5635670, -0.5633844,
        -0.5630851, -0.5627330, -0.5623273, -0.5619635, -0.5617617,
        -0.5616497, -0.5616615, -0.5617725, -0.5619434, -0.5620617,
        -0.5620084, -0.5618021, -0.5613899, -0.5608535, -0.5603361,
        -0.5599010, -0.5595846, -0.5593790, -0.5592658, -0.5592120,
        -0.5591238, -0.5589822, -0.5587808, -0.5584692, -0.5580355,
        -0.5575381, -0.5569484, -0.5562836, -0.5556252, -0.5550355,
        -0.5545827, -0.5543245, -0.5542773, -0.5543954, -0.5546603,
        -0.5549621, -0.5552267, -0.5553912, -0.5554227, -0.5553649,
        -0.5551768, -0.5549219, -0.5547419, -0.5546515, -0.5546473,
        -0.5547811, -0.5550177, -0.5552732, -0.5555264, -0.5557507,
        -0.5558575, -0.5558380, -0.5556881, -0.5554285  /* 2012/08/11*/
};

#endif  //  __DM_DELTA_UT_HH__
