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
 
    ll n,x;
    cin>>n>>x;

    ll mx = INT16_MIN;
    ll mn = INT16_MAX;

    set<ll> s;
    for(ll i=0;i<n;i++){
        ll ele;
        cin>>ele;
        s.insert(ele);
        if(ele > mx){
            mx = ele;
        }
        if(ele < mn){
            mn = ele;
        }
    }

    if((x > mx) || (x<mn)){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
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