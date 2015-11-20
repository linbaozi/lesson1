#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<iostream.h>
#include<time.h>
HANDLE hInput;  /*  获取标准输入设备句柄 */
INPUT_RECORD inRec;/*  返回数据记录 */
DWORD numRead; /*  返回已读取的记录数 */
int comp(int(a0[22][22]),int(b0[22][22]))
{
	int comp1,comp2,comp3,comp4;
	for(comp1=1;comp1<=20;comp1++)
	for(comp2=1;comp2<=20;comp2++)
	for(comp3=comp1-1;comp3<=comp1+1;comp3++)
	for(comp4=comp2-1;comp4<=comp2+1;comp4++)
			if(a0[comp1][comp2]==0&&b0[comp3][comp4]==1&&b0[comp1][comp2]==0)return 1;
			return 0;
}
void HideCursor(int n) 
{ 
CONSOLE_CURSOR_INFO cursor_info={1,n};
SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
}
void gotoxy(int x,int y)
{
	COORD pos;
	pos.X=2*x;
	pos.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); 
}
void color(int n)
{
HANDLE hConsole = GetStdHandle((STD_OUTPUT_HANDLE));
SetConsoleTextAttribute(hConsole,n);
}
int main()
{
	HideCursor(0);
	HWND hwnd=FindWindow("ConsoleWindowClass",NULL);/*  控制台窗口句柄 */
	int i,j,a[22][22]={{0},{0}},s[22][22]={{0},{0}},p[22][22]={{0},{0}},h=0,m[22][22]={{0},{0}},key=0,i1,i2,j1,j2,b=0,c=0,M_x,M_y,mouse;
	char ch;
	srand((unsigned)time(NULL));
loop:
	b=0;
	c=0;
	for(i=1;i<=20;i++)
	 {
		for(j=1;j<=20;j++)
			{
				if(rand()%100<=80){a[i][j]=0;c++;}
				else a[i][j]=1;
				s[i][j]=0;
				p[i][j]=0;
				m[i][j]=0;
			}
		printf("\n");}
		for(i1=1;i1<=20;i1++)
		for(j1=1;j1<=20;j1++)
		for(i2=i1-1;i2<=i1+1;i2++)
		for(j2=j1-1;j2<=j1+1;j2++)
		if(a[i2][j2]==1)
		m[i1][j1]++;
//=================================================================================雷的分布
		for(i=0;i<=21;i++)
		for(j=0;j<=21;j++)
		{
			gotoxy(i,j);
			color(07);
			printf("■");
		}
		for(i=1;i<=20;i++)
		{
			for(j=1;j<=20;j++){gotoxy(i,j);color(06);printf("■");}
		}
//--------------------------------------------------------------------------------界面输出-------------------//
	



do
{
		INPUT_RECORD inRec;
DWORD res;
HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
ReadConsoleInput(hInput, &inRec, 1, &res);
if(inRec.EventType == MOUSE_EVENT && inRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) //鼠标左键
{
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),inRec.Event.MouseEvent.dwMousePosition);
M_x=inRec.Event.MouseEvent.dwMousePosition.X/2;
M_y=inRec.Event.MouseEvent.dwMousePosition.Y;
if(M_x>=21||M_y>=21||M_x==0||M_y==0||s[M_x][M_y]==1)continue;
//----------------------------------------------------------------------------------------------			
if(a[M_x][M_y]==1)
	{															//失败判断
	for(i1=1;i1<=20;i1++)
	for(j1=1;j1<=20;j1++)										
		if(a[i1][j1]==1){gotoxy(i1,j1);color(12);printf("●");}
		mouse=MessageBox(hwnd,"你踩到了雷，游戏失败！\n是否再来一局？","蠢逼！",MB_YESNO|MB_ICONQUESTION);																																						
		if(mouse==IDYES){ReadConsoleInput(hInput, &inRec, 1, &res);goto loop;}
		else exit(0);																												
	}
else
	{
		if(m[M_x][M_y]==0)p[M_x][M_y]=1;
//----------------------------------------------------------------------------------------------
		do
		{	
			for(i1=1;i1<=20;i1++)
			for(j1=1;j1<=20;j1++)								
			for(i2=i1-1;i2<=i1+1;i2++)
			for(j2=j1-1;j2<=j1+1;j2++)
			{
			if(p[i2][j2]==1&&m[i1][j1]==0)
				{
				p[i1][j1]=1;
				gotoxy(i1,j1);
				color(m[i1][j1]+1);
				printf("%d",m[i1][j1]);				//  空白区域牵连判断
				if(s[i1][j1]==0)b++;
				s[i1][j1]=1;
				break;
				}
			if(p[i2][j2]==1)
				{
				gotoxy(i1,j1);
				color(m[i1][j1]+1); 
				printf("%d",m[i1][j1]);
				if(s[i1][j1]==0)b++;
				s[i1][j1]=1;
				}
			}
		}
		while(comp(m,p));
//----------------------------------------------------------------------------------------------
		for(i1=1;i1<=20;i1++)
		for(j1=1;j1<=20;j1++)								
		for(i2=i1-1;i2<=i1+1;i2++)
		for(j2=j1-1;j2<=j1+1;j2++)
		{			
		if(p[i2][j2]==1)
			{
			gotoxy(i1,j1);
			color(m[i1][j1]+1);
			printf("%d",m[i1][j1]);
			if(s[i1][j1]==0)b++;
			s[i1][j1]=1;
			}
		}
		gotoxy(M_x,M_y);
		color(m[M_x][M_y]+1);
		printf("%d",m[M_x][M_y]);
		if(s[M_x][M_y]==0)b++;s[M_x][M_y]=1;
	}
}
			
if(inRec.EventType == MOUSE_EVENT && inRec.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED) //鼠标右键
{
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),inRec.Event.MouseEvent.dwMousePosition);
M_x=inRec.Event.MouseEvent.dwMousePosition.X/2;
M_y=inRec.Event.MouseEvent.dwMousePosition.Y;
if(M_x>=21||M_y>=21||M_x==0||M_y==0||s[M_x][M_y]==1)continue;
if(s[M_x][M_y]==2){gotoxy(M_x,M_y);color(06);printf("■");s[M_x][M_y]=0;continue;}
if(s[M_x][M_y]==0)  {gotoxy(M_x,M_y);color(12);printf("★");s[M_x][M_y]=2;}
}
		if(c==b)break;
}
while(1);

		gotoxy(30,10);
		
		mouse=MessageBox(hwnd,"恭喜过关！\n要再来一局吗？","厉害厉害",MB_YESNO|MB_ICONQUESTION);																																						
		if(mouse==IDYES){goto loop;}else exit(0);
		gotoxy(8,23);
		Sleep(10000);
		exit(0);
		return 0;
}