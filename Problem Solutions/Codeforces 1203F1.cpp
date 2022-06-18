#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
    fastio
    int n, r;
    cin >> n >> r;

    vector<pair<int,int>> v1, v2;

    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        if(b > 0) v1.push_back({a,b});
        else v2.push_back({a,b});
    }

    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end(),[&](pair<int,int> a, pair<int,int> b){
        return max(a.first,-a.second)+a.second > max(b.first,-b.second)+b.second;
    });

    for(auto [a,b] : v1){
        if(r < a){
            cout << "NO\n";
            return 0;
        }
        r += b;
    }

    for(auto [a,b] : v2){
        if(r < a){
            cout << "NO\n";
            return 0;
        }
        r += b;
    }

    cout << "YES\n";

}