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

bool dp[maxm], q[maxm];

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
        memset(dp+1,0,sizeof(int)*m);
        for(int i = 0; i < n; i++){
            if(C[i] == 1){
                for(int j = m; j >= A[i]; j--){
                    if(dp[j-A[i]] && !dp[j]) dp[j] = true;
                }
            }
            else
            if(A[i]*C[i] >= m){
                for(int j = A[i]; j <= m; j++){
                    if(dp[j-A[i]] && !dp[j]) dp[j] = true;
                    //if(dp[j-A[i]] && !dp[j]) dp[j] = true; 2110 ms
                    //if(dp[j-A[i]]) dp[j] = true; 2813 ms
                    //dp[j] = dp[j-A[i]] || dp[j]; 2891 ms
                }
            }
            else {
                for(int r = 0; r < A[i]; r++){
                    int sum = 0, hd = 0, rr = 0;
                    for(int j = r; j <= m; j += A[i]){
                        if(rr - hd > C[i]){
                            sum -= q[hd++];
                        }
                        sum += q[rr++] = dp[j];
                        if(sum && !dp[j]) dp[j] = true;
                    }
                }
            }
        }
        for(int i = 1; i <= m; i++) ans += dp[i];
        printf("%d\n",ans);
    }
    return 0;
}
