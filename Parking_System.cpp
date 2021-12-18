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
    printf("1. 주차\n");
    printf("2. 출차\n");
    printf("3. 주차 위치 확인\n");
    printf("4. 주차현황 출력\n"); 
    printf("0. 종료\n");
    printf("==================================================\n");
    printf("> 번호선택 : ");
}
void printMain2(void)
{
    printf("==================================================\n");
    printf("1. 주차\n");
    printf("2. 출차\n");
    printf("3. 주차현황 출력\n"); 
    printf("0. 종료\n");
    printf("==================================================\n");
    printf("> 번호선택 : ");
}
void menu1(fl * floor){
    int n;
    printf("주차 할 번호를 선택해주세요 (1~10까지 입력): ");
    while(1){
        scanf("%d", &n);
        if(count[n-1] == 1){
            printf("번호를 다시 선택해주세요^^ : ");
            continue; 
        }
        count[n-1]++;
        if(n>=1&&n<11){
           printf("본인의 이름을 입력해주세요 : ");
           scanf("%s",floor->rooms[n-1].carOwner);
           printf("차 번호를 입력해주세요: "); 
           scanf("%s", floor->rooms[n-1].carNum);
           printf("주차를 완료하였습니다!\n");
              break;
        }else{
            printf("번호를 다시 입력해주세요^^ : ");
            continue; 
        }
    }
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
        if(!strcmp(name, floor->rooms[i].carOwner)&&!strcmp(number, floor->rooms[i].carNum)){
            printf("출차를 완료하였습니다!\n");
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
    printf("본인의 이름을 입력해주세요 : ");
    scanf("%s", name);
    printf("차 번호를 입력해주세요 : "); 
    scanf("%s", number);
    for(int i = 0; i<10; i++){
    	if(!strcmp(name, floor->rooms[i].carOwner)&&!strcmp(number, floor->rooms[i].carNum))
        	printf("%s님의 주차 위치는 %d번입니다!!!!!!!!!!!!\n",floor->rooms[i].carOwner, i+1);
    }
}

void printAll(fl * floor){
    printf("[B1층]============================================\n");
    for(int i = 0; i < 10;i++){
    	if(i == 5)printf("\n");
      	printf("[   %s  ] ",floor->rooms[i].carNum);
   	}
   	printf("\n");
}

void printAll2(fl * floor2){
    printf("[지상]============================================\n");
    for(int i = 0; i < 10;i++){
    	printf("[   %s  ] ",floor2->rooms[i].carNum);
   	}
   	printf("\n");
}

int isFull() {    // 스택이 포화 상태인지 검사하는 함수
	if(top >= SIZE - 1){   // top이 최대 크기와 같거나 클 경우
    	return 1;  // 1 반환 (true)
	}
	return 0;   // 그렇지 않을 경우 0 반환 (false)
}

void put_car(fl * floor2){
    int n1;
	if(!isFull()){
    	top++;
    	printf("본인의 이름을 입력해주세요 : ");
    	scanf("%s", floor2->rooms[top].carOwner);
		printf("차 번호를 입력해주세요: "); 
    	scanf("%s", floor2->rooms[top].carNum);
    	printf("주차를 완료하였습니다!\n");
   	}
   	else {
    	printf("주차공간이 가득 찼습니다.");
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
        printf("%s님의 %s번 출차를 완료하였습니다!\n", floor2->rooms[top].carOwner, floor2->rooms[top].carNum);
        strcpy(floor2->rooms[top].carNum, test);
        top--;
   }
   else printf("주차장이 비어있습니다.\n");
}

int main(){
   	system("주차 관리 프로그램");
   	system("color 8f");
	fl floor;
   	fl floor2;
	int answer, answer2, select;
    while(1){
	    printf("==================================================\n");
	    printf("0. 종료\n");
	    printf("1. 일반 주차장\n");
	    printf("2. 스택 주차장\n"); 
	    printf("==================================================\n");
	    printf("> 번호선택 : ");
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
	                    printf("안녕히가세요!\n");
	                    break;
	                default :
	                    printf("잘못 입력하셨습니다. 다시 입력해주세요.\n");
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
                   	printf("안녕히가세요!");
                    break;
                default :
                   	printf("잘못 입력하셨습니다. 다시 입력해주세요.\n");
            	}
            	if(answer2 == 0){
					break;
        		}
         	}
        }
       else if(select==0){
           printf("안녕히가세요!\n");
           break;
       }
       else{
           printf("다시 입력해주세요.\n");
           continue;
      }
   }
}
