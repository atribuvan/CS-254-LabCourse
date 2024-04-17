#include<bits/stdc++.h>
using namespace std;
const int N=1e5+8;
stack<int>s;
int visited[N];

void dfs(vector<vector<int>>&g,int a){
    visited[a]=1;
    for(auto it:g[a]){
       if(!visited[it]){
        dfs(g,it);
       }
    }
    s.push(a);
}

void transpose_dfs(vector<vector<int>>&transpose,vector<int>&transpose_visited,int a){
    transpose_visited[a]=1;
    cout<<a<<" ";
    for(auto it:transpose[a]){
      if(!transpose_visited[it]){
        transpose_dfs(transpose,transpose_visited,it);
      }
    }
}

void topological_sort(vector<vector<int>>&g,int vertices,vector<int>&outpt){
    for(int i=0;i<vertices;i++){
        if(!visited[i]){
            dfs(g,i);
        }
    }
    while(!s.empty()){
        int fst=s.top();
        s.pop();
        outpt.push_back(fst);
    }

}

int main(){
   freopen("thirdquesinpt.txt","r",stdin);
   freopen("thirdquesoutpt.txt","w",stdout);

    int vertices,edges;
    cin>>vertices>>edges;
    vector<vector<int>>g(vertices);
    vector<vector<int>>transpose(vertices);
    while(edges--){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        transpose[b].push_back(a);
    }
    vector<int>outpt;
    vector<int>transpose_visited(vertices,0);
    topological_sort(g,vertices,outpt);
      for(auto it:outpt){
         if(!transpose_visited[it]){
            transpose_dfs(transpose,transpose_visited,it);
            cout<<endl;
         }
      }

    return 0;
}