#include <stdio.h>
#include <string.h>

int main() {
   int year, month, day;
   printf("[현재 날짜를 yyyy-mm-dd 형식으로 입력하세요]: ");
   scanf("%d-%d-%d", &year,&month,&day);
   getchar();

   char name[100];
   printf("[당신의 이름을 입력하세요:] ");
   fgets(name, sizeof(name), stdin);

   name[strcspn(name, "\n")] = '\0';

   if (strcmp(name, "아서 덴트") == 0) {
      printf("**입력이 정상적으로 처리되었습니다.");

   }
   return 0;
}