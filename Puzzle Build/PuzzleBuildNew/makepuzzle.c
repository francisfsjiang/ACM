//#ifndef
//#define
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include"timecounter.h"
#define MAXLENGTH 5000
#define MAXWIDTH 5000
#define BARRIERNUM 0
#define WELL 1
#define WAY 0
int MoveX[4]={1,-1,0,0};
int MoveY[4]={0,0,1,-1};
short ListX[50*MAXLENGTH];
short ListY[50*MAXLENGTH];
short ListD[50*MAXLENGTH];
int ListLength;

int SizeStartX,SizeStartY;
int SizeEndX,SizeEndY;
int StartX,StartY;
int EndX,EndY;
bool Map[MAXWIDTH][MAXLENGTH];
bool Barrier[MAXWIDTH][MAXLENGTH];


void Read()
{
  freopen("make.in","r",stdin);
  freopen("make.out","w",stdout);
  scanf("%d%d%d%d%d%d%d%d",&SizeStartX,&SizeStartY,&SizeEndX,&SizeEndY,&StartX,&StartY,&EndX,&EndY);
}

void Write()
{
  int i,j;
  printf("%d %d\n%d %d\n%d %d\n%d %d\n",SizeStartX,SizeStartY,SizeEndX,SizeEndY,StartX,StartY,EndX,EndY);
  for(i=SizeStartX;i<=SizeEndX;i++)
  {
    for(j=SizeStartY;j<=SizeEndY;j++)printf("%d ",Map[i][j]);
    printf("\n");
  }
}

void WriteForMathematica()
{
  int i,j;
  Map[StartX][StartY-1]=0;
  Map[StartX-1][StartY]=0;
  Map[StartX][StartY+1]=0;
  Map[StartX+1][StartY]=0;
  Map[EndX][EndY+1]=0;
  Map[EndX+1][EndY]=0;
  Map[EndX][EndY-1]=0;
  Map[EndX-1][EndY]=0;
  for(i=SizeStartX-1;i<=SizeEndX+1;i++)
  {
    printf("{");
    for(j=SizeStartY-1;j<=SizeEndY;j++)printf("%d,",!Map[i][j]);
    printf("%d},\n",!Map[i][SizeEndY+1]);
  }
  //for(i=;i<=SizeEndX-SizeStartX;i++)printf("0,");printf("\n");
}

int Check(int x,int y)
{
  if(x>=SizeStartX&&x<=SizeEndX&&y>=SizeStartY&&y<=SizeEndY&&Map[x][y]==WELL&&Barrier[x][y]==WAY)return 1;
  else return 0;
}



void Insert(int x,int y)
{
  int i;
  Map[x][y]=WAY;
  for(i=0;i<=3;i++)
  {
    if(Check(x+MoveX[i],y+MoveY[i]))
    {
      ListX[ListLength]=x+MoveX[i];
      ListY[ListLength]=y+MoveY[i];
      ListD[ListLength]=i;
      ListLength++;
    }
  }
}

void MakeDoor(int x,int y)
{
  if(x>(SizeEndX-SizeStartX)/2)
  {
    while(Map[x][y]==WELL)
    {
      Map[x][y]=WAY;
      Map[x-1][y]=WAY;
      x--;
      y--;
    }
  }
  else
  {
    while(Map[x][y]==WELL)
    {
      Map[x][y]=WAY;
      Map[x+1][y]=WAY;
      x++;
      y--;
    }
  }
}

//int Map[][],int barrier[][],int SizeStartX,int SizeStartY,int SizeEndY,int SizeEndY,int StartX,int StartY,int EndX,int EndY

/*void puzzlemaker(int map[][],int barrier[][],int sizestartx,int sizestarty,int sizeendx,int sizeendy,int startx,int starty,int endx,int endy)
{Print()
  Map=map;
  Barrier=barrier;
  SizeStartX=sizestartx;
  SizeStartY=sizestartY;
  SizeEndY=sizeendy;
  SizeEndX=sizeendx;
  StartX=startx;
  StartY=Starty;
}*/


int main()
{
  int randnum,headx,heady,headd,i,j;
  Read();
  ListLength=1;
  memset(Map,1,sizeof(Map));
  //Write();
  Insert(StartX,StartY);
  while(ListLength>0)
  {
    randnum=rand()%ListLength;
    headx=ListX[randnum];
    heady=ListY[randnum];
    headd=ListD[randnum];
    if(Check(headx+MoveX[headd],heady+MoveY[headd]))
    {
      Map[headx][heady]=WAY;
      Insert(headx+MoveX[headd],heady+MoveY[headd]);
    }
    ListLength--;
    ListX[randnum]=ListX[ListLength];
    ListY[randnum]=ListY[ListLength];
    ListD[randnum]=ListD[ListLength];
  }
  MakeDoor(EndX,EndY);
  Write();
  //WriteForMathematica();
  return 0;
}

//#endif
