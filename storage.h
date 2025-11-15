#ifndef STORAGE_H
#define STORAGE_H

#include "abstract_shape.h"
#include <vector>
#include<memory>
#include<algorithm>


class Storage
{
private:
	std::vector<std::shared_ptr<AbstractShape>> shapes; //указатель на объект типа AbstractShape

	int max_capacity; //максимальное количество фигу, которые можно хранить

public:

	//конструктор с начальной емкостью
	Storage(int capacity = 100);

	//Добавление фигуры
	void add(std::shared_ptr<AbstractShape>shape);

	//удаление объекта по индексу 
	void remove(int index);

	//получение объектов по индексу
	std::shared_ptr<AbstractShape>getObject(int index) const;


	//получение количества объектов
	int getCount() const;

	//удаление всех выделенных объектов
	void removeSelected();


	void clear();


};

#endif //STORAGE_H

