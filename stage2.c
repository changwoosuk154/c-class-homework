#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define TRAINING_COUNT 8
#define MEMBER_COUNT 5
#define TEST_ITEM_COUNT 7
#define MAX_NAME_LEN 32
#define DAYS_PER_WEEK 6
#define MAX_MENTORS 8

void main_menu();
void audition_management();
void training_menu(char results[]);
void debut();
void training_physical_and_knowledge(char results[]);
void setHealth();
void getHealth();
int parse_input(const char *input, float scores[]);
void init_health_scores();
void setExerciseRoutine();
void getExerciseRoutine();
void matchMentoring();
void training_self_and_teamwork();

const char *test_items[TEST_ITEM_COUNT] = {
    "1마일 러닝", "스프린트", "푸시업", "스쿼트", "팔굽혀펴기", "수영", "무게들기"
};

const char *exercise_types[][3] = {
    {"러닝", "자전거", "빠른 걷기"},
    {"푸시업", "스쿼트", "버피"},
    {"레그 프레스", "레그 컬", "런지"},
    {"철봉", "풀업 바", "덤벨 컬"},
    {"플랭크", "크런치", "마운틴 클라이머"}
};

const char *weekdays[DAYS_PER_WEEK] = {"월", "화", "수", "목", "금", "토"};

char member_routine[MEMBER_COUNT][DAYS_PER_WEEK][32];

typedef struct {
    char name[MAX_NAME_LEN];
    char nickname[MAX_NAME_LEN];
} Member;

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    int mentee_number;
} Mentor;

const Member milliways_members[MEMBER_COUNT] = {
    {"Alice", "StarA"},
    {"Bob", "FlashB"},
    {"Carol", "WaveC"},
    {"Dave", "PowerD"},
    {"Eve", "ShineE"}
};

float health_scores[MEMBER_COUNT][TEST_ITEM_COUNT];

int parseIntMember(const char *nickname) {
    int sum = 0;
    for (int i = 0; nickname[i] != '\0'; i++) {
        sum += (int)nickname[i];
    }
    return sum;
}

int getRandomAbility() {
    return 100 + rand() % 901; // 100~1000 사이
}

void matchMentoring() {
    int member_nums[MEMBER_COUNT];
    int member_abilities[MEMBER_COUNT];
    Mentor mentors[MAX_MENTORS];
    int mentor_count = 0;

    srand((unsigned int)time(NULL));

    printf("\n--- 멘토 등록 (최대 8명) ---\n");
    for (int i = 0; i < MAX_MENTORS; i++) {
        printf("멘토 %d 이름 입력 (종료는 빈 줄): ", i + 1);
        char name[MAX_NAME_LEN];
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = 0;
        if (strlen(name) == 0) break;

        mentors[mentor_count].id = i;
        strncpy(mentors[mentor_count].name, name, MAX_NAME_LEN);
        mentors[mentor_count].mentee_number = -1;
        mentor_count++;
    }

    printf("\n--- 연습생 매칭 ---\n");
    for (int i = 0; i < MEMBER_COUNT; i++) {
        member_nums[i] = parseIntMember(milliways_members[i].nickname);
        member_abilities[i] = getRandomAbility();
        int mentor_id = member_nums[i] % mentor_count;
        mentors[mentor_id].mentee_number = member_nums[i];

        printf("연습생: %s (%d) - 능력치: %d\n", milliways_members[i].nickname, member_nums[i], member_abilities[i]);
        printf(" -> 멘토: [%d] %s\n", mentors[mentor_id].id, mentors[mentor_id].name);
    }
}

void training_self_and_teamwork() {
    char input[10];
    while (1) {
        printf("\n[2. 자기관리 및 팀워크] 하위 메뉴\n");
        printf("A. 멘토링\n");
        printf("0. 이전 메뉴로\n");
        printf("선택: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "0") == 0) break;
        else if (strcmp(input, "A") == 0 || strcmp(input, "a") == 0) {
            matchMentoring();
        } else {
            printf("잘못된 입력입니다.\n");
        }
    }
}

// main_menu 내부 training_menu 호출에서 자기관리 메뉴로 진입 연결 추가
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

        if (choice == 1) {
            training_physical_and_knowledge(results);
        } else if (choice == 2) {
            training_self_and_teamwork();
        } else {
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
}
