#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
typedef int DataType;   /*����һ��DataTypeΪint����*/
typedef struct linknode /*����һ��������ṹ��*/

{
  DataType data;         /*�������������*/
  struct linknode *next; /*�������ָ����*/
} LinkList;

/*����һ����ʼ������ĺ���*/
LinkList *InitList()
{
  LinkList *head;                              /*ͷ���*/
  head = (LinkList *)malloc(sizeof(LinkList)); /*��̬����һ�����ռ�*/
  head->next = NULL;
  return head; /*ͷ���Lָ����Ϊ�գ���ʾ������*/
}

/*��ʾ�˵��Ӻ���*/
void MenuLine()
{
  printf("\n���Ա���ϵͳ");
  printf("\n=========================================");
  printf("\n|           1-����                       |");
  printf("\n|           2-����                       |");
  printf("\n|           3-ɾ��                       |");
  printf("\n|           4-��λ�ò���                  |");
  printf("\n|           5-��Ԫ�ز���                  |");
  printf("\n|           6-���                      |");
  printf("\n|           0-����                        |");
  printf("\n=========================================");
  printf("\n������˵��ţ�0~6����");
}

int main()
{
  MenuLine();
  return 0;
}
