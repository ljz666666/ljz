#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#define N 20

struct teachers

{

unsigned long num;//职工号

char name[N];//姓名

char sex[N];//性别

char title[N];//职称

char lesson[N];//3门讲授课程名称

int score;//教学效果综合评分

};//结构体

void menu();

int reads(struct teachers tea[N]);//读取教师文件中的内容

void save(struct teachers tea[N],int n);//输入保存数据

void add();//添加教师信息

void show();//显示教师信息

void order_num();//按职工号进行排序

void order_score();// 按教学效果综合评分进行排序

void query_name();//按姓名查找教关信息

void query_lesson();//按课程查找教师信息

void modify();//修改教师信息

void backspace();//删除教师信息

void quit();//退出系统.....................................................函数说明

void main()

{

system("color 90");
printf(" *************************学院信息管理系统欢迎您 ***********************\n");
printf("    ==============================================================\n");
printf("    ┃**********************************************************┃\n");
printf("    ┃***____________________________________________________***┃\n");
printf("    ┃***|**************************************************|***┃\n");
printf("    ┃***|****                                          ****|***┃\n");
printf("    ┃***|****        欢迎使用学院信息管理系统        ****|***┃\n");
printf("    ┃***|****                                          ****|***┃\n");
printf("    ┃***|****                                          ****|***┃\n");
printf("    ┃***|****            制作人      栾佳哲          ****|***┃\n");
printf("    ┃***|****                                          ****|***┃\n");
printf("    ┃***|****                  2020.07.01              ****|***┃\n");
printf("    ┃***|****                                          ****|***┃\n");
printf("    ┃***|**************************************************|***┃\n");
printf("    ┃***----------------------------------------------------***┃\n");
printf("    ┃**********************************************************┃\n");
printf("  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

printf("\n 请按任意键进入系统 \n");

getch();

int n;

while(1)

{

menu();

printf("\n 请输入您要选择的操作序号，按回车键确认：");

scanf("%d",&n);
getchar();
switch(n)

{

case 1: add();break;

case 2: show();break;

case 3: order_num();break;

case 4: order_score();break;

case 5: query_name();break;

case 6: query_lesson();break;

case 7: modify();break;

case 8: backspace();break;

case 0: quit();break;

default:  printf("输入错误，请输入列表中存在的序号！\n ");

}

}

}

void menu()

{    printf("\n");

printf("\n");

printf("\n");

printf("      ************************* 学院教学信息管理系统************************ \n");
printf("    ============================================================================\n");
printf("  || **********************************主菜单******************************** ||\n");
printf("  ||                              1  添加教师数据信息                        ||\n");
printf("  ||                              2  显示教师数据信息                        ||\n");
printf("  ||                              3  按职工号进行排序                        ||\n");
printf("  ||                              4  按教学效果综合评分进行排序              ||\n");
printf("  ||                              5  按教师姓名查询教师信息                  ||\n");
printf("  ||                              6  按教师课程查询教师信息                  ||\n");
printf("  ||                              7  修改教师信息                            ||\n");
printf("  ||                              8  删除教师信息                            ||\n");
printf("  ||                              0  退出系统                                ||\n");
printf("  ******************************************************************************\n");
printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

}//.........................................................................................................主菜单

int  reads(struct teachers tea[N]) // 读取教师文件中的信息

{


FILE *fp;

int i=0;

if((fp=fopen("d:\\teachers.txt","r"))==NULL)
{

printf("文件打开失败！\n");
return 0;

}

else

{

for(i=0;!feof(fp);i++)
fscanf(fp,"%lu %s %s %s %s %d\n",&tea[i].num,&tea[i].name,&tea[i].sex,&tea[i].title,&tea[i].lesson,&tea[i].score);


}

fclose(fp);

return i;

}

void add()/*添加教师信息*/

{

FILE *fp;

int n,i;
struct teachers tea;
if((fp=fopen("d:\\teachers.txt","a"))==NULL)  //如果文件已经存在，可以追加教师信息

{

if((fp=fopen("d:\\teachers.txt","w"))==NULL) // 文件不存在时，创建新文件，输入教师信息

{

printf("文件打开失败！\n");

return;

}

}

printf("请输入要添加的教师的数量，按回车键确认：");

scanf("%d",&n);

for(i=0;i<n;i++)

{

printf("\n请输入第%d个教师的工号、姓名，用空格分开，并按回车键确认：\n",i);
scanf("%lu%s",&tea.num,&tea.name);
printf("\n请输入第%d个教师的性别、职称、讲授课程名称、教学效果综合评分，用空格分开，并按回车键确认：\n",i);
scanf("%s%s%s%d",&tea.sex,&tea.title,&tea.lesson,&tea.score);
fprintf(fp,"%lu %s %s %s %s %d\n",tea.num,tea.name,tea.sex,tea.title,tea.lesson,tea.score);


}

fclose(fp);

printf(".............................................................》保存成功！\n");
printf(".............................................................》请按任意键回到主菜单\n");

getch();

}

void show()/*显示教师信息*/

{

struct teachers tea[N];

int i,n;

n=reads(tea);

printf("*********************所有的教师信息如下************************\n\n");
printf("  序号 || 职工号 || 姓名 || 性别 || 职称 ||    课程    ||  评分        \n");
printf("***************************************************************\n");

for(i=0;i<n;i++)

printf("\n%3d  %lu  %4s  %1s  %5s  %20s  %3d\n",i+1,tea[i].num,tea[i].name,tea[i].sex,tea[i].title ,tea[i].lesson,tea[i].score);
printf("***************************************************************\n");
printf(".............................................................》显示成功！\n");
printf(".............................................................》请按任意键回到主菜单\n");

getch();

}

void order_num()  //按教工号排序教师相关记录

{

struct teachers tea[N];

int z=1;

int    i,n,j;

int t;
unsigned long m[20];
n=reads(tea);
for(i=0;i<n;i++)

{

m[i]=tea[i].num;

}

for(i=0;i<n-1;i++)

for(j=0;j<n-1;j++)

if(m[j]>m[j+1])

{

t=m[j];
m[j]=m[j+1];
m[j+1]=t;

}

printf("  序号 || 职工号 || 姓名 || 性别 || 职称 ||    课程    ||  评分        \n");
printf("***************************************************************\n");

for(i=0;i<n;i++)

{

for(j=0;j<n;j++)

if(tea[j].num==m[i])

{

printf("\n%3d  %lu  %4s  %1s  %5s  %20s  %3d\n",z++,tea[j].num,tea[j].name,tea[j].sex,tea[j].title ,tea[j].lesson,tea[j].score);

}

}

printf("***************************************************************\n");
printf("............................................................》排序成功！\n");
printf("...........................................................》请按任意键回到主菜单\n");

getch();

}

void order_score()  //按教学综合评分排序教师信息

{

struct teachers tea[N];

int z=1;

int    i,n,j;

int m[20],t;

n=reads(tea);

for(i=0;i<n;i++)

{

m[i]=tea[i].score;

}

for(i=0;i<n-1;i++)

for(j=0;j<n-1;j++)

if(m[j]<m[j+1])

{

t=m[j];
m[j]=m[j+1];
m[j+1]=t;

}

printf("  序号 || 职工号 || 姓名 || 性别 || 职称 ||    课程    ||  评分        \n");
printf("***************************************************************\n");

for(i=0;i<n;i++)

{

for(j=n;j>=0;j--)

if(tea[j].score==m[i])

{

printf("\n%3d  %lu  %4s  %1s  %5s  %20s  %3d\n",z++,tea[j].num,tea[j].name,tea[j].sex,tea[j].title ,tea[j].lesson,tea[j].score);

}

}

printf("***************************************************************\n");
printf("............................................................》排序成功！\n");
printf("...........................................................》请按任意键回到主菜单\n");
getch();

}

void query_name()  // 按教师姓名对教师信息查询

{

struct teachers tea[N];

char name[N];

int i,n;

bool flag=0;

n=reads(tea);

printf("\n请输入待查询的教师姓名，按回车键确认：\n");

scanf("%s",&name);

for(i=0;i<n;i++)

{

if(strcmp(name,tea[i].name)==0)

{

printf("  序号 || 职工号 || 姓名 || 性别 || 职称 ||    课程    ||  评分        \n");
printf("***************************************************************\n");
printf("\n%3d  %lu  %4s    %1s  %5s  %20s  %3d\n",i+1,tea[i].num,tea[i].name,tea[i].sex,tea[i].title ,tea[i].lesson,tea[i].score);
printf("***************************************************************\n");
printf(".............................................................》查询成功！\n");
printf(".............................................................》请按任意键回到主菜单\n");

flag=1;

getch();

}

}

if(flag==0)

{

printf("\n.............................................................》未找到相关信息！\n");
printf(".............................................................》请按任意键回到主菜单\n");
getch();

}

}

void query_lesson()  // 按教师课程对教师信息查询

{

struct teachers tea[N];

char lesson[N];

int i,n;

bool flag=0;

n=reads(tea);
printf("\n请输入待查询的教师课程，按回车键确认：\n");
scanf("%s",&lesson);

for(i=0;i<n;i++)

{

if(strcmp(lesson,tea[i].lesson)==0)

{

printf("  序号 || 职工号 || 姓名 || 性别 || 职称 ||    课程    ||  评分        \n");
printf("***************************************************************\n");
printf("\n%3d  %lu  %4s    %1s  %5s  %20s  %3d\n",i+1,tea[i].num,tea[i].name,tea[i].sex,tea[i].title ,tea[i].lesson,tea[i].score);
printf("***************************************************************\n");
printf(".............................................................》查询成功！\n");
printf(".............................................................》请按任意键回到主菜单\n");

flag=1;

getch();

}

}

if(flag==0)

{

printf("\n.............................................................》未找到相关信息！\n");
printf(".............................................................》请按任意键回到主菜单\n");

getch();

}

}

void modify()//修改教师信息

{

struct teachers tea[N];

FILE *fp;

fp=fopen("d:\\teachers.txt","ab");

int i,n;

bool flag=0;

n=reads(tea);

char m[N];

printf("请输入要修改的老师的名字：");

scanf("%s",&m);

for(i=0;i<n;i++)

fread(&tea[i],sizeof(struct teachers),1,fp);

for(i=0;i<n;i++)

{

if(strcmp(tea[i].name,m)==0)

{

printf("这是此老师原来的信息：\n");
printf("  序号 || 职工号 || 姓名 || 性别 || 职称 ||    课程    ||  评分        \n");
printf("***************************************************************\n");
printf("\n%3d  %lu  %4s    %1s  %5s  %20s  %3d\n",i+1,tea[i].num,tea[i].name,tea[i].sex,tea[i].title ,tea[i].lesson,tea[i].score);
printf("***************************************************************\n");
printf("请输入新信息：\n");
printf("\n请输入教师的工号、姓名，用空格分开，并按回车键确认：\n");
scanf("%lu%s",&tea[i].num,&tea[i].name);
printf("\n请输入教师的性别、职称、讲授课程名称、教学效果综合评分，用空格分开，并按回车键确认：\n");
scanf("%s%s%s%d",&tea[i].sex,&tea[i].title,&tea[i].lesson,&tea[i].score);

fclose(fp);

fp=fopen("d:\\teachers.txt","w");

fclose(fp);

fp=fopen("d:\\teachers.txt","ab");

for(i=0;i<n;i++)

{

fprintf(fp,"%lu %s %s %s %s %d",tea[i].num,tea[i].name,tea[i].sex,tea[i].title,tea[i].lesson,tea[i].score);
fprintf(fp,"\n");

}

fclose(fp);

flag=1;

printf(".............................................................》修改成功！\n");
printf(".............................................................》请按任意键回到主菜单\n");

getch();

}

}

if(flag==0)

{

printf("\n.............................................................》未找到相关信息！\n");
printf(".............................................................》请按任意键回到主菜单\n");
getch();

}

}

void backspace()//删除教师信息

{

struct teachers tea[N];

FILE *fp;

fp=fopen("d:\\teachers.txt","ab");

int i,n;

bool flag=0;
n=reads(tea);

char m[N];

printf("请输入要删除的老师的名字：");
scanf("%s",&m);
for(i=0;i<n;i++)
fread(&tea[i],sizeof(struct teachers),1,fp);
for(i=0;i<n;i++)

{

if(strcmp(tea[i].name,m)==0)

{

tea[i]=tea[i+1];

n--;

}

fclose(fp);
fp=fopen("d:\\teachers.txt","w");
fclose(fp);
fp=fopen("d:\\teachers.txt","ab");
for(i=0;i<n;i++)

{

fprintf(fp,"%lu %s %s %s %s %d",tea[i].num,tea[i].name,tea[i].sex,tea[i].title,tea[i].lesson,tea[i].score);
fprintf(fp,"\n");

}

fclose(fp);

flag=1;

printf(".............................................................》删除成功！\n");
printf(".............................................................》请按任意键回到主菜单\n");
getch();

}

if(flag==0)

{

printf("\n.............................................................》未找到相关信息！\n");
printf(".............................................................》请按任意键回到主菜单\n");
getch();

}

}

void quit()  //退出系统

{

char  a;

printf("你真的想退出学院教学信息管理系统么？\n");
printf("          是(Y)/否(N)              \n");

scanf("%c",&a);
getchar();


if(a=='Y'||a=='y')

{

printf("*******************************谢谢使用!*******************************\n");
printf("\n 请按任意键退出系统 \n");

exit(0);

}

}
