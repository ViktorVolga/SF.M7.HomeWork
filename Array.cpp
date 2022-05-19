#include "Array.h"


Array::Array(int length)
{
if (length >= 0)
	{
		m_length = length;
		m_data = new int[m_length]; // ������� ����� ������	
	}
else
	{
		throw bad_length();
	}
}

Array::~Array()
{
	delete[] m_data; //����������� ������ 
}

void Array::erase()
{
	delete[] m_data; //����������� ������
	m_data = nullptr; // ����������� ��������� �� ����
	m_length = 0; // ������ ����� ������� �� ����
}

int& Array::operator[](int index)
{
	if (index >= 0 && index < m_length) // ��������� �� ������� �� �� ������
	{
		return m_data[index]; //���������� ������ ���� ��� � �������
	}
	throw bad_range(); //���������� ���������� ���� ����� �� ����� �������
}

void Array::realocate(int newlength)
{
	erase(); //������� ������
	if (newlength <= 0)
	{
		//���� ����� ����� ���� ��� ������ - ��������� ��� ����������
		return;
	}
	m_data = new int[newlength]; //������� ����� ������
	m_length = newlength; // ����������� ����� �����
}

void Array::resize(int newLength)
{
	if (newLength == m_length)
	{
		// ���� ����� �� ���������� - ���������
		return;
	}
	// ��������� �� ����� ��� ������ �� ���� ����� �����
	if (newLength <= 0)
	{
		erase();
		return;
	}
	//������� ����� ������
	int* data = new int[newLength];

	if (m_length > 0)
	{
		//�������� ������� �������� ����� �����������
		//���� ����� ����� ������ - �������� ������ ���-��
		//���� ������ ������ - �������� ����� ���-�� 
		int elementsToCopy = ((newLength > m_length) ? m_length : newLength);
		//�������� �������� ������� � ����� ������			
		for (int index = 0; index < elementsToCopy; ++index)
			data[index] = m_data[index];
	}
	delete[] m_data; //������� ������ ������
	m_data = data; //����������� ������� ��������� ����� ������
	m_length = newLength; // ������ ������ �������		
}

void Array::insertBefore(int value, int index) //�������� ������� � ��������� ����� � �������
{
	//��������� �� ������� �� �� �� ������
	if (index <= 0 || index >= m_length)
	{
		throw bad_range(); // ������ �� ������ ���� ����� �� �������
	}

	// ������� ����� ������ �������� �� 1 ������ ��� ������
	int* data = new int[m_length + 1];

	// �������� �������� �� ����������
	for (int before = 0; before < index; ++before)
		data[before] = m_data[before];

	// ��������� ����� ������� � ������
	data[index] = value;

	// �������� ��� �������� ����� ������
	for (int after = index; after < m_length; ++after)
		data[after + 1] = m_data[after];

	//������� ������ ������ � ����������� ������ ������ ���������
	delete[] m_data;
	m_data = data;
	++m_length; // ����������� �� 1 �����
}