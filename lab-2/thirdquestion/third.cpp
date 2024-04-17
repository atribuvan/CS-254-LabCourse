#include<bits/stdc++.h>
using namespace std;

void sortfunc(int A[],int total){

    for(int i=1;i<total;i++){
        int key=A[i];
        int j=i-1;
        while(j>=0 && A[j]>key){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
    }

}

int main(){
    ifstream inputFile("thirdinput.txt");
    ofstream outputFile("thirdoutput.txt");
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
    int *A =new int[total];
    for(int i=0;i<total;i++){
        inputFile>>A[i];
        }
    inputFile.close();

    sortfunc(A,total);
    outputFile<<"The Whole sorted array is: "<<endl;
    for(int i=0;i<total;i++){
        outputFile<<A[i]<<" ";
    }
    outputFile<<endl;

    return 0;
}