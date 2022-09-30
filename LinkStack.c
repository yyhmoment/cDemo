#define _CRT_SECURE_NO_WARNINGS
/*栈子系统*/
#include <stdio.h>
#include <malloc.h>
#define MAXSIZE 100;
typedef int DataType;
typedef struct stacknode
{
  DataType data;
  struct stacknode *next;
} LinkStack;

/*初始化链栈函数*/
LinkStack *InitStack()
{
  LinkStack *S;
  S = NULL;
  return S; /*初始化栈为空*/
}

/*判断栈空函数*/
int EmptyStack(LinkStack *S)
{
  if (S == NULL)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

/*进栈函数*/
LinkStack *Push(LinkStack *S, DataType x)
{
  LinkStack *p;
  p = (LinkStack *)malloc(sizeof(LinkStack));
  p->data = x;
  p->next = S;
  S = p;    /*新结点作为栈顶*/
  return S; /*返回栈顶*/
}

/*出栈函数*/
LinkStack *Pop(LinkStack *S, DataType *x)
{
  LinkStack *p;
  if (EmptyStack(S))
  { /*调用判空函数，判断栈是否为空*/
    printf("\t栈空，不能出栈！");
    return NULL;
  }
  else
  {
    *x = S->data; /*栈顶元素取出赋给x*/
    p = S;        /*p结点指向原栈顶S*/
    S = S->next;  /*原栈顶S指向其下一个结点*/
    free(p);      /*释放原栈顶空间*/
    return S;     /*返回栈顶S*/
  }
}

/*获取栈顶元素函数*/
int GetTop(LinkStack *S, DataType *x)
{
  if (EmptyStack(S))
  {
    printf("栈空！");
    return 0;
  }
  else
  {
    *x = S->data; /*栈顶元素赋值给变量x*/
    return 1;
  }
}

/*显示栈中元素*/
void ShowStack(LinkStack *S)
{
  LinkStack *p = S;
  if (p == NULL)
  {
    printf("\t栈空！");
  }
  else
  {
    printf("从栈顶元素起栈中各元素为：");
    while (p != NULL)
    {
      printf("%d", p->data);
      p = p->next; /*移至下一个元素*/
    }
  }
}

/*十进制转换成任意进制数*/
void D_B(LinkStack *S, DataType x, DataType num)
{
  if (num == 2)
  {
    while (x)
    {
      S = Push(S, x % 2); /*余数入栈*/
      x /= 2;             /*被除数data整除以2，得到新的被除数*/
    }
    printf("转换后的二进制为：");
    while (!EmptyStack(S))
    {
      S = Pop(S, &x); /*依次从栈中弹出每一个余数并输出*/
      printf("%d", x);
    }
  }
  else if (num == 8)
  {
    while (x)
    {
      S = Push(S, x % 8); /*余数入栈*/
      x /= 8;             /*被除数data整除以8，得到新的被除数*/
    }
    printf("转换后的八进制为：");
    while (!EmptyStack(S))
    {
      S = Pop(S, &x); /*依次从栈中弹出每一个余数并输出*/
      printf("%d", x);
    }
  }
  else if (num == 16)
  {
    while (x)
    {
      S = Push(S, x % 16); /*余数入栈*/
      x /= 16;             /*被除数data整除以16，得到新的被除数*/
    }
    printf("转换后的十六进制为：");
    while (!EmptyStack(S))
    {
      S = Pop(S, &x); /*依次从栈中弹出每一个余数并输出*/
      printf("%d", x);
    }
  }
}

/*显示菜单子函数*/
void MenuStack()
{
  printf("\n                栈子系统");
  printf("\n============================================");
  printf("\n|           1-初始化栈                     |");
  printf("\n|           2-入栈操作                     |");
  printf("\n|           3-出栈操作                     |");
  printf("\n|           4-求栈顶元素                   |");
  printf("\n|           5-显示栈中元素                 |");
  printf("\n|           6-10到n进制数转换              |");
  printf("\n|           0-返回                         |");
  printf("\n============================================");
  printf("\n请输入菜单号（0~6）：");
}
int main(int argc, char const *argv[])
{
  int i, n, flag;
  LinkStack *S;
  DataType x, num; /*num为第6点的进制数*/
  char ch1, ch2, a;
  ch1 = 'y';
  while (ch1 == 'y' || ch1 == 'Y')
  { /*控制循环*/
    MenuStack();
    scanf("%c", &ch2);
    getchar();
    switch (ch2)
    {
    case '1':
      S = InitStack();
      printf("栈的初始化完成！");
      break;
    case '2':
      /*进栈函数*/
      if (S == NULL || S->next != NULL) /*判断是否初始化栈和S指向的next是否为空*/
      {
        printf("请输入要入栈的元素个数：");
        scanf("%d", &n);
        printf("请输入%d个整数进行入栈：", n);
        for (i = 0; i < n; i++)
        {
          scanf("%d", &x);
          S = Push(S, x);
        }
        printf("入栈成功！");
      }
      else
      {
        printf("请先初始化栈，再做此入栈操作！");
        break;
      }
      break;
    case '3':
      /*出栈函数*/
      if (S == NULL || S->next != NULL)
      {
        printf("请输入要出栈的元素个数：");
        scanf("%d", &n);
        printf("出栈的元素为：");
        for (i = 0; i < n; i++)
        {
          S = Pop(S, &x);
          if (S != NULL)
          {
            printf("%5d", x);
          }
        }
      }
      else
      {
        printf("请先初始化栈，再做此出栈操作！");
        break;
      }
      break;
    case '4':
      /*求栈顶元素*/
      if (S == NULL || S->next != NULL)
      {
        if (flag = GetTop(S, &x))
        {
          printf("当前的栈顶元素值为：%d", x);
        }
      }
      else
      {
        printf("请先初始化栈，再做此求栈顶操作！");
        break;
      }
      break;
    case '5':
      /*显示栈中元素*/
      if (S == NULL || S->next != NULL)
      {
        ShowStack(S);
      }
      else
      {
        printf("请先初始化栈，再做此显示栈元素操作！");
        break;
      }
      break;
    case '6':
      /*10到n进制转换*/
      S = InitStack();
      printf("请输入十进制正整数：");
      scanf("%d", &x);
      printf("请输入需要转换的进制数：");
      scanf("%d", &num);
      D_B(S, x, num);
      break;
    case '0':
      ch1 = 'n';
      break;
    default:
      printf("输入有误，请输入0~6进行选择！");
    }
    if (ch2 != '0')
    {
      printf("\n按回车键继续，按任意键返回主菜单！\n");
      a = getchar();
      if (a != '\xA')
      {
        getchar();
        ch1 = 'n'; /*将ch1制为n，即while循环条件不符而结束*/
      }
    }
  }

  return 0;
}
