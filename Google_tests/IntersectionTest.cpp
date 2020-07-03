//
// Created by dansid on 4/27/20.
//

#include "IntersectionTest.h"

//TEST_F(IntersectionTest, CanConstruct) {
//    Intersection intersection;
//}

TEST_F(IntersectionTest, CheckInitialization) {
    EXPECT_EQ(nullptr,intersection->getDownStreet());
    EXPECT_EQ(nullptr,intersection->getLeftStreet());
    EXPECT_EQ(nullptr,intersection->getRightStreet());
    EXPECT_EQ(nullptr,intersection->getUpStreet());
}

TEST_F(IntersectionTest, CheckCorrectType) {
    EXPECT_EQ(intersection->getType(),ObjectType::intersection);
}

TEST_F(IntersectionTest, CheckXAndYSetCorrectly) {
    intersection->setLocation(200,250);
    EXPECT_EQ(200,intersection->getLocationX());
    EXPECT_EQ(250,intersection->getLocationY());
}

TEST_F(IntersectionTest, CheckNeigboringStreetsSetCorrectly) {
    intersection->setLocation(200,250);
    std::shared_ptr<Intersection> leftEndIntersection = std::make_shared<Intersection>();
    leftEndIntersection->setLocation(150,250);
    std::shared_ptr<Street> leftstreet = std::make_shared<Street>();
    leftstreet->initializeStreet(true,true,true,true,intersection,leftEndIntersection
    ,false);
    intersection->connectStreet(leftstreet);
    EXPECT_EQ(leftstreet.get(),intersection->getLeftStreet().get());

    std::shared_ptr<Intersection> rightEndIntersection = std::make_shared<Intersection>();
    rightEndIntersection->setLocation(350,250);
    std::shared_ptr<Street> rightstreet = std::make_shared<Street>();
    rightstreet->initializeStreet(true,true,true,true,intersection,rightEndIntersection
            ,false);
    intersection->connectStreet(rightstreet);
    EXPECT_EQ(rightstreet.get(),intersection->getRightStreet().get());

    std::shared_ptr<Intersection> upEndIntersection = std::make_shared<Intersection>();
    upEndIntersection->setLocation(200,150);
    std::shared_ptr<Street> upstreet = std::make_shared<Street>();
    upstreet->initializeStreet(true,true,true,true,intersection,upEndIntersection
            ,false);
    intersection->connectStreet(upstreet);
    EXPECT_EQ(upstreet.get(),intersection->getUpStreet().get());

    std::shared_ptr<Intersection> downEndIntersection = std::make_shared<Intersection>();
    downEndIntersection->setLocation(200,350);
    std::shared_ptr<Street> downstreet = std::make_shared<Street>();
    downstreet->initializeStreet(true,true,true,true,intersection,downEndIntersection
            ,false);
    intersection->connectStreet(downstreet);
    EXPECT_EQ(downstreet.get(),intersection->getDownStreet().get());
}

TEST_F(IntersectionTest, CheckFoodEatenProperly) {
    intersection->setLocation(200,250);
    std::shared_ptr<Intersection> leftEndIntersection = std::make_shared<Intersection>();
    leftEndIntersection->setLocation(150,250);
    std::shared_ptr<Street> leftstreet = std::make_shared<Street>();
    leftstreet->initializeStreet(true,true,true,true,intersection,leftEndIntersection
            ,false);
    intersection->connectStreet(leftstreet);
    EXPECT_EQ(intersection->eatFood(),1);
}