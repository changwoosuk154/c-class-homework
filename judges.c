#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JUDGES 100
#define MAX_STR_LEN 512

int main() {
    char project_name[100];
    int total_judges = 0;
    int selected_members = 0;
    char judges_array[MAX_JUDGES][MAX_STR_LEN];
    int count = 0;

    // 프로젝트명, 총 인원, 선발 인원 입력
    printf("####################################\n");
    printf("#      심사위원 명단 데이터 입력       #\n");
    printf("####################################\n");

    printf("> 참여 프로젝트: ");
    fgets(project_name, sizeof(project_name), stdin);
    project_name[strcspn(project_name, "\n")] = '\0';

    printf("> 심사 총 인원: ");
    scanf("%d", &total_judges);
    getchar();  // 개행 제거

    printf("> 선발 멤버 수: ");
    scanf("%d", &selected_members);
    getchar();

    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("%d명의 심사위원 정보 입력을 시작합니다.\n", total_judges);
    printf("++++++++++++++++++++++++++++++++++++\n");

    // 심사위원 정보 입력
    while (count < total_judges) {
        char input[MAX_STR_LEN];
        printf("*심사위원 %d: ", count + 1);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        // 항목 수 검사
        int comma_count = 0;
        for (int i = 0; input[i] != '\0'; i++) {
            if (input[i] == ',') comma_count++;
        }

        if (comma_count != 6) {
            printf("입력 항목이 정확하지 않습니다. 다시 입력해주세요.\n");
            continue;
        }

        // 저장
        strncpy(judges_array[count], input, MAX_STR_LEN - 1);
        judges_array[count][MAX_STR_LEN - 1] = '\0';
        count++;
    }

    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("심사위원 정보 입력이 끝났습니다.\n");
    printf("++++++++++++++++++++++++++++++++++++\n");

    // Y/N 입력
    char choice;
    printf("\"%s 심사위원 정보를 확인할까요?\" (Y/N): ", project_name);
    scanf(" %c", &choice);

    if (choice == 'Y') {
        printf("####################################\n");
        printf("#        심사위원 데이터 출력        #\n");
        printf("####################################\n");

        for (int i = 0; i < total_judges; i++) {
            printf("[심사위원 %d]\n", i + 1);
            char temp[MAX_STR_LEN];
            strncpy(temp, judges_array[i], MAX_STR_LEN);
            temp[MAX_STR_LEN - 1] = '\0';

            // 콤마로 항목 분리
            char *token = strtok(temp, ",");
            while (token != NULL) {
                printf("%s\n", token);
                token = strtok(NULL, ",");
            }
            printf("-----------------------------------\n");
        }
    } else {
        printf("프로그램을 종료합니다.\n");
    }

    return 0;
}
