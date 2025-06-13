#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRAINING_COUNT 8

void main_menu();
void audition_management();
void training_menu(char results[]);
void debut();

int main() {
    main_menu();
    return 0;
}

void main_menu() {
    char input[10];
    char training_results[TRAINING_COUNT] = {'\0'};

    while (1) {
        printf("\n[프로그램 마그라테아]\n");
        printf("I. 오디션 관리\n");
        printf("II. 훈련\n");
        printf("III. 데뷔\n");
        printf("(종료하려면 0, Q, q 중 하나 입력)\n");
        printf("메뉴를 선택하세요: ");

        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "0") == 0 || strcmp(input, "Q") == 0 || strcmp(input, "q") == 0 || strlen(input) == 0) {
            printf("프로그램을 종료합니다.\n");
            break;
        } else if (strcmp(input, "I") == 0 || strcmp(input, "i") == 0) {
            audition_management();
        } else if (strcmp(input, "II") == 0 || strcmp(input, "ii") == 0) {
            training_menu(training_results);
        } else if (strcmp(input, "III") == 0 || strcmp(input, "iii") == 0) {
            debut();
        } else {
            printf("올바른 메뉴를 선택하세요.\n");
        }
    }
}

void audition_management() {
    printf("[오디션 관리] 기능은 구현되지 않았습니다.\n");
}

void debut() {
    printf("[데뷔] 기능은 구현되지 않았습니다.\n");
}

void training_menu(char results[]) {
    char input[10];

    while (1) {
        printf("\n[훈련 메뉴]\n");
        printf("1. 체력과 지식 [%c]\n", results[0] ? results[0] : ' ');
        printf("2. 자기관리 및 팀워크 [%c]\n", results[1] ? results[1] : ' ');
        printf("3. 언어 및 발음 [%c]\n", results[2] ? results[2] : ' ');
        printf("4. 보컬 [%c]\n", results[3] ? results[3] : ' ');
        printf("5. 댄스 [%c]\n", results[4] ? results[4] : ' ');
        printf("6. 비주얼 및 이미지 [%c]\n", results[5] ? results[5] : ' ');
        printf("7. 연기 및 무대 퍼포먼스 [%c]\n", results[6] ? results[6] : ' ');
        printf("8. 팬 소통 [%c]\n", results[7] ? results[7] : ' ');
        printf("(상위 메뉴로 돌아가려면 0 입력)\n");
        printf("훈련 번호 선택: ");

        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "0") == 0) break;

        int choice = atoi(input);

        if (choice < 1 || choice > 8) {
            printf("올바른 번호를 선택하세요.\n");
            continue;
        }

        if (results[choice - 1] == 'P') {
            printf("이미 통과한 훈련입니다. 다른 훈련을 선택하세요.\n");
            continue;
        }

        if (choice >= 2 && results[0] != 'P') {
            printf("1번 훈련을 먼저 통과해야 합니다.\n");
            continue;
        }
        if (choice >= 3 && results[1] != 'P') {
            printf("2번 훈련을 먼저 통과해야 합니다.\n");
            continue;
        }

        char confirm[10];
        printf("평가 결과를 입력하시겠습니까? (Y/N): ");
        fgets(confirm, sizeof(confirm), stdin);
        confirm[strcspn(confirm, "\n")] = 0;

        if (strcmp(confirm, "Y") == 0 || strcmp(confirm, "y") == 0) {
            char result[10];
            printf("훈련을 마치고 인증에 통과했나요? (P/F): ");
            fgets(result, sizeof(result), stdin);
            result[strcspn(result, "\n")] = 0;

            if (strcmp(result, "P") == 0 || strcmp(result, "p") == 0) {
                results[choice - 1] = 'P';
                printf("훈련 %d번을 성공적으로 통과했습니다.\n", choice);
            } else {
                results[choice - 1] = 'F';
                printf("훈련 %d번을 실패했습니다. 다음에 다시 도전하세요.\n", choice);
            }
        } else {
            printf("훈련을 취소했습니다. 다시 선택해주세요.\n");
        }
    }
}
