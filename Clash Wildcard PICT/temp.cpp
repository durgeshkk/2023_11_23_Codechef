#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define vii vector<int>
#define vll vector<long long int>
#define pi pair<int,int>
#define pll pair<long long int, long long int>
#define vvl vector<vll>
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define nl "\n"
#define debug(x) cerr << x << nl;
#define multi_ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
const ll mod = 1e9 + 7,inf = 1e18;//998244353
ll expo(ll x, ll y){ll res=1;x%=mod;while(y){if(y%2)res=(res*x%mod)%mod;x=(x*x)%mod;y/=2;}return res;}
ll inv(ll x) {return expo(x,mod-2);}
ll madd(ll a, ll b){a=a%mod;b=b%mod;return(((a + b) % mod)+mod)%mod;}
ll mmul(ll a, ll b){a=a%mod;b=b%mod;return(((a * b) % mod)+mod)%mod;}
ll msub(ll a, ll b){a=a%mod;b=b%mod;return(((a - b) % mod)+mod)%mod;}
ll mdiv(ll a, ll b){a=a%mod;b=b%mod;return(mmul(a, inv(b))+mod)%mod;}
ll gcd(ll a, ll b){if(b == 0)return a;return gcd(b, a % b);}
ll lcm(ll a, ll b){return a/gcd(a,b) * b;}
const ll N = 5e3 + 7;

ll n;
vll v(N);
vector<vvl> dp;

string a, b;

ll solve(ll idx, ll x, ll y) {
    if(idx == n) {
        if(x == 0 || y == 0) {
            return inf;
        }
        return abs(x - y);
    }


    if(dp[idx][x][y] != -1) return dp[idx][x][y];

    ll choice1 = solve(idx+1, x + ((a[idx] == '1') ? (v[idx]) : (0)), y);
    ll choice2 = solve(idx+1, x, y + ((b[idx] == '1') ? (v[idx]) : (0)));

    return dp[idx][x][y] = min(choice1, choice2);
}


void PerformOp(){

    cin >> n; 
    for(ll i=0; i<n; i++)
        cin >> v[i];
    
    cin >> a >> b;

    int x = 0;
    int y = 0;

    for(ll i=0; i<n; i++){
        if(a[i] == '1') x += v[i];
        if(b[i] == '1') y += v[i];
    }

    dp.assign(n+2, vvl(x + 1, vll(y + 1, -1)));
    ll res = solve(0, 0, 0);
    cout << res;
    
}

signed main(){
    fastio;
    int t=1;
    cin>>t;
    while(t--){
        PerformOp();
        cout << nl;
    }
    return 0;
}