#include<bits/stdc++.h>
#include<conio.h> 
#include<windows.h>
using namespace std;
int ma[13][13];
int main(){
	memset(ma,0,sizeof(ma));
	int x[5],y[5],have=98,pc[5];
	pc[0]=1;pc[1]=1;
	x[0]=1;y[0]=1;x[1]=10;y[1]=10;
	bool p1=true;
	ma[1][1]=1;
	ma[10][10]=2;
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
						cout<<"2";
						break;
					case 3:
						cout<<"x";
						break;
					case 4:
						cout<<"o";
				}
			cout<<endl;
		}
		cout<<"���1ռ����:"<<pc[0]<<" ���2ռ����:"<<pc[1]<<endl;
		cout<<"ʣ�����:"<<have<<endl;
		cout<<"�����"<<!p1+1<<"��"<<endl;
		cout<<"1:���1�ڵ�λ�� 2:���2�ڵ�λ�� o:���1ռ�ĸ��� x:���2ռ�ĸ���";
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
		int nx=x[!p1]+wx,ny=y[!p1]+wy;
		if(nx>0&&nx<11&&ny>0&&ny<11&&ma[nx][ny]!=p1+1&&ma[nx][ny]!=!p1+3){
			ma[x[!p1]][y[!p1]]=p1+3;
			if(!ma[nx][ny]){
				pc[!p1]++;
				have--;
			}
			ma[nx][ny]=!p1+1;
			x[!p1]=nx;
			y[!p1]=ny;
		}
		p1=!p1;
	}
	system("cls");
	if(pc[0]>pc[1])
		cout<<"���1ʤ����ռ��"<<pc[0]<<"�飡";
	else
		if(pc[1]<pc[0])
			cout<<"���2ʤ����ռ��"<<pc[1]<<"�飡";
		else
			cout<<"ƽ�֣���ռ��"<<pc[0]<<"�飡";
	Sleep(3000);
	return 0;
}

