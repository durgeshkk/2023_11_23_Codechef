#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll n,k;
    cin>>n>>k;

    if(n%4==0 && k==0){
        cout<<"Off\n";
    }
    else if(n%4!=0 && k==0){
        cout<<"On\n";
    }
    else if(n%4==0 && k==1){
        cout<<"On\n";
    }
    else{
        cout<<"Ambiguous\n";

    }
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