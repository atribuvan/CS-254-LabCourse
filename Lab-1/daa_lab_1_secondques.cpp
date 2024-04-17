#include <bits/stdc++.h>
using namespace std;

int knapsack(int Wt,vector<int> weights,vector<int> vals,int size){
    vector<vector<int>>dp(size+1,vector<int>(Wt+1,0));
    for(int i=1;i<=size;i++) {
        for(int w=1;w<=Wt;w++){
            if(weights[i-1]<=w) {
                dp[i][w]=max(vals[i-1]+dp[i-1][w-weights[i-1]],dp[i-1][w]);
            }
            else{
                dp[i][w]=dp[i-1][w];
            }
        }
    }

    return dp[size][Wt];
}

int main(){
    ifstream inputFile("daa_lab1secondquesin.txt");
    ofstream outputFile("daa_lab1secondquesout.txt");

    if(!inputFile.is_open()){
        cerr<<"Error in the opening of input file."<<endl;
        return 0;
    }
    if(!outputFile.is_open()){
        cerr<<"Error in the opening of output file."<<endl;
        return 0; 
    }

    int Wt,size;
    inputFile>>Wt>>size;

    vector<int>weights(size);
    vector<int>vals(size);
    for(int i=0;i<size;i++){
        inputFile>>weights[i]>>vals[i];
    }
    inputFile.close();

    int max_val=knapsack(Wt,weights,vals,size);

    outputFile<<"Maximum Value is: "<<max_val<<endl;
    outputFile.close();

    return 0; 
}
