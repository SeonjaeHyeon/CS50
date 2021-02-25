#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // memcpy 예제
    char *str = "Hello, World!!";
    char *c1 = malloc(sizeof(str));

    memcpy(c1, str, strlen(str) + 1);
    printf("src: %s\ndst: %s\n", str, c1);
    printf("\n");

    // memmove 예제
    char str2[] = "Hello, World!!!!!!!!!!";

    printf("src: %s\n", str2);
    memmove(str2 + 7, str2, 12);
    printf("dst: %s\n", str2);
    printf("\n");

    // memcmp 예제
    int len1 = strlen(str);
    int len2 = strlen(str2);
    int n = memcmp(str, str2, len1 > len2 ? len1 : len2);

    if (n != 0)
    {
        printf("%s and %s are different.\n", str, str2);
    }
    else
    {
        printf("%s and %s are identical.\n", str, str2);
    }
    printf("\n");

    // memchr 예제
    char c = 'W';
    char *addr = (char*)memchr(str, c, strlen(str));

    if (addr != NULL)
    {
        printf("'%c' found at position %lu.\n", c, addr - str + 1);
    }
    else
    {
        printf("'%c' not found.", c);
    }
    printf("\n");

    // memset 예제
    char str3[] = "Hello, World!!!";

    printf("src: %s\n", str3);
    memset(str3, ' ', 7);
    printf("dst: %s\n", str3);
}
