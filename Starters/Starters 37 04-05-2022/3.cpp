#include<bits/stdc++.h>
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
 
void solve()
{
 
    ll n;
    cin>>n;
    vector<ll> v;
    map<ll,ll> mp;
    ll maxi = -1;
    // ll f=0;
    for(ll i=0;i<n;i++){
       ll ele;
       cin>>ele;
       v.push_back(ele);
       mp[(ele)]++;
    }

    ll maxfreq = 0;
    for(ll i=0;i<v.size();i++){
        if(mp[v[i]] > maxfreq){
            maxi = v[i];
            maxfreq = mp[v[i]];
        }
    }

    ll f = 0;
    for(ll i=0;i<v.size();i++){
        if(v[i]!=maxi && mp[v[i]]== maxfreq){
            f = 1;
        }
    }

    if(f == 1){
        cout<<"CONFUSED\n";
    }
    else{
        cout<<maxi<<endl;
    }
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   ll t;
   cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}