#include "AdditionalFunction.h"
#include <cmath>

 int Nod(int a, int b)
{
	a = abs(a);
	b = abs(b);
	while (a != b)
	{
		if (a > b)
		{
			a -= b;
		}
		else
		{
			b -= a;
		}
	}
	if (!a) a = 1;
	return a;
};
 void Reduction(int& a, int& b)
{
	int red = Nod(a, b);
	if (!red) return;
	a /= red;
	b /= red;
};