#include<iostream.h>
#include<graphics.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
class pacman {
 private:
  int x,y;
  int r;
  int sa,ea;
  char flag,ch;
  int c;
  int count;
  void draw(int px,int py,int psa,int pea,int pr,int ft,int fc,int bc) {
   setcolor(bc);
   setfillstyle(ft,fc);
   if(pea-psa>=180) {
    if(psa+160>360) {
     pieslice(px,py,psa,360,pr);
     pieslice(px,py,0,psa+160,pr);
    } else pieslice(px,py,psa,psa+160,pr);
    if(pea>360) {
     pieslice(px,py,psa,360,pr);
     pieslice(px,py,0,pea,pr);
    } else pieslice(px,py,psa+160,pea,pr);
   } else pieslice(px,py,psa,pea,pr);
  }
 void moveforward(int ns=2,int sl=1,int speed=20) {
   for(int i=1;i<=ns;i++) {
    draw(x,y,sa,ea,r,1,0,0);
    switch(flag){
     case 'd': x+=sl;break;
     case 'a': x-=sl;break;
     case 'w': y-=sl;break;
     case 's': y+=sl;break;
    }
    draw(x,y,sa,ea,r,1,c,c);
    delay(speed);
   }
 }
 void gameover() {
  setcolor(6);
  rectangle(140,195,500,225);
  setfillstyle(1,6);
  floodfill(160,210,6);
  setcolor(15);
  outtextxy(160,207,"GAME OVER! PRESS \"c\" TO CONTINUE... ");
  while(1) {
   ch=getch();
   if(ch=='c') exit(0);
  }
 }
 void wonthegame() {
  setcolor(6);
  rectangle(140,195,520,225);
  setfillstyle(1,6);
  floodfill(160,210,6);
  setcolor(15);
  outtextxy(160,207,"THOU ART VICTORIOUS! PRESS \"c\" TO CONTINUE... ");
  for(int z=0;z<7;z++) {
   delay(300);
   turnleft();
   delay(300);
   turnright();
  }
  while(1) {
   ch=getch();
   if(ch=='c') exit(0);
  }
 }

 public:
 void haswon() {
  if((x>=310&&x<=320) && (y>=410&&y<=420)) wonthegame();
  else return;
 }
 void movetowards(int px,int py) {
   if((px-x>=0&&px-x<=10)||(x-px<=0&&x-px>=-10))
    if((py-y>=0&&py-y<=10)||(y-py<=0&&y-py>=-10))
      gameover();
   if((py-y>=0&&py-y<=10)||(y-py<=0&&y-py>=-10))
    if((px-x>=0&&px-x<=10)||(x-px<=0&&x-px>=-10))
      gameover();
   if(count%50>=25) {
    if(x-px>0) turnleft();
    else if(x-px<0) turnright();
    else if(y-py>0) turnup();
    else if(y-py<0) turndown();
    else gameover();
    count++;
   }
   else {
    if(y-py>0) turnup();
    else if(y-py<0) turndown();
    else if(x-px>0) turnleft();
    else if(x-px<0) turnright();
    else gameover();
    count++;
   }
 }
  pacman(int px,int py,int pr,char pflag,int pc) {
   x=px;
   y=py;
   r=pr;
   flag=pflag;
   c=pc;
   switch(flag) {
    case 'a': sa=200;ea=160+360;break;
    case 'd': sa=20;ea=340;break;
    case 'w': sa=110;ea=70+360;break;
    case 's': sa=290;ea=250+360;break;
   }
   draw(x,y,sa,ea,r,1,c,c);
   moveforward();
  }
  void turndown() {
   draw(x,y,sa,ea,r,1,0,0);
   sa=290; ea=250+360;
   draw(x,y,sa,ea,r,1,c,c);
   flag='s';
   moveforward();
  }
  void turnup() {
   draw(x,y,sa,ea,r,1,0,0);
   sa=110; ea=70+360;
   draw(x,y,sa,ea,r,1,c,c);
   flag='w';
   moveforward();
  }
  void turnleft() {
   draw(x,y,sa,ea,r,1,0,0);
   sa=200; ea=520;
   draw(x,y,sa,ea,r,1,c,c);
   flag='a';
   moveforward();
  }
  void turnright() {
   draw(x,y,sa,ea,r,1,0,0);
   sa=20; ea=340;
   draw(x,y,sa,ea,r,1,c,c);
   flag='d';
   moveforward();
  }
  int getx() { return x; }
  int gety() { return y; }
};
void main() {
 int gd=0,gm; char input;
 initgraph(&gd,&gm,"C:\\TurboC3\\BGI");

 setcolor(6);
 rectangle(0,0,640,480);
 setfillstyle(1,15);
 floodfill(1,1,6);

 setcolor(6);
 rectangle(270,20,370,50);
 setfillstyle(1,6);
 floodfill(300,25,6);
 setcolor(15);
 outtextxy(278,32,"PACMAN v0.1");

 setcolor(0);
 rectangle(540,400,559,419);
 rectangle(560,400,579,419);
 rectangle(580,400,599,419);
 rectangle(560,380,579,399);
 setfillstyle(1,6);
 floodfill(541,401,0);
 floodfill(561,401,0);
 floodfill(581,401,0);
 floodfill(561,381,0);
 setcolor(15);
 outtextxy(546,406,"a");
 outtextxy(566,406,"s");
 outtextxy(586,406,"d");
 outtextxy(566,386,"w");
 setcolor(0);
 outtextxy(540,360,"CONTROLS");

 setcolor(0);
 setfillstyle(1,6);
 rectangle(305,400,325,430);
 floodfill(306,405,0);
 line(315,400,315,430);
 circle(311,415,2);
 circle(319,415,2);
 setfillstyle(1,14);
 floodfill(311,415,0);
 floodfill(319,415,0);
 outtextxy(275,445,"SAFE-HOUSE");
 outtextxy(560,260,"Reach");
 outtextxy(560,270,"Safe");
 outtextxy(560,280,"house");
 outtextxy(570,446,"EXIT");
 setcolor(6); outtextxy(537,270,"?");
 setcolor(0); rectangle(540,440,559,459);
 setfillstyle(1,6); floodfill(541,441,0);
 setcolor(15); outtextxy(547,446,"x");

 pacman player(100,100,10,'d',2);
 pacman enemy1(300,300,10,'d',4);
 pacman enemy2(100,300,10,'d',4);

 setcolor(0);  outtextxy(560,308,"YOU"); outtextxy(560,328,"ENEMY");
 setcolor(2); setfillstyle(1,2); sector(540,310,20,340,5,5);
 setcolor(4); setfillstyle(1,4); sector(540,330,20,340,5,5);

 delay(1000);

 do {
  player.haswon();
  enemy1.movetowards(player.getx(),player.gety());
  enemy2.movetowards(player.getx(),player.gety());
  input=getch();
  switch(input) {
   case 'a': player.turnleft();break;
   case 's': player.turndown();break;
   case 'd': player.turnright();break;
   case 'w': player.turnup();break;
  }
 } while(!(input=='x'||input=='X'));

 getch();
 closegraph();
}