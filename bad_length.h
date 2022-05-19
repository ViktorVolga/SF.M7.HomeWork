#pragma once
#include <exception>
using namespace std;

class bad_length : public exception //наследуем класс для исключений
{
public:
	virtual const char* what() const noexcept override; //переопределяем функцию
};

