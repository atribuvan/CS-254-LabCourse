#include<bits/stdc++.h>
using namespace std;

double find_median(vector<int>a,vector<int>b,int fst,int sst){
    int i=0;
    int j=0;
    int k=0;
    vector<int>ans(fst+sst);
    while(i<fst && j<sst){
        if(a[i]<=b[j]){
            ans[k]=a[i];
            i++;
            k++;
        }
        else{
            ans[k]=b[j];
            j++;
            k++;
        }
    }
    while(i<fst){
        ans[k]=a[i];
        i++;
        k++;
    }
    while(j<sst){
        ans[k]=b[j];
        j++;
        k++;
    }
    int mid=(fst+sst)/2;
    if((fst+sst)%2==1){
        return ans[mid];
    }
    else{
        return (ans[mid-1]+ans[mid])/2.0;
    }
}

int main(){
    ifstream inputFile("secinputfile.txt");
    ofstream outputFile("secondoutputfile.txt");
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
    vector<int>v1(size1);
    vector<int>v2(size2);
    for(int i=0;i<size1;i++){
        inputFile>>v1[i];
    }
    for(int i=0;i<size2;i++){
        inputFile>>v2[i];
    }
     inputFile.close();
     
     outputFile<<"Median Element is: "<<find_median(v1,v2,size1,size2)<<endl;
    outputFile.close();

    return 0;
}