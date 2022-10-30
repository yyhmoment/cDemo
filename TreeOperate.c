#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define MAX 100
int count = 0; /*定义计算结点个数的变量*/
typedef struct tnode
{
  char data;                     /*二叉树结点的值*/
  struct tnode *lchild, *rchild; /*左、右孩子结点指针*/
} BT;

BT *CreateBTree()
{
  /*以先序序列输入结点的值，创建二叉链表*/
  BT *t;
  char ch;
  scanf("%c", &ch);
  getchar();
  if (ch == '0')
    t = NULL;
  else
  {
    t = (BT *)malloc(sizeof(BT));
    t->data = ch;
    printf("请输入%c结点的左孩子结点：", t->data);
    t->lchild = CreateBTree();
    printf("请输入%c结点的右孩子结点：", t->data);
    t->rchild = CreateBTree();
  }
  return t;
}

void ShowBTree(BT *T)
{
  /*用广义表表示法显示二叉树子函数*/
  if (T != NULL) /*当二叉树非空时*/
  {
    printf(" % c", T->data);                    /*输入该结点数据域*/
    if (T->lchild != NULL || T->rchild != NULL) /*若其左子树非空*/
    {
      printf("(");          /*输出左括号*/
      ShowBTree(T->lchild); /*递归调用该函数输出其左子树各结点*/
      printf(",");          /*输出逗号*/
      ShowBTree(T->rchild); /*递归调用该函数输出其右子树各结点*/
      printf(")");
    }
    else if (T->rchild != NULL) /*若其左子树为空，右子树不为空*/
    {
      printf("(");           /*输出左括号*/
      ShowBTree(T->lchild);  /*递归调用该函数输出其左子树各结点*/
      if (T->rchild != NULL) /*若其右子树非空*/
      {
        printf(",");          /*输出逗号*/
        ShowBTree(T->rchild); /*递归调用该函数输出其右子树各节点*/
      }
      printf(")");
    }
  }
}

void Leafnum(BT *T)
{
  /*2.求二叉树叶子结点数*/
  if (T) /*若树不为空*/
  {
    if (T->lchild == NULL && T->rchild == NULL)
      count++;          /*全局变量count为计数值，其初始值为0*/
    Leafnum(T->lchild); /*递归统计T的左子树叶子结点数*/
    Leafnum(T->rchild); /*递归统计T的右子树叶子结点数*/
  }
}

void Nodenum(BT *T)
{
  /*3.求二叉树的总结点数*/
  if (T) /*若树不为空*/
  {
    count++;            /*全局变量count为计数值，其初值为0*/
    Nodenum(T->lchild); /*递归统计T的左子树结点树*/
    Nodenum(T->rchild); /*递归统计T的右子树结点树*/
  }
}

int TreeDepth(BT *T)
{
  /*4.求二叉树深度*/
  int ldep = 0, rdep = 0; /*定义两个整型变量，用以存放左、右子树的深度*/
  if (T == NULL)
    return 0;
  else
  {
    ldep = TreeDepth(T->lchild); /*递归统计T的左子树深度*/
    rdep = TreeDepth(T->rchild); /*递归统计T的右子树深度*/
    if (ldep > rdep)
      return ldep + 1;
    else
      return rdep + 1;
  }
}

void ChangeLRtree(BT *T)
{
  if (T == NULL)
  {
    return;
  }
  else
  {
    BT *temp = T->lchild;    //将右孩子结点值赋给temp
    T->lchild = T->rchild;   //将左孩子结点值赋给右孩子结点值域
    T->rchild = temp;        //将temp中保存的右孩子的值赋值给左孩子结点值域
    ChangeLRtree(T->lchild); //递归
    ChangeLRtree(T->rchild);
  }
}

void MenuTree()
{
  /*显示菜单子函数*/
  printf("\n                 二叉树子系统");
  printf("\n====================================================================");
  printf("\n|         1——用先序方法建立二叉树，并用广义表表示法显示二叉树结构 |");
  printf("\n|         2——求叶子结点数目                                       |");
  printf("\n|         3——求二叉树总结点数目                                   |");
  printf("\n|         4——求树深度                                             |");
  printf("\n|         5——交换二叉树每一结点的左右子树                         |");
  printf("\n|         0——返回                                                 |");
  printf("\n====================================================================");
  printf("\n 请输入菜单号（0——5：）");
}

main(int argc, char const *argv[])
{
  BT *T = NULL;
  char ch1, ch2, a;
  ch1 = 'y';
  int aa = 0;
  while (ch1 == 'y' || ch1 == 'Y')
  {
    MenuTree();
    scanf("%c", &ch2);
    getchar();
    switch (ch2)
    {
    case '1':
      // 建立一个新二叉树
      printf("请输入先序序列输入二叉树的结点：\n");
      printf("说明：输入结点后按回车键('0'表示后继结点为空)：\n");
      printf("请输入根节点：");
      T = CreateBTree();
      printf("二叉树成功建立！\n");
      int aa = 1;
      printf("广义表法显示该二叉树为：");
      ShowBTree(T);
      break;
    case '2':
      // 求叶子结点数目
      if (aa == 1)
      {
        count = 0;
        Leafnum(T);
        printf("该二叉树有%d个叶子。", count);
      }
      else
      {
        printf("请先建立一个二叉树！");
        break;
      }
      break;
    case '3':
      // 求二叉树总结点数目
      if (aa == 1)
      {
        count = 0;
        Nodenum(T);
        printf("该二叉树共有%d个结点。", count);
      }
      else
      {
        printf("请先建立一个二叉树！");
        break;
      }
      break;
    case '4':
      // 求树深度
      if (aa == 1)
      {
        printf("该二叉树的深度是%d。", TreeDepth(T));
      }
      else
      {
        printf("请先建立一个二叉树！");
        break;
      }
      break;
    case '5':
      // 5.交换二叉树每一结点的左右子树
      if (aa == 1)
      {
        ChangeLRtree(T);
        printf("交换后的二叉树广义表显示为：");
        ShowBTree(T);
      }
      else
      {
        printf("请先建立一个二叉树！");
        break;
      }
      break;
    case '0': /*返回*/
      ch1 = 'n';
      break;
    default:
      printf("输入有误，请输入0——5进行选择！");
    }
    if (ch2 != '0')
    {
      printf("\n按回车键继续，按任意键返回主菜单！\n");
      a = getchar();
      if (a != '\xA')
      {
        getchar();
        ch1 = 'n';
      }
    }
  }
  return 0;
}