#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAXSIZE 100
typedef float KeyType;

typedef struct
{
  char id[20];
  char name[20];
  float grade;
} student;

//表的建立
void CreateList(student r[], int n)
{
  int i;
  printf("请输入%d位学生的信息(学号--姓名--成绩):\n", n);
  for (i = 1; i <= n; i++) //从1开始，是因为之后查找算法第0位要设置监视哨
  {
    printf("请输入第%d个学生的信息:", i);
    scanf("%s %s %f", &r[i].id, &r[i].name, &r[i].grade);
  }
}

//遍历表
void DispList(student r[], int n)
{
  int i;
  printf("现在表中的信息为:\n");
  for (i = 1; i <= n; i++)
  {
    printf("%s--%s--%.2f\n", r[i].id, r[i].name, r[i].grade);
  }
}

// 2.顺序查找-一条
void SeqSearch(student r[], int n, KeyType k)
{
  int i = n;
  printf("设置监视哨输入(成绩):");
  scanf("%f", &r[0].grade);
  while (r[i].grade != k)
  {
    i--;
  }
  printf("顺序查找的结果为(一条):%s--%s--%.2f", r[i].id, r[i].name, r[i].grade);
}

// 3.顺序查找-全部
void SeqAllSearch(student r[], int n, KeyType k)
{
  int i = n;
  printf("设置监视哨输入(成绩):");
  scanf("%f", &r[0].grade);
  printf("顺序查找的结果为(全部):\n");
  for (i; i > 0; i--)
  {
    if (r[i].grade == k)
    {
      printf("%s--%s--%.2f\n", r[i].id, r[i].name, r[i].grade);
    }
  }
}

//给数组排序
void BubbleSort(student r[], int n)
{
  int i, j;
  student temp; //定义一个中间变量
  for (i = 1; i < n; i++)
  { //进行每趟比较
    for (j = 1; j < n - i; j++)
    { //每趟交换的次数
      if (r[j].grade > r[j + 1].grade)
      {              //拿两者的分数进行比较
        temp = r[j]; //此时这里为什么不带.grade呢，因为不带就相当于把当前的下标值的三个数据都移动
        r[j] = r[j + 1];
        r[j + 1] = temp;
      }
    }
  }
}

// 4.折半查找-一条
int BinSearch(student r[], int n, KeyType k)
{
  int low, high, mid;
  low = 1;
  high = n;           //置区间初值
  while (low <= high) //查找区间不为空时
  {
    mid = (low + high) / 2;
    if (k == r[mid].grade)
    {
      return mid; //找到待查元素
    }
    else if (k < r[mid].grade)
    {
      high = mid - 1; //未找到，继续在前半区间进行查找
    }
    else
    {
      low = mid + 1; // 条件相当于k>r[mid].grade 未找到，进行在后半区间进行查找
    }
    return 0;
  }
}

// 5.折半查找-全部
void BinAllSearch(student r[], int n, KeyType k)
{
  int low, high, mid, i;
  low = 1;
  high = n;           //置区间初值
  while (low <= high) //查找区间不为空时
  {
    mid = (low + high) / 2;
    if (k == r[mid].grade)
    {
      printf("折半查找的结果为(全部):%s--%s--%.2f\n", r[mid].id, r[mid].name, r[mid].grade);
      for (i = mid - 1; i > 0; i--) // mid左边的值
      {
        if (k == r[i].grade)
        {
          printf("折半查找的结果为(全部):%s--%s--%.2f\n", r[i].id, r[i].name, r[i].grade);
        }
      }

      for (i = mid + 1; i <= n; i++)
      { // mid右边的值
        if (k == r[i].grade)
        {
          printf("折半查找的结果为(全部):%s--%s--%.2f", r[i].id, r[i].name, r[i].grade);
        }
      }
      break;
    }
    else if (k < r[mid].grade)
    {
      high = mid - 1; //未找到，继续在前半区间进行查找
    }
    else
    {
      low = mid + 1; // 条件相当于k>r[mid].grade 未找到，进行在后半区间进行查找
    }
  }
}

/*显示菜单子函数*/
void MenuStack()
{
  printf("\n                查找子系统");
  printf("\n============================================");
  printf("\n|           1-建立查找表                   |");
  printf("\n|           2-顺序查找-一条                |");
  printf("\n|           3-顺序查找-全部                |");
  printf("\n|           4-折半查找-一条                |");
  printf("\n|           5-折半查找-全部                |");
  printf("\n|           0-返回                         |");
  printf("\n============================================");
  printf("\n请输入菜单号（0~5）：");
}

int main(int argc, char const *argv[])
{
  student r[MAXSIZE];
  int n; //学生人数
  char ch1, ch2, a;
  int button = 0;
  ch1 = 'y';
  while (ch1 == 'y' || ch1 == 'Y')
  { /*控制循环*/
    MenuStack();
    scanf("%c", &ch2);
    getchar();
    switch (ch2)
    {
    case '1':
      // 1.建立查找表
      printf("请输入要录入信息的学生人数:");
      scanf("%d", &n);
      CreateList(r, n); //建立
      DispList(r, n);   //查找
      button = 1;
      printf("建立查找表完成！");
      break;
    case '2':
      // 2.顺序查找-一条
      if (button == 1)
      {
        SeqSearch(r, 5, 80);
      }
      else
      {
        printf("请先建立查找表！");
      }
      break;
    case '3':
      // 3.顺序查找-全部
      if (button == 1)
      {
        SeqAllSearch(r, 5, 80);
      }
      else
      {
        printf("请先建立查找表！");
      }
      break;
    case '4':
      // 4.折半查找-一条
      if (button == 1)
      {
        BubbleSort(r, n);
        int num = BinSearch(r, n, 80.0);
        if (num != 0)
        {
          printf("折半查找的结果为(一条):%s--%s--%.2f", r[num].id, r[num].name, r[num].grade);
        }
        else
        {
          printf("未找到结果!");
        }
      }
      else
      {
        printf("请先建立查找表！");
      }
      break;
    case '5':
      // 5.折半查找-全部
      if (button == 1)
      {
        BubbleSort(r, n);
        BinAllSearch(r, n, 80);
      }
      else
      {
        printf("请先建立查找表！");
      }
      break;
    case '0':
      ch1 = 'n';
      break;
    default:
      printf("输入有误，请输入0~5进行选择！");
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
