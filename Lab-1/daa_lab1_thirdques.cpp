#include <bits/stdc++.h>
using namespace std;

int func(int vis,int curr,vector<vector<int>>dis,map<pair<int,int>,int>p){
    int n=dis.size();
    if(vis==(1<<n)-1){
        return dis[curr][0];
        }
    
    pair<int,int>pr={vis,curr};
    if(p.find(pr)!=p.end()){
        return p[pr];
    }

    int min_dis=INT_MAX;
    for(int i=0;i<n;++i){
        if((vis & (1<<i))==0){
            int visits_now = vis | (1<<i);
            int res=dis[curr][i]+func(visits_now,i,dis,p);
            min_dis=min(min_dis,res);
        }
    }
    p[pr]=min_dis;
    return min_dis;
}

int main(){
    ifstream inputFile("daa_lab1thirdquesin.txt");
    ofstream outputFile("daa_lab1thirdquesout.txt");
    if(!inputFile.is_open()){
        cerr<<"Error in the opening of input file."<<endl;
        return 0;
    }
    if(!outputFile.is_open()) {
        cerr<<"Error in the opening of output file."<<endl;
        return 0; 
    }

    int size;
    inputFile>>size;

    vector<vector<int>>dis(size,vector<int>(size));
    for(int i=0;i<size;i++){
        for(int j=i;j<size;j++){
            if(i==j){
               dis[i][i]=0;
            }
            else{
                int a;
                inputFile>>a;
                dis[i][j]=a;
                dis[j][i]=a;
            }
        }
    }

    map<pair<int,int>,int>p;
    inputFile.close();

    outputFile<<"Minimum Distance is: "<<func(1,0,dis,p);
    outputFile.close();

    return 0;
}

    //     vector<vector<int>>dis= {
    //     {0, 10, 15, 20},
    //     {10, 0, 35, 25},
    //     {15, 35, 0, 30},
    //     {20, 25, 30, 0}
    // };