#pragma once
#include <exception>
#include <iostream>
using namespace std;

class bad_range : public exception //��������� ����� ��� ����������
{
public:
	virtual const char* what() const noexcept override; //�������������� �������
};