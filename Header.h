#pragma once
#include <exception> //�������� ����� exception � �����������
using namespace std;

class bad_range : public exception //��������� ����� ��� ����������
{
public:
	virtual const char* what() const noexcept override //�������������� �������
	{ 
		return "exception catched - bad range";
		
	}
};



class IntArray // ������ ����� �������
{
	int m_length = 0; //����� �������
	int* m_data {}; // ��������� �� ������
public:
	IntArray() = default; // ����������� �� ���������
	IntArray(int length) : m_length{ length } //����������� � ����������
	{
		m_data = new int[length] {}; // ������� ����� ������
	}
	~IntArray() // ����������
	{
		delete[] m_data; //����������� ������ 
	}
	void erase() // ������ ������� ��� �������� �������
	{
		delete[] m_data; //����������� ������
		m_data = nullptr; // ����������� ��������� �� ����
		m_length = 0; // ������ ����� ������� �� ����
	}
	//����������� �������� [] ��� ������� � ��������� ������� 
	int& operator[](int index) 
	{
		if (index >= 0 && index < m_length) // ��������� �� ������� �� �� ������
		{
			return m_data[index]; //���������� ������ ���� ��� � �������
		}
		throw bad_range(); //���������� ���������� ���� ����� �� ����� �������
	}
	auto getLength() const -> int { return m_length; } //������ ��� ������� �������

	//����� ������� ��� ��������� �������� �������. ������� - ������� ������ � ������� �����
	void realocate(int newlength) 
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
	//����� ��������� ��������� �����
	//������� ������� �����
	void resize(int newLength)
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
		int* data{ new int[newLength] };

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

	void insertBefore(int value, int index) //�������� ������� � ��������� ����� � �������
	{
		//��������� �� ������� �� �� �� ������
		if (index <= 0 && index >= m_length)
		{
			return; // ������ �� ������ ���� ����� �� �������
		}

		// ������� ����� ������ �������� �� 1 ������ ��� ������
		int* data{ new int[m_length + 1] };

		// �������� �������� �� ����������
		for (int before{ 0 }; before < index; ++before)
			data[before] = m_data[before];

		// ��������� ����� ������� � ������
		data[index] = value;

		// �������� ��� �������� ����� ������
		for (int after{ index }; after < m_length; ++after)
			data[after + 1] = m_data[after];

		//������� ������ ������ � ����������� ������ ������ ���������
		delete[] m_data;
		m_data = data;
		++m_length; // ����������� �� 1 �����
	}
	void remove(int index)
	{
		//��������� �� ������� �� �� �� ������
		if (index <= 0 && index >= m_length)
		{
			return; // ������ �� ������ ���� ����� �� �������
		}

		// ���� �������� ������� ����� 1 ������ ������� ������
		if (m_length == 1 && index == 1)
		{
			erase();
			return;
		}

		// ������� ���� ������ ������ ������ �������
		int* data{ new int[m_length - 1] };

		// �������� �������� �� ����������
		for (int before{ 0 }; before < index; ++before)
		{
			data[before] = m_data[before];
		}

		// �������� ��� �������� ����� ��������� � �������� -1
		for (int after{ index + 1 }; after < m_length; ++after)
		{
			data[after - 1] = m_data[after];
		}

		//������� ������ ������ � ����������� ������ ������ ���������
		delete[] m_data;
		m_data = data;
		--m_length; // ��������� ����� ������� �� 1
	}
	void insertAtBeginning(int value) { insertBefore(value, 0); } //�������� �������
	void insertAtEnd(int value) { insertBefore(value, m_length); } // �������� � �����



};

