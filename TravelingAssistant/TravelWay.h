#ifndef TRAVELWAY_H
#define TRAVELWAY_H

#include <vector>

#include "PositionPoint.h"
#include "VehicleType.h"

class TravelWay {
public:
    TravelWay();
    ~TravelWay();

    void addPoint(PositionPoint& );
    void removePoint(const PositionPoint& );

    const int getDirectDistance();
    const int getFullDistance();
    const unsigned getTravelTime(const VehicleType& = ON_FOOT);
    const std::vector<PositionPoint> getWayPoints();

private:
    void countDirectDistance();
    void countFullDistance();

    std::vector<PositionPoint> m_points;
    int m_directDistance;
    int m_fullDistance;

};

#endif // TRAVELWAY_H
