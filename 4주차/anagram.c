/*
숫자 애너그램 찾기 프로그램
---------------------------
예)
입력값: 12345, 54321 -> 출력값: True
입력값: 14258, 25431 -> 출력값: False
입력값: 11132, 21131 -> 출력값: True
*/

// 헤더 선언
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 입력값 배열 초기화
const int num_x[3] = {12345, 14258, 11132};
const int num_y[3] = {54321, 25431, 21131};

// 사용자 정의 함수 선언
int get_digit(int);
char* to_chars(int);
char* sort(char*);
bool anagram(int, int);

// main 함수
int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        // 입력값 출력
        printf("입력값: %i, %i", num_x[i], num_y[i]);
        // 출력값 출력
        // strcmp()에서 같다면 0을 반환하므로 삼항연산자를 사용하여 0일 때(false) True, 0이 아닐 때(true) False 출력
        printf(" -> 출력값: %s\n", anagram(num_x[i], num_y[i]) ? "False" : "True");
    }
}

// 자릿수 반환 함수
int get_digit(int n)
{
    // 밑이 10인 로그를 씌우면 log10^(자릿수 - 1) + log(나머지)이므로 1을 더해준다. int 형이므로 소숫점은 버려진다.
    // 예를 들어 n = 314인 경우, log314 = log10^2 + log3.14 = 2 + log3.14이므로 2.XXX가 된다.
    return log10(n) + 1;
}

// int -> char* 변환 함수
char* to_chars(int n)
{
    // n의 자릿수만큼 char 배열 크기 동적할당
    char* result = malloc(get_digit(n));

    // int 변수값을 char 배열에 저장
    sprintf(result, "%d", n);
    return result;  // char 배열 반환
}

// 선택 정렬 함수
// 참고: https://www.boostcourse.org/cs112/lecture/119023/
char* sort(char* c)
{
    int size = strlen(c);  // char 배열 크기 저장

    // 마지막 요소는 정렬하지 않아도 되므로 size - 1까지만 반복
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;  // 최솟값 초기화

        // 현재 인덱스의 뒷부분만 비교하면 되므로 j 값을 i + 1로 초기화
        for (int j = i + 1; j < size; j++)
        {
            // 최솟값으로 설정된 값이 현재 인덱스의 값보다 클 경우
            // 즉, 현재 값이 최솟값인 경우
            if (c[min] > c[j])
            {
                min = j;  // 최솟값 변경
            }
        }

        // 초기화한 최초 최솟값과 현재 최솟값이 다를 경우
        if (min != i)
        {
            // 임시 char 변수에 i번째 값 저장
            char temp = c[i];

            // i번째 값과 min번째 값을 서로 바꿈
            c[i] = c[min];
            c[min] = temp;
        }
    }

    // 정렬된 char 배열 반환
    return c;
}

// 애너그램 판별 함수
bool anagram(int x, int y)
{
    char* a = to_chars(x);  // char 배열로 변환한 x를 변수 a에 저장
    char* b = to_chars(y);  // char 배열로 변환한 y를 변수 b에 저장

    // char 배열인 a, b를 오름차순으로 정렬한 후, 같은 값인지 비교하여 boolean 값 반환
    return strcmp(sort(a), sort(b));
}
