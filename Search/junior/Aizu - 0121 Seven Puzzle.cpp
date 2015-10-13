#include<bits/stdc++.h>
using namespace std;

int d[40320];
int fac[8];
int u[8];

int cantor()
{
    int re = 0;
    for(int i = 0; i < 8; i++){
        int inv = 0;
        for(int j = i; ++j < 8; ){
            if(u[i]>u[j]) inv++;
        }
        re += fac[7-i]*inv;
    }
    return re;
}

void invCantor(int x)
{
    bool vis[8] = {};
    for(int i = 0; i < 8; i++){
        int w = x/fac[7-i];
        x %= fac[7-i];
        int j = 0;
        for( ; j < 8; j++){
            if(!vis[j]){
                if(!w) break;
                w--;
            }
        }
        u[i] = j; vis[j] = true;
    }
}

int cur;
queue<int> q;

inline void updata(int p0,int p1)
{
    swap(u[p0],u[p1]);
    int s = cantor();
    if(!d[s]){
        d[s] = d[cur]+1;
        q.push(s);
    }
    swap(u[p0],u[p1]);
}

void bfs()
{
    d[0] = 1;
    q.push(0);
    while(q.size()){
        invCantor(cur = q.front()); q.pop();
        int p;
        for(int i = 0; i < 8; i++)
            if(!u[i]){ p = i; break; }
        int r = p%4;
        if(r) {
            updata(p-1,p);
        }
        if(r<3){
            updata(p+1,p);
        }
        updata(p,p+(p>3?-4:4));
    }
}

void preDeal()
{
    fac[0] = 1;
    for(int i = 1; i < 8; i++){
        fac[i] = fac[i-1]*i;
    }
    bfs();
}

int read()
{
    if(scanf("%d",u)<0) return -1;
    for(int i = 1; i < 8; i++) scanf("%d",u+i);
    return cantor();
}

//#define LOCAL
int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    preDeal();
    int s;
    while( ~(s = read()) ){
        printf("%d\n",d[s]-1);
    }
    return 0;
}
