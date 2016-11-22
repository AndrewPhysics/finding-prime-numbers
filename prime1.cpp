#include "prime1.h"
#include <iostream>
using namespace std;
prime1::prime1(){}
prime1::~prime1(){}




int prime1::testNumber(int n) {
	bool isPrime = true;
	for (int i = 2; i <= n / 2; ++i)
	{
		if (n % i == 0)//if i is not a perfect divisor then the number is prime
		{
			isPrime = false;
			break;
		}
	}
	if (isPrime) {

		cout << "This is a prime number" << endl;
		return n;
	}
	else {
		cout << "This is not a prime number" << endl;
		return 0;
	}
}


bool prime1::P_property(int x) {
	return x != 0;
}



int prime1::conditionalCount(int aa[], int size)
{
	int number = 0;
	for (int i = 0; i < size; i++)
	{
		if (P_property(aa[i]))
		{
			number++;
		}
	}
	cout << "The number of elements with P_property: " << number << endl;
	return number;
}


void prime1::assortment(int aa[], int lenght1, int lenght2) {
	int* p = new int[lenght2];
	int j = 0;
	int i = 0;
	while (i < lenght1) {
		if (P_property(aa[i])) {
			p[j] = aa[i];
			j++;
		}
		i++;
	}
	if (j == 0) {
		cout << "There is no element with P_property! " << endl;
	}
	for (int i = 2; i < lenght2; i++) {
		cout << "The selected elements are: " << p[i] << endl;
	}
	delete[]p;
}



void prime1::callFunction() {
	const int length1 = 10000;
	int aa[length1];
	for (int i = 2; i < length1; i++)
	{
		aa[i] = testNumber(i);
		cout << aa[i] << endl;
	}
	int length2 = conditionalCount(aa, length1);
	assortment(aa, length1, length2);
}