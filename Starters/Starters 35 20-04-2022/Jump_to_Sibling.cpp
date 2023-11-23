#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll n;
    cin>>n;

    vector<ll> v;
    for(ll i=0;i<n;i++){
       ll ele;
       cin>>ele;
       v.push_back(ele%2);
    }

    ll s = v[0];
    ll e = v[v.size()-1];

    ll jump = 0;
    if(s == 0 && e==1){
        ll num = 1;
        ll ind=0;
        for(ll i=0;i<n;i++){
            if(v[i] == num){
                ind = i;
                break;
            }
        }

        if(ind == (n-1)){
            cout<<ind<<endl;
        }
        else{
            cout<<ind+1<<endl;
        }
    }
    else if(s == 0 && e==0){
        ll num = 1;
        ll ind=0;
        for(ll i=0;i<n;i++){
            if(v[i] == num){
                ind = i;
                break;
            }
        }
        cout<<ind<<endl;
    }
    else if(s == 1 && e==0){
        ll num = 0;
        ll ind=0;
        for(ll i=0;i<n;i++){
            if(v[i] == num){
                ind = i;
                break;
            }
        }

        if(ind == (n-1)){
            cout<<ind<<endl;
        }
        else{
            cout<<ind+1<<endl;
        }
    }
    else{//1 1
        ll num = 0;
        ll ind=0;
        for(ll i=0;i<n;i++){
            if(v[i] == num){
                ind = i;
                break;
            }
        }
        cout<<ind<<endl;
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