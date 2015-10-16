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

//string line;
int line[11];
bool vis[11];
int len1,len2, n;
const int wei[] = {1,10,100,1000,10000,100000,1000000};
int ans;
int num1;

void dfs2(int d,int cur)
{
    if(abs(num1 - cur*wei[len2-d]) >= ans) return;
    if(d == len2){
        ans = min(ans,abs(num1-cur));
        return;
    }
    for(int j = 0; j < n; j++){
        if(!vis[j]){
            vis[j] = true;
            dfs2(d+1,cur*10+line[j]);
            vis[j] = false;
        }
    }
}

//permutation
void dfs1(int d,int cur)
{
    if(d == len1){
        num1 = cur;
        for(int fi = 0; fi < n; fi++){
            if(!vis[fi] && line[fi]){
                vis[fi] = true;
                dfs2(1,line[fi]);
                vis[fi] = false;
            }
        }
        return;
    }
    for(int j = 0; j < n; j++){
        if(!vis[j]){
            vis[j] = true;
            dfs1(d+1,cur*10+line[j]);
            vis[j] = false;
        }
    }
}

//0 2 , 0 3

//#define LOCAL
int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    int T; scanf("%d",&T);
    scanf("\n");
    while(T--){
        char ch;
        n = 0;
        while((ch = getchar())!= '\n'){
            if(isdigit(ch)){
                line[n++] = ch-'0';
            }
        }
        if(n == 2){ printf("%d\n",abs(line[0]-line[1])); continue; }
        len1 = n>>1; len2 = n-len1;
        ans = 1<<30;
        memset(vis,0,sizeof(vis));
        for(int fi = 0; fi < n; fi++){
            if(line[fi]){
                vis[fi] = true;
                dfs1(1,line[fi]);
                vis[fi] = false;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
