#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll n,x;
    cin>>n>>x;

    vector<ll> v;
    for(ll i=0;i<n;i++){
       ll ele;
       cin>>ele;
       v.push_back(ele);
    }

    sort(v.begin(),v.end());

    ll tym=0;
    if(v[0]==1){
        for(ll i=0;i<x;i++){
            tym += (x-i);
        }
        cout<<tym<<endl;
    }
    else if(v[0] >= x){
        cout<<v.size()<<endl;
    }
    else{
        ll ppl = x;
        tym = v.size();
        while(ppl > 0){
            tym += (ppl/v[0]);
            ppl -= v[0];
        }
        cout<<tym<<endl;
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