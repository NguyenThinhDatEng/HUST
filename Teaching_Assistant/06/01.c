#include <stdio.h>

int main()
{
    // khai bao va khoi tao
    char s[100], t[100];
    int numberOfChar[26]; // mang chua so luong cac ki tu
    scanf("%s", s);
    scanf("%s", t);
    for (int i = 0; i < 26; i++) // so lan xuat hien cua moi ki tu deu bang 0
        numberOfChar[i] = 0;

    // dem so cac ki tu xuat hien trong s
    int i = 0, index;
    while (s[i] != '\0') // so sanh 2 ki tu kieu char => phai dung dau nhay don
    {
        index = s[i] - 'a'; // 'a' co kieu du lieu la int
        numberOfChar[index]++;
        i++;
    }

    // dem so cac ki tu xuat hien trong t
    i = 0;
    while (t[i] != '\0')
    {
        index = t[i] - 'a';
        numberOfChar[index]++;
        i++;
    }

    // hien thi xau ket qua
    char c;
    for (int i = 0; i < 26; i++)
    {
        if (numberOfChar[i]) // neu so lan xuat hien khac 0
        {
            c = (char)i + 'a'; // ep kieu: int -> char (theo bang ma ASCII)
            printf("%c", c);
        }
    }

    // hien thi so lan xuat hien cua moi phan tu
    for (int i = 0; i < 26; i++)
    {

        if (numberOfChar[i]) // neu so lan xuat hien khac 0
        {
            printf("\n%d", numberOfChar[i]);
        }
    }
    return 0;
}
