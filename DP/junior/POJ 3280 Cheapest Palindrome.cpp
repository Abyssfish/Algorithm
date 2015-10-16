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

const int sigma_size = 26, maxm = 2e3+5;
char s[maxm];
int add[sigma_size], del[sigma_size];
int cost[sigma_size];
int dp[maxm][maxm];

//#define LOCAL
int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    int n, m;
    scanf("%d%d",&n,&m);
    scanf("%s",s);
    for(int i = n; i--;){
        char ch[2];
        scanf("%s",ch);
        int id = *ch-'a';
        scanf("%d%d",add+id,del+id);
        cost[id] = min(add[id],del[id]);
    }
    for(int L = 2; L <= m; L++){
        for(int i = 0; i+L <= m; i++){
            int j = i+L;
            if(s[i] == s[j-1]){
                dp[i][j] = dp[i+1][j-1]; // empty 0
            }else {
                dp[i][j] = min(dp[i+1][j] + cost[s[i]-'a'], dp[i][j-1] + cost[s[j-1]-'a']);
            }
        }
    }
    printf("%d\n",dp[0][m]);
    return 0;
}
