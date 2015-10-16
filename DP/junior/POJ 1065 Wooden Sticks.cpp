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

const int N = 5e3+5;

struct Stick
{
    int l, w;
    bool operator <(const Stick &th) const{
        return l < th.l || (l == th.l && w < th.w);
    }
    void IN(){ scanf("%d%d",&l,&w); }
}stick[N];

int g[N];

//#define LOCAL
int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    int T; cin>>T;
    while(T--){
        int n; scanf("%d",&n);
        for(int i = 0; i < n; i++){
            stick[i].IN();
        }
        sort(stick,stick+n);
        memset(g,0x3f,sizeof(int)*n);
        int ans = 0;
        for(int i = n-1; i >= 0; i--){
            int k = lower_bound(g+1,g+n-i,stick[i].w)-g;
            ans = max(ans,k);
            g[k] = stick[i].w;
        }
        printf("%d\n",ans);
    }
    return 0;
}
