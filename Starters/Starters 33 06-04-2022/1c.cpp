#include <bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;

void solve()
{
    ll x;
    ll y;
    cin>>x>>y;
    if(x>y){
        cout<<"SECOND\n";
    }
    else if(x<y){
        cout<<"FIRST\n";
    }
    else{
        cout<<"ANY\n";

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