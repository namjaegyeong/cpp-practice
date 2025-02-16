#include <iostream>
#include "HeapStackExample.h"

using namespace std;

Orange::Orange(int price)
{
	this->price = price;
	cout << "[»ý¼ºÀÚ] ¿À·»Áö °¡°Ý : " << price << endl;
};

Orange::~Orange()
{
	cout << "[¼Ò¸êÀÚ]" << endl;
};

void Orange::ShowPrice()
{
	cout << "[°¡°Ý] ¿À·»Áö : " << price << endl;
};