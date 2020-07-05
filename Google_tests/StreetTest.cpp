//
// Created by dansid on 5/12/20.
//

#include "StreetTest.h"

TEST_F(StreetTest, CheckInitialization) {
	std::shared_ptr<Intersection> startIntersection = std::make_shared<Intersection>();
	std::shared_ptr<Intersection> endIntersection = std::make_shared<Intersection>();
	startIntersection->setLocation(5,100);
	endIntersection->setLocation(95,100);
	street->initializeStreet(false,false,false,true,startIntersection,endIntersection,false);
	EXPECT_EQ(false,street->hasFood());
	EXPECT_EQ(TravelDirection::horizontal,street->getTravelDirection());
	EXPECT_EQ(true,street->getAccessible());
	EXPECT_EQ(false,street->isconnecting());
	SDL_Point avegage = street->getAverage();
	EXPECT_EQ(avegage.x,50);
	EXPECT_EQ(avegage.y,100);
}