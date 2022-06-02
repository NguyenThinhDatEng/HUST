#include <stdio.h>
#include <string.h> // strlen(s)
#include <math.h>   // pow(x, exp)

int main()
{
    // khai bao va khoi tao xau
    char s[16];
    scanf("%s", s);         // strlen(s) = lengthOf_s
    int length = strlen(s); // lay do dai xau s

    // chuyen doi tu so nhi phan sang so thap phan
    int exponent = 0, decimal_number = 0;
    for (int i = length - 1; i > 0; i--)
    {
        if (s[i] == '1')
            decimal_number += pow(2, exponent);
        exponent++;
    }

    // hien thi
    if (s[0] == '0') // so mang dau duong
        printf("%d", decimal_number);
    else                                                      // so mang dau am
        printf("%d", decimal_number - (int)pow(2, exponent)); // ep kieu pow: double -> int
    return 0;
}
