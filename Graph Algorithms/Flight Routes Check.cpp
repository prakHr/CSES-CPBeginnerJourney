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
const int fx[]={+1,-1,+0,+0};
const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/
 
const int INF = 0x3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 10e-10;
const int maxN = 2e5+1;

int N, M, a, b;
bool vis1[maxN], vis2[maxN];
vector<int> G1[maxN], G2[maxN];

void dfs1(int u = 1, int p = 0){
    vis1[u] = true;
    for(int v : G1[u])
        if(v != p && !vis1[v])
            dfs1(v, u);
}

void dfs2(int u = 1, int p = 0){
    vis2[u] = true;
    for(int v : G2[u])
        if(v != p && !vis2[v])
            dfs2(v, u);
}
void Solution() {
	cin>>N>>M;
	REP(i,M){
		cin>>a>>b;
		G1[a].pb(b);
		G2[b].pb(a);
	}
	dfs1();
	dfs2();
	FOR(i,1,N+1,1){
		if(!vis1[i] or !vis2[i]){
			cout<<"NO\n";
			if(!vis1[i])cout<<"1 "<<i<<endl;
			else cout<<i<<" 1"<<endl;
			return;
		} 
	}
	cout<<"YES\n";
}
 
 
int32_t main() {
   
    int tc=1;

    FOR(tn,1,tc+1,1) {
        
        Solution();  
	}
 
    return 0;
}
