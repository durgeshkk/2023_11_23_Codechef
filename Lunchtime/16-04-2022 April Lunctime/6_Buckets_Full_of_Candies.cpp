#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
void solve()
{
    ll n,m,k;
    cin>>n>>m>>k;

    /*
    ll num_buc = (n/2)*(2*k + n - 1);

    if(n%2 != 0){
        num_buc = n*((2*k + n - 1)/2);
    }

    if((num_buc*k) < m){
        cout<<abs((num_buc*k)-m)<<endl;
        return;
    }

    else if((num_buc*k) == m){
        cout<<0<<endl;
        return;
    }

    else{
        cout<<(m%k)<<endl;
    }
    ll sm_buc = k+n-1;
    while(m >= (sm_buc*k) && (sm_buc>=k)){
        m = m - (sm_buc*k);
        sm_buc--;
    }
    cout<<m<<endl;
*/
    ll last_bucs = n+k-1;
/*  TLE
    while(m>=0 && (last_bucs >= k)){
        if((last_bucs*k) <= m){
            m = m-(last_bucs*k);
        }
        else if(last_bucs <= m){
            m = (m%last_bucs);
        }
        last_bucs--;
    }
*/
/*
    while(m >= k){
        m = m%last_bucs;
        last_bucs--;
    }

    cout<<m<<endl;*/

    ll rem = m%last_bucs;
    if(n == 0){
        cout<<m<<endl;
    }

    if(rem >= k){
        cout<<0<<endl;
    }
    else{
        cout<<rem<<endl;
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