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
		ccolor("'w'��'s'�����¼�����ѡ��enter���Ҽ���'d'����ȷ��",tipscolor);
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
int who=1,have=100;
map<string,int>id;
int main(){
	initkeyboard();
	string col[13]={"white","blue","red","green","cyan"};
	string icon[23]={" ","1","o","2","x","3","@","4","+"};
	memset(ma,0,sizeof(ma));
	peo a[5];
	string peop[5]={"˫��","����"};
	int people=selectwhat("��ѡ������","red","blue",peop,2,"green","white");
	people=(people+1)*2;
	have-=people;
	for(int i=1;i<=people;i++)
		a[i].cnt=1;
	a[1].x=1;
	a[1].y=1;
	a[2].x=10;
	a[2].y=10;
	ma[1][1]=1;
	ma[10][10]=3;
	if(people==4){
		a[3].x=10;
		a[3].y=1;
		a[4].x=1;
		a[4].y=10;
		ma[10][1]=5;
		ma[1][10]=7;
	}
	for(int i=1;i<=people;i++){
		tocolor(5);
		cout<<"���������"<<i<<"�����֣�";
		tocolor(i);
		cin>>a[i].name;
		id[a[i].name]=i;
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
				ccolor(icon[ma[i][j]],col[(ma[i][j]+1)/2]);
			ccolor("|\n","pink");
		}
		for(int i=0;i<=11;i++)
			ccolor("-","pink");
		cout<<endl;
		for(int i=1;i<=people;i++){
			tocolor(i);
			cout<<a[i].name<<"ռ����:"<<a[i].cnt<<" ";
		}
		tocolor(5);
		cout<<endl;
		cout<<"ʣ�����:"<<have<<endl;
		cout<<"��";
		ccolor(a[who].name,col[who]);
		tocolor(5);
		cout<<"��"<<endl;
		for(int i=1;i<=people;i++)
			ccolor(icon[i*2-1]+":"+a[i].name+"�ڵ�λ�� ",col[i]);
		cout<<endl;
		for(int i=1;i<=people;i++)
			ccolor(icon[i*2]+":"+a[i].name+"ռ�ĸ��� ",col[i]);
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
		if(who<people)
			who++;
		else
			who=1;
	}
	system("cls");
	sort(a+1,a+1+people,cmp);
	ccolor("����\n���� ���� ռ������\n","white");
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
