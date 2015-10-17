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

const int maxk = 401, maxh = 4e4+5;
struct Block
{
    int h, a, c;
    bool operator <(const Block& th) const{
        return a < th.a;
    }
    void IN(){ scanf("%d%d%d",&h,&a,&c); }
}B[maxk];

int f[maxh];

//#define LOCAL
int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    int k;
    scanf("%d",&k);
    for(int i = k; i--;) B[i].IN();
    sort(B,B+k);
    int ans = 0;
    memset(f+1,-1,sizeof(int)*B[k-1].a);
    for(int i = 0; i < k; i++){
        for(int j = 0; j <= B[i].a; j++){
            if(~f[j]) f[j] = B[i].c;
            else if(j>=B[i].h && f[j-B[i].h] > 0){
                f[j] = f[j-B[i].h] - 1;
                ans = max(j,ans);
            }else f[j] = -1;
        }
    }
    printf("%d\n",ans);
    return 0;
}
