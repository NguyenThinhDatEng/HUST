#include <stdio.h>

int main(){
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    double sum, average;
    sum = a + b + c;
    average = sum / 3;
    printf('%f\n%f', sum, average);
    return 0;
}