#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll n,m;
    cin>>n>>m;

    cout<<abs(n-m)<<endl;
    /*
    vector<ll> v;
    for(ll i=0;i<n;i++){
       ll ele;
       cin>>ele;
       v.push_back(ele);
    }*/
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
   return 0;
}