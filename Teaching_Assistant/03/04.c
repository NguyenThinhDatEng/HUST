#include <stdio.h>

int main()
{
    double p, w, t;
    scanf("%lf%lf%lf", &p, &w, &t);
    double origin_price, tax_price;
    origin_price = p * w;
    tax_price = p * w * t / 100;
    printf('%lf', origin_price + tax_price);
    return 0;
}
