#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define all(v)   v.begin(), v.end()
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
bool vowel(char x) {
    if (x == 'a' || x == 'i' || x == 'o' || x == 'e'||  x == 'u'){
        return true;
    }
    else{
        return false;
    }
}

void solve()
{
 
    ll n;
    cin>>n;
    string s;
    cin>>s;
/*
    ll k=0;
    vector<string> st;
    for(ll i = 0;i<n;++i){
        if(vowel(s[i])) {
            st.push_back(s.substr(k, i - k));
            k = i;
        }
    }

    string ans;
    st.push_back(s.substr(k, n - k));

    ll dk = st.size();
    for(ll i = dk-2;i>=0;i-=2) {
        reverse(all(st[i]));
        ans = ans+st[i];
    }

    ll as = 1;
    if(dk & 1){
        as = 0;
    }
    
    for(as;as<dk;as+=2){
        ans = ans+st[as];
    }
    cout<<ans<<endl;*/
    map<char, int> mp;
    mp['a']++;
    mp['e']++;
    mp['i']++;
    mp['o']++;
    mp['u']++;
    ll c = 0;
    vector<bool> visited(n);
    for (int j = s.size() - 1; j >= 0; j--)
    {
        if (c % 2 != 0)
        {
            cout << s[j];
            visited[j] = true;
        }

        if (mp.find(s[j]) != mp.end())
        {
            c++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            cout << s[i];
        }
    }

    cout << endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20)// also use precision with ans now
   //precomputefact();
   //createsieve();
   //bfs();//call in solve()
   //dfs(1,0);//call in solve()
 
   ll t=1;
   cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}