#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e5+5;

int isprime[N];
vector<int> primes;

void init(){
    fill(isprime,isprime+N,1);
    for(int i = 2;i < N;i++){
        if(isprime[i]){
            primes.push_back(i);
            for(int j = i*i;j < N;j += i){
                isprime[j] = 0;
            }
        }
    }
}

signed main(){
    fastio
    init();
    int n;
    cin >> n;
    vector<pair<int,int>> ans;
    set<int> s;
    for(int i = 1;i <= n;i++) s.insert(i);
    for(int i = 1;i < primes.size();i++){
        int p = primes[i];
        vector<int> num;
        int even = 0;
        for(int i = p;i <= n;i+=p){
            if(s.find(i)!=s.end()){
                if(!even && i%2==0) even = i;
                else num.push_back(i);
            }
        }

        if(num.size()%2 && even) num.push_back(even);

        for(int i = 0;i+1 < num.size();i+=2){
            ans.push_back({num[i],num[i+1]});
            s.erase(num[i]);
            s.erase(num[i+1]);
        }
    }
    vector<int> e;
    for(auto x : s){
        if(x%2==0) e.push_back(x);
    }

    for(int i = 0;i < e.size();i+=2){
        if(i+1 == e.size()) break;
        ans.push_back({e[i],e[i+1]});
    }
    cout << ans.size() << "\n";
    for(auto [a,b] : ans){
        cout << a << " " << b << "\n";
    }
}