#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#define MAXSIZE 100

typedef struct
{
  char ch[MAXSIZE];
  int Len;
} String;

/*求串长度函数*/
int StrLength(String *S)
{
  int i = 0;
  while (S->ch[i] != '\0')
  {
    i++;
    S->Len = i;
    return (S->Len); //返回Len值，即串长度
  }
}

/*建立一个新串*/
void CreatStr(String *S)
{
  gets(S->ch);
  S->Len = StrLength(S);
}

/*求字串函数*/
int SubString(String *S, String *Sub, int pos, int len)
{
  int j;
  if (pos < 1 || pos > S->Len || len < 1 || len > S->Len - pos + 1)
  {
    Sub->Len = 0;
    printf("参数错误！\n");
    return 0;
  }
  else
  {
    for (j = 0; j < len; j++)
    {
      Sub->ch[j] = S->ch[pos + j - 1];
      Sub->ch[j] = '\0';
      Sub->Len = len;
      return 1;
    }
  }
}

/*在串s中删除从指定位置i开始连续的j个字符*/
int StrDelete(String *S, int i, int l)
{
  int k;
  if (i + 1 - 1 > S->Len)
  {
    printf("所要删除的字串超界！");
    return 0;
  }
  else
  {
    for (k = i + 1 - 1; k < S->Len; k++, i++)
    {
      S->ch[i - 1] = S->ch[k];
      S->Len = S->Len - 1;
      S->ch[S->Len] = '\0';
      return 1;
    }
  }
}

/*在串s中插入字串s1函数*/
int StrInsert(String *S, String *S1, int i)
{
  int k;
  if (i > S->Len + 1)
  {
    printf("插入位置错误！");
    return 0;
  }
  else if (S->Len + S1->Len > MAXSIZE)
  {
    printf("两串长度超过存储空间长度！");
    return 0;
  }
  else
  {
    for (k = S->Len - 1; k > i - 1; k--)
    {
      S->ch[S1->Len + k] = S->ch[k];
      for (k = 0; k < S1->Len; k++)
      {
        S->ch[i + k - 1] = S1->ch[k];
      }
      S->Len = S->Len + S1->Len;
      S->ch[S->Len] = '\0';
      return 1;
    }
  }
}

/*显示菜单子函数*/
void MenuString()
{
  printf("\n                串子系统");
  printf("\n============================================");
  printf("\n|           1-建立新串并显示该串及长度     |");
  printf("\n|           2-求子串                       |");
  printf("\n|           3-删除子串                     |");
  printf("\n|           4-插入子串                     |");
  printf("\n|           5-查找子串                     |");
  printf("\n|           6-比较两个串大小               |");
  printf("\n|           7-连接两个串                   |");
  printf("\n|           8-子串替换                     |");
  printf("\n|           0-返回                         |");
  printf("\n============================================");
  printf("\n请输入菜单号（0~8）：");
}

int main(int argc, char const *argv[])
{
  int i, len, flag;
  String x, y, z;
  String *S = &x, *S1 = &y, *S2 = &z;
  char ch1, ch2, a;
  ch1 = 'y';
  while (ch1 == 'y' || ch1 == 'Y')
  {
    MenuString();
    scanf("%c", &ch2);
    getchar();
    switch (ch2)
    {
    case '1':
      printf("请输入一个字符串：");
      CreatStr(S);
      printf("该串值为：");
      if (S->ch[0] == '\0')
      {
        printf("空串！");
      }
      else
      {
        puts(S->ch);
        printf("该串的长度为：%d", S->Len);
      }
      break;
    case '2':
      printf("请输入从第几个字符开始求子串：");
      scanf("%d", &i);
      printf("请输入取出的子串长度：");
      scanf("%d", &len);
      flag = SubString(S, S1, i, len);
      if (flag)
      {
        printf("求子串成功，原来主串为：");
        puts(S->ch);
        printf("所得子串为：");
        puts(S1->ch);
      }
      else
      {
        printf("求子串失败！");
      }
      break;
    case '3':
      printf("请输入要删除的子串的起始位置：");
      scanf("%d", &i);
      printf("请输入要删除的字串的长度：");
      scanf("%d", &len);
      printf("原来串为：");
      puts(S->ch);
      if (flag = StrDelete(S, i, len))
      {
        printf("删除字串成功，删除后的新的串为：");
        puts(S->ch);
      }
      else
      {
        printf("删除字串失败！");
      }
      break;
    case '4':
      printf("请输入要插入字串在主串中的位置：");
      scanf("%d", &i);
      printf("请输入一个字串：");
      getchar();
      CreatStr(S1);
      printf("原来主串为：");
      puts(S->ch);
      if (flag = StrInsert(S, S1, i))
      {
        printf("插入字串成功！插入后的新的子串为：");
        puts(S->ch);
      }
      else
      {
        printf("插入字串失败！");
      }
      break;
    case '5':

      break;
    default:
      break;
    }
  }

  return 0;
}
