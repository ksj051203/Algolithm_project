#include <stdio.h>
#include <string.h>
#define FLOOR 2
#define ROOM 10
struct carInfo{
	char carNum[5];
	int number;
	int floor;
	char carOwner[4];
	
};

struct floorInfo{
	struct carInfo rooms[ROOM];
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
//struct floorInfo input, 
void menu1(struct carInfo *car){
	printf("본인의 이름을 입력해주세요 : ");
	scanf("%s", car->carOwner);
	printf("차 번호를 입력해주세요 : "); 
	scanf("%s", car->carNum);
	printf("주차할 층을 선택해주세요 : "); 
	scanf("%d", &car->floor);
	printf("주차 할 번호를 선택해주세요 : ");
	scanf("%d", &car->number);
	printf("주차를 완료하였습니다!");
}
int main(){
	struct carInfo car[10];
	struct floorInfo floor[2];
    int answer;
  	while (1)
    {
        printMain();
        scanf("%c", &answer);
        fflush(stdin);
 
        if (answer == '1')
        {
            menu1(car);
        }
        else if (answer == '2')
        {
            printf("이태현 바");
        }
        else if (answer == '3')
        {
            printf("이태현 바ㅂ");
        }
        else if (answer == '4')
        {
            printf("이태현 바22");
        }
        else if (answer == '0')
            break;
 
        else
        {
            printf("잘못 입력하셨습니다. 다시 입력해주세요.");
        }
    }
}

 

