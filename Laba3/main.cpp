#include "Laba3Sourse.h"

int main()
{
	DiffHelm a(15646513, "A");
	DiffHelm b(54717361, "B");

	GandP gAndp;

	gAndp = a.GenGandP();
	unsigned long long A = a.GenOpenKey(gAndp);
	unsigned long long B = b.GenOpenKey(gAndp);

	a.GenProtKey(B, gAndp);
	b.GenProtKey(A, gAndp);

	a.Print(gAndp);
	b.Print(gAndp);

	return 0;
}