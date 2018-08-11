#include <fstream>
using namespace std;
ifstream in("gradina.in");
ofstream out("gradina.out");

bool gradina[1005][1005];

int main() {
	int nr,p,k,maxPosib=1,maxPomi=0;
	in>>nr>>p>>k;
	for(int i=0;i<p;i++)
	{
		int lin,col;
		in>>lin>>col;
		gradina[lin][col]=true;
	}
	for(int i=1;i<=nr-k;i++)
	{
		for(int j=1;j<=nr-k;j++)
		{
			int pomi = 0;
			for(int m=i;m<i+k;m++)
			{
				for(int n=j;n<j+k;n++)
				{
					if(gradina[m][n])
						pomi++;	
				}
			}
			if(pomi == maxPomi)
				maxPosib++;
			if(pomi>maxPomi)
			{
				maxPosib=1;
				maxPomi=pomi;
			}
		}
	}
	out<<maxPomi<<"\n"<<maxPosib;
	return 0;
}
