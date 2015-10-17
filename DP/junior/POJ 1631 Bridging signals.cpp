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

const int maxn = 4e4+5;
int g[maxn];

//#define LOCAL
int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    int T; cin>>T;
    while(T--){
        int n, ans = 0; scanf("%d",&n);
        for(int i = 0,c = 1; i < n; i++){
            int x, k; scanf("%d",&x);
            k = lower_bound(g+1,g+c,x)-g;
            ans = max(ans,k);
            g[k] = x;
            if(k==c) c++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
