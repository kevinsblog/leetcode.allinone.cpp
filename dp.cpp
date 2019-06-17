#include "comm.h"

using namespace std;

//64. Minimum Path Sum
int minPathSum(vector<vector<int>>& grid) {
    int row = grid.size();
    if(row <= 0)
        return 0;
    int col = grid[0].size();

    vector<vector<int>> costs(row, vector<int>(col, 0));
    costs[0][0] = grid[0][0];
    for(int i = 1; i < row; i++){
        costs[i][0] = grid[i][0] + costs[i-1][0];
    }

    for(int j = 1; j < col; j++){
        costs[0][j] = grid[0][j] + costs[0][j-1];
    }

    for(int i = 1; i < row; i++){
        for(int j = 1; j < col; j++){
            costs[i][j] = grid[i][j] + min(costs[i-1][j], costs[i][j-1]);
        }
    }

    return costs[row-1][col-1];
}

//120. Triangle
// int minimumTotal(vector<vector<int>>& triangle) {
//     vector<vector<int>> minPath = triangle;
//     int n = triangle.size();

//     for(int i = 1; i < n; i++){ //the ith layer
//         for(int j = 0; j <= i; j++){ //all node in the ith layer
//             int first = j == 0 ? INT_MAX : minPath[i-1][j],
//                 second = j == i ? INT_MAX : minPath[i-1][j-1];
//             minPath[i][j] = min(first, second) + triangle[i][j];
//         }
//     }

//     return *max_element(minPath[n-1].begin(), minPath[n-1].end());
// }

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    int m = triangle[n-1].size();
    vector<int> dp = triangle[n-1];
    for(int i = n - 2; i >= 0; i--){
        for(int j = 0; j < m; j++){
            dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
        }
    }
    return dp[0];
}