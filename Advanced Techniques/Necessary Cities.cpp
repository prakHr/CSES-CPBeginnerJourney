#include <bits/stdc++.h>
#pragma GCC target("popcnt")
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
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

const int MOD = 1e9 + 7;
const double EPS = 10e-10;
const int maxN = 1e5+10;
int N,M,timer,tin[maxN],low[maxN];
bool vis[maxN],is_artic[maxN];
vi adj[maxN];
vi ans;

void dfs(int node=1,int parent=-1){
	vis[node]=true;
	tin[node]=low[node]=++timer;
	int children = 0;
	for(int child:adj[node]){
		if(child!=parent){
			if(vis[child]){
				// there is a backedge so we have to take the min time in an stack of array
				low[node]=min(low[node],tin[child]);
			}
			else{
				dfs(child,node);
				low[node]=min(low[node],low[child]);
				if(low[child]>=tin[node] and parent!=-1){
//					bridges.pb({node,child});				
					if(!is_artic[node]){
						ans.pb(node);
						is_artic[node]=true;
					}	
				}
				children++;
			}
		}
	}
	if(parent==-1 and children>1){
		if(!is_artic[node]){
			ans.pb(node);
			is_artic[node]=true;
		}
	}
}
int32_t main() {

	cin>>N>>M;
	REP(i,M){
		int a,b;
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs();
	int K= ans.size();
	cout<<K<<endl;
	REP(i,K){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
//	cout<<bridges.size()<<endl;
//	for(pii P:bridges){
//		cout<<P.ff<<" "<<P.ss<<endl;
//	}
    return 0;
}
