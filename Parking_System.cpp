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
    printf("1. ����\n");
    printf("2. ����\n");
    printf("3. ���� ��ġ Ȯ��\n");
    printf("4. ������Ȳ ���\n"); 
    printf("0. ����\n");
    printf("> ��ȣ���� : ");
}
//struct floorInfo input, 
void menu1(struct carInfo *car){
	printf("������ �̸��� �Է����ּ��� : ");
	scanf("%s", car->carOwner);
	printf("�� ��ȣ�� �Է����ּ��� : "); 
	scanf("%s", car->carNum);
	printf("������ ���� �������ּ��� : "); 
	scanf("%d", &car->floor);
	printf("���� �� ��ȣ�� �������ּ��� : ");
	scanf("%d", &car->number);
	printf("������ �Ϸ��Ͽ����ϴ�!");
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
            printf("������ ��");
        }
        else if (answer == '3')
        {
            printf("������ �٤�");
        }
        else if (answer == '4')
        {
            printf("������ ��22");
        }
        else if (answer == '0')
            break;
 
        else
        {
            printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.");
        }
    }
}

 

