#include<bits/stdc++.h>
using namespace std;
int A[10000000];

// void sortfunc(int A[],int size1,int total){

//     for(int i=size1;i<total;i++){
//         int key=A[i];
//         int j=i-1;
//         while(j>=0 && A[j]>key){
//             A[j+1]=A[j];
//             j--;
//         }
//         A[j+1]=key;
//     }

// }

void sortfunc(int A[],int size1,int total){
    int at=size1;
    while(at>0){
        for(int i=0;i+at<total;i++){
            if(A[i]>A[i+at]){
                swap(A[i],A[i+at]);
            }
        }

        if(at==1){
            at=0;
        }
        else{
            at=ceil(at/2.0);
        }
    }
}

int main(){
    ifstream inputFile("secondinput.txt");
    ofstream outputFile("secondoutput.txt");
    if(!inputFile.is_open()){
        cerr<<"Error in the opening of input file!"<<endl;
        return 0;
    }

    if(!outputFile.is_open()){
        cerr<<"Error in the opening of output file!"<<endl;
        return 0;
    }

     // total is the total size of the array
     // size1 is the size of the 1st sorted part of the array
    int total,size1;
    inputFile>>total>>size1;
    // int *A =new int[total];
    for(int i=0;i<total;i++){
        inputFile>>A[i];
        }
    inputFile.close();

    sortfunc(A,size1,total);
    outputFile<<"The Whole sorted array is: "<<endl;
    for(int i=0;i<total;i++){
        outputFile<<A[i]<<" ";
    }
    outputFile<<endl;

    return 0;
}