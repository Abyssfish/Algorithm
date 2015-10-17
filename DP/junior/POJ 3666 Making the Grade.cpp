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

const int maxn = 2001;
int a[maxn],b[maxn];

int dp[maxn];

//#define LOCAL
int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    int n; scanf("%d",&n);
    for(int i = 0; i < n; i++) scanf("%d",a+i);
    memcpy(b,a,sizeof(int)*n);
    sort(b,b+n);
    //dp zero
    for(int i = 0; i < n; i++){
        int mn = 1<<30;
        for(int j = 0; j < n; j++){
            mn = min(mn,dp[j]);
            dp[j] = mn+abs(a[i]-b[j]);
        }
    }
    printf("%d\n",*min_element(dp,dp+n));
    return 0;
}
