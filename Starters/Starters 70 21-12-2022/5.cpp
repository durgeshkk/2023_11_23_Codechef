// Sol 1:
/*
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector<ll>lev(300010);
vector<bool>vis(300010);
vector<ll>adj[300010];
vector<ll>val(300010);
void dfs(ll n,ll t){
    lev[n]=t;
    vis[n]=1;
    for(auto it:adj[n]){
        if(!vis[it]){
            dfs(it,t+1);    
        }
    }    
}


void solve(){

    ll n;
    cin>>n;
    
    for(ll i=1;i<=n;i++){
        vis[i]=false;
        adj[i].clear();
        lev[i]=-1;
        val[i] =0;  
    }
    
    for(ll i=0;i<n-1;i++){
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1,0);
    ll ans=n-1;
    
    ll tot=0;
    ll q;
    cin>>q;
    for(ll i=0;i<q;i++){
    
        ll r;
        cin>>r;
            
        if(r==2){
            if(tot==n){
                cout<<n-1<<endl;
                continue;
            }
            cout<<ans<<endl;
        }  
        else{
        
            ll b;
            cin>>b;
            
            if(adj[b].size()<=1 && b!=1){
                if(tot==n){ 
                    continue;
                }
                if(val[b]==1){
                    continue;
                }
                val[b]=1;    
                tot++;
                ans--;
            }
            else{
                if(tot==n||val[b]==1){
                    continue;      
                }
                int f=0;
                int ct=0;
                for(auto it:adj[b]){
                    if(lev[it]>lev[b]){
                        ct++;
                        if(val[it]!=1){
                            f=1;
                            break;
                        }      
                    }
                }
    
                if(f==0){
                    ans--;
                    val[b]=1;
                    tot++;
                }    
            }  
        }
    }
}


int main()
{
 
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}*/

// Sol 2:
#include<bits/stdc++.h>
#include<iomanip>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

vector<ll> adj[300005];
ll ans;
unordered_map<ll,ll> par,child_got_one,tot_childs;
void tree(){
    ll u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
 
vector<ll> vis; 
void bacche(ll i,ll x){
    vis[i] = 1;
    par[i] = x;

    ll cnt = 0;
    for(auto it:adj[i]){
        if(!vis[it]){
            bacche(it,i);
            // cnt += bacche(it,i);
        }
    }

    // tot_childs[i] = cnt;
    // return (1+cnt);
}

void solve()
{
    ll n;cin>>n;
    ans = n-1;
    par.clear();child_got_one.clear();tot_childs.clear();
    vis.assign(n+1,0);
    for(ll i = 1;i<=n;++i){
        adj[i].clear();
        child_got_one[i] = 0;
    }

    ll t = n-1;
    while(t--){
        tree();
    }

    tot_childs[1] = adj[1].size();
    for(ll i = 2;i<=n;++i){
        tot_childs[i] = (adj[i].size()-1);
    }

    bacche(1,-1);

    ll got_one = 0,flag = 0;
    ll q;cin>>q;
    set<pair<ll,ll>> query;
    while(q--){
        ll a,b;cin>>a;
        
        if(a == 1){
            cin>>b;
        }

        if(flag & 1){
            if(a == 2){cout<<n-1<<endl;}
            continue;
        }

        if(a == 1){
            if(query.find({a,b}) != query.end()){
                continue;
            }

            if(child_got_one[b] == tot_childs[b]){
                --ans;
                ++got_one;
                child_got_one[par[b]]++;
                query.insert({a,b});
            }
        }else{
            if(got_one == n){
                ans = n-1;
                flag = 1;
            }
            cout<<ans<<endl;
        }
    }
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   ll t=1;
   cin >> t;
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   //solve();
   return 0;
}