#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>v,int low,int high){
	int pivot=v[high];
    int i=low;
    int j=low;
   while(j!=high){
		if(v[j]<=pivot){
			swap(v[i],v[j]);
		}
        j++;
	}
    //i++;
	swap(v[i],v[high]);
	return i;
}

int kth_largest_element(vector<int>v,int low,int high,int ind){

	if(ind>0 && ind<=high-low+1){
		int p_index=partition(v,low,high);
		if(p_index-low==ind-1){
			return v[p_index];
        }
		else if(p_index-low>ind-1){
			return kth_largest_element(v,low,p_index-1,ind);
        }
        else{
		return kth_largest_element(v,p_index+1,high,ind-p_index+low-1);	
        }		
	}
	 return INT_MIN;
}

int main(){
    ifstream inputFile("thirdinputfile.txt");
    ofstream outputFile("thirdoutputfile.txt");
    if(!inputFile.is_open()){
        cerr<<"Error in the opening of input file!"<<endl;
        return 0;
    }

    if(!outputFile.is_open()){
        cerr<<"Error in the opening of output file!"<<endl;
        return 0;
    }

    int size,k;
    inputFile>>size>>k;
    vector<int>v(size);
    for(int i=0;i<size;i++){
        inputFile>>v[i];
    }
     inputFile.close();

    outputFile<<k<<"'th largest element is: "<<kth_largest_element(v,0,size-1,size-k+1)<<endl;
    outputFile.close();

    return 0;
}


