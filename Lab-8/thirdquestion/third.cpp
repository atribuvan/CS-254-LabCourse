#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<pair<int,int>,int>&a,pair<pair<int,int>,int>&b){
    return a.second<b.second;
}

void union_find(map<int,vector<int>>&m,map<int,int>&parent,map<int,int>&size,int frnt,int scnd){
    int var;
    if(size[parent[scnd]]<size[parent[frnt]]){
       var=parent[scnd];
       size[parent[frnt]]=size[parent[frnt]]+size[parent[scnd]];
       for(auto it:m[var]){
        parent[it]=parent[frnt];
        m[parent[frnt]].push_back(it);
       }
    }
    else if(size[parent[frnt]]<=size[parent[scnd]]){
       var=parent[frnt];
       size[parent[scnd]]=size[parent[scnd]]+size[parent[frnt]];
       for(auto it:m[var]){
        parent[it]=parent[scnd];
        m[parent[scnd]].push_back(it);
       }
    }
}

int removed_mst(vector<pair<pair<int,int>,int>>&g,int vertices,int edges,int j){
    map<int,int>parent;
    map<int,int>size;
    map<int,vector<int>>m;
    for(int i=1;i<=vertices;i++){
        parent[i]=i;
        size[i]=1;
        m[i].push_back(i);
    }
    sort(g.begin(),g.end(),cmp);
    int v=0;
    for(int i=0;i<edges;i++){
        int frnt=g[i].first.first;
        int scnd=g[i].first.second;
        if(parent[frnt]!=parent[scnd] && i!=j){
            v=v+g[i].second;
            union_find(m,parent,size,frnt,scnd);
        }
    }
    return v;
}

void print_second_best_mst(vector<pair<pair<int,int>,int>>&g,int vertices,int edges,int j){
    map<int,int>parent;
    map<int,int>size;
    map<int,vector<int>>m;
    for(int i=1;i<=vertices;i++){
        parent[i]=i;
        size[i]=1;
        m[i].push_back(i);
    }
    sort(g.begin(),g.end());
    for(int i=0;i<edges;i++){
        int frnt=g[i].first.first;
        int scnd=g[i].first.second;
        if(parent[frnt]!=parent[scnd] && i!=j){
            cout<<frnt<<" "<<scnd<<endl;
            union_find(m,parent,size,frnt,scnd);
        }
    }
}

void second_best_mst(vector<pair<pair<int,int>,int>>&g,int vertices,int edges){
    map<int,int>parent;
    map<int,int>size;
    map<int,vector<int>>m;
    for(int i=1;i<=vertices;i++){
        parent[i]=i;
        size[i]=1;
        m[i].push_back(i);
    }
    sort(g.begin(),g.end(),cmp);
    int outpt=0;
    for(int i=0;i<edges;i++){
        int frnt=g[i].first.first;
        int scnd=g[i].first.second;
        if(parent[frnt]!=parent[scnd]){
            outpt=outpt+g[i].second;
            union_find(m,parent,size,frnt,scnd);
        }
    }
    int x=-1;
    int temp=INT_MAX;
    for(int i=0;i<edges;i++){
       if(removed_mst(g,vertices,edges,i)>outpt && outpt-removed_mst(g,vertices,edges,i)<temp){
        temp=outpt-removed_mst(g,vertices,edges,i);
        x=i;
       }
    }
    print_second_best_mst(g,vertices,edges,x);
}

int main(){
    freopen("thirdinpt.txt","r",stdin);
    freopen("thirdoutpt.txt","w",stdout);
    int vertices,edges;
    cin>>vertices>>edges;
    vector<pair<pair<int,int>,int>>g;
    for(int i=0;i<edges;i++){
        int fst,sst,wt;
        cin>>fst>>sst>>wt;
        g.push_back({{fst,sst},wt});
    }
    cout<<"Edges that are present in the Second Best Minumum Spanning tree are: "<<endl;
    second_best_mst(g,vertices,edges);

    return 0;
}