#include<bits/stdc++.h>
using namespace std;

set<string> S;

class Bracket107
{
    bool chk(const string&s){
        int cur = 0;
        for(auto c:s){
            cur += c=='('?1:-1;
            if(cur < 0) return false;
        }
        return cur == 0;
    }

public:

    int yetanother(string s){
        int n = s.size()-1;
        for(int i = 0; i <= n; i++){
            string s0 = s.substr(0,i)+s.substr(i+1);
            for(int i = 0; i <= n; i++){
                S.insert(s0.substr(0,i)+'('+s0.substr(i));
                S.insert(s0.substr(0,i)+')'+s0.substr(i));
            }
        }
        S.erase(s);
        int ans = 0;
        for(auto &s1: S){
           if(chk(s1)) ans++;
        }
        return ans;
    }
}sol;
