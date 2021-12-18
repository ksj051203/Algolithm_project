#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#define FLOOR 2
#define ROOM 10
#define SIZE 10
int count[11];
int top = -1;
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
void printMain2(void)
{
    printf("==================================================\n");
    printf("1. ����\n");
    printf("2. ����\n");
    printf("3. ������Ȳ ���\n"); 
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
    	if(i == 5)printf("\n");
      	printf("[   %s  ] ",floor->rooms[i].carNum);
   	}
   	printf("\n");
}

void printAll2(fl * floor2){
    printf("[����]============================================\n");
    for(int i = 0; i < 10;i++){
    	printf("[   %s  ] ",floor2->rooms[i].carNum);
   	}
   	printf("\n");
}

int isFull() {    // ������ ��ȭ �������� �˻��ϴ� �Լ�
	if(top >= SIZE - 1){   // top�� �ִ� ũ��� ���ų� Ŭ ���
    	return 1;  // 1 ��ȯ (true)
	}
	return 0;   // �׷��� ���� ��� 0 ��ȯ (false)
}

void put_car(fl * floor2){
    int n1;
	if(!isFull()){
    	top++;
    	printf("������ �̸��� �Է����ּ��� : ");
    	scanf("%s", floor2->rooms[top].carOwner);
		printf("�� ��ȣ�� �Է����ּ���: "); 
    	scanf("%s", floor2->rooms[top].carNum);
    	printf("������ �Ϸ��Ͽ����ϴ�!\n");
   	}
   	else {
    	printf("���������� ���� á���ϴ�.");
   	}
 }

int isEmpty() {    
	if(top == -1) {   
    	return 1;  
   	}
   	return 0;   
}

void pop(fl * floor2) {
	char test[100]={};
    if(!isEmpty()){
        printf("%s���� %s�� ������ �Ϸ��Ͽ����ϴ�!\n", floor2->rooms[top].carOwner, floor2->rooms[top].carNum);
        strcpy(floor2->rooms[top].carNum, test);
        top--;
   }
   else printf("�������� ����ֽ��ϴ�.\n");
}

int main(){
   	system("���� ���� ���α׷�");
   	system("color 8f");
	fl floor;
   	fl floor2;
	int answer, answer2, select;
    while(1){
	    printf("==================================================\n");
	    printf("0. ����\n");
	    printf("1. �Ϲ� ������\n");
	    printf("2. ���� ������\n"); 
	    printf("==================================================\n");
	    printf("> ��ȣ���� : ");
	    scanf("%d", &select);
	    if(select==1){
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
            	if(answer == 0){
					break;
        		}
        	}
    	}
        
       	else if(select==2){
          	while(1){
            	printMain2();
            	scanf("%d", &answer2);
            	switch(answer2){
                case 1:
                   	put_car(&floor2);
                   	break;
                case 2:
                   	pop(&floor2); 
                case 3:
                   	printAll2(&floor2);
                    break;
                case 0:
                   	printf("�ȳ���������!");
                    break;
                default :
                   	printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.\n");
            	}
            	if(answer2 == 0){
					break;
        		}
         	}
        }
       else if(select==0){
           printf("�ȳ���������!\n");
           break;
       }
       else{
           printf("�ٽ� �Է����ּ���.\n");
           continue;
      }
   }
}
