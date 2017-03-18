#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#ifdef __unix__
# include <unistd.h>
#elif defined _WIN32
# include <windows.h>
#define sleep(x) Sleep(1000 * x)
#endif

char a[3][6],key;

void Jump()
{
        if(key=='w')
        {
        a[0][0]='G';
        a[1][0]=a[2][0];
        PRINT();
        }
        else{
        a[1][0]='G';
        a[0][0]=' ';
        }

}

void Check()
{
    if(a[1][0]=='|'&&a[0][0]!='G')
    {
        printf("\n\n\n\n\n\n\n\t\t\t\t\tGame Over");
        exit(0);
    }

}

char INIT()
{
    int i,r;
    r=rand()%6;
    if(r==0||r==1) return '|';
    else return '_';

}

void init()
{
    int j;
    a[2][0]=a[2][1];
    a[2][1]=a[2][2];
    a[2][2]=a[2][3];
    a[2][3]=a[2][4];
    a[2][4]=a[2][5];
    a[2][5]=INIT();
    for(j=0;j<6;j++)
    {
        a[1][j]=a[2][j];
    }
    if(a[1][0]=='_'||a[0][0]=='G'){
        a[1][0]='G';
        a[0][0]=' ';
    }

    //if(a[0][0]=='G') a[1][0]==a[2][0];
    //else a[1][0]='G';
}

void PRINT()
{
    system("cls");
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<6;j++)
        {
            printf("%c ",a[i][j]);
        }
        printf("\n");
    }
    sleep(1);
}
int main()
{
    int i;
    a[1][0]='G';
    a[2][0]=a[2][1]=a[2][2]=a[2][3]=a[2][5]='_';
    a[2][4]=a[1][4]='|';
    for(i=0;;i++)
    {
        if(kbhit()) {key=getch(); Jump();}
        init();
        if(kbhit()) {key=getch(); Jump();}
        Check();
        if(kbhit()) {key=getch(); Jump();}
        PRINT();
        if(kbhit()) {key=getch(); Jump();}
    }
return 0;
}
