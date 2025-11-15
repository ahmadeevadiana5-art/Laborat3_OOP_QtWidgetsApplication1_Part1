#include "storage.h"

Storage::Storage(int capacity) : max_capacity(capacity)
{
	shapes.reserve(capacity);

}

//Добавление фигуры
void Storage::add(std::shared_ptr<AbstractShape>shape)
{
	if (shapes.size() < max_capacity)
	{
		shapes.push_back(shape); //добавляем в конец
	}
}

//удаление объекта по индексу 
void Storage::remove(int index)
{
	if (index >= 0 && index < shapes.size())
	{
		shapes.erase(shapes.begin() + index);

	}
}

//получение объектов по индексу
std::shared_ptr<AbstractShape>Storage::getObject(int index) const
{
	if (index >= 0 && index < shapes.size())
	{
		return shapes[index];
	}
	return nullptr;
}

//получение количества объектов
int Storage::getCount() const
{
	return static_cast<int>(shapes.size());
}

//удаление всех выделенных объектов
void Storage::removeSelected()
{
	std::vector<std::shared_ptr<AbstractShape>>notHighlightedShapes;

	for (int i = 0; i < shapes.size(); i++)

	{
		auto currentShape = shapes[i];
		bool isShapeSelected = currentShape->isSelected();

		if (!isShapeSelected)
		{
			notHighlightedShapes.push_back(currentShape);

		}

	}
	shapes = notHighlightedShapes;

}

void Storage::clear()
{
	shapes.clear();
}



