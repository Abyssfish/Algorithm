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

#define PS push
#define PB push_back
#define MP make_pair
#define fi first
#define se second

const int maxm = 1e5+5;
const int maxn = 101;

bool dp[maxm];

int A[maxn], C[maxn];

int n, m;

inline int read()
{
    int ret; char c; while(c = getchar(),c<'0'||c>'9');
    ret = c-'0';
    while(c = getchar(),c>='0'&&c<='9') ret = ret*10 + c-'0';
    return ret;
}

//#define LOCAL
int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    dp[0] = true;
    while(scanf("%d%d",&n,&m),n+m){
        for(int i = 0; i < n; i++)
            A[i] = read();
        for(int i = 0; i < n; i++){
            C[i] = read();
        }
        int ans = 0;
        memset(dp+1,0,sizeof(bool)*m);
        for(int i = 0; i < n; i++){
            int cnt[maxm] = {};
            for(int j = A[i]; j <= m; j++){
                if(!dp[j] && dp[j-A[i]] && cnt[j-A[i]] < C[i]){
                    cnt[j] = cnt[j-A[i]] + 1;
                    ans++;
                    dp[j] = true;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
