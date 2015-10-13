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

const int maxn = 1e3+5;
int val[2][maxn];
int dp[31][2];

//#define LOCAL
int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    int T,W;
    cin>>T>>W;
    for(int i = 0; i < T; i++) {
        int x; scanf("%d",&x);
        val[x-1][i] = 1;
    }
    for(int t = T-1; t >= 0; t--){
        for(int w = W; w >= 0; w--){
            for(int i = 0; i < 2; i++){
                dp[w][i] += val[i][t];
                if(w) dp[w][i] = max(dp[w][i],dp[w-1][i^1]+val[i^1][t]);
            }
        }
    }
    printf("%d\n",max(dp[W][0],dp[W][1]));
    return 0;
}
