#include<bits/stdc++.h>
#include<conio.h> 
#include<windows.h>
using namespace std;
int ma[13][13];
struct peo{
	int x,y,cnt;
	string name;
};
int who=1,have=98;
int main(){
	memset(ma,0,sizeof(ma));
	peo a[5];
	a[1].cnt=1;a[2].cnt=1;
	a[1].x=1;a[1].y=1;
	a[2].x=10;a[2].y=10;
	ma[1][1]=1;
	ma[10][10]=3;
	for(int i=1;i<=2;i++){
		cout<<"请输入玩家"<<i<<"的名字：";
		cin>>a[i].name;
	}
	system("cls");
	while(have){
		system("cls");
		for(int i=1;i<=10;i++){
			for(int j=1;j<=10;j++)
				switch(ma[i][j]){
					case 0:
						cout<<" ";
						break;
					case 1:
						cout<<"1";
						break;
					case 2:
						cout<<"o";
						break;
					case 3:
						cout<<"2";
						break;
					case 4:
						cout<<"x";
				}
			cout<<endl;
		}
		for(int i=1;i<=2;i++)
			cout<<a[i].name<<"占格数:"<<a[i].cnt<<" ";
		cout<<endl;
		cout<<"剩余格数:"<<have<<endl;
		cout<<"该"<<a[who].name<<"了"<<endl;
		cout<<"1:"<<a[1].name<<"在的位置 2:"<<a[2].name<<"在的位置 o:"<<a[1].name<<"占的格子 x:"<<a[2].name<<"占的格子";
		char ch=getch();
		int wx=0,wy=0;
		switch(ch){
			case 'w':
				wx--;
				break;
			case 'a':
				wy--;
				break;
			case 'd':
				wy++;
				break;
			case 's':
				wx++;
		}
		int nx=a[who].x+wx,ny=a[who].y+wy;
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
	if(a[1].cnt>a[2].cnt)
		cout<<a[1].name<<"胜利，占了"<<a[1].cnt<<"块！";
	else
		if(a[1].cnt<a[2].cnt)
			cout<<a[2].name<<"胜利，占了"<<a[2].cnt<<"块！";
		else
			cout<<"平局，都占了"<<a[1].cnt<<"块！";
	Sleep(3000);
	return 0;
}

