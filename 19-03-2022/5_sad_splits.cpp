#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    char *ans[t] = {};
    int i=0;
    while(t != 0){
        int num;
        cin>>num;

        int count = 0;
        if(num %2 == 0)
        {
            while(num != 0){
                if(count == 2){
                    ans[i] = "YES";
                    // cout<<"YES\n";
                    break;
                }
                int rem = num%10;
                if(rem%2 == 0){
                    count += 1;
                }
                num = num/10;
            }    
        }
        if(count != 2){
            // cout<<"NO\n";
            ans[i] = "NO";
        }

        i++;
        t--;
    }

    for(int ind = 0;ind<i;ind++){
        cout<<ans[ind]<<endl;
    }
    return 0;
}