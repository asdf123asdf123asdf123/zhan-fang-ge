#include<bits/stdc++.h>
#include<conio.h> 
#include<windows.h>
using namespace std;
int ma[13][13];
int main(){
	memset(ma,0,sizeof(ma));
	int x1=1,y1=1,x2=10,y2=10,count=98,pc1=1,pc2=1;
	bool p1=true;
	ma[1][1]=1;
	ma[10][10]=2;
	while(count){
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
		cout<<"���1ռ����:"<<pc1<<" ���2ռ����:"<<pc2<<endl;
		cout<<"ʣ�����:"<<count<<endl;
		cout<<"�����"<<(p1?"1":"2")<<"��"<<endl;
		cout<<"1:���1�ڵ�λ�� 2:���2�ڵ�λ�� o:���1ռ�ĸ��� x:���2ռ�ĸ���";
		char ch=getch();
		if(p1)
			switch(ch){
				case 'w':
					if(x1>1&&ma[x1-1][y1]!=2&&ma[x1-1][y1]!=3){
						ma[x1][y1]=4;
						x1--;
						if(!ma[x1][y1]){
							pc1++;
							count--;
						}
						ma[x1][y1]=1;
					}
					break;
				case 'a':
					if(y1>1&&ma[x1][y1-1]!=2&&ma[x1][y1-1]!=3){
						ma[x1][y1]=4;
						y1--;
						if(!ma[x1][y1]){
							pc1++;
							count--;
						}
						ma[x1][y1]=1;
					}
					break;
				case 'd':
					if(y1<10&&ma[x1][y1+1]!=2&&ma[x1][y1+1]!=3){
						ma[x1][y1]=4;
						y1++;
						if(!ma[x1][y1]){
							pc1++;
							count--;
						}
						ma[x1][y1]=1;
					}
					break;
				case 's':
					if(x1<10&&ma[x1+1][y1]!=2&&ma[x1+1][y1]!=3){
						ma[x1][y1]=4;
						x1++;
						if(!ma[x1][y1]){
							pc1++;
							count--;
						}
						ma[x1][y1]=1;
					}
			}
		else
			switch(ch){
				case 'w':
					if(x2>1&&ma[x2-1][y2]!=1&&ma[x2-1][y2]!=4){
						ma[x2][y2]=3;
						x2--;
						if(!ma[x2][y2]){
							pc2++;
							count--;
						}
						ma[x2][y2]=2;
					}
					break;
				case 'a':
					if(y2>1&&ma[x2][y2-1]!=1&&ma[x2][y2-1]!=4){
						ma[x2][y2]=3;
						y2--;
						if(!ma[x2][y2]){
							pc2++;
							count--;
						}
						ma[x2][y2]=2;
					}
					break;
				case 'd':
					if(y2<10&&ma[x2][y2+1]!=1&&ma[x2][y2+1]!=4){
						ma[x2][y2]=3;
						y2++;
						if(!ma[x2][y2]){
							pc2++;
							count--;
						}
						ma[x2][y2]=2;
					}
					break;
				case 's':
					if(x2<10&&ma[x2+1][y2]!=1&&ma[x2+1][y2]!=4){
						ma[x2][y2]=3;
						x2++;
						if(!ma[x2][y2]){
							pc2++;
							count--;
						}
						ma[x2][y2]=2;
					}
			}
		p1=!p1;
	}
	system("cls");
	if(pc1>pc2)
		cout<<"���1ʤ����ռ��"<<pc1<<"�飡";
	else
		if(pc2<pc1)
			cout<<"���2ʤ����ռ��"<<pc2<<"�飡";
		else
			cout<<"ƽ�֣���ռ��"<<pc1<<"�飡";
	Sleep(3000);
	return 0;
}

