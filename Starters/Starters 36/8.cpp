#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll n;
    cin>>n;
    vector<ll> a;
    for(ll i=0;i<n;i++){
       ll ele;
       cin>>ele;
       a.push_back(ele);
    }
    vector<ll> b;
    for(ll i=0;i<n;i++){
       ll ele;
       cin>>ele;
       b.push_back(ele);
    }
    vector<ll> c;
    for(ll i=0;i<n;i++){
       ll ele;
       cin>>ele;
       c.push_back(ele);
    }

    ll k1,k2;
    cin>>k1>>k2;

    ll sum = 0;
    for(ll i=0;i<n;i++){
        if(a[i]>b[i] && a[i]>c[i] && k1>0){
            
            k1--;
        }
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
   return 0;
}