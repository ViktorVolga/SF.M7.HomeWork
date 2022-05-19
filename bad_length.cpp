#include "bad_length.h"

const char* bad_length::what() const noexcept  //переопределяем функцию
{
	return "exception catched - bad length";
}