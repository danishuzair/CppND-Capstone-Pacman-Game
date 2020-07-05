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

TEST_F(StreetTest, CheckIfAtIntersection) {
    std::shared_ptr<Intersection> startIntersection = std::make_shared<Intersection>();
    std::shared_ptr<Intersection> endIntersection = std::make_shared<Intersection>();
    startIntersection->setLocation(5,100);
    endIntersection->setLocation(95,100);
    street->initializeStreet(false,false,false,true,startIntersection,endIntersection,false);
    EXPECT_EQ(startIntersection.get(),street->checkifatintersection(5.2323,99.64545).get());
    EXPECT_EQ(startIntersection.get(),street->checkifatintersection(4.5323,100.3232).get());
    EXPECT_EQ(endIntersection.get(),street->checkifatintersection(94.6343,100).get());
    EXPECT_EQ(nullptr,street->checkifatintersection(322,53).get());
    EXPECT_EQ(nullptr,street->checkifatintersection(5,101).get());
}

TEST_F(StreetTest, CheckIfEatingFoodProperly) {
    std::shared_ptr<Intersection> startIntersection = std::make_shared<Intersection>();
    std::shared_ptr<Intersection> endIntersection = std::make_shared<Intersection>();
    startIntersection->setLocation(5,100);
    endIntersection->setLocation(95,100);
    street->initializeStreet(true,true,true,true,startIntersection,endIntersection,false);
    for (int i=5; i<=76; i+=23.5) {
        EXPECT_EQ(true,street->eatFood(i,100));
    }
    EXPECT_EQ(true,street->eatFood(93,100));
    EXPECT_EQ(false,street->eatFood(95,100));
    EXPECT_EQ(false,street->eatFood(7,100));
}

TEST_F(StreetTest, CheckIfOtherStreetFoundCorrectly) {
    std::shared_ptr<Intersection> startIntersection = std::make_shared<Intersection>();
    std::shared_ptr<Intersection> leftEdgeIntersection = std::make_shared<Intersection>();
    std::shared_ptr<Intersection> rightEdgeIntersection = std::make_shared<Intersection>();
    std::shared_ptr<Intersection> endIntersection = std::make_shared<Intersection>();
    startIntersection->setLocation(50,100);
    leftEdgeIntersection->setLocation(5,100);
    rightEdgeIntersection->setLocation(195,100);
    endIntersection->setLocation(150,100);
    street->initializeStreet(true,true,true,true,startIntersection,leftEdgeIntersection,false);
    std::shared_ptr<Street> connectingStreet = std::make_shared<Street>();
    std::shared_ptr<Street> finalStreet = std::make_shared<Street>();
    connectingStreet->initializeStreet(false,false,false,true,leftEdgeIntersection,rightEdgeIntersection,true);
    finalStreet->initializeStreet(true,true,true,true,rightEdgeIntersection,endIntersection);
    float x, y;
    EXPECT_EQ(finalStreet.get(),connectingStreet->getOtherStreet(5,100,x,y,Direction::left).get());
    EXPECT_EQ(street.get(),connectingStreet->getOtherStreet(195,100,x,y,Direction::right).get());

    std::shared_ptr<Intersection> startVerticalIntersection = std::make_shared<Intersection>();
    std::shared_ptr<Intersection> upEdgeIntersection = std::make_shared<Intersection>();
    std::shared_ptr<Intersection> downEdgeIntersection = std::make_shared<Intersection>();
    std::shared_ptr<Intersection> endVerticalIntersection = std::make_shared<Intersection>();
    startVerticalIntersection->setLocation(100,50);
    upEdgeIntersection->setLocation(100,5);
    downEdgeIntersection->setLocation(100,195);
    endVerticalIntersection->setLocation(100,150);
    std::shared_ptr<Street> downTargetStreet = std::make_shared<Street>();
    std::shared_ptr<Street> connectingStreetVertical = std::make_shared<Street>();
    std::shared_ptr<Street> upTargetStreet = std::make_shared<Street>();
    downTargetStreet->initializeStreet(true,true,true,true,startVerticalIntersection,upEdgeIntersection);
    connectingStreetVertical->initializeStreet(false,false,false,true,upEdgeIntersection,downEdgeIntersection,true);
    upTargetStreet->initializeStreet(true,true,true,true,downEdgeIntersection,endVerticalIntersection);
    EXPECT_EQ(upTargetStreet.get(),connectingStreetVertical->getOtherStreet(100,5,x,y,Direction::up).get());
    EXPECT_EQ(downTargetStreet.get(),connectingStreetVertical->getOtherStreet(100,195,x,y,Direction::down).get());
}

TEST_F(StreetTest, CheckCloseToIntersection) {
    std::shared_ptr<Intersection> startIntersection = std::make_shared<Intersection>();
    std::shared_ptr<Intersection> endIntersection = std::make_shared<Intersection>();
    startIntersection->setLocation(50,100);
    endIntersection->setLocation(50,300);
    street->initializeStreet(true,true,true,true,startIntersection,endIntersection,false);
    EXPECT_EQ(false,street->closetointersection(55,100,Direction::left,Direction::left));
}