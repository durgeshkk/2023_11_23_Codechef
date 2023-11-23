#include <bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;

void solve()
{
    ll d;
    cin>>d;

    string s;
    cin>>s;

    ll i=0;
    while(i<s.size()){
        if(s[i] == '0' || s[i] == '5'){
            cout<<"Yes\n";
            return;
        }
        i++;
    }
    cout<<"NO\n";
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