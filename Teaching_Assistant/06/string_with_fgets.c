#include <stdio.h>
#include <string.h> // strlen(s)

int main()
{
    // Khai bao va khoi tao
    char s[100], result[100];
    fgets(s, 100, stdin); // strlen(s) = lengthOf_s + 1
    for (int i = 0; i < strlen(s); i++)
    {
        printf("s[%d]: %d\n", i, (int)s[i]);
    }

    return 0;
}