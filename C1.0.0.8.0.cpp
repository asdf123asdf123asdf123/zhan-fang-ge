#include<bits/stdc++.h>
#include<conio.h> 
#include<windows.h>
using namespace std;
int ma[53][53],who=1,have,map_size=0,people;
map<string,int>id;
map<char,int>gox;
map<char,int>goy;
string col[13]={"white","blue","red","green","yellow"};
string icon[23]={" ","1","2","3","4"};
struct peo{
	int x,y,cnt;
	string name;
}a[5];
void gotoxy(int x, int y){
	COORD pos;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void hidecursor(){
	CONSOLE_CURSOR_INFO cursor_info={1,0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
}
string chars(string ch,int times){
	string s="";
	for(int i=1;i<=times;i++)
		s+=ch;
	return s;
}
void initkeyboard(){
	goy['a']=0;
	goy['d']=0;
	goy['w']=-1;
	goy['s']=1;
	gox['w']=0;
	gox['s']=0;
	gox['a']=-1;
	gox['d']=1;
}
void ccolor(string str,string fore,string back=""){
	int foreground=0,background=0;
	if(fore=="red")
		foreground=FOREGROUND_INTENSITY|FOREGROUND_RED;
	if(fore=="green")
		foreground=FOREGROUND_INTENSITY|FOREGROUND_GREEN;
	if(fore=="blue")
		foreground=FOREGROUND_INTENSITY|FOREGROUND_BLUE;
	if(fore=="yellow")
		foreground=FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN;
	if(fore=="pink")
		foreground=FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE;
	if(fore=="cyan")
		foreground=FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE;
	if(fore=="white")
		foreground=FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE;
	if(back=="red")
		background=BACKGROUND_INTENSITY|BACKGROUND_RED;
	if(back=="green")
		background=BACKGROUND_INTENSITY|BACKGROUND_GREEN;
	if(back=="blue")
		background=BACKGROUND_INTENSITY|BACKGROUND_BLUE;
	if(back=="yellow")
		background=BACKGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_GREEN;
	if(back=="pink")
		background=BACKGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_BLUE;
	if(back=="cyan")
		background=BACKGROUND_INTENSITY|BACKGROUND_GREEN|BACKGROUND_BLUE;
	if(back=="white")
		background=BACKGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_BLUE;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),foreground|background);
	cout<<str;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY);
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
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
			break;
		case 5:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_BLUE);
			break;
	}
}
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
int selectwhat(string title,string titleforegroundcolor,string titlebackgroundcolor,string selectforegroundcolor,string selectbackgroundcolor,string text[],int textcount,string textforegroundcolor,string textbackgroundcolor,string tipsforegroundcolor,string tipsbackgroundcolor){
	int select=0;
	ccolor(title+"\n",titleforegroundcolor,titlebackgroundcolor);
	for(int i=0;i<textcount;i++)
		ccolor("\n "+text[i]+"\n",textforegroundcolor,textbackgroundcolor);
	cout<<"\n";
	ccolor("'w'、's'或上下键进行选择，enter、右键或'd'进行确定",tipsforegroundcolor,tipsbackgroundcolor);
	while(1){
		gotoxy(0,2*select+1);
		ccolor(chars("-",text[select].size()+2),selectforegroundcolor,selectbackgroundcolor);
		ccolor("\n|",selectforegroundcolor,selectbackgroundcolor);
		gotoxy(text[select].size()+1,2*select+2);
		ccolor("|\n",selectforegroundcolor,selectbackgroundcolor);
		ccolor(chars("-",text[select].size()+2),selectforegroundcolor,selectbackgroundcolor);
		switch(scanc()){
			case 'w':
				if(select!=0){
					gotoxy(0,2*select+1);
					ccolor(chars(" ",text[select].size()+2),selectforegroundcolor,selectbackgroundcolor);
					ccolor("\n ",selectforegroundcolor,selectbackgroundcolor);
					gotoxy(text[select].size()+1,2*select+2);
					ccolor(" \n",selectforegroundcolor,selectbackgroundcolor);
					ccolor(chars(" ",text[select].size()+2),selectforegroundcolor,selectbackgroundcolor);
					select--;
				}
				break;
			case 's':
				if(select<textcount-1){
					gotoxy(0,2*select+1);
					ccolor(chars(" ",text[select].size()+2),selectforegroundcolor,selectbackgroundcolor);
					ccolor("\n ",selectforegroundcolor,selectbackgroundcolor);
					gotoxy(text[select].size()+1,2*select+2);
					ccolor(" \n",selectforegroundcolor,selectbackgroundcolor);
					ccolor(chars(" ",text[select].size()+2),selectforegroundcolor,selectbackgroundcolor);
					select++;
				}
				break;
			case 'd':
				return select;
			case 13:
				return select;
		}
	}
}
bool cmp(peo a,peo b){
	return a.cnt>b.cnt;
}
void initmap(){
	cout<<chars(" ",map_size+2)+"\n";
	for(int i=1;i<=map_size;i++){
		cout<<" ";
		ccolor(chars(" ",map_size),"","white");
		cout<<" \n";
	}
	cout<<chars(" ",map_size+2)+chars("\n",4);
	for(int i=1;i<=people;i++){
		ccolor(icon[i],"black",col[i]);
		ccolor(":"+a[i].name+"在的位置 ",col[i]);
	}
	cout<<endl;
	for(int i=1;i<=people;i++){
		gotoxy(a[i].x,a[i].y);
		ccolor(icon[i],"black",col[i]);
	}
}
void connectus(){
	ccolor("\
作者：黄*森\n联系电话：18580878129（有可能不在线）\n\
未经允许：\n\
不能转载！\n\
不能抄袭！\n\
不能纂改！\n\
2022~2023版，版权归黄*森所有。\n\
","white");
	cout<<"按任意键返回";
	getch();
	system("cls");
}
void play(){
	string peop[5]={"双人","四人"};
	memset(ma,0,sizeof(ma));
	people=selectwhat("请选择人数","red","","blue","",peop,2,"green","","white","");
	people=(people+1)*2;
	system("cls");
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
	system("cls");
	initmap();
	while(have>0){
		gotoxy(0,map_size+2);
		for(int i=1;i<=people;i++){
			tocolor(i);
			cout<<a[i].name<<"占格数:"<<a[i].cnt<<" ";
		}
		tocolor(5);
		cout<<chars(" ",12)+"\n剩余格数:"<<have<<chars(" ",12)+"\n该";
		ccolor(a[who].name,col[who]);
		tocolor(5);
		cout<<"了"+chars(" ",12);
		char ch=scanc();
		int nx=a[who].x+gox[ch],ny=a[who].y+goy[ch];
		if(nx>=1&&nx<=map_size&&ny>=1&&ny<=map_size&&(ma[nx][ny]==who||ma[nx][ny]==0)){
			if(!ma[nx][ny]){
				a[who].cnt++;
				have--;
			}
			ma[a[who].x][a[who].y]=who;
			gotoxy(a[who].x,a[who].y);
			ccolor(" ","",col[who]);
			a[who].x=nx;
			a[who].y=ny;
			ma[a[who].x][a[who].y]=who;
			gotoxy(a[who].x,a[who].y);
			ccolor(icon[who],"black",col[who]);
		}
		if(who<people)
			who++;
		else
			who=1;
	}
	system("cls");
	sort(a+1,a+1+people,cmp);
	ccolor("排名\n名次 名字 占格数\n","white");
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
	Sleep(3000);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY);
	cout<<"按任意键退出";
	getch();
	system("cls");
}
void menu(){
	string men[13]={"开始游戏","联系我们","退出"};
	while(1){
		int type=selectwhat("占方格","red","","blue","",men,3,"green","","pink","");
		system("cls");
		switch(type){
			case 0:
				play();
				break;
			case 1:
				connectus();
				break;
			case 2:
				exit(0);
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY);

}
int main(){
	cout<<"游戏加载中...";
	hidecursor(); 
	initkeyboard();
	system("cls");
	menu();
	return 0;
}
