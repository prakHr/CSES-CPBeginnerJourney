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
const int MAXN = 1000;
bool visited[MAXN][MAXN];
char ans[MAXN*MAXN],parent[MAXN][MAXN],c[MAXN][MAXN];
int monstersDistance[MAXN][MAXN],srcDistance[MAXN][MAXN];
int n,m,sx,sy;
queue<pii> Q;

bool inbounds(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m;
}
void printsolution(int x, int y){
    int D = srcDistance[x][y];
    printf("YES\n%d\n", D);
    for(int i = D-1; i >= 0; i--){
        ans[i] = parent[x][y];
        if(ans[i] == 'D')       x--;
        else if(ans[i] == 'U')  x++;
        else if(ans[i] == 'R')  y--;
        else if(ans[i] == 'L')  y++;
    }
    for(int i = 0; i < D; i++)
        printf("%c", ans[i]);
    printf("\n");
}
void Solution() {
	cin>>n>>m;
	REP(i,n){
		REP(j,m){
			cin>>c[i][j];
			if(c[i][j]=='#')visited[i][j]=true;
			else if(c[i][j]=='M'){
				visited[i][j]=true;
				Q.push({i,j});
			}
			else if(c[i][j]=='A'){
				sx=i,sy=j;
			}
		}
	}
	while(!Q.empty()){
		pii P=Q.front();
		Q.pop();
		for(int i=0;i<4;i++){
			int x=P.ff+fx[i];
			int y=P.ss+fy[i];
			if(inbounds(x,y) and !visited[x][y]){
				monstersDistance[x][y]=monstersDistance[P.ff][P.ss]+1;
				visited[x][y]=true;
				Q.push({x,y});
			}
		}
	}
	REP(i,n){
		REP(j,m){
			if(!visited[i][j])monstersDistance[i][j]=INF;
			visited[i][j]=(c[i][j]=='#');
		}
	}
	visited[sx][sy]=true;
	Q.push({sx,sy});
	while(!Q.empty()){
		pii P=Q.front();
		Q.pop();
		for(int i=0;i<4;i++){
			int x=P.ff+fx[i];
			int y=P.ss+fy[i];
			if(inbounds(x,y) and !visited[x][y] and 
			srcDistance[P.ff][P.ss]+1<monstersDistance[x][y]){
				if(i==0) parent[x][y]='D';
				else if(i==1) parent[x][y]='U';
				else if(i==2) parent[x][y]='R';
				else if(i==3) parent[x][y]='L';
				srcDistance[x][y]=srcDistance[P.ff][P.ss]+1;
				visited[x][y]=true;
				Q.push({x,y});
			} 
		}
	}
	for(int i=0;i<n;i++){
		if(c[i][0]!='#' and c[i][0]!='M' and visited[i][0]){
			printsolution(i,0);
			return;
			
		}
		else if(c[i][m-1]!='#' and c[i][m-1]!='M' and visited[i][m-1]){
			printsolution(i,m-1);
			return;
			
		} 
	}
	for(int i = 0; i < m; i++){
        if(c[0][i] != '#' && c[0][i] != 'M' && visited[0][i]){
            printsolution(0, i);
            return;
        } else if(c[n-1][i] != '#' && c[n-1][i] != 'M' && visited[n-1][i]){
            printsolution(n-1, i);
            return;
        }
    }

    printf("NO\n");
}	
 
 
int32_t main() {
   
    int tc=1;

    FOR(tn,1,tc+1,1) {
        
        Solution();  
	}
 
    return 0;
}
