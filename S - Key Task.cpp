/*
The Czech Technical University is rather old — you already know that it celebrates 300 years of its existence in 2007. Some of the university buildings are old as well. And the navigation in old buildings can sometimes be a little bit tricky, because of strange long corridors that fork and join at absolutely unexpected places.
The result is that some first-graders have often di?culties finding the right way to their classes. Therefore, the Student Union has developed a computer game to help the students to practice their orientation skills. The goal of the game is to find the way out of a labyrinth. Your task is to write a verification software that solves this game.
The labyrinth is a 2-dimensional grid of squares, each square is either free or filled with a wall. Some of the free squares may contain doors or keys. There are four di?erent types of keys and doors: blue, yellow, red, and green. Each key can open only doors of the same color.
You can move between adjacent free squares vertically or horizontally, diagonal movement is not allowed. You may not go across walls and you cannot leave the labyrinth area. If a square contains a door, you may go there only if you have stepped on a square with an appropriate key before.
Input
The input consists of several maps. Each map begins with a line containing two integer numbers R and C (1 ≤ R, C ≤ 100) specifying the map size. Then there are R lines each containing C characters. Each character is one of the following:
Note that it is allowed to have
more than one exit,
no exit at all,
more doors and/or keys of the same color, and
keys without corresponding doors and vice versa.
You may assume that the marker of your position (“*”) will appear exactly once in every map.
There is one blank line after each map. The input is terminated by two zeros in place of the map size.
Output
For each map, print one line containing the sentence “Escape possible in S steps.”, where S is the smallest possible number of step to reach any of the exits. If no exit can be reached, output the string “The poor student is trapped!” instead.
One step is defined as a movement between two adjacent cells. Grabbing a key or unlocking a door does not count as a step.
思路： 
	struct node {
	int x,y;
	int st;
	int k;
};
这个k存储的是钥匙，并且是用二进制存储 
vis[x1][y1][f.k]这个代表走到x1,y1时只有f.x钥匙比若说后四位1111就代表四八钥匙全有了并且钥匙可以重复使用
 
*/

```
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2+100;
char a[maxn][maxn];
int vis[maxn][maxn][33];
int nex[4][2]= {{0,1},{-1,0},{0,-1},{1,0}};
int n,m;
int dx,dy;

struct node {
	int x,y;
	int st;
	int k;
};

bool check(int x,int y) {
	if(a[x][y]=='#') return false;
	if(x<0||y<0||x>=n||y>=m) return false;
	return true;
}

int to(char c) {
	if(c=='b'||c=='B') return 0;
	if(c=='Y'||c=='y') return 1;
	if(c=='R'||c=='r') return 2;
	if(c=='g'||c=='G') return 3;
}

void bfs() {
	node t;
	t.x=dx;
	t.y=dy;
	t.st=0;
	t.k=0;
	a[dx][dy]='.';
	memset(vis,0,sizeof vis);
	queue<node> que;
	vis[dx][dy][t.k]=1;
	que.push(t);
	while(!que.empty()) {
		node f = que.front();
		for(int i=0; i<4; i++) {
			int x1,y1;
			x1=f.x+nex[i][0];
			y1=f.y+nex[i][1];	
			if(check(x1,y1)) {
//					cout<<x1<<" "<<y1<<endl;
				if(a[x1][y1]=='.'&&!vis[x1][y1][f.k]) {
					vis[x1][y1][f.k]=1;
					node temp;
					temp.x=x1;
					temp.y=y1;
					temp.st=f.st+1;
					temp.k=f.k;
					que.push(temp);

				} else if(a[x1][y1]>='a'&&a[x1][y1]<='z') {
					int hh=1<<to(a[x1][y1]);
					int t1=f.k;
					if((f.k&hh)==0)
						t1+=hh;
					if(!vis[x1][y1][t1]) {
						vis[x1][y1][t1]=1;
						node temp;
						temp.x=x1;
						temp.y=y1;
						temp.st=f.st+1;
						temp.k=t1;
						que.push(temp);
					}
				} else if(a[x1][y1]>='A'&&a[x1][y1]<='Z') {
					if(a[x1][y1]=='X') {
						printf("Escape possible in %d steps.\n",f.st+1);
						return;
					}
					int h1=1<<to(a[x1][y1]);
					if((h1&f.k)&&!vis[x1][y1][f.k]) {
						vis[x1][y1][f.k]=1;
						node temp;
						temp.x=x1;
						temp.y=y1;
						temp.st=f.st+1;
						temp.k=f.k;
						que.push(temp);
					}
				}
			}
		}
		que.pop();
	}
	cout<<"The poor student is trapped!"<<endl;
	return ;
}
int main() {
	while(cin>>n>>m) {
		if(n==m&&m==0) {
			break;
		}
		for(int i=0; i<n; i++) {
			cin>>a[i];
		}
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(a[i][j]=='*') {
					dx=i;
					dy=j;
					break;
				}
			}
		}
//		cout<<dx<<" "<<dy<<endl;
		bfs();
	}
	return 0;
}
```
