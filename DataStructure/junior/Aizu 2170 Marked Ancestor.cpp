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

const int maxn = 1e5+5;
int pa[maxn];
int Mrk[maxn];

int qt[maxn],qv[maxn];
int Qt;
int fdst(int x)
{
    return Mrk[x] < Qt ? x :pa[x] = fdst(pa[x]);
}

//#define LOCAL
int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    int N, Q;
    while(scanf("%d%d",&N,&Q),N){
        for(int i = 2; i <= N; i++){
            scanf("%d",pa+i);
            Mrk[i] = Q+1;
        }
        int c = 0;
        for(int i = 1; i <= Q; i++){
            char op[2];
            int v;
            scanf("%s%d",op,&v);
            if(*op == 'Q'){
                qt[c] = i;
                qv[c++] = v;
            }else {
                Mrk[v] = min(Mrk[v],i);//取最早生效的标记
            }
        }
        long long ans = 0;
        while(c--){
            Qt = qt[c];
            ans += fdst(qv[c]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
