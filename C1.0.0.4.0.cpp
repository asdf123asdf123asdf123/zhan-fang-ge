#include<bits/stdc++.h>
#include<conio.h> 
#include<windows.h>
using namespace std;
int ma[103][103],who=1,have,map_size=0;
map<string,int>id;
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
	if(color=="white")
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);
	if(color=="red")
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	if(color=="green")
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	if(color=="blue")
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	if(color=="yellow")
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |FOREGROUND_GREEN);
	if(color=="pink")
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |FOREGROUND_BLUE);
	if(color=="cyan")
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |FOREGROUND_BLUE);
	cout<<str;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
}
void tocolor(int a){
	switch(a){
		case 1:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
			break;
		case 2:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
			break;
		case 3:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			break;
		case 4:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |FOREGROUND_BLUE);
			break;
		case 5:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);
			break;
	}
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
int selectwhat(string title,string titlecolor,string selectcolor,string text[],int textcount,string textcolor,string tipscolor){
	int select=0;
	while(1){
		ccolor(title,titlecolor);
		cout<<endl;
		for(int i=0;i<textcount;i++){
			if(select==i)
				ccolor("->",selectcolor);
			else
				cout<<"  ";
			ccolor(text[i],textcolor);
			cout<<endl;
		}
		ccolor("'w'、's'或上下键进行选择，enter、右键或'd'进行确定",tipscolor);
		switch(scanc()){
			case 'w':
				if(select!=0)
					select--;
				break;
			case 's':
				if(select<textcount-1)
					select++;
				break;
			case 'd':
				system("cls");
				return select;
			case 13:
				system("cls");
				return select;
		}
		system("cls");
	}
}
bool cmp(peo a,peo b){
	return a.cnt>b.cnt;
}
int main(){
	initkeyboard();
	string col[13]={"white","blue","red","green","cyan"};
	string icon[23]={" ","1","o","2","x","3","@","4","+"};
	memset(ma,0,sizeof(ma));
	peo a[5];
	string peop[5]={"双人","四人"};
	int people=selectwhat("请选择人数","red","blue",peop,2,"green","white");
	people=(people+1)*2;
	for(int i=1;i<=people;i++){
		tocolor(5);
		cout<<"请输入玩家"<<i<<"的名字：";
		tocolor(i);
		cin>>a[i].name;
		id[a[i].name]=i;
	}
	system("cls");
	tocolor(5); 
	cout<<"请输入地图大小（N*N）（2~37）：";
	cin>>map_size;
	for(int i=1;i<=people;i++)
		a[i].cnt=1;
	a[1].x=1;
	a[1].y=1;
	a[2].x=map_size;
	a[2].y=map_size;
	ma[1][1]=1;
	ma[map_size][map_size]=3;
	if(people==4){
		a[3].x=map_size;
		a[3].y=1;
		a[4].x=1;
		a[4].y=map_size;
		ma[map_size][1]=5;
		ma[1][map_size]=7;
	}
	have=map_size*map_size-people;
	while(have){
		system("cls");
		for(int i=0;i<=map_size+1;i++)
			ccolor("-","pink");
		cout<<endl;
		for(int i=1;i<=map_size;i++){
			ccolor("|","pink");
			for(int j=1;j<=map_size;j++)
				ccolor(icon[ma[i][j]],col[(ma[i][j]+1)/2]);
			ccolor("|\n","pink");
		}
		for(int i=0;i<=map_size+1;i++)
			ccolor("-","pink");
		cout<<endl;
		for(int i=1;i<=people;i++){
			tocolor(i);
			cout<<a[i].name<<"占格数:"<<a[i].cnt<<" ";
		}
		tocolor(5);
		cout<<endl;
		cout<<"剩余格数:"<<have<<endl;
		cout<<"该";
		ccolor(a[who].name,col[who]);
		tocolor(5);
		cout<<"了"<<endl;
		for(int i=1;i<=people;i++)
			ccolor(icon[i*2-1]+":"+a[i].name+"在的位置 ",col[i]);
		cout<<endl;
		for(int i=1;i<=people;i++)
			ccolor(icon[i*2]+":"+a[i].name+"占的格子 ",col[i]);
		char ch=scanc();
		int nx=a[who].x+gox[ch],ny=a[who].y+goy[ch];
		if(nx>=1&&nx<=map_size&&ny>=1&&ny<=map_size&&(ma[nx][ny]==who*2||ma[nx][ny]==0)){
			ma[a[who].x][a[who].y]=2*who;
			if(!ma[nx][ny]){
				a[who].cnt++;
				have--;
			}
			ma[nx][ny]=2*who-1;
			a[who].x=nx;
			a[who].y=ny;
		}
		if(who<people)
			who++;
		else
			who=1;
	}
	system("cls");
	sort(a+1,a+1+people,cmp);
	ccolor("排名\n名次 名字 占的数量\n","white");
	int ct=1;
	for(int i=1;i<=people;i++){
		tocolor(id[a[i].name]);
		if(a[i].cnt==a[ct].cnt)
			cout<<ct;
		else{
			cout<<i;
			ct=i;
		}
		cout<<" "<<a[i].name<<" "<<a[i].cnt<<endl;
	}
	ccolor("按任意键退出","white");
	getch();
	return 0;
}
