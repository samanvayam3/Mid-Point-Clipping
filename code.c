#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<math.h>
#include<graphics.h>

typedef struct coordinate
{ int x,y;
  char code[4];
}PT;

void pause()
{ outtextxy(10,460,"Press any key to Continue ...");
  getch();
}

void drawline (PT p1,PT p2,int cl)
{ setcolor(cl);
  line(p1.x,p1.y,p2.x,p2.y);
}

PT setcode(PT p)
{ PT ptemp;
  if(p.y<=100)
  ptemp.code[0]='1';
  else
  ptemp.code[0]='0';
  if(p.y>=400)
  ptemp.code[1]='1';
  else
  ptemp.code[1]='0';
  if(p.x>=450)
  ptemp.code[2]='1';
  else
  ptemp.code[2]='0';
  if(p.x<=150)
  ptemp.code[3]='1';
  else
  ptemp.code[3]='0';
  ptemp.x=p.x;
  ptemp.y=p.y;
  return(ptemp);
}

int visibility(PT p1,PT p2)
{ int i,flag=0;
  for(i=0;i<4;i++)
  { if((p1.code[i]!='0')||(p2.code[i]!='0'))
    flag=1;
  }
  if(flag==0)
  return(0);
  for(i=0;i<4;i++)
  { if((p1.code[i]==p2.code[i])&&(p1.code[i]=='1'))
    flag=0;
  }
}

void midsub(PT p1,PT p2)
{ PT mid;
  int v;
  p1=setcode(p1);
  p2=setcode(p2);
  v=visibility(p1,p2);
  switch(v)
  { case 0 : drawline(p1,p2,15);
             break;
    case 1 : break;
    case 2 : mid.x=p1.x+(p2.x-p1.x)/2;
             mid.y=p1.y+(p2.y-p1.y)/2;
             midsub(p1,mid);
             mid.x=mid.x+1;
             mid.y=mid.y+1;
             midsub(mid,p2);
             break;
  }
}

PT resetendpt (PT p1,PT p2);

void main()
{ int gd=DETECT,gm,v;
  PT p1,p2,ptemp;
  initgraph(&gd,&gm,"C:\\TURBOC3\\BGI ");
  printf("\n\n\n Enter x1 y1 : ");
  scanf("%d %d",&p1.x,&p1.y);
  printf(" Enter x2 y2 : ");
  scanf("%d %d",&p2.x,&p2.y);
  cleardevice();
  drawwindow();
  midsub(p1,p2);
  closegraph();
}
