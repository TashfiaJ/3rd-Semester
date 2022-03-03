#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define EPSILON 0.000000001


double func(double x)
{
	return x*x*x + 4*x*x -10;
}

void regulaFalsi(double a, double b)
{
	if (func(a) * func(b) >= 0)
	{
		printf("You have not assumed right a and b\n");
		return;
	}

	double c = a;
    int count=0;
	while(1)
	{

		c = (a*func(b) - b*func(a))/ (func(b) - func(a));
        count++;

		if (fabs(func(c))<=EPSILON)
		{
			break;
		}

		else if (func(c)*func(a) < 0)
		{
			b = c;

		}
		else
		{
			a = c;

     	}

	}
	printf("The value of root is : %.9lf ",c);
	printf("\nIteration is %d",count);
}


int main()
{
	double a =1, b = 2;
	regulaFalsi(a, b);
	return 0;
}
