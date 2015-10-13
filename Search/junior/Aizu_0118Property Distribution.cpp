#include<bits/stdc++.h>
using namespace std;
const int N = 105;

char g[N][N], cur;

bool dfs(int i,int j)
{
    if(!g[i][j] || g[i][j] != cur) return false;
    g[i][j] = 0;
    dfs(i,j-1); dfs(i-1,j); dfs(i+1,j); dfs(i,j+1);
    return true;
}

//#define LOCAL
int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    int X,Y;
    while(scanf("%d%d\n",&Y,&X),X){
        for(int i = 1; i <= Y; i++){
            gets(g[i]+1);
        }
        int ans = 0;
        for(int i = 1; i <= Y; i++){
            for(int j = 1; j <= X; j++){
                cur = g[i][j];
                if(dfs(i,j)) ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
