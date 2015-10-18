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


const int maxn = 2e5+2;
int pa[maxn];
int hei[maxn];

int fdst(int x){ return x==pa[x]?x:pa[x]=fdst(pa[x]); }
inline void mrge(int a,int b)
{
    int s1 = fdst(a), s2 = fdst(b);
    if(s1 != s2){
        if(hei[s1] < hei[s2])
            pa[s1] = s2;
        else {
            pa[s2] = s1;
            if(hei[s1] == hei[s2]) hei[s1]++;
        }
    }
}
inline bool same(int a,int b){ return fdst(a) == fdst(b); }

void initDisjointSet(int n)
{
    for(int i = 1; i <= n; i++){
        pa[i] = i;
        hei[i] = 0;
    }
}

//#define LOCAL
int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    int T; cin>>T;
    while(T--){
        int n, m; scanf("%d%d",&n,&m);
        initDisjointSet(n*2);
        while(m--){
            char ch[2];
            int a,b;
            scanf("%s%d%d",ch,&a,&b);
            if(*ch == 'D'){
                mrge(a,b+n);
                mrge(a+n,b);
            }else {
                if(same(a,b+n)){
                    puts("In different gangs.");
                }else if(same(a,b)){
                    puts("In the same gang.");
                }else puts("Not sure yet.");
            }
        }
    }
    return 0;
}
