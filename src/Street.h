//
// Created by dansid on 4/1/20.
//

#ifndef SDL2TEST_STREET_H
#define SDL2TEST_STREET_H

#include <vector>
#include "SDL.h"
#include <memory>
#include "TrafficObject.h"
#include "Ghost.h"
#include "Pacman.h"

class Intersection;
enum class Direction;

enum class TravelDirection{vertical, horizontal};
enum class IntersectionLocation{start, end, neither};

class Street : public TrafficObject, public std::enable_shared_from_this<Street> {
public:
    Street() {
        type = ObjectType::street;
    }
    void initializeStreet(bool hasfood_in, bool hasfoodatstart, bool hasfoodatend, bool accessible_in,
                          std::shared_ptr<Intersection> startintersection_in,
                          std::shared_ptr<Intersection> endIntersection_in,
                          bool connectingends_in = false);
    std::shared_ptr<Street> get_shared_this() { return shared_from_this(); }
    bool hasFood() const {return hasfood;}
    std::vector<SDL_Point>& getFood() {return foods;}
    TravelDirection getTravelDirection() const {return traveldirection;}
    SDL_Point getAverage() const {return average;}
    std::shared_ptr<Intersection> checkifatintersection(float xlocation, float ylocation);
    bool getAccessible() const { return accessible;}
    bool eatFood(float x, float y);
    bool closetointersection(float x, float y, Direction currentdirection, Direction desireddirection);
    bool isconnecting() const {return connectingends;}
    std::shared_ptr<Street> getOtherStreet(float xlocation,float ylocation,float &newxlocation,
            float &newylocation, Direction direction_in);
    int getRemainingFoodOnStreet() const {return foods.size();}
    std::shared_ptr<Intersection> getOtherIntersection(std::shared_ptr<Intersection> currentIntersection) const;
    std::shared_ptr<Intersection> getStartIntersection() const {return startintersection;}
    std::shared_ptr<Intersection> getEndIntersection() const {return endintersection;}
    bool checkifonstreet(int x, int y) const;
    int getStreetLength() const {return length;}
    bool isGhostFound(Direction currentdirection,int x,int y,int xGhost, int yGhost) const;

private:
    bool findGhost(int x, int y, int xIntersection, int yIntersection, Direction currentdirection,int xGhost, int yGhost) const;
    void FindIntersectionCoordinatesAtEndOfCurrentDirection(Direction currentdirection, int &x, int &y) const;
    IntersectionLocation checkifclosetointersection(float x, float y, Direction direction);
    void setLength();
    void setTravelDirection();
    void setFood(bool hasfoodatstart,bool hasfoodatend);
    void setAverage();
    SDL_Point average;
    TravelDirection traveldirection;
    bool hasfood;
    bool accessible; // Is Pacman allowed to travel on this street
    bool connectingends;
    int length;
    std::vector<SDL_Point> foods;
    std::shared_ptr<Intersection> startintersection;
    std::shared_ptr<Intersection> endintersection;
};

#endif //SDL2TEST_STREET_H
