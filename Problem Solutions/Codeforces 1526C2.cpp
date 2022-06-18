#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
    fastio
    int n;
    cin >> n;

    int sum = 0;
    priority_queue<int,vector<int>,greater<>> pq;

    for(int i = 0;i < n;i++){
        int x;
        cin >> x;
        pq.push(x);
        sum += x;
        while(sum < 0){
            sum -= pq.top();
            pq.pop();
        }
    }

    cout << pq.size() << '\n';
}