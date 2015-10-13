#include<bits/stdc++.h>
using namespace std;

const int maxn = 10000;
bitset<maxn> bs[20];
bitset<maxn> *pbs[10];
//#define LOCAL
int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    int R,C;
    while(cin>>R>>C && R){
        cin.ignore();
        string line;
        for(int i = R; i--;){
            getline(cin,line);
            remove(line.begin(),line.end(),' ');
            line.resize(C);
            stringstream strin(line);
            strin>>bs[i];
        }
        for(int i = R; i--;){
            bs[i+R] = bs[i];
            bs[i+R].flip();
        }
        int ans = 0;
        for(int S = 1<<R; --S >= 0;){
            for(int i = 0; i < R; i++){
                pbs[i] = bs + i + (S>>i&1?R:0);
            }
            int cur = 0;
            for(int j = 0; j < C; j++){
                int cnt = 0;
                for(int i = 0; i < R; i++){
                    if((*pbs[i])[j]) cnt++;
                }
                cur += max(cnt,R-cnt);
            }
            ans = max(cur,ans);
        }
        printf("%d\n",ans);
    }
    return 0;
}
