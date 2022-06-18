#include <bits/stdc++.h>
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
using namespace std;
 
int main(){
	fastio
	int n;
	cin >> n;
	vector<pair<int,int>> v;
	for(int i = 0;i < n;i++){
		int l,r;
		cin >> l >> r;
		v.push_back({l,r});
	}
	sort(v.begin(),v.end(),[&](pair<int,int> a, pair<int,int> b){
		return a.second < b.second;
	});
	int now = 0, ans = 0;
	for(auto x : v){
		if(x.first >= now){
			ans++, now = x.second;
		}
	}
	cout << ans << "\n";
}