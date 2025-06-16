#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>

#define KEYWORD_LEN 16
#define MESSAGE_LEN 512
#define MAX_KQ 10
#define MAX_NAME_LEN 32
#define MAX_QUIZ 5

// 이스터에그 구조체 정의
typedef struct {
    char keyword[KEYWORD_LEN];
    char message[MESSAGE_LEN];
} EasterEgg;

EasterEgg arthur_easter_egg = {
    "specter",
    "나는 고백한다. 대학 졸업 후 스타트업 창업이라는 허세에 빠져 치기 어린 행동으로 친구들의 앞길을 막았다. 나는 나의 아이디어가 설득되는 사람이 나 뿐일 때 파괴적인 결과를 보게 된다는 것을 뼈저리게 경험했다. 과거의 아서는 독선과 아집의 망령이다."
};

// 한국어 문제 은행 구조체
typedef struct {
    int id;
    char question[128];
    char answer[64];
} KoreanQuestion;

KoreanQuestion koreanBank[MAX_KQ] = {
    {1, "What is your name?", "이름이 무엇입니까?"},
    {2, "How old are you?", "몇 살입니까?"},
    {3, "Where are you from?", "어디서 오셨습니까?"},
    {4, "What do you do?", "무슨 일을 하십니까?"},
    {5, "Do you speak Korean?", "한국어 하실 수 있습니까?"},
    {6, "What is your hobby?", "취미가 무엇입니까?"},
    {7, "How are you today?", "오늘 기분이 어떠세요?"},
    {8, "Do you like K-pop?", "케이팝 좋아하세요?"},
    {9, "What is your favorite food?", "가장 좋아하는 음식이 무엇입니까?"},
    {10, "Where is the bathroom?", "화장실이 어디에 있습니까?"}
};

// 연습생 구조체
typedef struct {
    char name[MAX_NAME_LEN];
    char nickname[MAX_NAME_LEN];
    char nationality[32];
    int score;
    bool passed;
} Trainee;

Trainee trainees[5] = {
    {"Jiyeon Park", "JYPark", "Korea", 0, false},
    {"Linda Kim", "LK", "USA", 0, false},
    {"Taro Yamada", "TYamada", "Japan", 0, false},
    {"Maria Gonzalez", "MG", "Mexico", 0, false},
    {"Luca Bianchi", "LB", "Italy", 0, false}
};

// 퀴즈 답지 구조체
typedef struct {
    int id;
    char result;
} QuizResult;

QuizResult quiz_sheet[MAX_QUIZ];

bool isAnswer(int id, const char *input) {
    for (int i = 0; i < MAX_KQ; i++) {
        if (koreanBank[i].id == id) {
            if (strcmp(koreanBank[i].answer, input) == 0) {
                return true;
            }
            break;
        }
    }
    return false;
}

int selectRandomTakers() {
    srand(time(NULL));
    int index;
    do {
        index = rand() % 5;
    } while (strcmp(trainees[index].nationality, "Korea") == 0);

    printf("{%s}님, 한국어 퀴즈 세션에 오신 걸 환영합니다!\n", trainees[index].name);
    return index;
}

void serveRandomQuiz(int traineeIndex) {
    printf("30초 뒤에 퀴즈가 시작됩니다...\n");
    sleep(30);  // 실제 프로그램에서는 시간 조정 필요

    int used[10] = {0};
    int score = 0;
    for (int i = 0; i < MAX_QUIZ; i++) {
        int qid;
        do {
            qid = rand() % MAX_KQ;
        } while (used[qid]);
        used[qid] = 1;

        printf("Q%d. %s\n답변: ", i + 1, koreanBank[qid].question);
        char input[128];
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        if (isAnswer(koreanBank[qid].id, input)) {
            quiz_sheet[i].id = koreanBank[qid].id;
            quiz_sheet[i].result = 'O';
            score += 20;
        } else {
            quiz_sheet[i].id = koreanBank[qid].id;
            quiz_sheet[i].result = 'X';
        }
    }

    trainees[traineeIndex].score = score;
    trainees[traineeIndex].passed = score >= 80;

    printf("\n퀴즈 종료!\n결과:\n");
    for (int i = 0; i < MAX_QUIZ; i++) {
        printf("문제 %d - %c\n", quiz_sheet[i].id, quiz_sheet[i].result);
    }
    printf("총점: %d점\n", score);
    printf("합격 여부: %s\n", trainees[traineeIndex].passed ? "합격" : "불합격");
}

void testKoreanLang() {
    int index = selectRandomTakers();
    serveRandomQuiz(index);
}

void print_keyword_binary_reverse(const char *keyword) {
    for (int i = strlen(keyword) - 1; i >= 0; i--) {
        unsigned char ch = keyword[i];
        for (int b = 7; b >= 0; b--) {
            printf("%d", (ch >> b) & 1);
        }
        printf(" ");
    }
    printf("\n");
}

bool isRightChar(const char *input, const char *keyword) {
    int len = strlen(keyword);
    if (strlen(input) != len) return false;
    for (int i = 0; i < len; i++) {
        if (input[i] != keyword[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

bool isEasterEgg(const char *word) {
    return strcmp(word, arthur_easter_egg.keyword) == 0;
}

void find_easter_egg() {
    char input[KEYWORD_LEN];
    char combo[KEYWORD_LEN];

    printf("<<아서의 이스터에그>>\n");
    print_keyword_binary_reverse(arthur_easter_egg.keyword);

    while (1) {
        printf("위 이진수에 해당하는 문자를 역순으로 입력하세요: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        if (isRightChar(input, arthur_easter_egg.keyword)) {
            printf("올바른 문자입니다! 이제 단어를 조합해 입력하세요: ");
            fgets(combo, sizeof(combo), stdin);
            combo[strcspn(combo, "\n")] = 0;

            if (isEasterEgg(combo)) {
                printf("##이스터에그 발견!$$\n");
                printf("%s\n", arthur_easter_egg.message);
            } else {
                printf("일치하지 않습니다. 메뉴로 돌아갑니다.\n");
            }
            break;
        } else {
            printf("잘못된 입력입니다. 다시 시도하세요.\n");
        }
    }
}

void training_self_and_teamwork() {
    char input[32];
    while (1) {
        printf("\n[2. 자기관리 및 팀워크] 하위 메뉴\n");
        printf("A. 멘토링\n");
        printf("B. 트라우마 관리\n");
        printf("0. 이전 메뉴로\n");
        printf("선택: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        if (strcasecmp(input, "Arthur") == 0) {
            find_easter_egg();
            continue;
        } else if (strcmp(input, "0") == 0) break;
        else if (strcasecmp(input, "A") == 0) {
            extern void matchMentoring();
            matchMentoring();
        }
        else if (strcasecmp(input, "B") == 0) {
            extern void overcomeTrauma();
            overcomeTrauma();
        }
        else printf("잘못된 입력입니다.\n");
    }
}
