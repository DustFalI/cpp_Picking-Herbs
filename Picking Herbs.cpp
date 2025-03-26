#include <bits/stdc++.h>
using namespace std;
int t, m, val[105], tt[105], ans = 0, dp[105][1005] = {0};//动态规划数组，没什么好说的
int main()
{
	cin >> t >> m;
	for(int i = 1; i <= m;  i++)
	{
		cin >> tt[i] >> val[i];//获取信息，没什么好说的
	}
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= t; j++)
		{
			int nv = val[i], nt = tt[i];//临时变量，方便
			if(nt <= j && dp[i][j] < nv)//判定，如果当前物品时间小于背包时间（j）代表可以放下并且当前位置比上一格小代表不是最优解
			{
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-tt[i]] + val[i]);//[i-1]代表上一行，因为物品只能选一次只能在上一行选择，tt[i]代表当前物品的时间，[j-tt[i]]代表减去当前时间剩余时间的最优解
			}//总体思路就是减去当前时间，在寻找剩下时间状态下的最优解，如何将其与上一格比较，区最大值就是这一个物品这一个包裹下的最优解。
			else
			{
				dp[i][j] = dp[i-1][j];//
			}
		}
	}
	cout << dp[m][t];//
	return 0;
}
