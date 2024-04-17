#include<bits/stdc++.h>
using namespace std;

void topological_sort(vector<vector<int>>&g,int vertices,vector<int>&outpt,bool &bol){
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
    ifstream inputFile("firstquesinpt.txt");
    ofstream outputFile("firstquesoutpt.txt");

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
    bool bol=true;
    topological_sort(g,vertices,outpt,bol);
    if(bol==true){
        outputFile<<"Topological sorting of given Directed Acyclic Graph is: "<<endl;
        for(auto it:outpt){
            outputFile<<it<<" ";
        }
        outputFile<<endl;
    }
    else{
        outputFile<<"It is not a directed acyclic graph"<<endl;
    }
    return 0;
}