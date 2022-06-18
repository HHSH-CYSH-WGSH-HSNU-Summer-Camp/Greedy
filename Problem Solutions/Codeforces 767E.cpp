#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e5+5;
int ans[N], res;

signed main(){
    fastio
    int n,m;
    cin >> n >> m;

    int c[n], w[n], v[n] = {};
    for(auto &x : c) cin >> x;
    for(auto &x : w) cin >> x;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;

    for(int i = 0;i < n;i++){
        if(c[i]%100) v[i] = w[i]*(100-c[i]%100);
    }

    for(int i = 0;i < n;i++){
        if(c[i]%100==0){
            ans[i] = 1;
            continue;
        }
        pq.push({v[i],i});
        if(m >= c[i]%100) m -= c[i]%100;
        else{
            if(m < c[i]%100) m += 100, res += v[pq.top().second], ans[pq.top().second] = 1, pq.pop();
            m -= c[i]%100;
        }
    }

    cout << res << "\n";

    for(int i = 0;i < n;i++){
        if(ans[i]) cout << (c[i]+100-1)/100 << " " << 0 << "\n";
        else cout << c[i]/100 << " " << c[i]%100 << "\n";
    }   
}