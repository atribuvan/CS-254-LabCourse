#include<bits/stdc++.h>
using namespace std;

int* merge(const int A[],const int B[],int size1,int size2){
    int *ans = new int[size1+size2];
    int i=0,j=0,k=0;

    while(i<size1 && j<size2){
        if(A[i]<=B[j]){
            ans[k]=A[i];            
            i++;
            k++;
        }
        else{
            ans[k]=B[j];
            k++;
            j++;
        }
    }
    while(i<size1){
        ans[k]=A[i];
        k++;
        i++;
        }
    while(j<size2){
        ans[k]=B[j];
        k++;
        j++;
        }

    return ans;
}

vector<int> merge_union(const int A[],const int B[],int size1,int size2){
    vector<int>anstwo;
    int i=0,j=0;

    while(i<size1 && j<size2){
        if(A[i]<B[j]){
            anstwo.push_back(A[i]);
            i++;
            }
        else if(A[i]>B[j]){
            anstwo.push_back(B[j]);
            j++;
        }
        else{
            anstwo.push_back(A[i]);
            i++;
            j++;
        }
    }

    while(i<size1){
        anstwo.push_back(A[i]);
        i++;
    }
    while(j<size2){
    anstwo.push_back(B[j]);
    j++;
    }
    anstwo.erase(unique(anstwo.begin(),anstwo.end()),anstwo.end());

    return anstwo;
}

vector<int>merge_intersection(const int A[],const int B[],int size1,int size2){
    vector<int>ansthree;
    int i=0,j=0;
    while(i<size1 && j<size2){
        if(A[i]>B[j]){
            j++;
            }
        else if(A[i]<B[j]){
            i++;
            }
        else if(A[i]==B[j]){
            ansthree.push_back(A[i]);
            i++;
            j++;
        }
    }

    ansthree.erase(unique(ansthree.begin(),ansthree.end()),ansthree.end());

    return ansthree;
}

int main(){
    ifstream inputFile("firstinput.txt");
    ofstream outputFile("firstoutput.txt");
    if(!inputFile.is_open()){
        cerr<<"Error in the opening of input file!"<<endl;
        return 0;
    }

    if(!outputFile.is_open()){
        cerr<<"Error in the opening of output file!"<<endl;
        return 0;
    }

    int size1,size2;
    inputFile>>size1>>size2;
    int *A = new int[size1];
    int *B = new int[size2];
    for(int i=0;i<size1;i++){
        inputFile>>A[i];
        }
    for(int i=0;i<size2;i++){
        inputFile>>B[i];
        }
    inputFile.close();

    outputFile<<"Outputs of all three subquestions of this question are present here:"<<endl;
    // For 1st subquestion
    int *f = merge(A,B,size1,size2);
    outputFile<<"a)Sorted Array by merging of A and B is given by: "<<endl;
    for(int i=0;i<size1+size2;i++){
        outputFile<<f[i]<<" ";
    }
    outputFile<<endl;

    //For 2nd subquestion
    vector<int>s= merge_union(A,B,size1,size2);
    outputFile<<"b)Sorted Array for A U B is given by: "<<endl;
    for(auto it:s){
        outputFile<<it<<" ";
    }
    outputFile<<endl;

    //For 3rd subquestion
    vector<int>t= merge_intersection(A,B,size1,size2);
    outputFile<<"c)Sorted Array for A intersection B is given by: "<<endl;
    for(auto jt:t){
        outputFile<<jt<<" ";
    }
    outputFile<<endl;

    return 0;
}