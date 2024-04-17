#include <bits/stdc++.h>
using namespace std;

void display_matrix(ofstream& outputFile,string label,vector<vector<int>>matrix,int starting_row, int starting_column,int ending_row,int ending_column){
    outputFile<<endl<<label<<":"<<endl;

    for(int i=starting_row;i<=ending_row;i++){
        for(int j=starting_column;j<=ending_column;j++){
            outputFile<<setw(10)<<matrix[i][j];
        }
        outputFile<<endl;
    }

    outputFile<<endl;
    return;
}

void add_two_matrices(vector<vector<int>>firstmatrix,vector<vector<int>>secondmatrix,vector<vector<int>>&resultant_matrix,int splt_index){
    for(auto i=0;i<splt_index;i++){
        for(auto j=0;j<splt_index;j++){
            resultant_matrix[i][j]=firstmatrix[i][j]+secondmatrix[i][j];
        }
    }

}

vector<vector<int>>multiply_two_matrices(vector<vector<int>>firstmatrix,vector<vector<int>>secondmatrix) {
    int first_cols=firstmatrix[0].size();
    int first_rows=firstmatrix.size();
    int second_cols=secondmatrix[0].size();
    int second_rows=secondmatrix.size();

    if(first_cols!=second_rows){
      cout<<"\nError: The number of columns in Matrix " "A must be equal to the number of rows in "
                "Matrix B\n";
        return {};
    }

    vector<int>result_matrixrow(second_cols,0);
    vector<vector<int>>result_matrix(first_rows,result_matrixrow);

    if(first_cols==1){
        result_matrix[0][0]=firstmatrix[0][0]*secondmatrix[0][0];
    }
    else{
        int split_Index=first_cols/2;

        vector<int>row_vector(split_Index,0);
        vector<vector<int>>result_matrix00(split_Index,row_vector);
        vector<vector<int>>result_matrix01(split_Index,row_vector);
        vector<vector<int>>result_matrix10(split_Index,row_vector);
        vector<vector<int>>result_matrix11(split_Index,row_vector);

        vector<vector<int>>a00(split_Index,row_vector);
        vector<vector<int>>a01(split_Index,row_vector);
        vector<vector<int>>a10(split_Index,row_vector);
        vector<vector<int>>a11(split_Index,row_vector);
        vector<vector<int>>b00(split_Index,row_vector);
        vector<vector<int>>b01(split_Index,row_vector);
        vector<vector<int>>b10(split_Index,row_vector);
        vector<vector<int>>b11(split_Index,row_vector);

        for(auto i=0;i<split_Index;i++){
            for(auto j=0;j<split_Index;j++){
                a00[i][j]=firstmatrix[i][j];
                a01[i][j]=firstmatrix[i][j+split_Index];
                a10[i][j]=firstmatrix[split_Index+i][j];
                a11[i][j]=firstmatrix[i+split_Index][j+split_Index];
                b00[i][j]=secondmatrix[i][j];
                b01[i][j]=secondmatrix[i][j+split_Index];
                b10[i][j]=secondmatrix[split_Index+i][j];
                b11[i][j]=secondmatrix[i+split_Index][j+split_Index];
            }
    }

    add_two_matrices(multiply_two_matrices(a00,b00),multiply_two_matrices(a01,b10),result_matrix00,split_Index);
    add_two_matrices(multiply_two_matrices(a00,b01),multiply_two_matrices(a01,b11),result_matrix01,split_Index);
    add_two_matrices(multiply_two_matrices(a10,b00),multiply_two_matrices(a11,b10),result_matrix10,split_Index);
    add_two_matrices(multiply_two_matrices(a10,b01),multiply_two_matrices(a11,b11),result_matrix11,split_Index);

        for(auto i=0;i<split_Index;i++){
            for (auto j=0;j<split_Index;j++){
                result_matrix[i][j]=result_matrix00[i][j];
                result_matrix[i][j+split_Index]=result_matrix01[i][j];
                result_matrix[split_Index+i][j]=result_matrix10[i][j];
                result_matrix[i+split_Index][j+split_Index]=result_matrix11[i][j];
            }
    }

        result_matrix00.clear();
        result_matrix01.clear();
        result_matrix10.clear();
        result_matrix11.clear();
        a00.clear();
        a01.clear();
        a10.clear();
        a11.clear();
        b00.clear();
        b01.clear();
        b10.clear();
        b11.clear();
    }
    return result_matrix;
}

int main(){
    ifstream inputFile("firstinpt.txt");
    ofstream outputFile("firstoutpt.txt");
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

    vector<vector<int>>firstmatrix,secondmatrix;
    int x;
    for(int i=0;i<total;i++){
        vector<int>first_row;
        for(int j=0;j<total;j++) {
            inputFile>>x;
            first_row.push_back(x);
        }
        firstmatrix.push_back(first_row);
    }
       
    int y;
    for(int i=0;i<total;i++) {
        vector<int>second_row;
        for(int j=0;j<total;j++) {
            inputFile>>y;
            second_row.push_back(y);
        }
        secondmatrix.push_back(second_row);
    }
    inputFile.close();

    vector<vector<int>>resultant_matrix(multiply_two_matrices(firstmatrix,secondmatrix));

    display_matrix(outputFile,"Final Result is ",resultant_matrix,0,0,total-1,total-1);
    outputFile.close();
    
    return 0;
}