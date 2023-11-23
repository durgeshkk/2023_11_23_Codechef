/*#include<bits/stdc++.h>
#include<iomanip>
#include<cstdint>
#include <deque>
#define ll long long int
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
 
void solve()
{
 
    ll n,k;
    cin>>n>>k;
    
    bitset<32> s(k);

    // if(n == 1){
    //     ll ans = builtin_popcount(n);
    // }


    ll idx = -1,c1=0;
    for(ll i=0;i<32;i++){
        if(s[i] == 1){
            idx = i;
            c1++;
        }
    }

    // idx--;
    if(n == 1){
        cout<<c1<<endl;
        return;
    }

    ll ans = 0;
    for(ll i=idx;n>0;--i,idx--,n--){
        if(k>n){
            k -= ((1<<idx)-1);
            ans+=(idx);
            if(k >= (1<<idx)){
                continue;
            }
        }
        else{
            cout<< ans+n << endl;
            return;
        }
        cout<<"k"<<k<<" ";
        cout<<"IDX : "<<idx<<endl;
        // n--;
    }

    if(k>0){
        bitset<32> z(k);
        for(ll i=0;i<32;i++){
            if(z[i] == 1){
                ans++;
            }
        }
    }
    cout<< ans<<endl;

    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20)// also use precision with ans now
   //precomputefact();
   //createsieve();
 
   ll t=1;
   cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}
*/
// /*
#include <bits/stdc++.h> 
using namespace std; 
#define ll long long 
 
int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 
    ll t; 
    cin >> t; 
    while (t--) 
    { 
        ll n; 
        cin >> n; 
 
        ll b[n]; 
        for (ll i = 0; i < n; i++) 
        { 
            cin >> b[i]; 
        } 
 
        ll maxi = b[0], mini = b[0]; 
        bool flag = true; 
         
        for (ll i = 1; i < n; i++) 
        { 
            mini = min(mini, b[i]); 
            maxi = max(maxi, b[i]); 
            if (b[i] != mini && b[i] != maxi) 
            { 
                flag = false; 
                continue; 
            } 
        } 
 
        if (flag) 
        { 
            cout << "YES" << endl; 
        } 
        else 
        { 
            cout << "NO" << endl; 
        } 
    } 
 
    return 0; 
}