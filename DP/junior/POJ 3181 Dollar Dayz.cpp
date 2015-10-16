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
typedef unsigned long long ll;
const int maxn = 1e3+5;

const ll carry = 1e18;
struct dll
{
    ll a,b;
    dll operator + (dll &th){
        dll re = {a+th.a,b+th.b};
        if(re.b >= carry) {
            re.a += re.b / carry;
            re.b %= carry;
        }
        return re;
    }
    void OUT(){
        if(a){
            printf("%I64u%I64u\n",a,b);
        }else{
            printf("%I64u\n",b);
        }
    }
};

dll f[maxn];

//f[i][j] = sigma f[i-1][r+k*i] = f[i][j-i] + f[i-1][j]

//#define LOCAL
int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    int N,K;
    cin>>N>>K;
    f[0].b = 1; f[0].a = 0;
    for(int i = 1; i <= K; i++){
        for(int r = 0; r < i; r++){
            for(int j = r+i; j <= N; j += i){
                f[j] = f[j-i] + f[j];
            }
        }
    }
    f[N].OUT();

    return 0;
}
