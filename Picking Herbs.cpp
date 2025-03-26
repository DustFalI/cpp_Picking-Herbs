#include <bits/stdc++.h>
using namespace std;
int t, m, val[105], tt[105], ans = 0, dp[105][1005] = {0};
int main()
{
	cin >> t >> m;
	for(int i = 1; i <= m;  i++)
	{
		cin >> tt[i] >> val[i];
	}
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= t; j++)
		{
			int nv = val[i], nt = tt[i];
			if(nt <= j && dp[i][j] < nv)
			{
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-tt[i]] + val[i]);
			}
			else
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	cout << dp[m][t];
	return 0;
}
