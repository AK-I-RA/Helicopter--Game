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