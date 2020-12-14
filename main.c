#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#define N 20

struct teachers

{

unsigned long num;//ְ����

char name[N];//����

char sex[N];//�Ա�

char title[N];//ְ��

char lesson[N];//3�Ž��ڿγ�����

int score;//��ѧЧ���ۺ�����

};//�ṹ��

void menu();

int reads(struct teachers tea[N]);//��ȡ��ʦ�ļ��е�����

void save(struct teachers tea[N],int n);//���뱣������

void add();//��ӽ�ʦ��Ϣ

void show();//��ʾ��ʦ��Ϣ

void order_num();//��ְ���Ž�������

void order_score();// ����ѧЧ���ۺ����ֽ�������

void query_name();//���������ҽ̹���Ϣ

void query_lesson();//���γ̲��ҽ�ʦ��Ϣ

void modify();//�޸Ľ�ʦ��Ϣ

void backspace();//ɾ����ʦ��Ϣ

void quit();//�˳�ϵͳ.....................................................����˵��

void main()

{

system("color 90");
printf(" *************************ѧԺ��Ϣ����ϵͳ��ӭ�� ***********************\n");
printf("    ==============================================================\n");
printf("    ��**********************************************************��\n");
printf("    ��***____________________________________________________***��\n");
printf("    ��***|**************************************************|***��\n");
printf("    ��***|****                                          ****|***��\n");
printf("    ��***|****        ��ӭʹ��ѧԺ��Ϣ����ϵͳ        ****|***��\n");
printf("    ��***|****                                          ****|***��\n");
printf("    ��***|****                                          ****|***��\n");
printf("    ��***|****            ������      �����          ****|***��\n");
printf("    ��***|****                                          ****|***��\n");
printf("    ��***|****                  2020.07.01              ****|***��\n");
printf("    ��***|****                                          ****|***��\n");
printf("    ��***|**************************************************|***��\n");
printf("    ��***----------------------------------------------------***��\n");
printf("    ��**********************************************************��\n");
printf("  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

printf("\n �밴���������ϵͳ \n");

getch();

int n;

while(1)

{

menu();

printf("\n ��������Ҫѡ��Ĳ�����ţ����س���ȷ�ϣ�");

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

default:  printf("��������������б��д��ڵ���ţ�\n ");

}

}

}

void menu()

{    printf("\n");

printf("\n");

printf("\n");

printf("      ************************* ѧԺ��ѧ��Ϣ����ϵͳ************************ \n");
printf("    ============================================================================\n");
printf("  || **********************************���˵�******************************** ||\n");
printf("  ||                              1  ��ӽ�ʦ������Ϣ                        ||\n");
printf("  ||                              2  ��ʾ��ʦ������Ϣ                        ||\n");
printf("  ||                              3  ��ְ���Ž�������                        ||\n");
printf("  ||                              4  ����ѧЧ���ۺ����ֽ�������              ||\n");
printf("  ||                              5  ����ʦ������ѯ��ʦ��Ϣ                  ||\n");
printf("  ||                              6  ����ʦ�γ̲�ѯ��ʦ��Ϣ                  ||\n");
printf("  ||                              7  �޸Ľ�ʦ��Ϣ                            ||\n");
printf("  ||                              8  ɾ����ʦ��Ϣ                            ||\n");
printf("  ||                              0  �˳�ϵͳ                                ||\n");
printf("  ******************************************************************************\n");
printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

}//.........................................................................................................���˵�

int  reads(struct teachers tea[N]) // ��ȡ��ʦ�ļ��е���Ϣ

{


FILE *fp;

int i=0;

if((fp=fopen("d:\\teachers.txt","r"))==NULL)
{

printf("�ļ���ʧ�ܣ�\n");
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

void add()/*��ӽ�ʦ��Ϣ*/

{

FILE *fp;

int n,i;
struct teachers tea;
if((fp=fopen("d:\\teachers.txt","a"))==NULL)  //����ļ��Ѿ����ڣ�����׷�ӽ�ʦ��Ϣ

{

if((fp=fopen("d:\\teachers.txt","w"))==NULL) // �ļ�������ʱ���������ļ��������ʦ��Ϣ

{

printf("�ļ���ʧ�ܣ�\n");

return;

}

}

printf("������Ҫ��ӵĽ�ʦ�����������س���ȷ�ϣ�");

scanf("%d",&n);

for(i=0;i<n;i++)

{

printf("\n�������%d����ʦ�Ĺ��š��������ÿո�ֿ��������س���ȷ�ϣ�\n",i);
scanf("%lu%s",&tea.num,&tea.name);
printf("\n�������%d����ʦ���Ա�ְ�ơ����ڿγ����ơ���ѧЧ���ۺ����֣��ÿո�ֿ��������س���ȷ�ϣ�\n",i);
scanf("%s%s%s%d",&tea.sex,&tea.title,&tea.lesson,&tea.score);
fprintf(fp,"%lu %s %s %s %s %d\n",tea.num,tea.name,tea.sex,tea.title,tea.lesson,tea.score);


}

fclose(fp);

printf(".............................................................������ɹ���\n");
printf(".............................................................���밴������ص����˵�\n");

getch();

}

void show()/*��ʾ��ʦ��Ϣ*/

{

struct teachers tea[N];

int i,n;

n=reads(tea);

printf("*********************���еĽ�ʦ��Ϣ����************************\n\n");
printf("  ��� || ְ���� || ���� || �Ա� || ְ�� ||    �γ�    ||  ����        \n");
printf("***************************************************************\n");

for(i=0;i<n;i++)

printf("\n%3d  %lu  %4s  %1s  %5s  %20s  %3d\n",i+1,tea[i].num,tea[i].name,tea[i].sex,tea[i].title ,tea[i].lesson,tea[i].score);
printf("***************************************************************\n");
printf(".............................................................����ʾ�ɹ���\n");
printf(".............................................................���밴������ص����˵�\n");

getch();

}

void order_num()  //���̹��������ʦ��ؼ�¼

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

printf("  ��� || ְ���� || ���� || �Ա� || ְ�� ||    �γ�    ||  ����        \n");
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
printf("............................................................������ɹ���\n");
printf("...........................................................���밴������ص����˵�\n");

getch();

}

void order_score()  //����ѧ�ۺ����������ʦ��Ϣ

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

printf("  ��� || ְ���� || ���� || �Ա� || ְ�� ||    �γ�    ||  ����        \n");
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
printf("............................................................������ɹ���\n");
printf("...........................................................���밴������ص����˵�\n");
getch();

}

void query_name()  // ����ʦ�����Խ�ʦ��Ϣ��ѯ

{

struct teachers tea[N];

char name[N];

int i,n;

bool flag=0;

n=reads(tea);

printf("\n���������ѯ�Ľ�ʦ���������س���ȷ�ϣ�\n");

scanf("%s",&name);

for(i=0;i<n;i++)

{

if(strcmp(name,tea[i].name)==0)

{

printf("  ��� || ְ���� || ���� || �Ա� || ְ�� ||    �γ�    ||  ����        \n");
printf("***************************************************************\n");
printf("\n%3d  %lu  %4s    %1s  %5s  %20s  %3d\n",i+1,tea[i].num,tea[i].name,tea[i].sex,tea[i].title ,tea[i].lesson,tea[i].score);
printf("***************************************************************\n");
printf(".............................................................����ѯ�ɹ���\n");
printf(".............................................................���밴������ص����˵�\n");

flag=1;

getch();

}

}

if(flag==0)

{

printf("\n.............................................................��δ�ҵ������Ϣ��\n");
printf(".............................................................���밴������ص����˵�\n");
getch();

}

}

void query_lesson()  // ����ʦ�γ̶Խ�ʦ��Ϣ��ѯ

{

struct teachers tea[N];

char lesson[N];

int i,n;

bool flag=0;

n=reads(tea);
printf("\n���������ѯ�Ľ�ʦ�γ̣����س���ȷ�ϣ�\n");
scanf("%s",&lesson);

for(i=0;i<n;i++)

{

if(strcmp(lesson,tea[i].lesson)==0)

{

printf("  ��� || ְ���� || ���� || �Ա� || ְ�� ||    �γ�    ||  ����        \n");
printf("***************************************************************\n");
printf("\n%3d  %lu  %4s    %1s  %5s  %20s  %3d\n",i+1,tea[i].num,tea[i].name,tea[i].sex,tea[i].title ,tea[i].lesson,tea[i].score);
printf("***************************************************************\n");
printf(".............................................................����ѯ�ɹ���\n");
printf(".............................................................���밴������ص����˵�\n");

flag=1;

getch();

}

}

if(flag==0)

{

printf("\n.............................................................��δ�ҵ������Ϣ��\n");
printf(".............................................................���밴������ص����˵�\n");

getch();

}

}

void modify()//�޸Ľ�ʦ��Ϣ

{

struct teachers tea[N];

FILE *fp;

fp=fopen("d:\\teachers.txt","ab");

int i,n;

bool flag=0;

n=reads(tea);

char m[N];

printf("������Ҫ�޸ĵ���ʦ�����֣�");

scanf("%s",&m);

for(i=0;i<n;i++)

fread(&tea[i],sizeof(struct teachers),1,fp);

for(i=0;i<n;i++)

{

if(strcmp(tea[i].name,m)==0)

{

printf("���Ǵ���ʦԭ������Ϣ��\n");
printf("  ��� || ְ���� || ���� || �Ա� || ְ�� ||    �γ�    ||  ����        \n");
printf("***************************************************************\n");
printf("\n%3d  %lu  %4s    %1s  %5s  %20s  %3d\n",i+1,tea[i].num,tea[i].name,tea[i].sex,tea[i].title ,tea[i].lesson,tea[i].score);
printf("***************************************************************\n");
printf("����������Ϣ��\n");
printf("\n�������ʦ�Ĺ��š��������ÿո�ֿ��������س���ȷ�ϣ�\n");
scanf("%lu%s",&tea[i].num,&tea[i].name);
printf("\n�������ʦ���Ա�ְ�ơ����ڿγ����ơ���ѧЧ���ۺ����֣��ÿո�ֿ��������س���ȷ�ϣ�\n");
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

printf(".............................................................���޸ĳɹ���\n");
printf(".............................................................���밴������ص����˵�\n");

getch();

}

}

if(flag==0)

{

printf("\n.............................................................��δ�ҵ������Ϣ��\n");
printf(".............................................................���밴������ص����˵�\n");
getch();

}

}

void backspace()//ɾ����ʦ��Ϣ

{

struct teachers tea[N];

FILE *fp;

fp=fopen("d:\\teachers.txt","ab");

int i,n;

bool flag=0;
n=reads(tea);

char m[N];

printf("������Ҫɾ������ʦ�����֣�");
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

printf(".............................................................��ɾ���ɹ���\n");
printf(".............................................................���밴������ص����˵�\n");
getch();

}

if(flag==0)

{

printf("\n.............................................................��δ�ҵ������Ϣ��\n");
printf(".............................................................���밴������ص����˵�\n");
getch();

}

}

void quit()  //�˳�ϵͳ

{

char  a;

printf("��������˳�ѧԺ��ѧ��Ϣ����ϵͳô��\n");
printf("          ��(Y)/��(N)              \n");

scanf("%c",&a);
getchar();


if(a=='Y'||a=='y')

{

printf("*******************************ллʹ��!*******************************\n");
printf("\n �밴������˳�ϵͳ \n");

exit(0);

}

}
