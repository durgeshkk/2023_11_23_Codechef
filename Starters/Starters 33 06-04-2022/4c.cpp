#include <bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;

void solve()
{

    ll n;
    cin>>n;

    string s;
    cin>>s;

    ll i=0;
    ll count_1 = 0;
    int f = 0;
    while(i<s.size()-1){

        if(s[i] == '1' && s[i+1] == '1'){
            f = 1;
        }

        if(s[i] == '1'){
            count_1++;
            // cout<<count_1<<endl;
        }
        i++;
    }

    if(s[i] == '1'){
        count_1++;
    }

    // cout<<count_1<<endl;
    
    if(count_1 == 0){
        cout<<0<<endl;
    }
    else if((n%2 == 0) && (count_1 == n) && (f==1) && (n == 2)){
        cout<<2<<endl;
    }
    else if((n%2 == 0) && (count_1 == n) && (f==1)){
        cout<<0<<endl;
    }
    else if(f == 1){
        cout<<2<<endl;
    }
    else{
        cout<<1<<endl;
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