#include <iostream>
#include "HeapStackExample.h"

using namespace std;

Orange::Orange(int price)
{
	this->price = price;
	cout << "[������] ������ ���� : " << price << endl;
};

Orange::~Orange()
{
	cout << "[�Ҹ���]" << endl;
};

void Orange::ShowPrice()
{
	cout << "[����] ������ : " << price << endl;
};