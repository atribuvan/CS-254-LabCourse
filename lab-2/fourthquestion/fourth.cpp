#include<bits/stdc++.h>
using namespace std;

void swap(int *num1,int *num2){
    int t= *num1;
    *num1 = *num2;
    *num2 =t;
}

//This Function returns the correct position of the pivot element
int partition(int a[],int left,int right){
    int last=a[right];
    int index=left,j=left;

    while(j<right){
        if(a[j]<last) {
            swap(&a[index],&a[j]);
            index++;
        }
        j++;
    }
    swap(&a[index],&a[right]);

    return index;
}

//Picks a random pivot element between left and right and partitions a[l...r] around the randomly picked pivot element by using partition() function;
int random_partition(int a[], int left,int right){
    int size= right-left+1;
    int pivot= rand() % size;
    swap(&a[left+pivot], &a[right]);

    return partition(a,left,right);
}

void median_calc(int a[], int left, int right,int k, int& x, int& y){
    if(left<=right){
        int part_index=random_partition(a,left,right);
    //If part_index=k, then we found the median of odd number element in a[]
        if(part_index==k){
            y=a[part_index];
            if(x!=-1){
                return;
            }

        }
    //If part_index=k-1, then we get x&y as middle element of a[]
        else if(part_index==k-1) {
            x=a[part_index];
            if(y!=-1){
                return;
            }

        }
 
    // If part_index>=k then find the index in first half of the a[]
        if(part_index>=k){
            return median_calc(a,left,part_index-1,k,x,y);
        }
        // If part_index<=k then find the index in second half of the a[]
        else{
            return median_calc(a,part_index+1,right,k,x,y);
        }
    }
 
    return;
}

int find_median(int A[],int total){
    int value;
    int x=-1;
    int y=-1;

    if(total%2==1){
        median_calc(A,0,total-1,total/2,x,y);
        value=y;
    }
    else{
        median_calc(A,0,total-1,total/2,x,y);
        value=(x+y)/2;
    }

    return value;
}

int main(){
    ifstream inputFile("fourthinput.txt");
    ofstream outputFile("fourthoutput.txt");
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
    inputFile.close();

    int median = find_median(A,total);
    outputFile<<"The median element of the unsorted array is: "<<median<<endl;

    return 0;
}