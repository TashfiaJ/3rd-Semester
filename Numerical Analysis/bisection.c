#include<stdio.h>
#define EPSILON 1e-9


double func(double x)
{
	return x*x*x + 4*x*x -10;
}


void bisection(double a, double b)
{
	if (func(a) * func(b) >= 0)
	{
		printf("You have not assumed right a and b\n");
		return;
	}

	double c = a;

	int itr=0;

	while ((b-a) >= EPSILON)
	{
	    itr++;
		c = (a+b)/2;

		if (fabs(func(c))<=EPSILON)
		{
			break;
		}

		else if (func(c)*func(a) < 0)
		{
			b=c;
		}
		else
		{
			a=c;
     	}
	}
	printf("The value of root is %.9lf \n",c);

	printf("iteration %d ",itr);

}



int main()
{
	double a =1, b =2;
	bisection(a, b);
	return 0;
}
