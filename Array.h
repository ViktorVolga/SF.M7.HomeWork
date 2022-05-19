#pragma once
#include <iostream>
#include "Bad_range.h"
#include "bad_length.h"

using namespace std;

class Array // задаем класс массива
{
	int m_length = 0; //длина массива
	int* m_data{}; // указатель на массив
public:
	Array() = default; // конструктор по умолчанию
	Array(int length);//конструктор с параметром
	~Array(); // деструктор
	void erase(); // вводим функцию для удаления массива
	int& operator[](int index);
	auto getLength() const -> int { return m_length; } //геттер для размера массива
	void realocate(int newlength);
	void resize(int newLength); //быстрое изменение (удаление и созд новое)
	//Далее медленное изменение длины
	//сначала создает копию
	void insertBefore(int value, int index); //вставить элемент в указанное место в массиве	
};