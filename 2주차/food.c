/*
요일별 오늘의 메뉴 출력 프로그램
------------------------------
출력 예시)
요일을 입력하세요: 화요일
화요일: 비빔밥
------------------------------
strcmp(str1, str2):
문자열 비교 결과를 반환.
같다면 0, 같지 않다면 1이 반환됨.
*/

#include <stdio.h>  // 표준입출력 헤더파일
#include <cs50.h>  // get_string() 사용을 위한 헤더파일
#include <string.h>  // strcmp() 사용을 위한 헤더파일

// 사용자 정의 함수 선언
void today_menu(string);

int main(void)
{
    // 사용자로부터 요일을 입력받음
    string day = get_string("요일을 입력하세요: ");
    // 사용자 정의 함수 호출
    today_menu(day);
}

void today_menu(string day)
{
    // 요일 비교 변수 선언
    string y1 = "월요일";
    string y2 = "화요일";
    string y3 = "수요일";
    string y4 = "목요일";
    string y5 = "금요일";
    string y6 = "토요일";
    string y7 = "일요일";
    string menu = "";

    // 요일 비교
    if (!strcmp(day, y1)) {  // 만약 월요일이라면
        menu = "청국장";
    } else if (!strcmp(day, y2)) {  // 만약 화요일이라면
        menu = "비빔밥";
    } else if (!strcmp(day, y3)) {  // 만약 수요일이라면
        menu = "된장찌개";
    } else if (!strcmp(day, y4)) {  // 만약 목요일이라면
        menu = "칼국수";
    } else if (!strcmp(day, y5)) {  // 만약 금요일이라면
        menu = "냉면";
    } else if (!strcmp(day, y6)) {  // 만약 토요일이라면
        menu = "소불고기";
    } else if (!strcmp(day, y7)) {  // 만약 일요일이라면
        menu = "오삼불고기";
    } else {  // 요일이 정확히 입력되지 않았을 경우 (예외처리)
        menu = "요일을 정확히 입력해주세요.";
    }

    // 오늘의 메뉴 출력
    printf("%s: %s\n", day, menu);
}
