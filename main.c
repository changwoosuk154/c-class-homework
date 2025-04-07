#include <stdio.h>

int main()
{
    printf("Hello, world!\n");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#define CLEAR_SCREEN "cls"
#define SLEEP(ms) Sleep(ms)
#else
#include <unistd.h>
#define CLEAR_SCREEN "clear"
#define SLEEP(ms) usleep((ms) * 1000)
#endif

#define WIDTH 81
#define MAX_NAME_LEN 50
#define MAX_DATE_LEN 11

void draw_splash(const char *name, const char *date);
void draw_triangle_left();
void draw_triangle_right();

int main() {
    char name[MAX_NAME_LEN];
    char date[MAX_DATE_LEN];
    int year, month, day;

    printf("[현재 날짜를 \"yyyy-mm-dd\" 형식으로 입력하세요]: ");
    scanf("%10s", date);

    // 날짜 형식 검증
    if (sscanf(date, "%d-%d-%d", &year, &month, &day) != 3 || month < 1 || month > 12 || day < 1 || day > 31) {
        printf("❌ 올바른 날짜 형식이 아닙니다. 프로그램을 종료합니다.\n");
        return 1;
    }

    printf("[당신의 이름을 입력하세요]: ");
    scanf(" %[^\n]", name);  // 공백 포함 입력 받기

    printf("**입력이 정상적으로 처리되었습니다.**\n");

    // 3초 대기 후 화면 클리어
    SLEEP(3000);
    system(CLEAR_SCREEN);

    // 스플래시 화면 출력
    draw_splash(name, date);

    return 0;
}

void draw_triangle_left() {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j <= i; ++j)
            printf("*");
        printf("\n");
    }
}

void draw_triangle_right() {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6 - i - 1; ++j)
            printf(" ");
        for (int k = 0; k <= i; ++k)
            printf("*");
        printf("\n");
    }
}

void draw_splash(const char *name, const char *date) {
    char buffer[200];
    int padding;
    int year, month, day;

    sscanf(date, "%d-%d-%d", &year, &month, &day);  // 날짜 다시 분해

    // 상단 구분선
    for (int i = 0; i < WIDTH; ++i) printf("+");
    printf("\n");

    // 제목
    snprintf(buffer, sizeof(buffer), "[마그라테아 ver 0.1]");
    padding = (WIDTH - (int)strlen(buffer)) / 2;
    printf("%*s%s\n", padding, "", buffer);

    // 문구 줄
    snprintf(buffer, sizeof(buffer), "풀 한 포기 없는 황무지에서 반짝이는 행성을 만들내는 곳 마그라테아,");
    padding = (WIDTH - (int)strlen(buffer)) / 2;
    printf("%*s%s\n", padding, "", buffer);

    snprintf(buffer, sizeof(buffer), "사람들이 보지 못하는 잠재력을 찾고 전문가의 손길을 더해 보석을 빗는 곳,");
    padding = (WIDTH - (int)strlen(buffer)) / 2;
    printf("%*s%s\n", padding, "", buffer);

    snprintf(buffer, sizeof(buffer), "마그라테아에 오신걸 환영합니다.");
    padding = (WIDTH - (int)strlen(buffer)) / 2;
    printf("%*s%s\n", padding, "", buffer);

    printf("\n");

    // 하단 구분선
    for (int i = 0; i < WIDTH; ++i) printf("+");
    printf("\n");

    // 사용자 정보
    printf("[사용자]: %-40s [실행 시간]: %d년 %02d월 %02d일\n", name, year, month, day);

    // 하단 마무리
    for (int i = 0; i < WIDTH; ++i) printf("=");
    printf("\n");

    // 삼각형 출력 (보너스)
    printf("\n왼쪽 직삼각형:\n");
    draw_triangle_left();
    printf("\n오른쪽 역직삼각형:\n");
    draw_triangle_right();
}
