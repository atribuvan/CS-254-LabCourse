#include<bits/stdc++.h>
using namespace std;

long long across_sum(vector<long long>&a,int left,int right,int mid){
    long long left_ans=INT_MIN;
    long long variable=0;
    for(long int i=mid;i>=left;i--){
        variable=variable+a[i];
        if(variable>left_ans){
            left_ans=variable;
        }
    }

    long long right_ans=INT_MIN;
    long long variable1=0;
    for(long int i=mid+1;i<=right;i++){
        variable1=variable1+a[i];
        if(variable1>right_ans){
            right_ans=variable1;
        }
    }

    return left_ans+right_ans;
}

long long max_sum_subarray(vector<long long>&a,int left,int right){
    if(left+1==right){
        return max({a[left],a[right],a[left]+a[right]});
    }
    int mid=(left+right)/2;
    //This is Base case for termination of recursion
    if(left==right){
        return a[left];
    }
    while(left<right){
    long long left_side=max_sum_subarray(a,left,mid);
    long long right_side=max_sum_subarray(a,mid,right);
    long long cross=across_sum(a,left,right,mid);
    return max(max(left_side,right_side),cross);
  }
}

int main(){
    ifstream inputFile("secondinpt.txt");
    ofstream outputFile("secondoutpt.txt");
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
    vector<long long>a(total);
    for(long int i=0;i<total;i++){
        inputFile>>a[i];
    }
    inputFile.close();

    outputFile<<"The Largest possible sum of a subsequnce of consecutive items in the given input list is: "<<endl;

    outputFile<<max_sum_subarray(a,0,total-1)<<endl;
    outputFile.close();

    return 0;
}