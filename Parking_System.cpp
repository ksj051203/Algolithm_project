#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FLOOR 2
#define ROOM 10
struct carInfo{
    char carNum[5];
    char carOwner[4];
};
struct floorInfo{
    struct carInfo *rooms[ROOM];
};
void printMain(void)
{
    printf("1. 주차\n");
    printf("2. 출차\n");
    printf("3. 주차 위치 확인\n");
    printf("4. 주차현황 출력\n"); 
    printf("0. 종료\n");
    printf("> 번호선택 : ");
}
void menu1(struct floorInfo * floor, struct carInfo *car){
    /*car = (carInfo *)malloc(sizeof(carInfo));
   floor = (floorInfo *)malloc(sizeof(floorInfo));*/
    int n;
    printf("주차 할 번호를 선택해주세요: ");
    scanf("%d", &n);
    printf("본인의 이름을 입력해주세요 : ");
    scanf("%s",floor->rooms[n]->carOwner);
    printf("차 번호를 입력해주세요 : "); 
    scanf("%s", floor->rooms[n]->carNum);
    printf("주차를 완료하였습니다!\n");
}

void printAll(struct carInfo * car){
   printf("[B1층]====================================================================\n");
   for(int i = 0;i < 10;i++){
      if(i == 5)printf("\n");
      printf("[   %d  ] ",(car+i)->carNum);   
   }
   printf("\n");
}
void menu2(struct floorInfo * floor){

}


int main(){
    struct floorInfo* floor;
    struct carInfo* car;
    
    car = (carInfo *)malloc(sizeof(carInfo));
   floor = (floorInfo *)malloc(sizeof(floorInfo));
    int answer;
    while (1){
        printMain();
        scanf("%d", &answer);
 
        if (answer == 1)
        {
            menu1(floor, car);
        }
        else if (answer == 2)
        {
           
        }
        else if (answer == 3)
        {
           
        }
        else if (answer == 4)
        {
            printAll(car);
        }
        else if (answer == 0)
            break;
        else
        {
            printf("잘못 입력하셨습니다. 다시 입력해주세요.\n");
            
        }
    }
}
