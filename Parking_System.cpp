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
    printf("1. ����\n");
    printf("2. ����\n");
    printf("3. ���� ��ġ Ȯ��\n");
    printf("4. ������Ȳ ���\n"); 
    printf("0. ����\n");
    printf("> ��ȣ���� : ");
}
void menu1(struct floorInfo * floor, struct carInfo *car){
    /*car = (carInfo *)malloc(sizeof(carInfo));
   floor = (floorInfo *)malloc(sizeof(floorInfo));*/
    int n;
    printf("���� �� ��ȣ�� �������ּ���: ");
    scanf("%d", &n);
    printf("������ �̸��� �Է����ּ��� : ");
    scanf("%s",floor->rooms[n]->carOwner);
    printf("�� ��ȣ�� �Է����ּ��� : "); 
    scanf("%s", floor->rooms[n]->carNum);
    printf("������ �Ϸ��Ͽ����ϴ�!\n");
}

void printAll(struct carInfo * car){
   printf("[B1��]====================================================================\n");
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
            printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.\n");
            
        }
    }
}
