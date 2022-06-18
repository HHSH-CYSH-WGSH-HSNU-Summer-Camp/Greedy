#include <bits/stdc++.h>
 
#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
using namespace std;
 
const int N = 2e5+5;
pair<int,int> arr[N];

signed main(){
    fastio
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr,arr+n);
    int nowtime = 0;
    int ans = 0;
    for(int i = 0;i < n;i++){
        nowtime += arr[i].first;
        ans += arr[i].second - nowtime;
    }
    cout << ans << "\n";
}