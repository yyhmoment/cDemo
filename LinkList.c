#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
typedef int DataType;   /*定义一个DataType为int类型*/
typedef struct linknode /*定义一个单链表结构体*/

{
  DataType data;         /*定义结点的数据域*/
  struct linknode *next; /*定义结点的指针域*/
} LinkList;

/*定义一个初始化链表的函数*/
LinkList *InitList()
{
  LinkList *head;                              /*头结点*/
  head = (LinkList *)malloc(sizeof(LinkList)); /*动态分配一个结点空间*/
  head->next = NULL;
  return head; /*头结点L指针域为空，表示空链表*/
}

/*显示菜单子函数*/
void MenuLine()
{
  printf("\n线性表子系统");
  printf("\n=========================================");
  printf("\n|           1-建立                       |");
  printf("\n|           2-插入                       |");
  printf("\n|           3-删除                       |");
  printf("\n|           4-按位置查找                  |");
  printf("\n|           5-按元素查找                  |");
  printf("\n|           6-求表长                      |");
  printf("\n|           0-返回                        |");
  printf("\n=========================================");
  printf("\n请输入菜单号（0~6）：");
}

int main()
{
  MenuLine();
  return 0;
}
