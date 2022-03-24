#include<stdio.h>
#include<math.h>

double f(double x)
{
    double a=2*sin(x);
    return fabs(a);
}
int main()
{
    int n=200,i;
    double a=0,b=3.14,c,h,sum=0,integral;
    double x[n+1],y[n+1];
    h=fabs(b-a)/n;
    for (i=0;i<n+1;i++)
    {
        x[i]=a+i*h;
        y[i]=f(x[i]);
    }
    for (i=1;i<n;i+=2)
    {
        sum=sum+4.0*y[i];
    }
    for (i=2;i<n-1;i+=2)
    {
        sum=sum+2.0*y[i];

    }
    integral=h/3.0*(y[0]+y[n]+sum);
    printf("\nThe definite integral  is %.9lf" ,integral);
    return 0;
}
