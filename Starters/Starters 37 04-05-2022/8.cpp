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
    for(ll i=0;i<n;i++){
       ll ele;
       cin>>ele;
       v.push_back(ele);
    }

    sort(v.begin(),v.end());

    double ans = (1.0*(v[0]+v[1]))/2;
    double mean = ans;

    if(v.size() == 2){
        cout<<ans<<endl;
        return;
    }
    
    // cout<<ans<<endl;
    for(ll i=2;i<n;i++){
        mean = (1.0*v[i] + mean)/2;
        // cout<<mean<<" "<<ans<<endl;
    }

    double ans2 = 1;
    for(ll i=0;i<n;i++){
        ans *= v[i];
    }

    cout<<mean<<endl;
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