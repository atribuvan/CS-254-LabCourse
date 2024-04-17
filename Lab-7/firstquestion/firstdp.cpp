#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("firstinpt.txt","r",stdin);
    freopen("firstoutpt.txt","w",stdout);
    int size,weight_limit;
    cin>>size>>weight_limit;
    vector<int>weights(size);
    vector<int>values(size);
     for(int i=0;i<size;i++){
    cin>>weights[i];
     }
   for(int i=0;i<size;i++){
    cin>>values[i];
   }
   vector<vector<int>>dp(size+1,vector<int>(weight_limit+1));
   for(int i=0;i<=size;i++){
    for(int wt=0;wt<=weight_limit;wt++){
         if(i==0 || wt==0){
            dp[i][wt]=0;
         }
         else{
            if(weights[i-1]<=wt){
                dp[i][wt]=max(dp[i-1][wt],dp[i-1][wt-weights[i-1]]+values[i-1]);
            }
            else{
                dp[i][wt]=dp[i-1][wt];
            }
         }
    }
   }
   cout<<"Max Cost is: "<<dp[size][weight_limit]<<endl;

    return 0;
}