#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
using namespace std;
typedef long long ll; 
typedef unsigned long long ull;

const int MOD = 1e9 + 7;

// we have options like :- to extend the previous blocks or not
// dp(i) :- ways to fill positions from i till n of tower
// need to have a linked boolean variable -> 1 if i-1 th pos had a tile of width 2
// 0 if i-1 th pos had 2 tile of width 1
// dp(i,0) acc to linked variable
// dp(i,1) have to extend both of this
// final_ans=dp(2,0)+dp(2,1)

// dp(i,0)=1.do not extend any tile -> dp(i+1,1)+dp(i+1,0)
//         2.extend both -> dp(i+1,0)
//         3.extend one of these -> 2*dp(i+1,0)

// dp(i,1)=1.do not extend any tile -> dp(i+1,1)+dp(i+1,0)
//         2.extend both -> dp(i+1,1)

void Solution() {

	int n;
	cin>>n;
	ll dp[n+2][2];
	dp[n+1][0]=dp[n+1][1]=1;
	
	for(int i=n;i>=2;i--){
		ll op1 = (dp[i+1][1]+dp[i+1][0])%MOD;
		ll op2 = (dp[i+1][0]);
		ll op3 = (2*dp[i+1][0])%MOD;
		ll op4 = dp[i+1][1];
		dp[i][0]=(op1+op2+op3)%MOD;
		dp[i][1]=(op1+op4)%MOD;
	}
	cout << (dp[2][1]+dp[2][0])%MOD << endl;
}	
 
 
int32_t main() {
	FAST_IO;
	int tc;
	cin>>tc;
    while(tc--) {
        
        Solution();  
	}
 
    return 0;
}
