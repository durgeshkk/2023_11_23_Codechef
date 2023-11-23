#include <bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;

void solve()
{
    ll a,b;
    cin>>a>>b;
    
    if(a==0){
        cout<<"https://www.codechef.com/practice"<<endl;
    }
    else if(a==1 && b==0){
        cout<<"https://www.codechef.com/contests\n";
    }
    else{
        cout<<"https://discuss.codechef.com\n";
    }

    return;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // ll t;
    // cin >> t;
    // while (t--)
    // {
        solve();
    // }

    return 0;
}