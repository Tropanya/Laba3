#ifndef LABA3SOURSE_H
#define LABA3SOURSE_H

#include <string>

struct GandP
{
	unsigned long long g, p;
};

class DiffHelm
{
private:
	unsigned long long _num;
	unsigned long long _key;
	std::string _userName;
private:
	unsigned long long _powm(unsigned long long a, unsigned long long b, unsigned long long n);
	bool _simpleNum(unsigned long long num);
public:
	DiffHelm(unsigned long long num, const std::string& userName);
	~DiffHelm();

	GandP GenGandP();
	unsigned long long GenOpenKey(const GandP& gAndp);
	void GenProtKey(unsigned long long openKey, const GandP& gAndp);

	void Print(const GandP& gAndp);
};

#endif // LABA3SOURSE_H