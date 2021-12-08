#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <ctype.h>
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

void menu1(struct floorInfo *input, struct carInfo * car){
	scanf("이름 : %s", carOwner);
	scanf("차 번호 : %s", carNum);
	scanf("층 선택 : %d", &floor);
	scanf("번호 선택 : %d", &number);
}
int main(){
    int rsvNum = 0;
    int answer;
    int i; 
 
    while (1)
    {
    	printMain();
    	
        scanf("%d", &answer);
 		switch(answer){
 			case 1 : 
 				printf("menu1");
 				break;
 			case 2 : 
 				printf("menu2");
 				break;
 			case 3 : 
 				printf("menu3");
 				break;
 			case 0 : 
 				printf("menu4");
 				break;
 			default : 
 				printf("menu5");
		}
	}
}

 

