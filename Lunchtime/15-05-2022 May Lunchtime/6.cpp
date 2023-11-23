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
 
bool isPalindrome(string str)
{
    int low = 0;
    int high = str.length() - 1;

    while (low < high)
    {
        // if a mismatch happens
        if (str[low] != str[high]) {
            return false;
        }

        low++;
        high--;
    }

    return true;
}
void solve()
{
 
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
       cin>>v[i];
    }

    ll flag=0;
    vector<ll> t(32);
    for (ll i = 0; i < n; i++)
    {
        ll e = v[i];

        bitset<32> rt(e);

        for (ll j = 0; j < 32; j++)
        {
            if ((rt[j]==1))
            {
                t[j]++;
            }
        }
    }

    bitset<32> st;
    ll ans = 0;
    for (int j = 0; j <=31; j++)
    {
        if ((t[j]==n))
        {
            st[j] = 1;
        }
    }

    ll temp = 0;
    for(ll i = 0;i<= 31;i++){
        if(st[i] == 1){
            temp += powl(2,i);
        }
    }

    ll first = v[0];
    for (ll i = 0; i<n; i++)
    {
        first = (first & v[i]);
        if ((first == temp) && (flag == 1))
        {
            flag = 0;
            if ((i+1)<n)
            {
                first = v[i+1];
            }
        }
        else if (first != temp)
        {
            flag = 1;
            ans++;
        }
        else if ((i+1)< n)
        {
            first = v[i+1];
        }
    }

    if (ans==n)
    {
        ans--;
    }

    cout<<ans<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   ll t=1;
   cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}