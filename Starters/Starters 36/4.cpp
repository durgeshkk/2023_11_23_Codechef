#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
 
    ll n;
    cin>>n;

    if(n < 5){
        cout<<n<<endl;
    }
    else if(n == 5){
        cout<<4<<endl;
    }
    else{
        ll intval = n/5;
        ll remain = n%5;

        cout<<intval*4 + remain<<endl;
    }
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   ll t;
   cin >> t;
   while (t--)
   {
       solve();
   }
   return 0;
}