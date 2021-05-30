/*
7月17日是Mr.W的生日，ACM-THU为此要制作一个体积为Nπ的M层生日蛋糕，每层都是一个圆柱体。
设从下往上数第i(1 <= i <= M)层蛋糕是半径为Ri, 高度为Hi的圆柱。当i < M时，要求Ri > Ri+1且Hi > Hi+1。
由于要在蛋糕上抹奶油，为尽可能节约经费，我们希望蛋糕外表面（最下一层的下底面除外）的面积Q最小。
令Q = Sπ
请编程对给出的N和M，找出蛋糕的制作方案（适当的Ri和Hi的值），使S最小。
（除Q外，以上所有数据皆为正整数）
Input
有两行，第一行为N（N <= 10000），表示待制作的蛋糕的体积为Nπ；第二行为M(M <= 20)，表示蛋糕的层数为M。
Output
仅一行，是一个正整数S（若无解则S = 0）。
Sample Input
100
2
Sample Output
68

思路：需要减枝，看题解写的
在三个地方进行剪枝
1.剩余体积大于最大可能体积剪枝
2.当前面积比最小大剪枝
3.当前面积加上剩下最小面积大于最小面积剪枝


*/
```
#include <iostream>
using namespace std;
int r[30],h[30];
int minv[30],mins[30];
int ans;
int now,v;
int n,m;
void dfs(int now,int sumV,int sumS,int lastR,int lastH)
{
	if(now*(lastR-1)*(lastR-1)*(lastH-1)<sumV&&now!=m||sumV<0)
		return;
	if(ans&&sumS>ans) 
		return;
	if(now==0)
	{
		if(sumV==0&&(sumS<ans||!ans)) 
			ans=sumS;
		return;
	}
	for(int r=lastR-1; r>=now; r--)
		for(int h=lastH-1; h>=now; h--)
		{
			int curV=r*r*h;
			int curA=2*r*h;
			if(now==m)
				curA+=r*r;
			if(sumS+2*sumV/r>ans&&ans) 
				continue;
			dfs(now-1,sumV-curV,sumS+curA,r,h);
		}

}
int main()
{
	cin>>n>>m;
	dfs(m,n,0,100,1000);
	cout<<ans<<endl;
	return 0;
}
```
