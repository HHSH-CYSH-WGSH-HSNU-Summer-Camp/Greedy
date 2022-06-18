#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n;
	while(cin >> n){
		if(n==0) break;
		vector<pair<int,int>> v;
		for(int i = 0;i < n;i++){
			int a,b;
			cin >> a >> b;
			v.push_back({a,b});
		}
		sort(v.begin(),v.end(),[&](pair<int,int> a, pair<int,int> b){
			return a.second > b.second;
		});
		int sum = 0, now = 0;
		for(auto [a,b] : v){
			sum += a, now = max(now,sum + b);
		}
		cout << now << "\n";
	}
}