#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream inputFile("daa_lab1firstquesin.txt");
    ofstream outputFile("daa_lab1firstquesout.txt");

    if(!inputFile.is_open()){
        cerr<<"Error in the opening of input file."<<endl;
        return 0; 
    }
    if(!outputFile.is_open()){
        cerr<<"Error in the opening of output file."<<endl;
        return 0;
    }

    int size;
    inputFile>>size;
    vector<int>v(size);
    for(int i=0;i<size;i++){
        inputFile>>v[i];
    }
    inputFile.close();
    if(size<2){
        cerr<<"Error: Array should have at least two elements to get sum."<<endl;
        return 0; 
    }

    int a=max(v[0],v[1]);
    int b=min(v[0],v[1]);
    for(int i=2;i<size;i++){
        if(v[i]>a){
           b=a;
           a=v[i];
        }
        else if(v[i]>b){
            b=v[i];
        }
    }

    outputFile<<"Maximum Possible Sum is: "<<a+b<<endl;
    outputFile.close();

    return 0; 
}
