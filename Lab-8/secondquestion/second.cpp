#include<bits/stdc++.h>
using namespace std;

int v[18][18][2];
long long a[1<<18][18][2];

long long minvalue(int vertices,int edges,int m,int prev,int cl){
    if(m== ((1<<vertices)-1)){
        return 0;
    }
     if(a[m][prev][cl==1]!=0){
         return a[m][prev][cl==1];
     }

        long long outpt=1e9;
        for(int i=0;i<vertices;i++){
            for(int j=0;j<2;j++){
                if(v[prev][i][j] && !(m & (1<<i)) && (j!=cl)){
                    long long temp1=v[prev][i][j]+minvalue(vertices,edges,m|(1<<i),i,j);
                    outpt=min(outpt,temp1);
                }
            }
        }
        return a[m][prev][cl==1]=outpt;
    }


int solution(int vertices,int edges){
    long long outpt=1e9;
    for(int i=0;i<vertices;i++){
        outpt=min(outpt,minvalue(vertices,edges, 1<<i ,i,2));
    }
    if(outpt!=1e9){
        return outpt;
    }
    else{
        return -1;//Not Possible
    }
}

int main(){
    freopen("secondinpt.txt","r",stdin);
    freopen("secondoutpt.txt","w",stdout);
    int vertices,edges;
    cin>>vertices>>edges;
    vector<pair<pair<int,int>,pair<int,char>>>g;
    for(int i=0;i<edges;i++){
        int fst,sst,wt;
        char color;
        cin>>fst>>sst>>wt;
        cin>>color;
        g.push_back({{fst,sst},{wt,color}});
    }
    for(int i=0;i<edges;i++){
        int fst=g[i].first.first-1;
        int sst=g[i].first.second-1;
        int weight=g[i].second.first;
        char clr=g[i].second.second;
        // if(clr=='W'){

        // }
        v[fst][sst][clr=='W']=weight;
        v[sst][fst][clr=='W']=weight;
    }
    cout<<solution(vertices,edges)<<endl;

    return 0;
}


// 3 4
// 1 2 2 B
// 1 2 3 W
// 2 3 4 W
// 2 3 5 B
