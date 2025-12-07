#include<bits/stdc++.h>
using namespace std;

// set matrix zeros

// Brute
void markRow(vector<vector<int>>& matrix, int i){
    int m = matrix[0].size();

    for(int j=0; j<m; j++){                         // to mark the whole row we have to iterate through all the columns
        if(matrix[i][j] != 0){
            matrix[i][j] = -1;
        }
    }
}

void markCol(vector<vector<int>>& matrix, int j){
    int n = matrix.size();

    for(int i=0; i<n; i++){                                          // to mark the column we have to iterate through all the rows
        if(matrix[i][j] != 0){
            matrix[i][j] = -1;
        }
    }
}

void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();              // row
    int m = matrix[0].size();           // column

    // this one is to mark the rows and cols as -1 if 0 lies in there
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] == 0){                    // if zero is found at a point then mark its row and column -1 (we are marking -1 and not zero as it might can cause incorrectness due to new zeros)
                markRow(matrix, i);
                markCol(matrix, j);
            }
        }
    }

    // this loop is to convert -1 to 0
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] == -1){
                matrix[i][j] = 0;
            }
        }
    }

}


// Better
void setZeroes2(vector<vector<int>>& matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> rowTrack(n);
    vector<int> colTrack(m);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] == 0){
                rowTrack[i] = 1;                       // means we have to mark this row and col zero
                colTrack[j] = 1;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(rowTrack[i] == 1 || colTrack[j] == 1){
                matrix[i][j] = 0;
            }
        }
    }
}


// Optimal
// here we'll use the first row for keeping track of the row and first column for the track of column. for column track we'll take a separate variable just for the first element as the matrix[0][0] is reserved for the rowTrack
void setZeroes3(vector<vector<int>>& matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    // rowTrack --> matrix[i][0]
    // colTrack --> col0 + matrix[0][j]

    int col0 = 1;
    for(int i=0; i<n; i++){                          // for marking the rowTrak and colTrack
        for(int j=0; j<m; j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;                    // mark the row

                if(j != 0){                          // means if it's not the first element then we'll be using the matrix else we'll use the separate varibale that we have defined
                    matrix[0][j] = 0;
                }
                else{
                    col0 = 0;
                }
            }
        }
    }

    // for converting the normal part of the matrix 
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(matrix[i][j] != 0){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                } 
            }
        }
    }

    // now for converting the rowTrack and colTrack part
    if(matrix[0][0] == 0){                                      // if any element=0 in the first row then the track will be at matrix[0][0]
        for(int j=0; j<m; j++) matrix[0][j] = 0;
    }

    if(col0 == 0){                                             // if any element=0 in the first column then the track will be at col0
        for(int i=0; i<n; i++) matrix[i][0] = 0;
    }

}

int main(){
    vector<vector<int>> arr = {{0,1,2,0}, {3,4,5,2}, {1,3,1,5}};

    setZeroes3(arr);

    for(auto it : arr){
        for(auto x : it){
            cout<<x<<" ";
        }
        cout<<endl;
    }

    return 0;
}