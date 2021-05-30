/*
Zty is a man that always full of enthusiasm. He wants to solve every kind of difficulty ACM problem in the world. And he has a habit that he does not like to solve
a problem that is easy than problem he had solved. Now yifenfei give him n difficulty problems, and tell him their relative time to solve it after solving the other one.
You should help zty to find a order of solving problems to solve more difficulty problem.
You may sure zty first solve the problem 0 by costing 0 minute. Zty always choose cost more or equal time’s problem to solve.
Input
The input contains multiple test cases.
Each test case include, first one integer n ( 2< n < 15).express the number of problem.
Than n lines, each line include n integer Tij ( 0<=Tij<10), the i’s row and j’s col integer Tij express after solving the problem i, will cost Tij minute to solve the problem j.
Output
For each test case output the maximum number of problem zty can solved.


Sample Input
3
0 0 0
1 0 1
1 0 0
3
0 2 2
1 0 1
1 1 0
5
0 1 2 3 1
0 0 2 3 1
0 0 0 3 1
0 0 0 0 2
0 0 0 0 0
Sample Output
3
2
4

题解：dfs直接搜更新最大值，题目中没有被解决过得且花费时间必须大于上一次的花费的问题，

*/

```
#include <bits/stdc++.h>
using namespace std;

int a[25][25];
int book[25];
int n,ans;

void dfs(int s, int i, int k)
{
	if(s>ans)
	{
		ans=s;
	}
	book[i]=1;
	for(int j=1; j<=n; j++)
	{
		if(book[j]==0&&a[i][j]>=k)
		{
			dfs(s+1,j,a[i][j]);
		}
	}
	book[i]=0;
}

int main()
{
	while(cin>>n)
	{
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				cin>>a[i][j];
			}
		}
		ans=0;
		dfs(1,1,0);
		cout<<ans<<endl;
	}
	return 0;
}
```
