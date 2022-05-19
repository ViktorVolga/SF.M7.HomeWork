#include <iostream>
#include "Array.h"
#include "Bad_range.h"
#include "bad_length.h"

int main() // здесь просто тестировал - никакой смысловой нагрузки
{
	Array a(3);
	a.insertBefore(3, 2);
	cout << a[2] << endl;
	try
	{
		Array b(-3);
	}
	catch (bad_length& e)
	{
		cout << e.what() << endl;
	}
	try
	{
		a.insertBefore(5, -1);
	}
	catch (bad_range& e)
	{
		cout << e.what() << endl;
	}


	return 0;
}

	

