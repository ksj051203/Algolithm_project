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
    printf("1. ����\n");
    printf("2. ����\n");
    printf("3. ���� ��ġ Ȯ��\n");
    printf("4. ������Ȳ ���\n"); 
    printf("0. ����\n");
    printf("> ��ȣ���� : ");
}

void menu1(struct floorInfo *input, struct carInfo * car){
	scanf("�̸� : %s", carOwner);
	scanf("�� ��ȣ : %s", carNum);
	scanf("�� ���� : %d", &floor);
	scanf("��ȣ ���� : %d", &number);
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

 

