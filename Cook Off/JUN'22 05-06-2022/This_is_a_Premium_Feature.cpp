#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#define ll long long int
using namespace std;
 
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
 
ll mod = 1000005;
void solve()
{
 
    ll n;
    cin>>n;

    vector<ll> v(n);
    vector<ll> psum(n);
    map<ll,ll> mp,mp1;
    for(ll i=0;i<n;i++){
       cin>>v[i];
        mp1[v[i]]++;

       if(v[i] == 0){
           mp[v[i]]++;
       }
    }

    if(mp.size() == mp1.size()){
        cout<<"NO\n";
        return;
    }

    psum[0] = v[0];
    for(ll i=1;i<n;i++){
       psum[i] = ((v[i]+psum[i-1])%mod);
    //    psum[i] = ((psum[i]+psum[i-1]));
    }

    /*
    for(ll i=0;i<n;i++){
        cout<<psum[i]<<" ";
        // cout<<v[i]<<" ";
    }
    cout<<endl;
    */

    for(ll i = 0;i<(n-1);++i){
        ll l = psum[i];
        ll r = psum[n-1];

        if(((r-l)%2 == 0) && (l%2==0) && (r%2==0)){
            cout<<"YES\n";
            cout<< 2 <<endl;
            cout<<1<<" "<<i+1<<endl;
            cout<<i+2<<" "<<n<<endl;
            return;
        }

        if(((r-l)%2 == 0) && (l%2!=0) && (r%2!=0)){
            cout<<"YES\n";
            cout<< 2 <<endl;
            cout<<1<<" "<<i+1<<endl;
            cout<<i+2<<" "<<n<<endl;
            return;
        }

    }

    cout<<"NO\n";
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20)// also use precision with ans now
   ll t=1;
   cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}