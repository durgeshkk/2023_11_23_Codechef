#include<bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;
 
ll LCM(ll a,ll b){
   ll ans = (a*b)/__gcd(a,b);
   return ans;
}
 
bool isPrime(int n){
   if (n <= 1)
       return false;
   for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}
 
void solve()
{
 
    ll na,nb,nc;
    cin>>na>>nb>>nc;
    
    ll a,b,c;
    a = max(na,max(nb,nc));

        if(na > (nb+nc)){
            cout<<"YES\n";
        }
        else if(nb > (na+nc)){
            cout<<"YES\n";
        }
        else if(nc > (na+nb)){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
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
   //solve();
   return 0;
}