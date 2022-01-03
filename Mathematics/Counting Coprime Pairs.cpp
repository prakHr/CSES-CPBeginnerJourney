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
const int maxValue=1e6+10;
// idea is that to apply inclusion and exclusion principle by first generation of divisors using sieve of eratosthenes
// and then compute number of primes in an array if it is divisible by 2 then add otherwise subtract 
// by iteration of all possible combinations of primes of a number and generating that on a sieve as well
// :-https://www.youtube.com/watch?v=2H65yrmM0wY
void Solution() {
	int n;
	cin>>n;
	vi values(n);
	REP(i,n){
		cin>>values[i];
	}
	vi sieve(maxValue);
	vvi divisorsOf(maxValue);
	for(int i=2;i<maxValue;i++){
		if(divisorsOf[i].size()==0){
			divisorsOf[i].pb(i);
			for(int j=2*i;j<maxValue;j+=i){
				divisorsOf[j].pb(i);
			}
		}
	}
	vi valuesDivisibleBy(maxValue);
	vi primeDivisorsOf(maxValue);
	REP(i,n){
		for(int mask=1;mask<(1<<(divisorsOf[values[i]].size()));mask++){
			int combination=1;
			int primeDivisors=0;
			for(int pos=0;pos<divisorsOf[values[i]].size();pos++){
				if((1<<pos)&mask){
					combination *= divisorsOf[values[i]][pos];
					primeDivisors++;
				}
			}
			valuesDivisibleBy[combination]++;
			primeDivisorsOf[combination]=primeDivisors;
		}
	}
	ll totalNumberOfPairs =( (ll)n*(ll)(n-1))/2;
	ll validPairs=0;
	for(int i=0;i<maxValue;i++){
		if(primeDivisorsOf[i]%2)validPairs+=((ll)valuesDivisibleBy[i]*(ll)(valuesDivisibleBy[i]-1))/2;
		else validPairs-=((ll)valuesDivisibleBy[i]*(ll)(valuesDivisibleBy[i]-1))/2;		
	}
	cout<<totalNumberOfPairs-validPairs;
}	
 
 
int32_t main() {
   
    int tc=1;
    FOR(tn,1,tc+1,1) {
        
        Solution();  
	}
 
    return 0;
}
