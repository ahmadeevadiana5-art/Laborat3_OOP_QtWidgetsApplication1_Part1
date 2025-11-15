#ifndef CIRCLE_H
#define CIRCLE_H


#include "abstract_shape.h"
#include<QPoint> //хранение координат точек
#include<QPainter> 
#include<QPen>
#include<QBrush> //заливка фигуры
#include<memory>

//Объявление класса круг
class Circle :
	public AbstractShape
{
	//объявляем переменные только внутри класса
private:
	QPoint m_center; //центр круга с координатами
	int m_radius; //радиус круга
	bool m_selected; //выделен ли круг? 


public:
	Circle(const QPoint& center, int radius = 20);

	bool contains(const QPoint& point) const override;

	void draw(QPainter& painter) const override;

	void setSelected(bool selected) override;
	bool isSelected() const override;

	//получаем информацию о круге
	QPoint getCenter() const;

	int getRadius() const;

};


#endif //CIRCLE_H