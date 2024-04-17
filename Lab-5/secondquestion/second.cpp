#include<bits/stdc++.h>
using namespace std;
int visited[1000000];

//Actuall we are finding shortest path using BFS
int number_of_moves_required(int destin[],int size){
       visited[1]=1;
       queue<pair<int,int>>q;
       //first indicates position
       //second indicates number of moves
       //pair<int,int>temp={1,0};
       q.push({1,0});
       pair<int,int>frnt;

       while(!q.empty()){
        frnt=q.front();
        q.pop();
        int val=frnt.first;
        if(val==size){
            break;
        }
        for(int i=val+1;i<=(val+6) && i<=size;i++){
            if(visited[i]==0){
                visited[i]=1;
                pair<int,int>p;
                p.second=1+frnt.second;
                if(destin[i]!=-1){
                    p.first=destin[i];
                }
                else{
                    p.first=i;
                }
                q.push(p);
            }
         }
       }
        return frnt.second;
}

int main(){
    //ifstream inputFile("secondquesinput.txt");
    ifstream inputFile("inptt.txt");
    ofstream outputFile("secondquesoutpt.txt");
    if(!inputFile.is_open()){
        cerr<<"Error in the opening of input file!"<<endl;
        return 0;
    }

    if(!outputFile.is_open()){
        cerr<<"Error in the opening of output file!"<<endl;
        return 0;
    }

    int size,obstacles;
    inputFile>>size>>obstacles;
    int destin[size+1];
    for(int i=0;i<=size;i++){
        destin[i]=-1;
    }
    for(int i=0;i<obstacles;i++){
        int start,destination;
        inputFile>>start>>destination;
        destin[start]=destination;
    }
    outputFile<<"Minimum Number of throws required to reach last cell is: "<<number_of_moves_required(destin,size)<<endl;

    return 0;
}