#pragma once
#include <exception> //содержит класс exception и наследников
using namespace std;

class bad_range : public exception //наследуем класс для исключений
{
public:
	virtual const char* what() const noexcept override //переопределяем функцию
	{ 
		return "exception catched - bad range";
		
	}
};



class Array // задаем класс массива
{
	int m_length = 0; //длина массива
	int* m_data {}; // указатель на массив
public:
	IntArray() = default; // конструктор по умолчанию
	IArray(int length)//конструктор с параметром
	{	
		if (length >= 0)
		{
			m_length = length;
			m_data = new int[m_length]; // создает новый массив	
		}
		else
		{
			throw bad_range();
		}
	}
	~IntArray() // деструктор
	{
		delete[] m_data; //освобождаем память 
	}
	void erase() // вводим функцию для удаления массива
	{
		delete[] m_data; //освобождаем память
		m_data = nullptr; // присваиваем указатель на ноль
		m_length = 0; // меняем длину массива на ноль
	}
	//перегружаем оператор [] для доступа к елементам массива 
	int& operator[](int index) 
	{
		if (index >= 0 && index < m_length) // проверяем не выходим ли за массив
		{
			return m_data[index]; //возвращаем данные если все в порядке
		}
		throw bad_range(); //генерируем исключение если вышли за рамки массива
	}
	auto getLength() const -> int { return m_length; } //геттер для размера массива

	//далее функция для изменения величины массива. Быстрая - удаляет массив и создает новый
	void realocate(int newlength) 
	{
		erase(); //удаляем массив
		if (newlength <= 0)
		{
			//если новая длина ноль или меньше - прерываем тут выполнение
			return; 
		}
		m_data = new int[newlength]; //создаем новый массив
		m_length = newlength; // присваиваем новую длину
	}
	//Далее медленное изменение длины
	//сначала создает копию
	void resize(int newLength)
	{
		if (newLength == m_length)
		{
			// если длина не изменилась - прерываем
			return;
		}
		// проверяем не равна или меньше ли нуля новая длина
		if (newLength <= 0)
		{
			erase();
			return;
		}
		//создаем новый массив
		int* data{ new int[newLength] };

		if (m_length > 0)
		{
			//выясняем сколько элемнтов нужно скопировать
			//если новая длина больше - копируем старое кол-во
			//если старая больше - копируем новое кол-во 
			int elementsToCopy = ((newLength > m_length) ? m_length : newLength);
			//копируем элементы массива в новый массив			
			for (int index = 0; index < elementsToCopy; ++index)
				data[index] = m_data[index];
		}
		delete[] m_data; //удаляем старый массив
		m_data = data; //присваиваем сиарому указателю новый массив
		m_length = newLength; // меняем размер массива		
	}

	void insertBefore(int value, int index) //вставить элемент в указанное место в массиве
	{
		//проверяем не выходим ли мы за массив
		if (index <= 0 || index >= m_length)
		{
			return; // ничего не делаем если вышли за пределы
		}

		// создаем новый массив размером на 1 больше чем старый
		int* data{ new int[m_length + 1] };

		// Копируем элементы до указанного
		for (int before{ 0 }; before < index; ++before)
			data[before] = m_data[before];

		// Вставляем новый элемент в массив
		data[index] = value;

		// Копируем все элементы после нового
		for (int after{ index }; after < m_length; ++after)
			data[after + 1] = m_data[after];

		//Удаляем старый массив и присваиваем новому старый указатель
		delete[] m_data;
		m_data = data;
		++m_length; // увеличиваем на 1 длину
	}
	void remove(int index)
	{
		//проверяем не выходим ли мы за массив
		if (index <= 0 || index >= m_length)
		{
			return; // ничего не делаем если вышли за пределы
		}

		// Если величина массива равна 1 просто стираем массив
		if (m_length == 1 && index == 1)
		{
			erase();
			return;
		}

		// создаем овый массив длиной меньше старого
		int* data{ new int[m_length - 1] };

		// Копируем элементы до указанного
		for (int before{ 0 }; before < index; ++before)
		{
			data[before] = m_data[before];
		}

		// Копируем все элементы после указаннго с индексом -1
		for (int after{ index + 1 }; after < m_length; ++after)
		{
			data[after - 1] = m_data[after];
		}

		//Удаляем старый массив и присваиваем новому старый указатель
		delete[] m_data;
		m_data = data;
		--m_length; // уменьшаем длину массива на 1
	}
	void insertAtBeginning(int value) { insertBefore(value, 0); } //вставить вначале
	void insertAtEnd(int value) { insertBefore(value, m_length); } // вставить в конце



};

