#include <gtest/gtest.h>

#include "TravelWay.h"

TEST(TravelWayConstructorTest, EmptyWay) {
    TravelWay way;

    EXPECT_TRUE(way.getWayPoints().empty());
}

TEST(AddPointTest, OnePoint) {
    TravelWay way;

    PositionPoint p1(-10, 12);
    way.addPoint(p1);

    EXPECT_EQ(1, way.getWayPoints().size());

    EXPECT_EQ(-10, way.getWayPoints().at(0).x);
    EXPECT_EQ(12, way.getWayPoints().at(0).y);
}

TEST(RemovePointTest, OnePoint) {
    TravelWay way;

    way.addPoint(PositionPoint(1, 1));
    way.removePoint(PositionPoint(1, 1));

    EXPECT_TRUE(way.getWayPoints().empty());
}

TEST(DirectDistanceTest, PositiveCoords) {
    TravelWay way;
    way.addPoint(PositionPoint(0, 0));
    way.addPoint(PositionPoint(2, 2));

    EXPECT_EQ(3, way.getDirectDistance());
}

TEST(DirectDistanceTest, NegativeCoords) {
    TravelWay way;
    way.addPoint(PositionPoint(-5, -2));
    way.addPoint(PositionPoint(-1, 4));

    EXPECT_EQ(7, way.getDirectDistance());
}
