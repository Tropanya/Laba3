#include "Laba3Sourse.h"

#include <time.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>

unsigned long long DiffHelm::_powm(unsigned long long a, unsigned long long b, unsigned long long n)
{
	unsigned long long c = 1;
	while (b != 0)
	{
		if (b % 2 == 0)
		{
			b /= 2;
			a = (a * a) % n;
		}
		else
		{
			b--;
			c = (c * a) % n;
		}
	}
	return c;
}

bool DiffHelm::_simpleNum(unsigned long long num)
{
	for (unsigned long long i = 2; i <= sqrt(num); i++)
		if (num % i == 0)
			return false;
	return true;
}

DiffHelm::DiffHelm(unsigned long long num, const std::string& userName)
{
	this->_num = num;
	this->_key = 0;
	this->_userName = userName;
}

DiffHelm::~DiffHelm()
{ }

GandP DiffHelm::GenGandP()
{
	srand(time(NULL));

	unsigned long long g, p;

	do
	{
		p = 1000 + rand();
	} while (!_simpleNum(p));

	unsigned long long tmp = 0;

	do
	{
		g = 2 + rand() % 20;

		tmp = _powm(g, p - 1, p);
	} while (tmp != 1);

	return { g, p };
}

unsigned long long DiffHelm::GenOpenKey(const GandP& gAndp)
{
	return _powm(gAndp.g, _num, gAndp.p);
}

void DiffHelm::GenProtKey(unsigned long long openKey, const GandP& gAndp)
{
	this->_key = _powm(openKey, _num, gAndp.p);
}

void DiffHelm::Print(const GandP& gAndp)
{
	std::cout << "User " << _userName << ": " << "\n" << "G: " << gAndp.g << "\n" << "P: " << gAndp.p << "\n"
			  << "Num: " << _num << "\n" << "Protected key: " << _key << std::endl;
}