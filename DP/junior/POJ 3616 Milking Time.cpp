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
struct Seg
{
    int l,r,v;
    bool operator < (const Seg& th) const{
        return l < th.l ;//|| (l == rh.l && r < rh.r) ;
    }
    void IN(){ scanf("%d%d%d",&l,&r,&v); }
}seg[maxn];

int nxt[maxn];
int dp[maxn];
int n,m,R;

void sol()
{
    sort(seg,seg+m);
    seg[m].l = 1<<30;
    for(int i = 0; i < m; i++){
        int j = i+1;
        while(seg[j].l < seg[i].r) j++;
        nxt[i] = j;
    }
    for(int i = m; i--;){
        dp[i] = max(dp[i+1],dp[nxt[i]]+seg[i].v);
    }
    printf("%d\n",dp[0]);
}

//#define LOCAL
int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    scanf("%d%d%d",&n,&m,&R);
    for(int i = 0; i < m; i++){
        seg[i].IN();
        seg[i].r += R;
    }
    sol();
    return 0;
}
