/*
可怜的fish在一次次被魔王掳走一次次被勇者们救回来之后，而今，不幸的他再一次面临生命的考验。
魔王已经发出消息说将在T时刻吃掉fish，因为他听信谣言说吃fish的肉也能长生不老。年迈的国王正是心急如焚，
告招天下勇者来拯救fish。不过fish早已习以为常，他深信智勇的勇者肯定能将他救出。
现据密探所报，fish被关在一个两层的迷宫里，迷宫的入口是S（0，0，0），fish的位置用P表示，
时空传输机用# 表示，墙用*表示，平地用.表示。勇者们一进入时空传输机就会被转到另一层的相对位置，但如果被转到的位置是墙的话，
那勇者们就会被撞死。勇者们在一层中只能前后左右移动，每移动一格花1时刻。层间的移动只能通过时空传输机，且不需要任何时间。
Input
输入的第一行C表示共有C个测试数据，每个测试数据的前一行有三个整数N，M，T。 N，M迷宫的大小N* M（1 <= N,M <=10) 。
T如上所意。接下去的前N* M表示迷宫的第一层的布置情况，后N* M表示迷宫第二层的布置情况。
Output
如果勇者们能够在T时刻能找到fish就输出“YES”，否则输出“NO”。
Sample Input
1
5 5 14
S*#*.
.#...
.....
****.
...#.

..*.P
#.*..
***..
...*.
*.#..
Sample Output
YES

思路：bfs搜索,注意两个#可能可能会死循环

*/
```
#include <bits/stdc++.h>
#include <queue>
using namespace std;
int qq;
char mp1[3][120][120];
int book[3][120][120];
int next1[4][2]= {0,1,-1,0,0,-1,1,0};
int flag;
int n,m,t;
struct node
{
	int x;
	int y;
	int high;
	int t;
};
node endd;
void bfs()
{
	node start,S;
	queue<node> que;
	start.x=0;
	start.y=0;
	start.high=1;
	start.t=0;
	que.push(start);
	while(!que.empty())
	{
		node temp;
		temp=que.front();
		que.pop();
		if(temp.high==endd.high&&temp.x==endd.x&&temp.y==endd.y&&temp.t<=t)
		{
			flag=1;
			return ;
		}
		for(int i=0; i<4; i++)
		{
			int fx,fy;
			fx=temp.x+next1[i][0];
			fy=temp.y+next1[i][1];
			S.t=temp.t+1;
			int high=temp.high;
			if(fx<0||fx>=n||fy<0||fy>=m||mp1[high][fx][fy]=='*'||book[high][fx][fy]==1)
				continue;
			if(mp1[high][fx][fy]=='#')
			{
				int h;
				if(high==1)h=2;
				if(high==2)h=1;
				book[high][fx][fy]=1;
				if(mp1[h][fx][fy]!='*'&&mp1[h][fx][fy]!='#'&&book[h][fx][fy]==0)
					high=h;
				else
					continue;
			}
			book[high][fx][fy]=1;
			S.high=high;
			S.x=fx;
			S.y=fy;
			que.push(S);
		}
	}
	return;
}
int main()
{
	int c;
	cin>>c;
	while(c--)
	{
		memset(book,0,sizeof book);
		cin>>n>>m>>t;
		int f=0;
		for(int i=0; i<n; i++)
		{
			cin>>mp1[1][i];
			for(int k=0; k<m; k++)
			{
				if(mp1[1][i][k]=='P')
				{
					endd.x=i;
					endd.y=k;
					endd.high=1;
					f=1;
				}
			}
		}
		for(int j=0; j<n; j++)
		{
			cin>>mp1[2][j];
			if(f==0)
				for(int k=0; k<m; k++)
				{
					if(mp1[2][j][k]=='P')
					{
						endd.x=j;
						endd.y=k;
						endd.high=2;
					}
				}
		}
//		for(int i=1; i<=2; i++)
//		{
//			for(int j=0; j<n; j++)
//			{
//				cout<<mp1[i][j]<<endl;;
//			}
//			cout<<endl;
//		}
		book[0][0][0]=1;
		bfs();
		if(flag)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		flag=0;
	}
	return 0;
}
```
