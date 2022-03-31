#include <stdio.h>
#include <math.h>

#define f1(x, y, z) (85 - 3*y + 2 * z) / 15
#define f2(x, y, z) (51 - 2 * x - z) / 10
#define f3(x, y, z) (5 - x + 2 * y) / 8
#define e 1.0e-9

/* Main function */
int main()
{
    double x0 = 0, y0 = 0, z0 = 0, x1, y1, z1, e1, e2, e3;
    int count = 1;


    do
    {
        x1 = f1(x0, y0, z0);
        y1 = f2(x0, y0, z0);
        z1 = f3(x0, y0, z0);


        e1 = fabs(x0 - x1);
        e2 = fabs(y0 - y1);
        e3 = fabs(z0 - z1);

        count++;

        x0 = x1;
        y0 = y1;
        z0 = z1;
    }while (e1 > e && e2 > e && e3 > e);

    printf("\nRoot(J): x=%16.9lf, y=%16.9lf and z = %16.9lf\n", x1, y1, z1);
    printf("%d", count);

    return 0;
}
