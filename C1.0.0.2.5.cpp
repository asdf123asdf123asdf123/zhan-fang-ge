#include<bits/stdc++.h>
#include<conio.h> 
#include<windows.h>
using namespace std;
int ma[13][13];
map<char,int>gox;
map<char,int>goy;
void initkeyboard(){
	goy['a']=-1;
	goy['d']=1;
	goy['w']=0;
	goy['s']=0;
	gox['w']=-1;
	gox['s']=1;
	gox['a']=0;
	gox['d']=0;
}
void ccolor(string str,string color){
	if(color=="red")
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	if(color=="blue")
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	if(color=="pink")
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |FOREGROUND_BLUE);
	cout<<str;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
}
void tocolor(int a){
	if(a%2)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
}
struct peo{
	int x,y,cnt;
	string name;
};
char scanc(){
	char ch='\0';
	ch=getch();
	switch(ch){
		case 'w':
			return 'w';
		case 'a':
			return 'a';
		case 'd':
			return 'd';
		case 's':
			return 's';
		case -32:
			char ch2;
			ch2=getch();
			switch(ch2){
				case 72:
					return 'w';
				case 75:
					return 'a';
				case 77:
					return 'd';
				case 80:
					return 's';
			}
			break;
		case 13:
			return 13;
	}
}
int who=1,have=98;
int main(){
	initkeyboard();
	string col[5]={"","blue","red"};
	memset(ma,0,sizeof(ma));
	peo a[5];
	a[1].cnt=1;a[2].cnt=1;
	a[1].x=1;a[1].y=1;
	a[2].x=10;a[2].y=10;
	ma[1][1]=1;
	ma[10][10]=3;
	for(int i=1;i<=2;i++){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);
		cout<<"请输入玩家"<<i<<"的名字：";
		tocolor(i);
		cin>>a[i].name;
	}
	system("cls");
	while(have){
		system("cls");
		for(int i=0;i<=11;i++)
			ccolor("-","pink");
		cout<<endl;
		for(int i=1;i<=10;i++){
			ccolor("|","pink");
			for(int j=1;j<=10;j++)
				switch(ma[i][j]){
					case 0:
						cout<<" ";
						break;
					case 1:
						ccolor("1","blue");
						break;
					case 2:
						ccolor("o","blue");
						break;
					case 3:
						ccolor("2","red");
						break;
					case 4:
						ccolor("x","red");
				}
			ccolor("|\n","pink");
		}
		for(int i=0;i<=11;i++)
			ccolor("-","pink");
		cout<<endl;
		for(int i=1;i<=2;i++){
			tocolor(i);
			cout<<a[i].name<<"占格数:"<<a[i].cnt<<" ";
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);
		cout<<endl;
		cout<<"剩余格数:"<<have<<endl;
		cout<<"该";
		ccolor(a[who].name,col[who]);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);
		cout<<"了"<<endl;
		ccolor("1:"+a[1].name+"在的位置 ","blue");
		ccolor("2:"+a[2].name+"在的位置 ","red");
		ccolor("o:"+a[1].name+"占的格子 ","blue");
		ccolor("x:"+a[2].name+"占的格子 ","red");
		char ch=scanc();
		int nx=a[who].x+gox[ch],ny=a[who].y+goy[ch];
		if(nx>0&&nx<11&&ny>0&&ny<11&&(ma[nx][ny]==who*2||ma[nx][ny]==0)){
			ma[a[who].x][a[who].y]=2*who;
			if(!ma[nx][ny]){
				a[who].cnt++;
				have--;
			}
			ma[nx][ny]=2*who-1;
			a[who].x=nx;
			a[who].y=ny;
		}
		if(who<2)
			who++;
		else
			who=1;
	}
	system("cls");
	if(a[1].cnt>a[2].cnt){
		tocolor(1);
		cout<<a[1].name<<"胜利，占了"<<a[1].cnt<<"块！";
	}
	else
		if(a[1].cnt<a[2].cnt){
			tocolor(2);
			cout<<a[2].name<<"胜利，占了"<<a[2].cnt<<"块！";
		}
		else{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout<<"平局，都占了"<<a[1].cnt<<"块！";
		}
	Sleep(3000);
	return 0;
}

