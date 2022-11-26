#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 100 /*最大顶点数*/
typedef char VertexType;
int visited[MAX]; /*全局变量，访问数组*/

typedef struct node
{
  int adjvex;        /*邻接点数*/
  int info;          /*权值*/
  struct node *next; /*指向下一邻接点的指针域*/
} EdgeNode;          /*定义边表结点*/

typedef struct vexnode
{
  VertexType data;     /*顶点域*/
  EdgeNode *firstedge; /*指向第一条边结点*/
} VHeadNode;           /*定义顶点表结点*/

typedef struct
{
  VHeadNode adjlist[MAX]; /*邻接表头结点数组*/
  int n, e;               /*顶点数，边数*/
} AdjList;

/*生成无向网的邻接表函数*/
void CreateAGraph(AdjList *g, int flag)
{
  int i, j, k, w; /*定义i,j,k,w,w为权值*/
  EdgeNode *p;    /*定义边结点*/
  if (flag == 0)
  {
    printf("\n开始建立一个无向图:\n");
  }
  else
  {
    printf("\n开始建立一个有向图:\n");
  }
  printf("请输入图的顶点数：");
  scanf("%d", &g->n);
  printf("请输入图的边数：");
  scanf("%d", &g->e);
  printf("\n请输入图的各顶点信息：\n");
  for (i = 0; i < g->n; i++) /*生成有n个顶点的顶点表*/
  {
    printf("第%d个顶点信息：", i + 1);
    scanf("\n%c", &(g->adjlist[i].data)); /*读入顶点信息*/
    g->adjlist[i].firstedge = NULL;       /*点的边表头指针设为空*/
  }
  printf("\n请输入边的信息，输入格式为：序号1，序号2,权值（序号依次为0，1，2...)：\n");
  for (k = 0; k < g->e; k++)
  {
    printf("请输入第%d条边：", k + 1);
    scanf("\n%d,%d,%d", &i, &j, &w);
    /*将编号为i的结点添加到邻接表中*/
    p = (EdgeNode *)malloc(sizeof(EdgeNode)); /*为边结点开辟空间*/
    p->adjvex = j;                            /*给边结点的邻接表域赋值*/
    p->info = w;                              /*给边结点权重赋值*/
    p->next = g->adjlist[i].firstedge;        /*先将原先顶点vi边表头的结点指针存入新结点p的next指针域*/
    g->adjlist[i].firstedge = p;              /*再将新结点p插到顶点vi边表头*/
    /*将编号为j的结点添加到邻接表中*/
    if (flag == 0)
    {
      p = (EdgeNode *)malloc(sizeof(EdgeNode));
      p->adjvex = i;
      p->info = w;
      p->next = g->adjlist[j].firstedge; /*将新结点p插到vi边表头*/
      g->adjlist[j].firstedge = p;
    }
  }
}

/*输出图的邻接表函数*/
void DispAGraph(AdjList *g)
{
  int i;
  EdgeNode *p; /*定义边结点指针*/
  printf("\n图的邻接表表示如下：\n");
  for (i = 0; i < g->n; i++)
  {
    printf("%2d[%c]", i, g->adjlist[i].data); /*输出顶i点表结点的data*/
    p = g->adjlist[i].firstedge;              /*将p指向第一条边结点，即边链表的表头*/
    while (p != NULL)
    {
      printf("-->[%d,%2d]", p->adjvex, p->info);
      p = p->next;
    }
    printf("\n");
  }
}

/*链栈方式实现图的深度优先遍历*/

/*定义链栈*/
typedef struct stacknode /*链栈存储类型*/
{
  int data;               /*定义结点的数据域*/
  struct stacknode *next; /*定义结点的指针域*/
} LinkStack;

/*初始化链栈*/
LinkStack *InitStack()
{
  LinkStack *S;
  S = NULL;
  return S; /*初始化栈为空*/
}

/*判断链栈是否为空*/
int EmptyStack(LinkStack *S)
{
  if (S == NULL) /*栈为空*/
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

/*进栈函数*/
LinkStack *Push(LinkStack *S, int x)
{
  LinkStack *p;
  p = (LinkStack *)malloc(sizeof(LinkStack)); /*生成新结点*/
  p->data = x;                                /*将x放入新结点的数据域*/
  p->next = S;                                /*将新结点插入链表表头之前*/
  S = p;                                      /*新结点作为栈顶*/
  return S;                                   /*返回栈顶S*/
}

/*出栈函数*/
LinkStack *Pop(LinkStack *S, int *x)
{
  LinkStack *p;
  if (EmptyStack(S)) /*调用判空函数EmptyStack(S),判断栈是否为空*/
  {
    printf("\t栈空,不能出栈！");
    return NULL; /*栈空不能出栈*/
  }
  else /*栈不为空*/
  {
    *x = S->data; /*栈顶元素取出赋给x*/
    p = S;        /*p结点指向原栈顶S*/
    S = S->next;  /*原栈顶S指向其下一个结点*/
    free(p);      /*释放原栈顶空间*/
    return S;     /*返回栈顶S*/
  }
}

/*获取栈顶元素函数*/
int GetTOP(LinkStack *S, int *x)
{
  if (EmptyStack(S)) /*调用判空函数EmptyStack(S),判断栈是否为空*/
  {
    printf("栈空！");
    return 0;
  }
  else
  {
    *x = S->data; /*栈顶元素取出赋给x*/
    return 1;
  }
}

void DFS_linkstack(AdjList *g, int vi)
{ /*用邻接表存储的图以顶点vi开始深度优先遍历函数-用链栈实现*/
  EdgeNode *p;
  LinkStack *S;
  int x;
  S = InitStack();    /*初始化链栈*/
  printf("(%d,", vi); /*访问起始顶点并入栈*/
  printf("%c)", g->adjlist[vi].data);
  visited[vi] = 1;       /*设置该结点访问状态为1*/
  S = Push(S, vi);       /*压栈*/
  while (!EmptyStack(S)) /*当栈不空循环*/
  {
    GetTOP(S, &vi);               /*取栈顶元素*/
    p = g->adjlist[vi].firstedge; /*取栈顶顶点的邻接点*/
    while (p != NULL)             /*还有邻接点就挨个数*/
    {
      if (visited[p->adjvex]) /*如果这个邻接点被访问过*/
        p = p->next;          /*取下一个邻接点*/
      else                    /*如果这个邻接点没有访问过*/
      {
        vi = p->adjvex;     /*把这个邻接点当成新的起始顶点*/
        printf("(%d,", vi); /*访问起始顶点并入栈*/
        printf("%c)", g->adjlist[vi].data);
        visited[vi] = 1;
        S = Push(S, vi);
        break;
      }
    }
    if (p == NULL)
      S = Pop(S, &x); /*该顶点出栈*/
  }
}

/*链队列实现图的广度优先遍历*/
typedef struct qnode /*链队列存储类型*/
{
  int data;           /*定义结点的数据域*/
  struct qnode *next; /*定义结点的指针域*/
} LinkListQ;
typedef struct
{
  LinkListQ *front, *rear; /*定义队列的队头指针和队尾指针*/
} LinkQueue;               /*链队列的头指针类型*/

LinkListQ *InitQueue()
{ /*初始化链队列函数*/
  LinkQueue *Q;
  LinkListQ *p;
  Q = (LinkQueue *)malloc(sizeof(LinkQueue)); /*建立链队列头指针所指结点*/
  p = (LinkListQ *)malloc(sizeof(LinkListQ)); /*建立链队列的头结点*/
  Q->front = p;                               /*Q指针所指的front指针指向p*/
  Q->rear = p;                                /*Q指针所指的rear指针指向p*/
  return Q;
}

int EmptyQueue(LinkQueue *Q)
{                          /*判断队空函数*/
  if (Q->front == Q->rear) /*链队为空*/
    return 1;
  else
    return 0;
}

void InQueue(LinkQueue *Q, int x)
{ /*入队函数*/
  LinkListQ *p;
  p = (LinkListQ *)malloc(sizeof(LinkListQ)); /*生成新结点*/
  p->data = x;                                /*将x存入新结点的数据域*/
  p->next = NULL;
  Q->rear->next = p; /*将新结点插入链队列之后*/
  Q->rear = p;       /*将队尾指针指向队尾元素*/
}

int DeQueue(LinkQueue *Q, int *x)
{ /*出队函数*/
  LinkListQ *p;
  if (EmptyQueue(Q)) /*调用判空函数EmptyQueue（Q），判断队列是否为空*/
  {
    printf("队空，不能出队元素！");
    return 0;
  }
  else
  {
    p = Q->front->next;       /*p指向队头元素*/
    *x = p->data;             /*队头元素取出赋给x*/
    Q->front->next = p->next; /*队头指针的指针域存放新队头元素的地址*/
    if (p->next == NULL)      /*队列中只含有一个元素出队*/
      Q->rear = Q->front;     /*出队队尾指针指向队头指针，此时队空*/
    free(p);                  /*释放队头结点空间*/
    return 1;
  }
}

int GetFront(LinkQueue *Q, int *x)
{                    /*获取队头元素函数*/
  if (EmptyQueue(Q)) /*调用判空函数EmptyQueue（Q），判断队列是否为空*/
  {
    printf("队空，无队头元素！");
    return 0;
  }
  else /*队不为空*/
  {
    *x = Q->front->next->data; /*队头元素赋给变量x*/
    return 1;
  }
}

void BFS_linkqueue(AdjList *g, int vi)
{ /*用邻接表存储的图以顶点vi开始广度优先遍历函数*/
  int i, v, visited[MAX];
  LinkQueue *Q; /*定义链队列*/
  Q = InitQueue();
  EdgeNode *p;
  for (i = 0; i < g->n; i++) /*辅助的访问数组赋初值*/
    visited[i] = 0;
  printf("(%d,", vi); /*输出起始访问顶点*/
  printf("%c)", g->adjlist[vi].data);
  visited[vi] = 1;
  InQueue(Q, vi); /*将vi入队-链队实现*/
  while (Q->front != Q->rear)
  {
    DeQueue(Q, &v);              /*将对头元素出队，赋给顶点v-链队实现*/
    p = g->adjlist[v].firstedge; /*将顶点v的邻接边顶点指针给p*/
    while (p != NULL)
    {
      if (visited[p->adjvex] == 0) /*若未访问*/
      {
        visited[p->adjvex] = 1;                    /*访问数组该元素置1*/
        printf("(%d,", p->adjvex);                 /*输出该顶点编号*/
        printf("%c)", g->adjlist[p->adjvex].data); /*输出该顶点*/
        InQueue(Q, p->adjvex);                     /*将p所指的顶点入队-链队实现*/
      }
      p = p->next; /*p指针后移*/
    }
  }
}

/*显示菜单子函数*/
void MenuGraph()
{
  printf("\n                  图子系统");
  printf("\n  ======================================");
  printf("\n  |            1——更新邻接表           |");
  printf("\n  |            2——深度优先遍历         |");
  printf("\n  |            3——广度优先遍历         |");
  printf("\n  |            4——返回                 |");
  printf("\n  ======================================");
  printf("\n请输入菜单号（0-3）：");
}

int main() /*主函数*/
{
  int i, f;
  char ch1, ch2, a;
  AdjList g;
  ch1 = 'y';
  while ("ch1 == 'y' || ch1 == 'Y'")
  {
    MenuGraph();
    scanf("%c", &ch2);
    getchar();
    switch (ch2)
    {
    case '1':
      printf("要建立的是有向图（1）还是无向图（0），请输入（1或0）：");
      scanf("%d", &f);
      CreateAGraph(&g, f);
      DispAGraph(&g);
      break;
    case '2':
      printf("请输入开始进行深度优先遍历的顶点序号（序号从0开始）：");
      scanf("%d", &f);
      printf("\n从顶点%d开始的深度优先遍历序列为：\n", f);
      for (i = 0; i < g.n; i++)
        visited[i] = 0;
      // DFS(&g,f)
      DFS_linkstack(&g, f);
      break;
    case '3':
      printf("请输入开始进行广度遍历的顶点序号（序号从0开始）:");
      scanf("%d", &i);
      printf("\n从顶点%d开始的广度优先遍历序列为：\n", i);
      // BFS(&g,f)
      BFS_linkqueue(&g, f);
      break;
    case '0':
      ch1 = 'n';
      break;
    default:
      printf("输入有误，请输入0-3进行选择！");
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
}