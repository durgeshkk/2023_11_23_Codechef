#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
ll memo[505][505][505];
ll n,p;
ll dfs(ll last_index,ll last_val,ll till_now,vector<ll> &v){
    if(till_now >= p){return 0;}
    if(last_index == n){return 0;}

    ll ans = 0;
    if(memo[last_index][last_val][till_now] != -1){return memo[last_index][last_val][till_now];}

    for(ll j = 0;j<=last_val+1;++j){
        if((till_now+j) <= p){
            ll small_ans = dfs(last_index+1,j,till_now+j,v) + (j*v[last_index]);
            ans = max(ans,small_ans);
        }
    }
    return memo[last_index][last_val][till_now] = ans;
} 
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>p;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }

    for(ll i=0;i<=n;i++){
        for(ll k=0;k<=n;k++){
            for(ll j=0;j<=n;j++){
                memo[i][k][j] = -1;
            }
        }
    }

    ll ans = dfs(0,0,0,v);
    cout<<ans;
    return 0;
}