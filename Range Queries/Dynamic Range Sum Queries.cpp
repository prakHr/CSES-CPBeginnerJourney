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
 
const int maxN = 2e5;

int N, Q, t, A,B;
ll x[maxN+1], ds[maxN+1];
// idea is to update the contribution of a[i] with diff=val-a[i] for type 1
// because sum at LSB of 1 bits will have some value x+a[i] then to update with val 
// we do this operation x+a[i]+diff=x+a[i]+val-a[i], than that means we update with diff


// Return sum from 0...i from array
int getSum(int fw[], int i)
{
   int sum = 0;
   // Fenwick's index start from 1
   i++;  
   
   while(i > 0)
   {
      sum += fw[i];
      // i & (-i)  returns the decimal value of last set digit
      // eg: if i = 12 (1100) then  i & (-i) will 4 (100)
      i -= i & (-i);
   }
   return sum;   
}  

// newVal will be updated to Fenwick and all its ancestor
void updateFW(int fw[], int n, int i, int newVal)
{ 
   // Fenwick's index start from 1
   i++;
   while (i <= n)
   {
      fw[i] += newVal;
      i += i & (-i);
   } 
}

// Build Fenwick's tree
int *constructFenwick(int a[], int n)
{ 
  int *fw = new int [n+1];
  for (int i = 0; i <= n; i++)
    fw[i] = 0;
 
  for (int i=0; i<n; i++)
   updateFW(fw, n, i, a[i]);

  return fw;
}

  
//int main()
//{
//   int a[] = {1, 2, 3, 4, 5, 6, 7};
//   int n = sizeof(a)/sizeof(a[0]);
//   int *fw = constructFenwick(a, n);
//   cout<<getSum(fw, 4);
//   a[3] += 7;
//   updateFW(fw, n, 3, 7);
//   cout<<"\nAfter update ";
//   cout<<getSum(fw, 4) << "\n";
//   return 0; 
//}
int32_t main(){
	int N,Q;
    cin>>N>>Q;
//    cout<<endl;
//    for(int k=0;k<16;k++){
//    	cout<<k<<" : "<<ds[k]<<" ";
//	}
//	cout<<endl;
	int a[N];
	for (int i=0; i<N; i++){
		cin>>a[i];
	}
	int *fw = constructFenwick(a, N);
	
//	for(int i = 1; i <= N; i++){
//        scanf("%lld", &x[0]);
//        update(i, x[0]);
//	  	cout<<endl;
//	    for(int k=0;k<16;k++){
//	    	cout<<"i: "<<k<<" -> "<<" ds[i]: "<<ds[k]<<endl;
//		}   
//		cout<<endl;   
//    }
    for(int q = 0; q < Q; q++){
        cin>>t>>A>>B;
        if(t==1){
        	A--;
        	ll diff=B-a[A];
//     		updateFW(fw, n, 3, 7);   
			updateFW(fw,N,A,diff);
			a[A]=B;	
		}
		else{
			B--;
			A--;
			cout<<getSum(fw,B)-getSum(fw,A-1)<<endl;	
		}
//        if(t == 1)  update(a, b);
//        else        printf("%lld\n", query(b)-query(a-1));
    }
}
