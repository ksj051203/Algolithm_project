#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#define FLOOR 2
#define ROOM 10
int count[11];
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
    printf("1. ����\n");
    printf("2. ����\n");
    printf("3. ���� ��ġ Ȯ��\n");
    printf("4. ������Ȳ ���\n"); 
    printf("0. ����\n");
    printf("==================================================\n");
    printf("> ��ȣ���� : ");
}

void menu1(fl * floor){
    int n;
    printf("���� �� ��ȣ�� �������ּ��� (1~10���� �Է�): ");
    while(1){
        scanf("%d", &n);
        if(count[n-1] == 1){
            printf("��ȣ�� �ٽ� �������ּ���^^ : ");
            continue; 
        }
        count[n-1]++;
        if(n>=1&&n<11){
	        printf("������ �̸��� �Է����ּ��� : ");
	        scanf("%s",floor->rooms[n-1].carOwner);
	        printf("�� ��ȣ�� �Է����ּ���: "); 
	        scanf("%s", floor->rooms[n-1].carNum);
	        printf("������ �Ϸ��Ͽ����ϴ�!\n");
            break;
        }else{
            printf("��ȣ�� �ٽ� �Է����ּ���^^ : ");
            continue; 
        }
    }
}

void menu2(fl * floor){
    char name[4];
    char number[5];
    int key;
    printf("������ �̸��� �Է����ּ��� : ");
    scanf("%s", name);
    printf("�� ��ȣ�� �Է����ּ��� : "); 
    scanf("%s", number);
    for(int i = 0; i<10; i++){
        if(!strcmp(name, floor->rooms[i].carOwner)&&!strcmp(number, floor->rooms[i].carNum)){
            printf("������ �Ϸ��Ͽ����ϴ�!\n");
            for(int j = 0;floor->rooms[i].carNum[j]!='\0';j++){
               floor->rooms[i].carNum[j] = NULL;
                count[i]--;
            }
        }
    }
}
   
void menu3(fl * floor){ 
    char name[4];
    char number[5];
    printf("������ �̸��� �Է����ּ��� : ");
    scanf("%s", name);
    printf("�� ��ȣ�� �Է����ּ��� : "); 
    scanf("%s", number);
    for(int i = 0; i<10; i++){
    	if(!strcmp(name, floor->rooms[i].carOwner)&&!strcmp(number, floor->rooms[i].carNum))
        	printf("%s���� ���� ��ġ�� %d���Դϴ�!!!!!!!!!!!!\n",floor->rooms[i].carOwner, i+1);
    }
}

void printAll(fl * floor){
    printf("[B1��]============================================\n");
    for(int i = 0; i < 10;i++){
    	if(i == 5)printf("\n"){
      		printf("[   %s  ] ",floor->rooms[i].carNum);
   		}
   	printf("\n");
}

int main(){
   	system("���� ���� ���α׷�");
   	system("color 8f");
	fl floor;
	int answer;
	    while(1){
	        printMain();
	        scanf("%d", &answer);
	        switch(answer){
	            case 1:
	                menu1(&floor);
	                break;
	            case 2:
	                menu2(&floor);
	                break;
	            case 3:
	                menu3(&floor); 
	                break;
	            case 4:
	                printAll(&floor);
	                break;
	            case 0:
	                printf("�ȳ���������!\n");
	                break;
	            default :
	                printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.\n");
            }
        }
    }
