#include <stdio.h>
#include <string.h>

int main() {
    int year, month, day;
    char name[100];
    char date[20];

    printf("[현재 날짜를 yyyy-mm-dd 형식으로 입력하세요]: ");
    scanf("%d-%d-%d", &year, &month, &day);
    getchar(); 

    printf("[당신의 이름을 입력하세요:] ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';  

    sprintf(date, "%04d-%02d-%02d", year, month, day);

    if (strcmp(name, "아서 덴트") == 0) {
        printf("**입력이 정상적으로 처리되었습니다.\n\n");
    }

    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
    printf("                         [마그라테아 ver 0.1]                              \n");
    printf("           풀 한 포기 없는 황무지에서 반짝이는 행성을 만들내는 곳 마그라테아,        \n");
    printf("         사람들이 보지 못하는 잠재력을 찾고 전문가의 손길을 더해 보석을 빗는 곳,   \n");
    printf("           마그라테아에 오신걸 환영합니다.                                    \n\n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("[사용자]: %s                                   [실행 시간]: %s\n", name, date);
    printf("================================================================================\n");

    return 0;
}
