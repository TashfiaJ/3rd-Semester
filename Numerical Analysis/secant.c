#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define EPSILON 1.0e-9

double f(double x)
{

	double f = pow(x, 3) + 4*pow(x, 2) - 10;
	return f;
}

void secant(double x1, double x2)
{
	double n = 0, xm, x0, c;
	int itr=0;
	if (f(x1) * f(x2) < 0) {
		do {
			// calculate the intermediate value
			x0 = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));

			// check if x0 is root of equation or not
			c = f(x1) * f(x0);

			// update the value of interval
			x1 = x2;
			x2 = x0;

			// update number of iteration
			itr++;

			// if x0 is the root of equation then break the loop
			if (c == 0)
				break;
			xm = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
		} while (fabs(xm - x0) >= EPSILON); // repeat the loop
								// until the convergence

		printf("Root of the given equation= %.9lf\n",  x0);
		printf( "No. of iterations = %d\n" , itr);
	} else
		printf("Can not find a root in the given interval");
}

// Driver code
int main()
{
	// initializing the values
	double x1 = 1, x2 = 2;
	secant(x1, x2);
	return 0;
}

