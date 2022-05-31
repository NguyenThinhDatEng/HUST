#include <stdio.h>
#include <math.h>

int main()
{
    // initialize
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    // Case: a != 0
    if (a) // a == 0 return false, a != 0 retrun true
    {
        double denta;
        denta = b * b - 4 * a * c;
        if (denta < 0)
        {
            double real_number = -b / (2 * a);
            double bigger_imimaginary = sqrt(-denta) / (2 * a);
            printf("%lf+%lfi\n%lf-%lfi", real_number, bigger_imimaginary, real_number, bigger_imimaginary);
        }
        else if (denta > 0)
            printf("%lf\n%lf", (-b + sqrt(denta)) / (2 * a), (-b - sqrt(denta)) / (2 * a));
        else
            printf("%lf", -b / (2 * a));
    }
    // Case: a == 0
    else if (b)
        printf("%lf", -c / b);
    else if (c)
        printf("Phuong trinh vo nghiem");
    else
        printf("Phuong trinh vo so nghiem");
    return 0;
}