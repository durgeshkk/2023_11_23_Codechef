#include <bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;

ll sumofdigit(ll no){
    // ll no = n;
    ll sum = 0;
    while(no != 0){
        ll rem = no % 10;
        sum += rem;
        no /= 10;
    }
    return sum;
}

void solve()
{
    ll n;
    cin>>n;

    ll sum = sumofdigit(n);

    ll ans = n;
    if(sum % 2 == 0){//return odd parity as ans
        ans = n+1;

        ll smallsum = sumofdigit(ans);

        if(smallsum%2 == 0){
            cout<<ans+1<<endl;
        }
        else{
            cout<<ans<<endl;
        }
    }
    else{
        ans = n+1;

        ll smallsum = sumofdigit(ans);

        if(smallsum%2 == 0){
            cout<<ans<<endl;
        }
        else{
            cout<<ans+1<<endl;
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