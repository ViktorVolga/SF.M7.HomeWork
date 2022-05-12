#include <iostream>
#include "Header.h"


using namespace std;

int main()
{
	try // пробуем
	{
		IntArray a(-7); // пробуем задать отрицательную величину массива
	}
	catch (const bad_array_new_length& e) //ловим обект классса сгенерированный как исключение
	{
		cout << "exception catched: ";
		cout << e.what() << endl;
	}
	
		IntArray b(2);
		
		cout << b.getLength() << endl;
		b.resize(3);
		cout << b.getLength() << endl;
		for (int i = 0; i < b.getLength(); ++i)
		{
			b[i] = i;
		}
		for (int i = 0; i < b.getLength(); ++i)
		{
			cout << b[i] << endl;
		}
		b.resize(5);
		cout << "new length " << b.getLength() << endl;
		try
		{
			for (int i = 0; i < 7; ++i)
			{
				
				b[i] = i;
			}
		}
		
		catch (const bad_range& e)
		{
			cout << e.what();
		}
		//далее просто тестирую работоспособность функций
		cout << endl << "new lengths: ";
		b.insertAtBeginning(1);
		cout << b.getLength() << " ";
		b.insertAtEnd(2);
		cout << b.getLength() << " ";
		b.remove(3);
		cout << b.getLength() << " ";
		b.insertBefore(3, 3);
		cout << b.getLength() << " ";
		


		return 0;
		

	
	
	return 0;
}