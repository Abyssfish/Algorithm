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
#include<cmath>
//#include<bits/stdc++.h>
using namespace std;

#define PB push_back
const int maxn = 1e3+2;
int x[maxn], y[maxn];
bool vis[maxn];
vector<int> nei[maxn];
inline int squ(int a){ return a*a; }
inline int dist(int i,int j){ return squ(x[i]-x[j])+squ(y[i]-y[j]); }
//const int eps = 1e-9;
int pa[maxn], hei[maxn];
int fdst(int x){ return x==pa[x]?x:pa[x]=fdst(pa[x]); }
inline void mrge(int a,int b)
{
    int s1 = fdst(a), s2 = fdst(b);
    if(s1 != s2){
        if(hei[s1] < hei[s2]) pa[s1] = s2;
        else {
            pa[s2] = s1;
            if(hei[s1] == hei[s2]) hei[s1]++;
        }
    }
}

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
    int N, d; scanf("%d%d",&N,&d);
    for(int i = 1; i <= N; i++){
        x[i] = read(); y[i] = read();
        pa[i] = i;
    }
    int dsqu = d*d;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j < i; j++){
            if(dist(i,j)<= dsqu){
                nei[i].PB(j);
                nei[j].PB(i);
            }
        }
    }
    char op[2];
    int p,q;
    while(~scanf("%s",op)){
        p = read();
        if(*op=='O'){
            if(vis[p]) continue;
            vis[p] = true;
            for(int i = 0; i < (int)nei[p].size(); i++){
                if(vis[nei[p][i]])
                    mrge(p,nei[p][i]);
            }
        }else {
            q = read();
            puts(fdst(p) == fdst(q)?"SUCCESS":"FAIL");
        }
    }
    return 0;
}
