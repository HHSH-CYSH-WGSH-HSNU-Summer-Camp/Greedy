#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
    fastio
    int n,k;
    cin >> n >> k;

    priority_queue<int> pq;

    int arr[n];
    for(int &x : arr) cin >> x;

    reverse(arr,arr+n);

    int sum = 0;
    for(int i = 0;i < n;i++){
        sum += arr[i];
        if(i != n-1) pq.push(sum);
    }

    int ans = sum;
    for(int i = 0;i < k-1;i++){
        ans += pq.top();
        pq.pop();
    }

    cout << ans << "\n";
}