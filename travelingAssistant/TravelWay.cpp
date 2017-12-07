#include "TravelWay.h"

#include <algorithm>
#include <cmath>

TravelWay::TravelWay() {

}

void TravelWay::addPoint(const PositionPoint& newPoint) {
	m_points.push_back(newPoint);

	countDirectDistance();
	m_fullDistance += static_cast<int>(round(countTwoPointsDistance(m_points.back(), newPoint)));
}

void TravelWay::removePoint(const PositionPoint& point) {
	auto it = std::find_if(m_points.begin(),
	                       m_points.end(), 
	                       [point](const PositionPoint &p) -> bool {
	                           return p.x == point.x && p.y == point.y;
	                       });
	if (it != m_points.end()) {
		m_points.erase(it);
	}

	countDirectDistance();
	countFullDistance();
}

int TravelWay::getDirectDistance() {
	return m_directDistance;
}

int TravelWay::getFullDistance() {
	return m_fullDistance;
}

std::vector<PositionPoint> TravelWay::getWayPoints() {
    return m_points;
}

unsigned TravelWay::getTravelTime(const VehicleType& type) {

}

void TravelWay::countDirectDistance() {
	m_directDistance = static_cast<int>(round(countTwoPointsDistance(m_points.front(), m_points.back())));
}

void TravelWay::countFullDistance() {
	m_fullDistance = 0;
	if (m_points.size() < 2) {
		return;
	}
	for (int i = 0; i < m_points.size() - 1; ++i) {
		m_fullDistance += static_cast<int>(round(countTwoPointsDistance(m_points[i], m_points[i + 1])));
	}
}

float TravelWay::countTwoPointsDistance(const PositionPoint& p1, const PositionPoint& p2) {
	return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}
