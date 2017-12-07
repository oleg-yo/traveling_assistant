/*!
    \file
    \brief Класс маршрута
    \author olegyakovchuk
    \version 1.0

    Описывает работу и методы маршрута
*/

#ifndef TRAVELWAY_H
#define TRAVELWAY_H

#include <vector>

#include "PositionPoint.h"
#include "VehicleType.h"

class TravelWay {
public:
    TravelWay();
    ~TravelWay() = default;

    /*!
        Добавляет новую точку
        \param[in] PositionPoint Координаты новой точки
    */
    void addPoint(const PositionPoint& );

    /*!
        Удаляет точку с заданными координатами
        \param[in] PositionPoint Координаты точки
    */
    void removePoint(const PositionPoint& );

    /*!
        Возвращает прямое расстояние маршрута
        \return Посчитанное ранее прямое расстояние маршрута
    */
    int getDirectDistance();

    /*!
        Возвращает полное расстояние маршрута
        \return Посчитанное ранее полное расстояние маршрута
    */
    int getFullDistance();

    /*!
        Считает и возвращает время маршрута
        \param[in] VehicleType Способ перемещения по маршруту
        \return Время маршрута
    */
    unsigned getTravelTime(const VehicleType& = ON_FOOT);

    /*!
        Возвращает вектор всех точек маршрута
        \return vector<PositionPoint> Массив точек маршрута
    */
    std::vector<PositionPoint> getWayPoints();

private:
    void countDirectDistance();
    void countFullDistance();
    float countTwoPointsDistance(const PositionPoint& , const PositionPoint& );

    std::vector<PositionPoint> m_points;
    int m_directDistance;
    int m_fullDistance;
};

#endif // TRAVELWAY_H
