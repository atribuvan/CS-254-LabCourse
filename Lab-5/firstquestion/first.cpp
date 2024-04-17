#include<bits/stdc++.h>
using namespace std;

int traverse(vector<vector<int>>&v,int i,int j){
    if(v[i][j]==0){
        return 0;
    }
    else{
        v[i][j]=0;
        int val=1;
        val=val+traverse(v,i,j-1)+traverse(v,i,j+1)+traverse(v,i+1,j)+traverse(v,i-1,j)+traverse(v,i-1,j-1)+traverse(v,i+1,j+1)+traverse(v,i+1,j-1)+traverse(v,i-1,j+1);
       return val;
        
    }
}

int main(){
   ifstream inputFile("firstquesinput.txt");
    ofstream outputFile("firstquesoutpt.txt");
    if(!inputFile.is_open()){
        cerr<<"Error in the opening of input file!"<<endl;
        return 0;
    }

    if(!outputFile.is_open()){
        cerr<<"Error in the opening of output file!"<<endl;
        return 0;
    }

    int size;
    inputFile>>size;
    vector<vector<int>>v(size+2,vector<int>(size+2,0));
    
    for(int i=1;i<=size;i++){
        for(int j=1;j<=size;j++){
            inputFile>>v[i][j];
        }
    }
    inputFile.close();
    int outpt=INT_MIN;
    for(int i=1;i<=size;i++){
        for(int j=1;j<=size;j++){
            outpt=max(outpt,traverse(v,i,j));
        }
    }
    outputFile<<"Size of the Largest region is: "<<outpt<<endl;
    
    return 0;
}