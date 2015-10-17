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
//#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e3+5, maxs = 2e5, bound = 1e5;
int s[maxn], f[maxn];
int dp[maxs+5];

//#define LOCAL
int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    int n, c = 0; cin>>n;
    int TS = 0, TF = 0;
    for(int i = n; i--;){
        scanf("%d%d",s+c,f+c);
        if(s[c]>0 && f[c]>0){
            TS += s[c];
            TF += f[c];
            continue;
        }
        if(s[c]<=0 && f[c]<=0) continue;
        c++;
    }
    memset(dp,0xc0,sizeof(dp));
    dp[bound] = 0;
    for(int i = c; i--;){
        if(s[i]>0){
            for(int j = maxs; j >= s[i]; j--){
                dp[j] = max(dp[j],dp[j-s[i]] + f[i]);
            }
        }
        else {
            for(int j = 0; j-s[i] <= maxs; j++){
                dp[j] = max(dp[j],dp[j-s[i]] + f[i]);
            }
        }
    }
    int ans = bound;
    for(int i = bound; i <= maxs; i++){
        if(dp[i]+TF>=0) ans = max(i+dp[i],ans);
    }
    printf("%d\n",ans-bound+TS+TF);
    return 0;
}
