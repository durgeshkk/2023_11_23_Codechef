/*
    set<ll> s;
    vector<ll> f(n),b(n);

    for(ll i=0;i<n;i++){
        if(s.find(v[i]) != s.end()){
            f[i] = 0;
        }
        else{
            f[i] = 1;
        }
        s.insert(v[i]);
    }

    for(auto it:s){
        cout<<it<<" ";
    }
    cout<<endl;

    for(auto it:f){
        cout<<it<<" ";
    }
    cout<<endl;

    s.erase(s.begin(),s.end());

    for(ll i=n-1;i>=0;i--){
        if(s.find(v[i]) != s.end()){
            b[i] = 0;
        }
        else{
            b[i] = 1;
        }
        s.insert(v[i]);
    }


    for(auto it:b){
        cout<<it<<" ";
    }
    cout<<endl;


    ll sm = 0;
    for(auto i=0;i<n;++i){
        if(f[i] == 0){
            sm = 0;
        }
        else{
            f[i] = sm+1;
            sm++;
        }
    }

    sm = 0;
    for(auto i=0;i<n;++i){
        if(b[i] == 0){
            sm = 0;
        }
        else{
            b[i] = sm+1;
            sm++;
        }
    }

    for(auto it2:f){
        cout<<it2<<" ";
    }
    cout<<endl;

    for(auto it1:b){
        cout<<it1<<" ";
    }
    cout<<endl;

    ll mx1 = *max_element(f.begin(),f.end());
    ll mx2 = *max_element(b.begin(),b.end());
    cout<<mx1<<" "<<mx2<<endl;

    ll idx1=-1,idx2 = -1;

    if(mx1 > mx2){

        for(ll i = 0;i<n;++i){
            if(mx1 == f[i]){
                idx2 = i;
                break;
            }
        }

        idx1 = (idx2-f[idx2]+1);

        ll lele = idx1;
        ll rele = (n-1-idx2);

        ll ans = 0;
        if(rele>lele){
            ans = (2*lele + rele);
        }
        else{
            ans = (2*rele+lele);
        }
        cout<<ans<<endl;
    }
    else{
        for(ll i = 0;i<n;++i){
            if(mx2 == b[i]){
                idx1 = i;
                break;
            }
        }

        idx2 = (idx1+b[idx1]-1);

        ll lele = idx1;
        ll rele = (n-1-idx2);

        ll ans = 0;
        if(rele>lele){
            ans = (2*lele + rele);
        }
        else{
            ans = (2*rele+lele);
        }
        cout<<ans<<endl;
    }

    // for(auto it:b){
    //     cout<<it<<" ";
    // }
    // cout<<endl;*/