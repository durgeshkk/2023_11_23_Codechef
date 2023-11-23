#include <bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;

void solve()
{
    ll n,x,y;
    cin>>n>>x>>y;

    string s;
    cin>>s;

    if(n <= 1){
        cout<<0<<endl;
        return;
    }

    ll i=0;
    ll count_0=0,count_1=0;
    while(i<s.size()){

        if(s[i] == '0'){
            count_0++;
        }
        else{
            count_1++;
        }
        i++;
    }

    // ll min_pair = min(count_0,count_1);

    if(x > y && count_0>=1 && count_1>=1){
        // cout<<y*min_pair<<endl;
        cout<<y<<endl;
    }
    else if(x <= y && count_0>=1 && count_1>=1){
        // cout<<x*min_pair<<endl;
        cout<<x<<endl;
    }
    else{
        cout<<0<<endl;
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