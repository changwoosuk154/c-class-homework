#include <stdio.h>
#include <string.h>

// 자동차 구조체
typedef struct {
    int x;              // x 좌표
    int y;              // y 좌표
    char dir;           // 방향: N/E/S/W
    int isRunning;      // 1이면 주행 중
} Car;

// 출발
void start(Car *car) {
    car->isRunning = 1;
    printf("출발합니다.\n");
}

// 멈춤
void stop(Car *car) {
    car->isRunning = 0;
    printf("멈춥니다.\n");
}

// 좌회전
void turn_left(Car *car) {
    switch (car->dir) {
        case 'N': car->dir = 'W'; break;
        case 'W': car->dir = 'S'; break;
        case 'S': car->dir = 'E'; break;
        case 'E': car->dir = 'N'; break;
    }
}

// 우회전
void turn_right(Car *car) {
    switch (car->dir) {
        case 'N': car->dir = 'E'; break;
        case 'E': car->dir = 'S'; break;
        case 'S': car->dir = 'W'; break;
        case 'W': car->dir = 'N'; break;
    }
}

// 이동 (전진 or 후진)
void move(Car *car, int forward) {
    if (!car->isRunning) {
        printf("출발 먼저 하세요.\n");
        return;
    }
    int step = forward ? 1 : -1;
    switch (car->dir) {
        case 'N': car->y += step; break;
        case 'S': car->y -= step; break;
        case 'E': car->x += step; break;
        case 'W': car->x -= step; break;
    }
}

// 상태 출력
void print_status(Car car) {
    printf("위치: (%d, %d), 방향: %c\n", car.x, car.y, car.dir);
}

int main() {
    Car car = {0, 0, 'N', 0};  // 초기화
    char cmd[20];

    printf("명령: 출발, 좌회전, 우회전, 후진, 멈춤, 기타=전진\n");

    while (1) {
        printf("\n입력 > ");
        scanf("%s", cmd);

        if (strcmp(cmd, "출발") == 0) start(&car);
        else if (strcmp(cmd, "멈춤") == 0) { stop(&car); break; }
        else if (strcmp(cmd, "좌회전") == 0) turn_left(&car);
        else if (strcmp(cmd, "우회전") == 0) turn_right(&car);
        else if (strcmp(cmd, "후진") == 0) move(&car, 0);
        else move(&car, 1);  // 기타 입력 = 전진

        print_status(car);
    }

    return 0;
}
