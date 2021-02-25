#include <stdio.h>

void sort(int, int *);
void aprint(int, int *);

int main(void)
{
    int n = 7;
    int arr[7] = {0, 25, 10, 17, 6, 12, 9};

    sort(n, arr);
    aprint(n, arr);

    return 0;
}

void sort(int n, int *arr)
{
    int tmp;
    int *a;
    int *b;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            a = arr + j;
            b = arr + j + 1;

            if (*a > *b)
            {
                tmp = *a;
                *a = *b;
                *b = tmp;
            }
        }
    }
}

void aprint(int n, int *arr)
{
    for (int i = 0; i < n; i++)
    {
        printf("%i\t", *(arr + i));
    }
    printf("\n");
}
