#include <bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;

void solve()
{
    ll n,x,y;
    cin>>n>>x>>y;

    ll diff = abs(x-y);

    /*
    if((x == 1 && diff<=2)||( y == 1 && diff<= 2)){
        cout<<1<<endl;
        return;
    }
    else if ((x==1 && diff>2)||( y == 1 && diff> 2)){
        cout<<0<<endl;
        return;
    }

    if(x == y){
        cout<<0<<endl;
        return;
    }

    if(diff > 2){
        cout<<0<<endl;
    }
    else if(diff == 2){
        cout<<1<<endl;
    }
    else{
        cout<<2<<endl;
    }
*/
    ll m = max(x,y);
    ll mn = min(x,y);

    if(diff != 1 && diff != 2){
        cout<<0<<endl;
        return;
    }

    else if(diff == 2 || (m == n) || (mn == 1)){
        cout<<1<<endl;
        return;
    }
    else{
        cout<<2<<endl;
        return;
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