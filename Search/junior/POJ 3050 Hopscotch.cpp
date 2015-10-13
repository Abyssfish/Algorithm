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

const int maxn = 5;
int g[maxn][maxn];

bool inside(int x,int y)
{
    return x>=0&&x<maxn&&y>=0&&y<maxn;
}

set<stack<int> > S;
stack<int> stk;
const int dx[] = {0,0,-1,1}, dy[] = {1,-1,0,0};
void dfs(int x,int y)
{
    if(!inside(x,y)) return;
    if(stk.size() == 6){
        S.insert(stk);
        return ;
    }
    for(int i = 0; i < 4; i++){
        int nx = x+dx[i], ny = y+dy[i];
        if(inside(nx,ny)){
            stk.push(g[nx][ny]);
            dfs(nx,ny);
            stk.pop();
        }
    }
}

//#define LOCAL
int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    for(int i = 0; i < maxn; i++){
        for(int j = 0; j < maxn; j++){
            scanf("%d",g[i]+j);
        }
    }
   for(int i = 0; i < maxn; i++)
        for(int j = 0; j < maxn; j++)
            dfs(i,j);
    printf("%d\n",S.size());
    return 0;
}
