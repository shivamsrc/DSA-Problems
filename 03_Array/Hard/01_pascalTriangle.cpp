#include<bits/stdc++.h>
using namespace std;

// Pascal's Triangle

// Type-1: Given the row and column, tell the element that place in the traingle----------
int element(int row, int col){
    int n = row-1;
    int r = col-1;
    int ans = 1;

    for(int i=0; i<r; i++){                    // using nCr shortcut
        ans = ans * (n-i);
        ans = ans / (i+1);
    }

    return ans;
}

// Type-2: Print the given Nth row --------------------------------------------------------

// Brute
void printRow(int n){
    for(int i=1; i<=n; i++){
        cout<<element(n, i)<<" ";
    }
}

// Optimal
void printRow2(int n){
    int ans = 1;
    cout<<ans<<" ";
    for(int i=1; i<n; i++){
        ans = ans * (n-i);
        ans = ans / i;
        cout<<ans<<" ";
    }
}

// Type-3: Generate the whole pascal's triangle ------------------------------------------

// Brute
vector<vector<int>> generate(int numRows) {
    int n = numRows;
    vector<vector<int>> ans;
    
    for(int i=1; i<=n; i++){
        vector<int> temp;

        for(int j=1; j<=i; j++){
            temp.push_back(element(i, j));
        }

        ans.push_back(temp);
    }

    return ans;
}

// Optimal

vector<int> generateRow(int row){                            // same as type-2 (optimal)
    vector<int> rowList;
    int ans = 1;
    rowList.push_back(ans);

    for(int i=1; i<row; i++){
        ans = ans * (row-i);
        ans = ans / i;
        rowList.push_back(ans);
    }

    return rowList;
}

vector<vector<int>> generateFull(int rowNum){
    vector<vector<int>> ans;

    for(int i=1; i<=rowNum; i++){
        ans.push_back(generateRow(i));
    }

    return ans;
}

int main(){
    vector<vector<int>> result = generateFull(6);

    for(auto it : result){
        for(auto x : it){
            cout<<x<<" ";
        }
        cout<<endl;
    }

    return 0;
}