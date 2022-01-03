#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
#define double long double
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define PI acos(-1)
#define sqr(a) ((a)*(a))
#define ff first
#define ss second
#define sf scanf
#define pf printf
#define pf1(a) pf("%lld", a);
#define pf2(a,b) pf("%lld %lld", a, b)
#define pf3(a,b,c) pf("%lld %lld %lld", a, b, c)
#define sf1(a) sf("%lld", &a)
#define sf2(a,b) sf("%lld %lld", &a, &b)
#define sf3(a,b,c) sf("%lld %lld %lld", &a, &b, &c)
#define sf4(a,b,c,d) sf("%lld %lld %lld %lld", &a, &b, &c, &d)
#define sf5(a,b,c,d,e) sf("%lld %lld %lld %lld %lld", &a, &b, &c, &d, &e)
#define sfc(a) sf(" %c", &a)
#define sfd(n) sf("%lf", &n)
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define RESET(a, b) memset(a, (b), sizeof(a))
#define lb lower_bound
#define ub upper_bound
#define nl pf("\n")
#define endl '\n'
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define SZ(v) (int)v.size()
#define ALL(v) v.begin(), v.end()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define UNIQUE(v) (v).erase(unique((v).begin(), (v).end()), (v).end())
#define on(n,i) (n|=(1LL<<i))
#define isOn(n,i) (n&(1LL<<i))
#define off(n,i) (n = isOn(n,i) ? n ^ (1LL<<i) : n)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a/gcd(a,b)*b)
#define watch(a) cout << (#a) << " is " << (a) << '\n'
#define watch2(a,b) cout << (#a) << " is " << (a) << " and " << (#b) << " is " << (b) << '\n'
#define MIN3(a,b,c) MIN(a, MIN(b,c))
#define MAX3(a,b,c) MAX(a, MAX(b,c))
 
using namespace std;
typedef long long ll; 
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int,int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef tuple<int,int,int> State;
 
template <class T>  inline void chmax(T &x,T &y) {if(x < y) swap(x,y);}
template <class T>  inline void chmin(T &x,T &y) {if(x > y) swap(x,y);}
 
/*----------------------Graph Moves----------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/
 
const int INF = 0x3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 10e-10;

// solved by digit dp
// https://www.youtube.com/watch?v=heUFId6Qd1A
// dp(N,x)=dp(N-1,X-0)+dp(N-1,X-1)+...+dp(N-1,X-9)
// TC:- O(X*log10(R)) where X=10,R=10^18 transition*state
// for R=5273 we follow tight constraint for 5 in R
// Final recurrence relation for R is 
// We have to find boolean variable tight in dp
// dp(N,X,1)=dp(N-1,X,0)+dp(N-1,X-1,0)+..dp(N-1,X-4,0)+dp(N-1,X-5,1)
int dp[101][181][2];
int solve(string& num,int n,int x,bool tight){
	if(x<0)return 0;
	if(n==1){
		if(x>=0 and x<=9){
			return 1;
		}
		
		return 0;
		
	}
	if(dp[n][x][tight]!=-1)return dp[n][x][tight];
	int ub=tight?(num[(num.length()-n)]-'0'):9;
	int ans=0;
	for(int dig=0;dig<=ub;dig++){
		ans+=solve(num,n-1,x-dig,(tight&(dig==ub)));
	}
	return dp[n][x][tight]=ans;
}
void Solution() {

}	
 
 
int32_t main() {
	memset(dp,-1,sizeof(dp));
    string L="",R="1120343423443535";
    cout<<solve(R,R.length(),15,1);
    int tc=1;
	
    FOR(tn,1,tc+1,1) {
        
        Solution();  
	}
 
    return 0;
}
