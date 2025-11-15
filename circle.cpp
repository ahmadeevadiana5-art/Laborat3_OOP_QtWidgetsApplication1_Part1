#include "Circle.h"
#include<QPainter>



Circle::Circle(const QPoint& center, int radius)
	:m_center(center), m_radius(radius), m_selected(false)
{

}

bool Circle::contains(const QPoint& point)
const
{
	int dx = point.x() - m_center.x(); //вычисляем разницу по координате х
	int dy = point.y() - m_center.y();
	return (dx * dx + dy * dy) <= (m_radius * m_radius); //если расстоясние<=радиусу, то точка находится внутри круга


}

void Circle::draw(QPainter& painter)
const
{
	if (m_selected) //если круг выделен
	{
		painter.setPen(QPen(Qt::red, 2));

	}
	else
	{
		painter.setPen(QPen(Qt::blue, 1));

	}
	painter.setBrush(QBrush(QColor(211, 211, 211, 150)));
	//painter.setBrush(QBrush(Qt::lightGray));
	painter.drawEllipse(m_center, m_radius, m_radius);

}

void Circle::setSelected(bool selected)

{
	m_selected = selected; //сохраняем значение

}

bool Circle::isSelected()
const
{
	return m_selected; //возвращаем значение (можем узнать выделен ли круг?)
}


//получаем информацию о круге
QPoint Circle::getCenter() const
{
	return m_center;
}

int Circle::getRadius() const
{
	return m_radius;
}


