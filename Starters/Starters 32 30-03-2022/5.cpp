#include <bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;

void solve()
{
    ll n,k;
    cin>>n>>k;

    vector<ll> v;

    for(ll i=0;i<n;i++){
        ll ele;
        cin>>ele;
        v.push_back(ele);
    }

    ll min_ind = 0,max_ind = 0;
    ll min_ind_ele = v[0],max_ind_ele = v[0];
    ll i=1;
    
    while(i<=v.size()){
        if(v[i] > v[0]){
            max_ind = i;
            max_ind_ele = v[i];
        }
        else if(v[i] < v[0]){
            min_ind = i;
            min_ind_ele = v[i];
        }
        i++;
    }

    if(abs(min_ind-max_ind) <= k){
        cout<<max_ind_ele<<endl;
    }
    else{
        i=0;
        while(i<v.size()){
            if(i==0 && v[i] == min_ind_ele){
                v[i] == v[i+1];
                cout<<v[i]<<endl;
                k--;
                // return;
            }
            if(v[i] == min_ind_ele){
                v[i] = min(v[i-1],v[i+1]);                
                cout<<v[i]<<endl;
                k--;
            }
            i++;
        }
    }
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