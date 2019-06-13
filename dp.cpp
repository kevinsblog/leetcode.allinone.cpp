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