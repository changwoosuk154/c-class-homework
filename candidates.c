#include <stdio.h>
#include <string.h>

int main() {
    // 변수 선언
    char name[100];
    char gender[10];
    char birth[20];
    char phone[20];
    char nationality[50];
    float bmi;
    char mainAffiliation[100];
    char newsAffiliation[100];
    char comment[200];
    char mbti[10];
    char extra[200];

    // 입력 받기
    printf("이름을 입력하세요: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("성별을 입력하세요: ");
    fgets(gender, sizeof(gender), stdin);
    gender[strcspn(gender, "\n")] = '\0';

    printf("생년월일을 입력하세요 (YYYY/MM/DD 형식): ");
    fgets(birth, sizeof(birth), stdin);
    birth[strcspn(birth, "\n")] = '\0';

    printf("연락처를 입력하세요: ");
    fgets(phone, sizeof(phone), stdin);
    phone[strcspn(phone, "\n")] = '\0';

    printf("국적을 입력하세요: ");
    fgets(nationality, sizeof(nationality), stdin);
    nationality[strcspn(nationality, "\n")] = '\0';

    printf("BMI 수치를 입력하세요: ");
    scanf("%f", &bmi);
    getchar(); // BMI 입력 후 버퍼 비우기

    printf("주 소속을 입력하세요: ");
    fgets(mainAffiliation, sizeof(mainAffiliation), stdin);
    mainAffiliation[strcspn(mainAffiliation, "\n")] = '\0';

    printf("보도 소속을 입력하세요: ");
    fgets(newsAffiliation, sizeof(newsAffiliation), stdin);
    newsAffiliation[strcspn(newsAffiliation, "\n")] = '\0';

    printf("하고 싶은 말을 입력하세요: ");
    fgets(comment, sizeof(comment), stdin);
    comment[strcspn(comment, "\n")] = '\0';

    printf("MBTI를 입력하세요: ");
    fgets(mbti, sizeof(mbti), stdin);
    mbti[strcspn(mbti, "\n")] = '\0';

    printf("추가 기재사항을 입력하세요: ");
    fgets(extra, sizeof(extra), stdin);
    extra[strcspn(extra, "\n")] = '\0';

    // 출력하기
    printf("\n================================================================================\n");
    printf("| %-10s | %-12s | %-15s | %-8s | %-5s | %-5s |\n", "이름", "생년월일", "연락처", "국적", "BMI", "성별");
    printf("--------------------------------------------------------------------------------\n");
    printf("| %-10s | %-12s | %-15s | %-8s | %-5.1f | %-5s |\n", name, birth, phone, nationality, bmi, gender);
    printf("--------------------------------------------------------------------------------\n");
    printf("| %-10s | %-10s | %-15s | %-8s | %-10s |\n", "주 소속", "보도 소속", "한마디", "MBTI", "추가사항");
    printf("--------------------------------------------------------------------------------\n");
    printf("| %-10s | %-10s | %-15s | %-8s | %-10s |\n", mainAffiliation, newsAffiliation, comment, mbti, extra);
    printf("================================================================================\n");

    return 0;
}
