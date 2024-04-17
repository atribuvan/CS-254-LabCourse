#include<bits/stdc++.h>
using namespace std;

long long merge(long long a[],int low,int mid,int high){
    long long outpt=0;
    int i=low;
    int j=mid;
    int k=0;
    int tempsize=high-low+1;
    int b[tempsize];
    while(i<mid && j<=high){
          if(a[i]<=a[j]){
            b[k]=a[i];
            i++;
            k++;
          }
          else{
            b[k]=a[j];
            outpt=outpt+(mid-i);
            j++;
            k++;
          }
    }
    while(i<mid){
        b[k]=a[i];
        ++i;
        ++k;
    }
    while(j<=high){
        b[k]=a[j];
        ++j;
        ++k;
    }
    int x=0;
    for(int i=low;i<=high;++i){
          a[i]=b[x];
          x++;
    }
    return outpt;
}

long long  count_inversion_using_merge_func(long long a[],int low,int high){
    long long outpt=0;
       if(low<high){
        int mid=(low+high)/2;
        outpt=outpt+count_inversion_using_merge_func(a,low,mid);
        outpt=outpt+count_inversion_using_merge_func(a,mid+1,high);
        outpt=outpt+merge(a,low,mid+1,high);
           }
        return outpt;

}

int main(){
    ifstream inputFile("firstinputfile.txt");
    ofstream outputFile("outputfirstquesfile.txt");
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
     long long a[size];
     for(int i=0;i<size;++i){
        inputFile>>a[i];
     }
     inputFile.close();

    long long val=count_inversion_using_merge_func(a,0,size-1);
    outputFile<<"Number of inversions is: "<<val<<endl;
    //outputFile.close();

    return 0;
}