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
		cout<<"���������"<<i<<"�����֣�";
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
			cout<<a[i].name<<"ռ����:"<<a[i].cnt<<" ";
		cout<<endl;
		cout<<"ʣ�����:"<<have<<endl;
		cout<<"��"<<a[who].name<<"��"<<endl;
		cout<<"1:"<<a[1].name<<"�ڵ�λ�� 2:"<<a[2].name<<"�ڵ�λ�� o:"<<a[1].name<<"ռ�ĸ��� x:"<<a[2].name<<"ռ�ĸ���";
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
		cout<<a[1].name<<"ʤ����ռ��"<<a[1].cnt<<"�飡";
	else
		if(a[1].cnt<a[2].cnt)
			cout<<a[2].name<<"ʤ����ռ��"<<a[2].cnt<<"�飡";
		else
			cout<<"ƽ�֣���ռ��"<<a[1].cnt<<"�飡";
	Sleep(3000);
	return 0;
}

