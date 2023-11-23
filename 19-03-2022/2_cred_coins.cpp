#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int ans[t];
    int i=0;
    while(t != 0){
        int x,y;
        cin>>x>>y;
        int no_of_bags = (x*y)/100;
        ans[i] = no_of_bags;
        i++;
        t--;
    }

    for(int ind = 0;ind<i;ind++){
        cout<<ans[ind]<<endl;
    }
    
    return 0;
}