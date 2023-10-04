#include<bits/stdc++.h>
#include<conio.h> 
#include<windows.h>
using namespace std;
int ma[103][103],who=1,have,map_size=0,people;
map<string,int>id;
map<char,int>gox;
map<char,int>goy;
string col[13]={"white","blue","red","green","cyan"};
string icon[23]={" ","1","o","2","x","3","@","4","+"};
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
	ccolor(title+"\n",titlecolor);
	for(int i=0;i<textcount;i++)
		ccolor("  "+text[i]+"\n",textcolor);
	ccolor("'w'��'s'�����¼�����ѡ��enter���Ҽ���'d'����ȷ��",tipscolor);
	while(1){
		gotoxy(0,select+1);
		ccolor("->",selectcolor);
		switch(scanc()){
			case 'w':
				if(select!=0){
					gotoxy(0,select+1);
					cout<<"  ";
					select--;
				}
				break;
			case 's':
				if(select<textcount-1){
					gotoxy(0,select+1);
					cout<<"  ";
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
	for(int i=0;i<=map_size+1;i++)
		ccolor("-","pink");
	cout<<endl;
	for(int i=1;i<=map_size;i++){
		ccolor("|","pink");
		for(int j=1;j<=map_size;j++)
			cout<<" ";
		ccolor("|\n","pink");
	}
	for(int i=0;i<=map_size+1;i++)
		ccolor("-","pink");
	cout<<endl;
	cout<<"\n\n\n";
	for(int i=1;i<=people;i++)
		ccolor(icon[i*2-1]+":"+a[i].name+"�ڵ�λ�� ",col[i]);
	cout<<endl;
	for(int i=1;i<=people;i++)
		ccolor(icon[i*2]+":"+a[i].name+"ռ�ĸ��� ",col[i]);
	for(int i=1;i<=people;i++){
		gotoxy(a[i].x,a[i].y);
		ccolor(icon[i*2-1],col[i]);
	}
}
int main(){
	hidecursor(); 
	initkeyboard();
	memset(ma,0,sizeof(ma));
	string peop[5]={"˫��","����"};
	people=selectwhat("��ѡ������","red","blue",peop,2,"green","white");
	people=(people+1)*2;
	system("cls");
	for(int i=1;i<=people;i++){
		tocolor(5);
		cout<<"���������"<<i<<"�����֣�";
		tocolor(i);
		cin>>a[i].name;
		id[a[i].name]=i;
	}
	system("cls");
	tocolor(5); 
	cout<<"�������ͼ��С��N*N����2~37����";
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
	while(have){
		gotoxy(0,map_size+2);
		for(int i=1;i<=people;i++){
			tocolor(i);
			cout<<a[i].name<<"ռ����:"<<a[i].cnt<<" ";
		}
		tocolor(5);
		cout<<"            \nʣ�����:"<<have<<"             \n��";
		ccolor(a[who].name,col[who]);
		tocolor(5);
		cout<<"��           ";
		char ch=scanc();
		int nx=a[who].x+gox[ch],ny=a[who].y+goy[ch];
		if(nx>=1&&nx<=map_size&&ny>=1&&ny<=map_size&&(ma[nx][ny]==who*2||ma[nx][ny]==0)){
			if(!ma[nx][ny]){
				a[who].cnt++;
				have--;
			}
			ma[a[who].x][a[who].y]=who*2;
			gotoxy(a[who].x,a[who].y);
			ccolor(icon[who*2],col[who]);
			a[who].x=nx;
			a[who].y=ny;
			ma[a[who].x][a[who].y]=who*2-1;
			gotoxy(a[who].x,a[who].y);
			ccolor(icon[who*2-1],col[who]);
		}
		if(who<people)
			who++;
		else
			who=1;
	}
	system("cls");
	sort(a+1,a+1+people,cmp);
	ccolor("����\n���� ���� ռ����\n","white");
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
	ccolor("��������˳�","white");
	getch();
	return 0;
}
