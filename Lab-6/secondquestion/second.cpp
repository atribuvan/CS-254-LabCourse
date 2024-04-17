#include<bits/stdc++.h>
using namespace std;

void topological_sort(vector<vector<int>>&g,int vertices,vector<int>&outpt,vector<int>&longest_path,bool &bol){
    vector<int>indegree(vertices);
    for(int i=0;i<vertices;i++){
        for(auto it:g[i]){
            indegree[it]++;
        }
    }

    queue<int>q;
    for(int i=0;i<vertices;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int fst=q.front();
        q.pop();
        outpt.push_back(fst);

        for(auto it:g[fst]){
            indegree[it]--;
            longest_path[it]=max(longest_path[it],longest_path[fst]+1);
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }

    if(outpt.size()!=vertices){
      bol=false;
    }
}

int main(){
    ifstream inputFile("secondquesinpt.txt");
    ofstream outputFile("secondquesoutpt.txt");

    if(!inputFile.is_open()){
        cerr<<"Error in the opening of input file!"<<endl;
        return 0;
    }

    if(!outputFile.is_open()){
        cerr<<"Error in the opening of output file!"<<endl;
        return 0;
    }

    int vertices,edges;
    inputFile>>vertices>>edges;
    vector<vector<int>>g(vertices);
    while(edges--){
        int a,b;
        inputFile>>a>>b;
        g[a].push_back(b);
    }
    vector<int>outpt;
    vector<int>longest_path(vertices,0);
    bool bol=true;
    topological_sort(g,vertices,outpt,longest_path,bol);
    if(bol==true){
        int max=longest_path[0];
        for(int i=1;i<vertices;i++){
            if(longest_path[i]>max){
                max=longest_path[i];
            }
        }
        outputFile<<"Lenght of Longest path in the graph is: "<<max<<endl;
    }
    else{
        outputFile<<"It is not a directed acyclic graph"<<endl;
    }
    return 0;
}