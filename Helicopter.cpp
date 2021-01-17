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
setfillstyle(SOLID_FILL,BLACK);
fillellipse(left,top+rady,radx+10,rady-5); //top fan
fillellipse(left-63,top+9,10,4);     //small fan
fillellipse(left,top,radx,rady);
bar(left,top-3,left-65,top+3);
sector(left,top,90,270,radx,rady);
bar(left-65,top+3,left-62,top+8);

setcolor(BLACK);

}
void rem_heli()
{
setcolor(BLACK);
setfillstyle(SOLID_FILL,BLACK);
fillellipse(left,top-rady,radx+10,rady-5);
fillellipse(left-63,top-9,10,4);
fillellipse(left,top,radx,rady);
bar(left,top-3,left-65,top+3);
sector(left,top,90,270,radx,rady);
bar(left-65,top-3,left-62,top-8);

}

void drawpipe(int px,int py)
{
setfillstyle(1,GREEN);
//up pipes
bar(px,py,px+60,py+200);
bar(px-15,py+200,px+75,py+220);

bar(px-40,py+400,px+20,getmaxy()-50);
bar(px-55,py+380,px+35,py+400);
chk_pipe();

d_score(++score);
}


void removepipe(int px,int py)
{

setfillstyle(1,BLACK);
//up pipes
bar(px,py,px+60,py+200);
bar(px-15,py+200,px+75,py+220);


//down pipes
bar(px-40,py+400,px+20,getmaxy()-50);
bar(px-55,py+380,px+35,py+400);


}
void draw_wall(int px,int py)
{
   setfillstyle(INTERLEAVE_FILL,BROWN);
   bar(0,0,getmaxx(),15);
   bar(0,getmaxy()-55,getmaxx(),getmaxy()-50);
   bar(px,py+250,px+40,py+250+ran);
   bar(px-50,py+350,px-20,py+350+ran);
   chk_pipe();
   d_score(++score);
}
void rem_wall(int px,int py)
{
   setfillstyle(SOLID_FILL,BLACK);
   bar(px,py+250,px+40,py+250+ran);
   bar(px-50,py+350,px-20,py+350+ran);

   //bar(px,py+300,px+30,py+ran);
   //bar(px-30,py+400,px,getmaxy()-ran) ;
}


void dance_pipe(int px,int py)
{

setfillstyle(1,GREEN);
//up pipes
bar(px,py,px+60,py+100);
bar(px-15,py+100,px+75,py+120);

///down pipes

bar(px-40,py+450,px+20,getmaxy()-50);
bar(px-55,py+430,px+35,py+450);
chk_pipe();

d_score(++score);
}


void dance_remove(int px,int py)
{

setfillstyle(1,BLACK);
//up pipes
bar(px,py,px+60,py+100);
bar(px-15,py+100,px+75,py+120);

///down pipes

bar(px-40,py+450,px+20,getmaxy()-50);
bar(px-55,py+430,px+35,py+450);

}




void ball(int px,int py)
{
  setfillstyle(SOLID_FILL,RED);
// fillellipse(px,0,abs(py),ran);
//	 fillellipse(px+ran,0,abs(py),ran);

  sector(px,0,180,360,75,(py+250)/2);
 sector(px,getmaxy()-50,0,180,75,(py+200)/2);


   setfillstyle(5,RED);
 fillellipse(px,py+ran+250,30,30) ;

  chk_pipe();
   d_score(++score);
}