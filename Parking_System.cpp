#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <ctype.h>
#define FLOOR 2
#define ROOM 10

void printMain(void)
{
    printf("1. 주차\n");
    printf("2. 출차\n");
    printf("3. 주차 위치 확인\n");
    printf("4. 주차현황 출력\n"); 
    printf("0. 종료\n");
    printf("> 번호선택 : ");
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

 

