#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream inputFile("fifthinput.txt");
    ofstream outputFile("fifthoutput.txt");
    if(!inputFile.is_open()){
        cerr<<"Error in the opening of input file!"<<endl;
        return 0;
    }

    if(!outputFile.is_open()){
        cerr<<"Error in the opening of output file!"<<endl;
        return 0;
    }

    int total;
    inputFile>>total;
    int *A = new int[total];
    for(int i=0;i<total;i++){
        inputFile>>A[i];
        }
    
    // int fst_min=min(A[0],A[1]);
    // int snd_min=max(A[0],A[1]);
    // for(int i=1;i<total;i++){
    //     if(A[i]<fst_min){
    //         snd_min=fst_min;
    //         fst_min=A[i];
    //     }
    //     else if(A[i]<snd_min){
    //         snd_min=A[i];
    //     }
    // }
      clock_t start,end;
      start=clock();

    int fst_min=A[0];
    int snd_min=A[0];

     for(int i=0;i<total;i++){
        if(A[i]<fst_min){
            fst_min=A[i];
            }
    }

    for(int i=0;i<total;i++){
        if(A[i]<snd_min && A[i]>fst_min){
            snd_min=A[i];
            }
    }

    end=clock();

    outputFile<<"The first minima of the given unsorted array is: "<<fst_min<<endl;
    outputFile<<"The second minima of the given unsorted array is: "<<snd_min<<endl;
    double time_took = double(end-start)/double(CLOCKS_PER_SEC);
    outputFile<<"The time taken to run this program is: "<<time_took<<" sec"<<endl;
    outputFile<<"Observation: The program contains two seperate for loops that run from 0 to total. Hence the Time Complexity is O(n)."<<endl;

    return 0;
}