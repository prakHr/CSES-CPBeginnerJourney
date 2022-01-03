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


//1234567891011121314151617181920
// pos = 10..99 = 99-10+1=100-10=90
// 90*2 = 180
// pos = 100..999=1000-100=900
// 900*3 = 2700

// (1-9) 10->180+9=(10-189) 190->2700+189(190-2889)
// Lets say we are looking at index 107
// then 107 lies between 10 and 189
// so we do binary search for low=10 and high=99
// mid = 50 and pos = (50-10)*2+10  
// final low = 106 so pos = 107-106 = 1
// ans = 58 so pos=0 is 5 and pos=1 is 8 
// so ans = 8
 
// for 107
//digitsSoFar:-189
//digitsBeforeActualBlock:-9
//numberOfDigits         :-2
//smallestValue         :-10
//largestValue          :-99
int32_t main() {
	vector<ll> powerOfTen(19,1);
   
	FOR(i,1,19,1){
		powerOfTen[i]=powerOfTen[i-1]*10;
	}
    int queries;
	cin>>queries;
    while(queries--){
	    	ll index;
	    	cin>>index;
	    	ll digitsSoFar=0;
	    	ll digitsBeforeActualBlock=0;
	    	int numberOfDigits;
	    	for(int i=1;i<=18;i++){
	    		digitsSoFar+=(powerOfTen[i]-powerOfTen[i-1])*i;
				if(digitsSoFar>=index){
					numberOfDigits=i;
					break;
				}
				digitsBeforeActualBlock+=(powerOfTen[i]-powerOfTen[i-1])*i;
			}
			cout<<"digitsSoFar"<<":-"<<digitsSoFar<<endl;
			cout<<"digitsBeforeActualBlock"<<":-"<<digitsBeforeActualBlock<<endl;
			cout<<"numberOfDigits         "<<":-"<<numberOfDigits<<endl;
			
			
			ll smallestValue=powerOfTen[numberOfDigits-1];
			ll largestValue =powerOfTen[numberOfDigits]-1;
			cout<<"smallestValue         "<<":-"<<smallestValue<<endl;
			cout<<"largestValue          "<<":-"<<largestValue<<endl;
			ll bestValue=0;
			ll startingPositionOfBestValue;
			while(smallestValue <= largestValue){
				ll actualValue = (smallestValue + largestValue)/2;
				ll startingPositionOfActualValue = digitsBeforeActualBlock+1+(actualValue-powerOfTen[numberOfDigits-1])*numberOfDigits;
				if(startingPositionOfActualValue <= index){
					if(actualValue > bestValue){
						bestValue=actualValue;
						startingPositionOfBestValue=startingPositionOfActualValue;
					}
					smallestValue=actualValue+1;
				}
				else largestValue = actualValue - 1;
			}
			string number = to_string(bestValue);
			cout<<number[index-startingPositionOfBestValue]<<endl;
	}
 
    return 0;
}
