#pragma once
#include <iostream>
#include "Bad_range.h"
#include "bad_length.h"

using namespace std;

class Array // ������ ����� �������
{
	int m_length = 0; //����� �������
	int* m_data{}; // ��������� �� ������
public:
	Array() = default; // ����������� �� ���������
	Array(int length);//����������� � ����������
	~Array(); // ����������
	void erase(); // ������ ������� ��� �������� �������
	int& operator[](int index);
	auto getLength() const -> int { return m_length; } //������ ��� ������� �������
	void realocate(int newlength);
	void resize(int newLength); //������� ��������� (�������� � ���� �����)
	//����� ��������� ��������� �����
	//������� ������� �����
	void insertBefore(int value, int index); //�������� ������� � ��������� ����� � �������	
};