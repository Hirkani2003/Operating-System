#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<vector<int>> allocation = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };
    vector<vector<int>> maximum = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2}, 
        {4, 3, 3} 
    };
    int n = allocation.size();
    int m = allocation[0].size();
    vector<vector<int>> need(n, vector<int>(m));
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }
    vector<int> available = {3, 3, 2};
    vector<int> flag(n, 0);
    vector<int> result;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(flag[j] == 0){
                int r = 1;
                for(int k=0; k<m; ++k){
                    if(need[j][k] <= available[k]) continue;
                    else{ 
                        r = 0;
                        break;
                    }
                }
                if(r){
                    flag[j] = 1;
                    for(int k=0; k<m; ++k){
                        available[k] += allocation[j][k];
                    }
                    result.push_back(j);
                }
            }
        }
    }
    int sum = 0;
    for(int i=0; i<n; ++i){
        sum += flag[i];
    }
    if(sum == n){
        cout<<"Safe Sequence is : ";
        for(int i=0; i<n; ++i){
            cout <<"P"<< result[i]+1 << " ";
        }
        cout<<endl;
    }
    else{
        cout<<"Deadlock Detected"<<endl;
    }
    return 0;
}