#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define n 300
double x[n+1], f[n+1], dc[n+1], dm[n+1],h;

double F(double x)
{
	return (x*x*x+4*x*x-10);
}

double diff(double x)
{
	return (3*x*x+8*x);
}

double forward(double x1, double x2)
{
	return ((F(x2)-F(x1))/(x2-x1));
}

double central(double x2, double x0)
{
	return ((F(x2)-F(x0))/(x2-x0));
}

double backward(double x1, double x0)
{
	return ((F(x1)-F(x0))/(x1-x0));
}


int main()
{

	x[0]=0;
	double l=0, r=10;
	double h=(r-l)/(double)n;
	f[0]=F(x[0]);
	dc[0]=diff(x[0]);
	int i;
	for(i=1; i<n; i++)
	{
		x[i]=x[i-1]+h;
		f[i]=F(x[i]);
		dc[i]=diff(x[i]);
	}
	x[n]=10;
    f[n]=F(x[n]);
	dc[n]=diff(x[n]);
	dm[0]=forward(x[0], x[1]);
	dm[n]=backward(x[n], x[n-1]);
	for( i=1; i<n; i++)
	{
		dm[i]=central(x[i+1], x[i-1]);
	}
	double max=fabs(dm[0]-dc[0]);
	for(i=1; i<=n; i++)
	{
		if(max<fabs(dm[i]-dc[i]))
			max=fabs(dm[i]-dc[i]);
	}
	printf("Maximum: %.9lf\n", max);
}
