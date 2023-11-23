#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

ll LCM(ll a,ll b){
   ll ans = (a*b)/__gcd(a,b);
   return ans;
}
 
bool isPrime(int n){
   if (n <= 1)
       return false;
   for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}
 
bool isPalindrome(string str)
{
    int low = 0;
    int high = str.length() - 1;

    while (low < high)
    {
        // if a mismatch happens
        if (str[low] != str[high]) {
            return false;
        }

        low++;
        high--;
    }

    return true;
}
// Fxn call(for ((b/a)%mod)) :
// ll c = (b*power(a,mod-2(prime num in power of a),mod))%mod;
// Also for formula like nCr..
ll power(ll base,ll n,ll mod){
   ll ans = 1;
   while( n!= 0){
      if(n%2){
          n-=1;
          ans = (ans*base)%mod;
      }
      else{
          n /= 2;
          base = (base*base)%mod;
      }
   }
   return ans;
}
 
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
 
ll sieve[1000005];
void createsieve(){
    ll ntlen = 1000000;
    sieve[0] = 0;
    sieve[1] = 0;
    for(ll i = 2;i<=ntlen;++i){
        sieve[i] = 1;
    }
 
    for(ll i = 2;i*i<=ntlen;++i){
 
        // Set all multiples to 0
        if(sieve[i] == 1){
 
            for(ll j = i*i;j<=ntlen;j+=i){
                 sieve[j] = 0;
            }
        }
    }
}
 
 
ll fact[100005];
ll powfact[100005];
void precomputefact(){
    fact[0] = 1;
    ll ans = 1;
    for(ll i = 1;i<=100005;++i){
         ans = (ans*i)%mod;
         fact[i] = ans;
         powfact[i] = power(fact[i],mod-2,mod);
    }
}
 
ll nCr(ll n,ll r){
     ll at = powfact[r];
     ll at2 = powfact[n-r];
     return ((fact[n]*((at*at2)%mod))%mod);
}
 
vector<ll> adj[100004];
 
void bfs(){
    queue<pair<ll,ll>> q;
    q.push({1,0});
 
    while(!q.empty()){
        auto it = q.front();
        q.pop();
 
        ll node = it.first;
        ll par = it.second;
 
        cout<<node<<" ";
 
        for(auto it:adj[node]){
            if(it != par){
                q.push({it,node});
            }
        }
    }
}
 
ll height;
ll subtree[100005];
ll lev[100005];
ll parent[200005];
 
void dfs(ll node, ll par, ll level=1){

    cout<<node<<" ";
    lev[node] = level;
    height = max(height,level);
 
    ll sm = 0;
 
    parent[node] = par;
    for(auto it:adj[node]){
        if(it != par){
            dfs(it,node,level+1);
            sm += subtree[it];
        }
    }
    subtree[node] = 1+sm;
}
 
void tree(){
    ll n;
    cin>>n;

    ll u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void solve(){

    ll n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;

    if(s1 == s2){
        cout<<"YES\n";
    }

    if(n == 2){
        if(s1 == "00" && s2 == "11"){
            cout<<"NO\n";
            return;
        }
    }

    bool f = false;
    size_t fnd = s1.find('1');
    for(ll i = 1;i<n;++i){
        if(s2[i] == s2[i-1]){
            f = true;
            break;
        }
    }

    if(f != true){
        if(s1 == s2){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
        return;
        
    }

    if(fnd == string::npos){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
    }
    return;

}
 /*
    ll n;
    cin>>n;

    string s1,s2;
    cin>>s1>>s2;

    for(ll i=0;i<n-1;i++){
        string ak;
        ak += s1[i];
        ak += s1[i+1];

        string dk;
        dk += s2[i];
        dk += s2[i+1];

        if(ak == "11"){
            if(dk == "01"){
                cout<<"NO\n";
                return;
            }
        }
        else if(ak == "10"){
            if(dk == "01"){
                cout<<"NO\n";
                return;
            }
            
        }
        else if(ak == "00"){
            if(dk[0] == '1' || ak[1] == '1'){
                cout<<"NO\n";
                return;
            }
        }
        else{//ak == "01"
            if(dk == "10"){
                cout<<"NO\n";
                return;
            }
        }
        s1[i] = dk[i];
        s1[i+1] = dk[i+1];
    }*/
/*
        char a = s1[i],b = s2[i];
        char a1 = s1[i+1],b1 = s2[i+1];

        // if(a == b){
        //     continue;
        // }
        // else{
            if(a == '0' && a == a1){
                cout<<"NO\n";
                return;
            }

            if(a == '0'){
                s1[i] = '1';
                s1[i+1] = '1';
            }
            else{
                s1[i] = '0';
                s1[i+1] = '0';
            }
        // }
    }
    */
/*
    if(s1[n-1] == s2[n-1]){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    return;
}
 */
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20)// also use precision with ans now
   //precomputefact();
   //createsieve();
   //bfs();//call in solve()
   //dfs(1,0);//call in solve()
 
   ll t=1;
   cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}
