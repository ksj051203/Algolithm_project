#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FLOOR 2
#define ROOM 10
typedef struct carInfo{
    char carNum[100]={};
    char carOwner[100]={};
}ca;

typedef struct floorInfo{
    ca rooms[ROOM];
}fl;

void printMain(void)
{
   printf("==================================================\n");
    printf("1. 주차\n");
    printf("2. 출차\n");
    printf("3. 주차 위치 확인\n");
    printf("4. 주차현황 출력\n"); 
    printf("0. 종료\n");
   printf("==================================================\n");
    printf("> 번호선택 : ");
    
}
void menu1(fl * floor){
    int n;
    printf("주차 할 번호를 선택해주세요: ");
    scanf("%d", &n);
    printf("본인의 이름을 입력해주세요 : ");
    scanf("%s",floor->rooms[n-1].carOwner);
    printf("차 번호를 입력해주세요 : "); 
    scanf("%s", floor->rooms[n-1].carNum);
    printf("주차를 완료하였습니다!\n");
}

void printAll(fl * floor, ca * car){
   printf("[B1층]============================================\n");
   
   for(int i = 0;i < 10;i++){
      if(i == 5)printf("\n");
      printf("[   %s  ] ",floor->rooms[i].carNum);   
   }
   printf("\n");
}

void menu2(fl * floor){
   char name[4];
   char number[5];
   int key;
    printf("본인의 이름을 입력해주세요 : ");
    scanf("%s", name);
    printf("차 번호를 입력해주세요 : "); 
    scanf("%s", number);
    for(int i = 0; i<10; i++){
       if(!(strncmp(name, floor->rooms[i].carOwner,3)&&strncmp(number, floor->rooms[i].carNum, 4))){
          printf("출차를 완료하였습니다!\n");
          
          for(int j = 0;floor->rooms[i].carNum[j]!='\0';j++){
             floor->rooms[i].carNum[j] = NULL;
         }
      }
   }
   
}
   
void menu3(fl * floor){ 
   char name[4];
   char number[5];
    printf("본인의 이름을 입력해주세요 : ");
    scanf("%s", name);
    printf("차 번호를 입력해주세요 : "); 
    scanf("%s", number);
    for(int i = 0; i<10; i++){
       if(!(strncmp(name, floor->rooms[i].carOwner,3)&&strncmp(number, floor->rooms[i].carNum, 4)))
          printf("%s님의 주차 위치는 %d번입니다!!!!!!!!!!!!\n",floor->rooms[i].carOwner, i+1);
   }
}


int main(){
    fl floor;
    ca car;
    //car = (carInfo)malloc(sizeof(carInfo));
      //floor = (floorInfo)malloc(sizeof(floorInfo));
    int answer;
    while (1){
        printMain();
        scanf("%d", &answer);
 
        if (answer == 1)
        {
            menu1(&floor);
        }
        else if (answer == 2)
        {
           menu2(&floor);
        }
        else if (answer == 3)
        {
         	menu3(&floor);  
        }
        else if (answer == 4)
        {
            printAll(&floor, &car);
        }
        else if (answer == 0)
            break;
        else
        {
            printf("잘못 입력하셨습니다. 다시 입력해주세요.\n");
        }
    }
}
