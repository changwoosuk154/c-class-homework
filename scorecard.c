#include <stdio.h>
#include <stdlib.h>
#define SIZE 6
#define FIELD_COUNT 5

// 후보자 이름과 고유 ID 배열
char *candidates[SIZE] = {"박지연", "Ethan Smith", "Helena Silva", "Liam Wilson", "Mina Chen", "Yuto Tanaka"};
int candidate_ids[SIZE] = {123456, 234567, 345678, 456789, 567890, 678901};

// 점수 시트: ID, 음악, 댄스, 보컬, 비주얼, 전달력, 총점
int scoring_sheet[SIZE][FIELD_COUNT + 2];

int is_equal(const char *a, const char *b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) return 0;
        i++;
    }
    return a[i] == b[i];
}

int get_field_index(char *field) {
    if (is_equal(field, "음악")) return 1;
    if (is_equal(field, "댄스")) return 2;
    if (is_equal(field, "보컬")) return 3;
    if (is_equal(field, "비주얼")) return 4;
    if (is_equal(field, "전달력")) return 5;
    return -1;
}

void input_scores(char *field, int field_index) {
    int score;
    printf("++++++++++++++++++++++++++++++++++++\n");
    for (int i = 0; i < SIZE; i++) {
        printf("후보자: %s\n", candidates[i]);
        while (1) {
            printf("%s 소양: ", field);
            scanf("%d", &score);
            if (score >= 10 && score <= 100) break;
            printf("잘못된 값입니다. 다시 입력하세요.\n");
        }
        scoring_sheet[i][0] = candidate_ids[i];
        scoring_sheet[i][field_index] = score;
        printf("------------------------------------\n");
    }
}

void print_scores(char *field, int field_index) {
    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("입력을 모두 완료했습니다.\n");
    printf("입력하신 내용을 검토하세요!\n");
    printf("------------------------------------\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%s: %d\n", candidates[i], scoring_sheet[i][field_index]);
    }
}

void modify_scores(char *field, int field_index) {
    int id, new_score;
    char more;
    do {
        printf("수정할 후보자의 6자리 ID를 입력하세요: ");
        scanf("%d", &id);
        int found = 0;
        for (int i = 0; i < SIZE; i++) {
            if (scoring_sheet[i][0] == id) {
                printf("%s의 새로운 %s 소양 점수: ", candidates[i], field);
                while (1) {
                    scanf("%d", &new_score);
                    if (new_score >= 10 && new_score <= 100) break;
                    printf("10~100 사이의 점수를 입력하세요: ");
                }
                scoring_sheet[i][field_index] = new_score;
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("해당 ID의 후보자를 찾을 수 없습니다.\n");
        }
        printf("계속 수정하시겠습니까? (Y/N): ");
        scanf(" %c", &more);
    } while (more == 'Y' || more == 'y');
}

void calculate_total_and_print_result() {
    for (int i = 0; i < SIZE; i++) {
        int sum = 0;
        for (int j = 1; j <= FIELD_COUNT; j++) {
            sum += scoring_sheet[i][j];
        }
        scoring_sheet[i][FIELD_COUNT + 1] = sum;
    }

    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            if (scoring_sheet[i][FIELD_COUNT + 1] < scoring_sheet[j][FIELD_COUNT + 1]) {
                int temp[FIELD_COUNT + 2];
                char *tmp_name;
                for (int k = 0; k < FIELD_COUNT + 2; k++) {
                    temp[k] = scoring_sheet[i][k];
                    scoring_sheet[i][k] = scoring_sheet[j][k];
                    scoring_sheet[j][k] = temp[k];
                }
                tmp_name = candidates[i];
                candidates[i] = candidates[j];
                candidates[j] = tmp_name;
            }
        }
    }

    printf("=======================================\n");
    printf("후보 선발 결과 집계 중 ...\n");
    printf("=======================================\n");
    printf("#######################################\n");
    printf("# 밀리웨이즈의 멤버가 된 걸축하합니다!  #\n");
    printf("#######################################\n");
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, candidates[i]);
    }
}

int main(void) {
    char judge[30], field[20];
    char confirm;
    int field_index;

    while (1) {
        printf("####################################\n");
        printf("#       오디션 심사 결과 입력       #\n");
        printf("####################################\n");
        printf("> 심사위원 이름: ");
        scanf("%s", judge);
        printf("> 전문 분야: ");
        scanf("%s", field);

        field_index = get_field_index(field);
        if (field_index == -1) {
            printf("잘못된 분야입니다.\n");
            continue;
        }

        input_scores(field, field_index);
        print_scores(field, field_index);

        printf("제출하시겠습니까? (Y/N): ");
        scanf(" %c", &confirm);

        if (confirm == 'Y' || confirm == 'y') {
            printf("***최종 제출을 완료했습니다.***\n");
            break;
        } else {
            modify_scores(field, field_index);
            break;
        }
    }

    calculate_total_and_print_result();
    return 0;
}
