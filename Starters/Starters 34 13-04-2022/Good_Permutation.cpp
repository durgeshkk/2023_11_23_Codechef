#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll n;
    cin>>n;

    if(n == 1 || n == 3){
        cout<<-1<<endl;
        return;
    }

    if(n%2 == 0){
        ll i=(n/2)+1;
        while(i != (n+1)){
            cout<<i<<" ";
            i++;
        }
        i = 1;
        while(i != ((n/2)+1)){
            cout<<i<<" ";
            i++;
        }
    }
    else{
        cout<<4<<" "<<5<<" "<<2<<" "<<1<<" "<<3<<" ";
        for (ll i = 6; i<=n; i--)
        {
            if(i%2 == 0){
                cout<<i+1<<" ";
            }
            else{
                cout<<i-1<<" ";
            }
        }
    }
    cout<<endl;
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