/*
伊菲的家在乡下，而梅基的家在市中心。于是，伊菲和梅基安排在KFC见面。西安有很多KFC，他们想选择一个花费总时间最短的KFC见面。
现在给你一张西安的地图，伊菲和梅基都可以上、下、左、右移动到相邻的地点，每移动一个位置花费11分钟。

Input
输入包含多个测试用例。
每个测试用例包括前两个整数n，m.（2<=n，m<=200）。
接下来的n行，每行包含m个字符。
“Y”表示伊菲的初始位置。
“M”表示梅基初始位置。
“#”死路；
'.'可走的路。
“@” KCF
对于每个测试用例，输出伊菲和梅基花费的最短总时间。总有一家KFC可以让他们见面。

Sample Input
4 4
Y.#@
….
.#..
@..M
4 4
Y.#@
….
.#..
@#.M
5 5
Y..@.
.#…
.#…
@..M.
#…#

Sample Output
66
88
66

题解：双向bfs，开个三维数组book[220][200][2]存每个人到@所画的时间
然后取每个人到@的时间和的最小值
*/

```
#include <bits/stdc++.h>
using namespace std;
char mp1[220][220];
int book[220][200][2];
int next1[4][2]= {1,0,0,1,-1,0,0,-1};
struct node
{
	int x;
	int y;
};
int n,m;
void bfs(node q,int z)
{
	queue<node> que;
	que.push(q);
	while(!que.empty())
	{
		node w;
		w = que.front();
		que.pop();
		for(int i=0; i<4; i++)
		{
			int x=w.x+next1[i][0];
			int y=w.y+next1[i][1];
			if(x<0||x>=n||y<0||y>=m)
				continue;
			if(!book[x][y][z]&&mp1[x][y]!='#')
			{
				book[x][y][z]=book[w.x][w.y][z]+1;
				node s;
				s.x = x;
				s.y = y;
				que.push(s);
			}
		}
	}
}
int main()
{

	while(cin>>n>>m)
	{
		getchar();
		memset(book,0,sizeof book);
		queue<node > que;
		int y1,y2,m1,m2;
		node Y,M;
		for(int i=0; i<n; i++)
		{
			cin>>mp1[i];
		}
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
			{
				if(mp1[i][j]=='M')
				{
					M.x = i;
					M.y = j;
				}
				if(mp1[i][j]=='Y')
				{
					Y.x = i;
					Y.y = j;
				}
				if(mp1[i][j]=='@')
				{
					node s;
					s.x = i;
					s.y = j;
					que.push(s);
				}
			}

		bfs(M,0);
		bfs(Y,1);
		int mina = 9999999;
		while(!que.empty())
		{
			node s=que.front();
			que.pop();
			if(book[s.x][s.y][0]&&book[s.x][s.y][1])
				mina=min(book[s.x][s.y][0]+book[s.x][s.y][1],mina);

		}
		cout<<mina*11<<endl;
	}
	return 0;
}
```
