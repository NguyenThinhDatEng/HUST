#include <stdio.h>
#include <ctype.h> // isalpha(c), isalnum(c)

int main()
{
    // khai bao va khoi tao
    char s[100];
    fgets(s, 101, stdin);

    // dem so ki tu
    int numberOfLetters = 0, numberOfNumbers = 0;
    int i = 0;

    while (s[i] != '\0')
    {
        if (isalpha(s[i])) // kiem tra ki tu chu
            numberOfLetters++;
        else if (isalnum(s[i])) // kiem tra ki tu so
            numberOfNumbers++;
        i++;
    }

    // hien thi
    if (numberOfLetters == numberOfNumbers)
        printf("0");
    else if (numberOfLetters > numberOfNumbers)
        printf("1");
    else
        printf("2");
    return 0;
}
