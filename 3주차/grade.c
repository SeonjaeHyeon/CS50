/*
학점 계산 프로그램
----------------------
출력 예시)
성적을 입력하세요 (0 ~ 100): 90
학점은 A입니다.
*/

// 헤더 선언
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// 학점과 점수 테이블 배열 초기화
const int  N_GRADES = 9;
const int  I_GRADES[N_GRADES] = {95, 90, 85, 80, 75, 70, 65, 60, 0};
const char *C_GRADES[N_GRADES] = {"A+", "A", "B+", "B", "C+", "C", "D+", "D", "F"};

// 최소, 최대 점수 선언
const int MIN_SCORE = 0;
const int MAX_SCORE = 100;

// 사용자 정의 함수 선언
void calc_grade(void);

int main(void)
{
    // 학점 계산 프로그램 안내문 출력
    printf("학점프로그램\n종료를 원하면 \"999\"를 입력");

    // 학점테이블 출력 (점수, 학점)
    printf("\n[학점테이블]");
    printf("\n점수 :");
    for (int i = 0; i < N_GRADES; i++){  // 점수 테이블
        printf("\t%i", I_GRADES[i]);
    }
    printf("\n학점 :");
    for (int i= 0; i < N_GRADES; i++){  // 학점 테이블
        printf("\t%s", C_GRADES[i]);
    }
    printf("\n");

    // 사용자 정의 함수 호출
    calc_grade();

    // 프로그램 종료 안내문 출력
    printf("학점 프로그램을 종료합니다.\n");
}

void calc_grade(void)
{
    while (true)  // 사용자로부터 999를 입력받아 반복문을 종료할 때까지 무한반복
    {
        // 사용자로부터 점수를 입력받음
        int num = get_int("성적을 입력하세요 (0 ~ 100) : ");

        if (num == 999)  // 999를 입력받았다면
        {
            break;  // 반복문 종료
        }
        else if (num < MIN_SCORE || num > MAX_SCORE)  // 입력받은 점수가 범위를 넘어갔을 경우 (유효성 검사)
        {
            // 입력 범위를 넘어갔다는 안내문 출력
            printf("** %i 성적을 올바르게 입력하세요. 범위는 0 ~ 100 입니다.\n", num);
            continue;  // 아랫줄 코드를 건너뛰고 반복문 처음으로 돌아감
        }

        // 반복문으로 I_GRADES 배열의 요소들과 입력받은 점수를 하나씩 비교
        // 배열안에 기준 점수들이 내림차순으로 되어있기 때문에 크거나 같은 경우만 비교하면 된다.
        for (int i = 0; i < N_GRADES; i++)
        {
            if (num >= I_GRADES[i])  // 입력받은 점수가 기준 점수보다 크거나 같을 경우
            {
                // 점수와 학점 출력
                printf("점수는 %i이고 학점은 %s 입니다.\n", num, C_GRADES[i]);
                break;  // 반복문 종료
            }
        }
    }
}
