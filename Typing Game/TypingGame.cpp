#include <bits/stdc++.h>
#include <conio.h>
#include "console.h"
using namespace std;

#define Width  80
#define Height 25

int sleepTime = 500;
int Point=0, Error=0, Level= 1;

struct Alp
{
	char s;
	int x,y;
	
};

void LineAround();
void Update(char s);
void Dropping(int x, int y, char s);
void Respawn();

void LineAround()
{
	//===LineMain===
		// Line Top
			gotoXY(Width/4,1);
				cout<<(char) 201;
			for(int i=1;i<=26;i++)
				cout<<(char) 205;
			cout<<(char) 187;
		// Line edge	
			for(int i=2;i<Height;i++)
			{
				gotoXY(Width/4,i);
					cout<<(char) 186;
				gotoXY(Width/4+27,i);
					cout<<(char) 186;	
			}			
		// Line Bottom
			gotoXY(Width/4,Height);
				cout<<(char) 200;
			for(int i=1;i<=26;i++)
					cout<<(char) 205;
				cout<<(char) 188;
			
	//===LineOfInfo===
		// Line Top
			gotoXY(Width/4+30,20);
				cout<<(char) 201;
			for(int i=1;i<=20;i++)
				cout<<(char) 205;
			cout<<(char) 187;
		// Line edge	
			for(int i=21;i<Height;i++)
			{
				gotoXY(Width/4+30,i);
					cout<<(char) 186;
				gotoXY(Width/4+51,i);
					cout<<(char) 186;	
			}
		// Line Bottom
			gotoXY(Width/4+30,Height);
				cout<<(char) 200;
			for(int i=1;i<=20;i++)
				cout<<(char) 205;
			cout<<(char) 188;
	//===Info===
		gotoXY(Width/4+35,21);
			cout<<"Score Board";
		gotoXY(Width/4+31,22);
			cout<<"Point: "<<Point;	
		gotoXY(Width/4+31,24);
			cout<<"Error: "<<Error;	
		gotoXY(Width/4+42,23);
			cout<<"Level: "<<Level;	
	//===Credit===
		gotoXY(Width/4+50,3);
			cout<<"TYPING GAME";
		gotoXY(Width/4+55,5);
			cout<<"MADE BY MINATO";			
		gotoXY(Width/4+50,10);
			cout<<"THANK FOR PLAYING!!!";			
}


void Update(char s,int x,int y)
{
	// Catching
	int index = 38;
		if(kbhit())
		{
		
			char key = getch();
			if( (char) toupper(key) == s)
			{
				Point++;
				gotoXY(Width/4+index,22);
					cout<<Point<<"  ";
			}	
				
			else
			{
				Error++;
				gotoXY(Width/4+index,24);
				cout<<Error;
				Point--;
				gotoXY(Width/4+index,22);
					cout<<Point<<"  ";	
			}
			gotoXY(x,y-1);
				cout<<" ";
		// Update level
			if(Point%5==0&&Point>0)
			{
				Level++;
				gotoXY(Width/4+index+11,23);
					cout<<Level;
				if(sleepTime>100)	
					sleepTime-=25;
			}		
			Respawn();
		}

	//GameOverOrYouWin
		if(Error==10)
		{
			gotoXY(x,y-1);
				cout<<" ";
			gotoXY(Width/4+8,13);
				cout<<"GAME OVER";
			return;		
		}
		if(Point==100)
		{
			gotoXY(x,y-1);
				cout<<" ";
			gotoXY(Width/4+8,13);
				cout<<"YOU WIN";
			return;		
		}		
}

void Dropping(int x, int y,char s)
{
	// move
	while(1)
	{
		gotoXY(x,y);
		cout<<s;
		y++;
		if(y-2>=2)
		{
			gotoXY(x,y-2);
			cout<<" ";
		}
		if(y>=Height)
		{
			Error++;
			gotoXY(Width/4+38,24);
				cout<<Error;
			gotoXY(x,y-1);
				cout<<" ";		
			Respawn();	
		}
		Update(s,x,y);
		Sleep(sleepTime);	
	}
}

void Respawn()
{
		// respawn character
	Alp target;
	target.s =1+ rand()%25;
	target.s+=64;
	target.x = rand()%((Width/4+26)-(Width/4+1)+1)+(Width/4+1);
	target.y = 2;
	Dropping(target.x,target.y,target.s);
//	Update(target.s);
}



int main()
{
	LineAround();
	Respawn();
//	Alp A;
//	A.s =(char) rand()%(90-65+1)+65;
}
