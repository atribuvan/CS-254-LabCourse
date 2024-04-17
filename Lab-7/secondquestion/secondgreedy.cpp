#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,pair<int,int>>a,pair<int,pair<int,int>>b){
    return a.first>=b.first;
}

int main(){
    freopen("secondinpt.txt","r",stdin);
    freopen("secondoutpt.txt","w",stdout);
    int t;
    cin>>t;
    while(t--){
    int size;
    cin>>size;
    // vector<char>jobId(size);
    vector<int>deadline(size);
    vector<int>profit(size);
    // for(int i=0;i<size;i++){
    //     cin>>jobId[i];
    // }
    for(int i=0;i<size;i++){
        cin>>deadline[i];
    }
    for(int i=0;i<size;i++){
        cin>>profit[i];
    }
    vector<pair<int,pair<int,int>>>p(size);
    for(int i=0;i<size;i++){
        p[i]={profit[i],{deadline[i],i}};
    }
    sort(p.begin(),p.end(),cmp);
    int max_profit=0;
    // int cnt=0;
    vector<int>assigned(size,-1);
   for(int i=0;i<size;i++){
     int temp=p[i].second.first;
     int var=min(size,temp);
     for(int j=var-1;j>=0;j--){
        if(assigned[j]==-1){
            assigned[j]=p[i].second.second+1;
            // cnt++;
            max_profit=max_profit+p[i].first;
            break;
        }
     }
   }
   cout<<"Indices of Items included are: ";
    for(auto it:assigned){
        if(it!=-1){
        cout<<it<<" ";
        }
    }
    cout<<endl;
    cout<<max_profit<<endl;
    }

    return 0;
}