#include <bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;

void solve()
{

    ll size;
    cin>>size;

    vector<ll> a;
    vector<ll> b;
    vector<pair<ll,ll>> v;

    for(ll i=0;i<size;i++){
        ll ele;
        cin>>ele;
        a.push_back(ele);
    }
    
    for(ll i=0;i<size;i++){
        ll ele;
        cin>>ele;
        b.push_back(ele);
    }

    for(ll i=0;i<size;i++){
        v.push_back(make_pair(b[i],a[i]));
    }

    sort(v.begin(),v.end());

    ll s = accumulate(a.begin(),a.end(),0);

    if(s<0){
        cout<<0<<endl;
        return;
    }
    else{
        s = 0;
        if(v[0].first == 0){
            ll i=0;
            while(i<v.size()-1){
                ll sum = 0;
                for(ll j = i+1;j<v.size();j++){
                    sum = sum + v[j].second;
                }

                if(sum > 0 && ((v[i].first+1) == v[i+1].first)){
                    s = s + v[i].second; 
                }   
                // do if consecutive 0's
                else if(sum > 0 && (v[i].first == v[i+1].first)){
                    ll max = v[i].second;
                    while((v[i+1].first != (v[i].first+1)) && i<v.size()){
                        if(max < v[i].second){
                            max = v[i].second;
                        }
                        i++;
                    }
                    s = s + max;
                }
                else{
                    cout<<(s/2)<<endl;
                    return;
                }
                i++;
            }

            if(v[v.size()-1].second > 0 && ((v[v.size()-2].first+1) == v[v.size()-1].first)){
                    s = s + v[v.size()-1].second; 

                cout<<(s/2)<<endl;
                return;
            }
        }
        else{
            cout<<0<<endl;
        }
    }   

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