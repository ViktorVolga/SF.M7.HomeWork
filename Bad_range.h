#pragma once
#include <exception>
#include <iostream>
using namespace std;

class bad_range : public exception //наследуем класс для исключений
{
public:
	virtual const char* what() const noexcept override; //переопределяем функцию
};