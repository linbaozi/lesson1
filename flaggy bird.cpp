 #include<stdio.h>                                          fuck                
#include<conio.h>
#include<stdlib.h>
#include<windows.h>

int x=5,y=3,t=3,k=5;                                          //定义全局变量
char area[20][200];

void gotoxy(int x,int y)                                      //控制坐标函数                         
{
COORD pos;
pos.X=x;
pos.Y=y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}


DWORD WINAPI ThreadProc1( LPVOID lpParam )                     //定义线程
{
	    
	    void gotoxy(int x,int y);
		int *px,*py,i,j,z=0; 
		px=&x; py=&y; 
		
		while(1)                          //此循环用作使地图
	{
		*py=*py+1;  *px=*px+1;              //改变“鸟”的坐标位置               
	    
	    system("cls");   
		
        t=3; //保持t值不改变

		gotoxy(k,t);//回到当前位置

        for(i=0;i<20;i++)//清屏后输出地图
		 {
			 for(j=0+z;j<39+z;j++)
				 printf("%c",area[i][j]);
			  t++;  gotoxy(k,t); //输出玩一行后，换行输出 不能直接用'\n'，用'\n'会返回到第0列输出		 
		}

		     z++; //用于使地图移动
			 
		gotoxy(7,*py);  putchar('B');//清屏后，重新输出鸟

		 if(area[*py-3][*px-6]=='*')//碰到*输掉游戏
		{
			 x=10; y=26;
			gotoxy(x,y);
			printf("这都过不了，傻逼"); break;
		}

		if(x>162)//判定胜利条件
		{
			x=10; y=26;
			gotoxy(x,y);
			printf("这才是我的好孩子"); break;
		} 
		
		Sleep(300); //300毫秒后重新输出地图与鸟     
	}   
return 0; 		
}

int main()
{
	void move(int *px,int *py);   //声明函数和定义各种变量
	void inter(char c[20][200]);
	 int i,j,*px,*py;	
	 char c;
	 gotoxy(x,y);
	 px=&x;  py=&y;

	 for(i=0;i<20;i++)//首先把地图全部定义为空格
	   for(j=0;j<200;j++)
		   area[i][j]=' ';

	     inter(area);
		 
		 
		 for(i=0;i<20;i++)//输出初始地图
		 {
			 for(j=0;j<39;j++)
	          printf("%c",area[i][j]);
			 gotoxy(k,++t);
		 }

		   x=7;   y=8;//输出鸟的初始位置
		 gotoxy(x,y);
	   putchar('B');
	   gotoxy(x,y);

	   CreateThread( NULL, 0, ThreadProc1, NULL, 0, NULL);                      //引用线程

	 while(1)
	{
        c=getch();   //输入字符
		 
		if(c==32)                                    //判定输入的是空格时，“鸟”往上升                                           
		 {
			 gotoxy(7,*py);                          //在原位置输出空格，覆盖掉原来的字符                  
			 putchar(' ');
			 gotoxy(7,*py);

			 *py=*py-1;                             //在新位置输出B
			 gotoxy(7,*py);
			 putchar('B');
			 gotoxy(7,*py);

		} 
		

		 if(area[*py-3][*px-6]=='*')               //“鸟”碰到*就退出循环
		{
			 x=10; y=26;
			gotoxy(x,y);
			printf("这都过不了，傻逼"); break;
		}
		
		 if(x>162)                               //胜利条件：走完整个地图
		{
			x=10; y=26;
			gotoxy(x,y);
			printf("这才是我的好孩子"); break;
		}  
		
	 } 
	 
	 getch();     

return 0;
}


void inter(char c[20][200])                              //生成地图
{
	int i,j,k;
	for(i=0;i<160;i++)

	{
		c[0][i]='*';
		c[19][i]='*';
	}
	
	  for(i=0;i<4;i++)
		 for(k=0;k<=11;k++)
		   for(j=9;j<=10;j++)
				c[k][j+i*40]='*';
			
		
		for(i=0;i<4;i++)
	      for(k=15;k<=18;k++)
	         for(j=13;j<=14;j++)
				c[k][j+i*40]='*';
	
		for(i=0;i<4;i++)
		 for(k=0;k<=15;k++)
			for(j=18;j<=24;j++)
				c[k][j+i*40]='*';
			
		for(i=0;i<4;i++)
		  for(k=13;k<=18;k++)
		    for(j=32;j<=33;j++)
				c[k][j+i*40]='*';
			


		for(i=0;i<4;i++)
		  for(k=9;k<=18;k++)
			for(j=38;j<=39;j++)
				c[k][j+i*40]='*';

		for(i=0;i<4;i++)
		  for(k=0;k<=6;k++)
			for(j=38;j<=39;j++)
				c[k][j+i*40]='*';


         
}

