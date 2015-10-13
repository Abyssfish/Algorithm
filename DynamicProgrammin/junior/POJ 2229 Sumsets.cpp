#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

const int mod = 1e9, maxn = 1e6+1;
int dp[maxn];
/*
有序地构造，划分是合并的逆过程
先把N展开成全部为1
然后合并，因为和顺序无关，所以只考虑出现次数
情况有点多，分类，C[i]表示序列中最大的数为2^i时的方案数

树形表示
7 (2^0) (7表示2^0出现的次数)
-----
| | |
1 2 3 (2^1) (7个1可以合并成1~3个2)
  _ _
  | |
  1 1 (2^2) (继续合并)
这棵树是分形的

f[n]表示方案
当n是偶数，第一层会增加一颗子树 其值为 n/2
当n是奇数，树的形态不变

*/
//#define LOCAL
int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    int n; cin>>n;
    dp[1] = 1;
    for(int i = 2; i <= n ; i++) {
        dp[i] = dp[i-1] + (i&1?0:dp[i>>1]);
        if(dp[i]>=mod) dp[i] -= mod;
    }
    cout<<dp[n]<<endl;
    return 0;
}
