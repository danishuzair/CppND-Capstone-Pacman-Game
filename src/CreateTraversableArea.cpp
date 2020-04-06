//
// Created by dansid on 4/1/20.
//

#include "CreateTraversableArea.h"

void CreateTraffic(std::vector<std::shared_ptr<Intersection>> &intersections, std::vector<std::shared_ptr<Street>> &streets) {
    int nIntersections = 68;
    for (size_t ni = 0; ni < nIntersections; ni++) {
        intersections.push_back(std::make_shared<Intersection>());
    }
    intersections.at(0)->setLocation(253,288);
    intersections.at(1)->setLocation(41,46);
    intersections.at(2)->setLocation(41,105);
    intersections.at(3)->setLocation(41,167);
    intersections.at(4)->setLocation(5,288);
    intersections.at(5)->setLocation(41,412);
    intersections.at(6)->setLocation(41,473);
    intersections.at(7)->setLocation(68,473);
    intersections.at(8)->setLocation(41,532);
    intersections.at(9)->setLocation(68,532);
    intersections.at(10)->setLocation(41,592);
    intersections.at(11)->setLocation(121,46);
    intersections.at(12)->setLocation(121,105);
    intersections.at(13)->setLocation(121,167);
    intersections.at(14)->setLocation(121,288);
    intersections.at(15)->setLocation(121,412);
    intersections.at(16)->setLocation(121,532);
    intersections.at(17)->setLocation(229,46);
    intersections.at(18)->setLocation(174,105);
    intersections.at(19)->setLocation(229,105);
    intersections.at(20)->setLocation(174,167);
    intersections.at(21)->setLocation(229,167);
    intersections.at(22)->setLocation(229,228);
    intersections.at(23)->setLocation(174,228);
    intersections.at(24)->setLocation(174,288);
    intersections.at(25)->setLocation(174,350);
    intersections.at(26)->setLocation(174,412);
    intersections.at(27)->setLocation(229,412);
    intersections.at(28)->setLocation(229,473);
    intersections.at(29)->setLocation(174,473);
    intersections.at(30)->setLocation(174,532);
    intersections.at(31)->setLocation(229,532);
    intersections.at(32)->setLocation(229,592);
    intersections.at(33)->setLocation(283,46);
    intersections.at(34)->setLocation(283,105);
    intersections.at(35)->setLocation(334,105);
    intersections.at(36)->setLocation(334,167);
    intersections.at(37)->setLocation(283,167);
    intersections.at(38)->setLocation(283,228);
    intersections.at(39)->setLocation(334,228);
    intersections.at(40)->setLocation(334,350);
    intersections.at(41)->setLocation(283,412);
    intersections.at(42)->setLocation(334,412);
    intersections.at(43)->setLocation(283,473);
    intersections.at(44)->setLocation(334,473);
    intersections.at(45)->setLocation(334,532);
    intersections.at(46)->setLocation(283,532);
    intersections.at(47)->setLocation(283,592);
    intersections.at(48)->setLocation(390,46);
    intersections.at(49)->setLocation(390,105);
    intersections.at(50)->setLocation(390,167);
    intersections.at(51)->setLocation(390,288);
    intersections.at(52)->setLocation(390,412);
    intersections.at(53)->setLocation(390,532);
    intersections.at(54)->setLocation(470,46);
    intersections.at(55)->setLocation(470,105);
    intersections.at(56)->setLocation(470,167);
    intersections.at(57)->setLocation(505,288);
    intersections.at(58)->setLocation(470,412);
    intersections.at(59)->setLocation(470,473);
    intersections.at(60)->setLocation(444,473);
    intersections.at(61)->setLocation(390,473);
    intersections.at(62)->setLocation(121,473);
    intersections.at(63)->setLocation(444,532);
    intersections.at(64)->setLocation(470,532);
    intersections.at(65)->setLocation(470,592);
    intersections.at(66)->setLocation(253,228);
    intersections.at(67)->setLocation(334,288);

    int nStreets = 88;
    for (size_t ni = 0; ni < nStreets; ni++) {
        streets.push_back(std::make_shared<Street>());
    }

    streets.at(0)->initializeStreet(true,true,true,true,intersections.at(1),intersections.at(11));
    streets.at(1)->initializeStreet(true,false,true,true,intersections.at(11),intersections.at(17));
    streets.at(2)->initializeStreet(true,true,true,true,intersections.at(33),intersections.at(48));
    streets.at(3)->initializeStreet(true,false,true,true,intersections.at(48),intersections.at(54));
    streets.at(4)->initializeStreet(true,false,false,true,intersections.at(1),intersections.at(2));
    streets.at(5)->initializeStreet(true,false,false,true,intersections.at(11),intersections.at(12));
    streets.at(6)->initializeStreet(true,false,false,true,intersections.at(17),intersections.at(19));
    streets.at(7)->initializeStreet(true,false,false,true,intersections.at(33),intersections.at(34));
    streets.at(8)->initializeStreet(true,false,false,true,intersections.at(48),intersections.at(49));
    streets.at(9)->initializeStreet(true,false,false,true,intersections.at(54),intersections.at(55));
    streets.at(10)->initializeStreet(true,true,true,true,intersections.at(2),intersections.at(12));
    streets.at(11)->initializeStreet(true,false,true,true,intersections.at(12),intersections.at(18));
    streets.at(12)->initializeStreet(true,false,true,true,intersections.at(18),intersections.at(19));
    streets.at(13)->initializeStreet(true,false,true,true,intersections.at(19),intersections.at(34));
    streets.at(14)->initializeStreet(true,false,true,true,intersections.at(34),intersections.at(35));
    streets.at(15)->initializeStreet(true,false,true,true,intersections.at(35),intersections.at(49));
    streets.at(16)->initializeStreet(true,false,true,true,intersections.at(49),intersections.at(55));
    streets.at(17)->initializeStreet(true,false,false,true,intersections.at(2),intersections.at(3));
    streets.at(18)->initializeStreet(true,false,false,true,intersections.at(12),intersections.at(13));
    streets.at(19)->initializeStreet(true,false,false,true,intersections.at(18),intersections.at(20));
    streets.at(20)->initializeStreet(true,false,false,true,intersections.at(35),intersections.at(36));
    streets.at(21)->initializeStreet(true,false,false,true,intersections.at(49),intersections.at(50));
    streets.at(22)->initializeStreet(true,false,false,true,intersections.at(55),intersections.at(56));
    streets.at(23)->initializeStreet(true,true,true,true,intersections.at(3),intersections.at(13));
    streets.at(24)->initializeStreet(true,true,true,true,intersections.at(20),intersections.at(21));
    streets.at(25)->initializeStreet(true,true,true,true,intersections.at(37),intersections.at(36));
    streets.at(26)->initializeStreet(true,true,true,true,intersections.at(50),intersections.at(56));
    streets.at(27)->initializeStreet(true,false,true,true,intersections.at(13),intersections.at(14));
    streets.at(28)->initializeStreet(false,false,false,true,intersections.at(21),intersections.at(22));
    streets.at(29)->initializeStreet(false,false,false,true,intersections.at(37),intersections.at(38));
    streets.at(30)->initializeStreet(true,false,true,true,intersections.at(50),intersections.at(51));
    streets.at(31)->initializeStreet(false,false,false,true,intersections.at(23),intersections.at(22));
    streets.at(32)->initializeStreet(false,false,false,true,intersections.at(22),intersections.at(66));
    streets.at(33)->initializeStreet(false,false,false,true,intersections.at(66),intersections.at(38));
    streets.at(34)->initializeStreet(false,false,false,true,intersections.at(38),intersections.at(39));
    streets.at(35)->initializeStreet(false,false,false,true,intersections.at(23),intersections.at(24));
    streets.at(36)->initializeStreet(false,false,false,false,intersections.at(66),intersections.at(0));
    streets.at(37)->initializeStreet(false,false,false,true,intersections.at(39),intersections.at(67));
    streets.at(38)->initializeStreet(false,false,false,true,intersections.at(4),intersections.at(14));
    streets.at(39)->initializeStreet(false,false,false,true,intersections.at(14),intersections.at(24));
    streets.at(40)->initializeStreet(false,false,false,true,intersections.at(67),intersections.at(51));
    streets.at(41)->initializeStreet(false,false,false,true,intersections.at(51),intersections.at(57));
    streets.at(42)->initializeStreet(false,false,false,true,intersections.at(4),intersections.at(57),true);
    streets.at(43)->initializeStreet(true,false,false,true,intersections.at(14),intersections.at(15));
    streets.at(44)->initializeStreet(false,false,false,true,intersections.at(25),intersections.at(40));
    streets.at(45)->initializeStreet(true,false,false,true,intersections.at(51),intersections.at(52));
    streets.at(46)->initializeStreet(false,false,false,true,intersections.at(25),intersections.at(26));
    streets.at(47)->initializeStreet(false,false,false,true,intersections.at(40),intersections.at(42));
    streets.at(48)->initializeStreet(true,true,true,true,intersections.at(5),intersections.at(15));
    streets.at(49)->initializeStreet(true,false,true,true,intersections.at(15),intersections.at(26));
    streets.at(50)->initializeStreet(true,false,true,true,intersections.at(26),intersections.at(27));
    streets.at(51)->initializeStreet(true,true,true,true,intersections.at(41),intersections.at(42));
    streets.at(52)->initializeStreet(true,false,true,true,intersections.at(42),intersections.at(52));
    streets.at(53)->initializeStreet(true,false,true,true,intersections.at(52),intersections.at(58));
    streets.at(54)->initializeStreet(true,false,false,true,intersections.at(5),intersections.at(6));
    streets.at(55)->initializeStreet(true,false,false,true,intersections.at(15),intersections.at(62));
    streets.at(56)->initializeStreet(true,false,false,true,intersections.at(27),intersections.at(28));
    streets.at(57)->initializeStreet(true,false,false,true,intersections.at(41),intersections.at(43));
    streets.at(58)->initializeStreet(true,false,false,true,intersections.at(52),intersections.at(61));
    streets.at(59)->initializeStreet(true,false,false,true,intersections.at(58),intersections.at(59));
    streets.at(60)->initializeStreet(true,true,true,true,intersections.at(6),intersections.at(7));
    streets.at(61)->initializeStreet(true,true,true,true,intersections.at(62),intersections.at(29));
    streets.at(62)->initializeStreet(true,false,true,true,intersections.at(29),intersections.at(28));
    streets.at(63)->initializeStreet(false,false,false,true,intersections.at(28),intersections.at(43));
    streets.at(64)->initializeStreet(true,true,true,true,intersections.at(43),intersections.at(44));
    streets.at(65)->initializeStreet(true,true,true,true,intersections.at(44),intersections.at(61));
    streets.at(66)->initializeStreet(true,true,true,true,intersections.at(60),intersections.at(59));
    streets.at(67)->initializeStreet(true,false,false,true,intersections.at(7),intersections.at(9));
    streets.at(68)->initializeStreet(true,false,false,true,intersections.at(62),intersections.at(16));
    streets.at(69)->initializeStreet(true,false,false,true,intersections.at(29),intersections.at(30));
    streets.at(70)->initializeStreet(true,false,false,true,intersections.at(44),intersections.at(45));
    streets.at(71)->initializeStreet(true,false,false,true,intersections.at(61),intersections.at(53));
    streets.at(72)->initializeStreet(true,false,false,true,intersections.at(60),intersections.at(63));
    streets.at(73)->initializeStreet(true,true,true,true,intersections.at(8),intersections.at(9));
    streets.at(74)->initializeStreet(true,false,true,true,intersections.at(9),intersections.at(16));
    streets.at(75)->initializeStreet(true,true,true,true,intersections.at(30),intersections.at(31));
    streets.at(76)->initializeStreet(true,true,true,true,intersections.at(46),intersections.at(45));
    streets.at(77)->initializeStreet(true,true,true,true,intersections.at(53),intersections.at(63));
    streets.at(78)->initializeStreet(true,false,true,true,intersections.at(63),intersections.at(64));
    streets.at(79)->initializeStreet(true,false,false,true,intersections.at(8),intersections.at(10));
    streets.at(80)->initializeStreet(true,false,false,true,intersections.at(31),intersections.at(32));
    streets.at(81)->initializeStreet(true,false,false,true,intersections.at(46),intersections.at(47));
    streets.at(82)->initializeStreet(true,false,false,true,intersections.at(64),intersections.at(65));
    streets.at(83)->initializeStreet(true,true,true,true,intersections.at(10),intersections.at(32));
    streets.at(84)->initializeStreet(true,false,true,true,intersections.at(32),intersections.at(47));
    streets.at(85)->initializeStreet(true,false,true,true,intersections.at(47),intersections.at(65));
    streets.at(86)->initializeStreet(false,false,false,true,intersections.at(24),intersections.at(25));
    streets.at(87)->initializeStreet(false,false,false,true,intersections.at(67),intersections.at(40));
}

