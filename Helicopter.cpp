#include<math.h>
#include<iostream.h>
#include<conio.h>
#include<time.h>
#include<graphics.h>
#include<process.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>

int j=1;
int left=200,top=200,radx=30,rady=15;
int py1,py2,py3,py4,ran;
long score=0;
char ch;
int t,l;
int px;
void downheli();
void upheli();
void chk_pipe();
void heli_dam();
void bk_m(int level);
void dance_pipe(int px,int py);

void main();
void play();
void drawMenu ( int selected , int defCol , int selCol ) ;
void start(int i);
int main_menu();

void level_page();
void level_draw(int lx,int ly);



int level=1;

void d_score(long sc)
{

	 setfillstyle(SOLID_FILL,BLACK);
	 bar(0,getmaxy()-50,getmaxx(),getmaxy());

	 setcolor(15);
	 settextstyle(2,0,5);
	 outtextxy(400,getmaxy()-40," SCORE :");
	 char s[10];
	 sprintf(s,"%ld",sc);
	 setfillstyle(SOLID_FILL,0);
	 outtextxy(500,getmaxy()-40,s);

	 setcolor(BLACK);
}

void draw_heli()
{
setcolor(BLACK);
setfillstyle(LINE_FILL,CYAN);
fillellipse(left,top-rady,radx+10,rady-5); //top fan
setfillstyle(SOLID_FILL,CYAN);
fillellipse(left-63,top-9,10,4);     //small fan
fillellipse(left,top,radx,rady);
setfillstyle(SOLID_FILL,WHITE);
bar(left,top-3,left-65,top+3);
sector(left,top,90,270,radx,rady);
bar(left-65,top-3,left-62,top-8);

}
void ulta_heli()
{
setfillstyle(LINE_FILL,CYAN);
fillellipse(left,top+rady,radx+10,rady-5); //top fan
setfillstyle(SOLID_FILL,CYAN);
fillellipse(left-63,top+9,10,4);     //small fan
fillellipse(left,top,radx,rady);
setfillstyle(SOLID_FILL,WHITE);
bar(left,top-3,left-65,top+3);
sector(left,top,90,270,radx,rady);
bar(left-65,top+3,left-62,top+8);
delay(20);