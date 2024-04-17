#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("firstinpt.txt","r",stdin);
    freopen("firstoutpt.txt","w",stdout);
    int size,weight_limit;
    cin>>size>>weight_limit;
    vector<double>weights(size);
    vector<double>values(size);
   vector<double>ratio(size);
   for(int i=0;i<size;i++){
    cin>>weights[i];
   }
   for(int i=0;i<size;i++){
    cin>>values[i];
   }
   vector<pair<double,int>>ratiopair(size);
   for(int i=0;i<size;i++){
    ratio[i]=values[i]/weights[i];
    ratiopair[i]={ratio[i],i};
   }
   sort(ratiopair.begin(),ratiopair.end());
   int temp=weight_limit;
   int max_cost=0;
   vector<int>sequence;
    for(int i=size-1;i>=0;i--){
        if(weights[ratiopair[i].second]<=temp){
            temp=temp-weights[ratiopair[i].second];
            max_cost=max_cost+values[ratiopair[i].second];
            sequence.push_back(ratiopair[i].second+1);
        }
        else if(temp<=0){
            break;
        }
    }
    cout<<"Indices of Items included are: ";
    for(auto it:sequence){
        cout<<it<<" ";
    }
    cout<<endl;
    cout<<"Max Cost is: "<<max_cost<<endl;
    // for(int i=0;i<size;i++){
    //     cout<<ratiopair[i].first<<" "<<ratiopair[i].second<<endl;
    // }

    return 0;
}

// 5 10
// 2 5 7 3 1
// 10 20 15 7 5

// 5 26
// 12 7 11 8 9
// 24 13 23 15 16

// 10 165
// 23 31 29 44 53 38 63 85 89 82
// 92 57 49 68 60 43 67 84 87 72