#include<bits/stdc++.h>
using namespace std;

// M coloring Problem --> Return true if we can color all the notes with max M colors making sure that no two adjacent nodes have same color.

map<int, int> mp;

bool isSafe(vector<vector<int> >& edges, int node, int clr){
    for(const auto &edge : edges){
        if(edge[0] == node){
            auto ptr = mp.find(edge[1]);
            if(ptr != mp.end() && ptr->second == clr){
                return false;
            }
        }
        else if(edge[1] == node){
            auto ptr = mp.find(edge[0]);
            if(ptr != mp.end() && ptr->second == clr){
                return false;
            }
        }
    }

    return true;
}

bool helper(vector<vector<int> >& edges, int m, int n, int currNode){
    if(currNode == n){
        return true;
    }

    for(int i=0; i<m; i++){                 // trying all the colors
        if(isSafe(edges, currNode, i)){
            mp[currNode] = i;
            if(helper(edges, m, n, currNode+1)){
                return true;
            }
        }
        else{
            continue;
        }

        mp.erase(currNode);
    }

    return false;
}

bool graphColoring(vector<vector<int> >& edges, int m, int n) {
    return helper(edges, m, n, 0);
}

int main(){
    vector<vector<int>> edges = {{0,1}, {1,2}, {2,3}, {3,0}, {0,2}};

    cout<<graphColoring(edges, 2, 4);

    return 0;
}