
#ifndef ABSTRACT_SHAPE_H
#define ABSTRACT_SHAPE_H

#include<QPoint>
#include<QPainter>

class AbstractShape
{
public:

	virtual ~AbstractShape() = default;

	virtual bool contains(const QPoint& point) const = 0;
	virtual void draw(QPainter& painter) const = 0;
	//virtual void draw(QPainter& painter) const = 0;
	virtual void setSelected(bool selected) = 0;
	virtual bool isSelected() const = 0;
};

#endif //ABSTRACT_SHAPE_H
