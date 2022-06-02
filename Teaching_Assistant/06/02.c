#include <stdio.h>
#include <string.h> // strlen(s)

int main()
{
    // Khai bao va khoi tao
    char s[100], result[100];
    fgets(s, 100, stdin); // strlen(s) = lengthOf_s + 1
    int length = strlen(s) - 1;

    // Lay chi so cua ki tu khong phai khoang trang o cuoi xau
    int lastIndex = length - 1; // chi so cua phan tu cuoi cua xau la lengthOf_s - 1
    while (s[lastIndex] == ' ') // kiem tra khoang trang o cuoi xau
        lastIndex--;

    // Lay chi so cua ki tu khong phai khoang trang o dau xau
    int firstIndex = 0;
    while (s[firstIndex] == ' ') // kiem tra khoang trang o dau xau
        firstIndex++;

    // Bo cac khoang trang thua o giua xau
    int indexOfResult = 0;
    for (int i = firstIndex; i <= lastIndex; i++)
        if (s[i] == ' ' && s[i + 1] == ' ') // kiem tra 2 khoang trang canh nhau
            continue;
        else
            result[indexOfResult++] = s[i]; // gan ki tu cho xau ket qua
    result[indexOfResult] = '\0';           // ngat xau

    // hien thi ket qua
    printf("%s", result);
    return 0;
}