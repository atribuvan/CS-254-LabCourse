#include<bits/stdc++.h>
using namespace std;
const int N=1e5+8;
bool vertex_visited[N];
bool edge_visited[N];
int vertex_discovered[N];
int vertex_low[N];
int edge_discovered[N];
int edge_low[N];

bool articulation_point_dfs(vector<vector<int>>&g,int a,int &vertex_time,int p){
    vertex_visited[a]=true;
    vertex_discovered[a]=vertex_low[a]= ++vertex_time;
    int c=0;
    for(auto it:g[a]){
        if(!vertex_visited[it]){
            c++;
            if(articulation_point_dfs(g,it,vertex_time,a)){
                return true;
            }
            vertex_low[a]=min(vertex_low[a],vertex_low[it]);
            if(p!=-1 && vertex_low[it]>=vertex_discovered[a]){
                return true;
            }
        }
        else if(it!=p){
            vertex_low[a]=min(vertex_low[a],vertex_discovered[it]);
        }
    }
    if(p==-1 && c>1){
        return true;
    }
    else{
        return false;
    }
}

bool articulation_edge_dfs(vector<vector<int>>&g,int a,int &edge_time,int p){
    edge_visited[a]=true;
    edge_discovered[a]=edge_low[a]= ++edge_time;
    for(auto it:g[a]){
        if(!edge_visited[it]){
            if(articulation_edge_dfs(g,it,edge_time,a)){
                return true;
            }
            edge_low[a]=min(edge_low[a],edge_low[it]);
            if(edge_low[it]>edge_discovered[a]){
                return true;
            }
        }
        else if(it!=p){
             edge_low[a]=min(edge_low[a],edge_discovered[it]);
        }
    }
    return false;
}

int main(){
    freopen("fifthquesinpt.txt","r",stdin);
    freopen("fifthquesoutpt.txt","w",stdout);

    int vertices,edges;
    cin>>vertices>>edges;
    vector<vector<int>>g(vertices);
    while(edges--){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }
    // vector<bool>vertex_visited(vertices,false);
    // vector<int>vertex_discovered(vertices,0);
    // vector<int>vertex_low(vertices,0);
    bool art_point=false;
    int vertex_time=0;
    for(int i=0;i<vertices;i++){
        if(!vertex_visited[i] && articulation_point_dfs(g,i,vertex_time,-1)){
            cout<<"It has Articulation points!"<<endl;
            art_point=true;
            break;
        }
    }
    if(art_point==false){
        cout<<"It does not contain Articulation points!"<<endl;
    }

    // vector<bool>edge_visited(vertices,0);
    // vector<int>edge_discovered(vertices,0);
    // vector<int>edge_low(vertices,0);
    bool art_edge=false;
    int edge_time=0;
    for(int i=0;i<vertices;i++){
        if(!edge_visited[i] && articulation_edge_dfs(g,i,edge_time,-1)){
            cout<<"It has Articulation edges!"<<endl;
            art_edge=true;
            break;
        }
    }
    if(art_edge==false){
        cout<<"It does not contain Articulation edges!"<<endl;
    }

    return 0;
}