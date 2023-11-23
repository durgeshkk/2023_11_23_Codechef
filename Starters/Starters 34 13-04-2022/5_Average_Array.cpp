#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll n;
    cin>>n;

    ll x;
    cin>>x;

    // vector<ll> v;
    // for(ll i=0;i<n;i++){
    //     ll ele;
    //     cin>>ele;
    //     v.push_back(ele);
    // }
/*
    vector<ll> ans;
    for(ll i=0;i<n-1;i++){
        if(i%2 == 0){
            ans.push_back((i+2)/2);
        }
        else{
            ans.push_back(-((i+1)/2));
        }
    }

    ll sum=accumulate(ans.begin(),ans.end(),0);
    ll y = ((n*x) - sum);
    ans.push_back(y);

    for(ll i=0;i<n-1;i++){
        ans.push_back(i+1);
    }

    ll sum=accumulate(ans.begin(),ans.end(),0);
    ll y = ((n*x) - sum);
    ans.push_back(y);

    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;*/
    vector<ll> ans;
    for(int i=0;i<n;i++){
        ans.push_back(x);
    }

    if(n%2 == 0){
        for(int i=0;i<n;i++){
            if(i%2 == 0){
                ll val = (i+2)/2;
                ans[i] += val;
            }
            else{
                ll val = -((i+1)/2);
                ans[i] += val;
            }
        }
    }
    else{
        ll i=0;
        ll prev = 0;
        while(i != (n/2)){
            ans[i] += (i+1);
            prev = i+1;
            i++;
        }

        i = (n/2)+1;
        ll j=1;
        while(i != n){
            ans[i] += (-j);
            j++;
            i++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll t;
   cin >> t;
   while (t--)
   {
       solve();
   }
   return 0;
}