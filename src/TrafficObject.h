//
// Created by dansid on 4/1/20.
//

#ifndef SDL2TEST_TRAFFICOBJECT_H
#define SDL2TEST_TRAFFICOBJECT_H

enum class ObjectType{street, intersection};

class TrafficObject {
public:
    ObjectType getType() const {return type;}
protected:
    ObjectType type;
    static constexpr float foodinterval = 23.5;
};

#endif //SDL2TEST_TRAFFICOBJECT_H
