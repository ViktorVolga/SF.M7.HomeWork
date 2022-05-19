#include "Bad_range.h"
#include <iostream>

const char* bad_range::what() const noexcept  //переопределяем функцию
{
	return "exception catched - bad range";
	
}
