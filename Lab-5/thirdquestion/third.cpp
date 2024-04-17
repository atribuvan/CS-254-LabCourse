#include<bits/stdc++.h>
using namespace std;
int size;

bool is_bipartite(vector<vector<int>>v,int source){
    vector<int>colour(size,-1);
    //-1 means not coloured
    //1-first colour
    //0-second colour
    colour[source]=1;
    queue<int>q;
    q.push(source);
    while(!q.empty()){
        int frnt=q.front();
        q.pop();
        for(int i=0;i<size;i++){
            if(v[frnt][i]==1 && colour[i]==-1){
                colour[i]=1-colour[frnt];
                q.push(i);
            }
            else if(v[frnt][i]==1 && colour[i]==colour[frnt]){
            return false;
        }
    }
  }

return true;
}


int main(){
    //int size;
     ifstream inputFile("thirdquesinput.txt");
    ofstream outputFile("thirdquesoutpt.txt");
    if(!inputFile.is_open()){
        cerr<<"Error in the opening of input file!"<<endl;
        return 0;
    }

    if(!outputFile.is_open()){
        cerr<<"Error in the opening of output file!"<<endl;
        return 0;
    }

    inputFile>>size;
    vector<vector<int>>v(size,vector<int>(size));
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
             int bol;
             inputFile>>bol;
             if(bol==1){
             v[i][j]=0;
             }
             else{
                v[i][j]=1;
             }
             if(i==j){
                v[i][j]=0;
             }
        }
    }
    if(is_bipartite(v,0)){
        outputFile<<"Yes!, It can be divided into two Cliques."<<endl;
    }
    else{
        outputFile<<"No!, It cant be divided into two Cliques."<<endl;
    }

    return 0;
}