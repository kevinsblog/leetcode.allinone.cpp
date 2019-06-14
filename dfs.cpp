#include "comm.h"

using namespace std;
//77. Combinations
void combineDFS(int start, const int k, const int n, vector<int> &path, 
                vector<vector<int>> &ans){
    if(path.size() == k){
        ans.push_back(path);
        return;
    }

    for(int i = start; i <= n; i++){
        path.push_back(i);
        combineDFS(i + 1, k, n, path, ans);
        path.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> path;
    combineDFS(1, k, n, path, ans);
    return move(ans);
}

// //401. Binary Watch
// const int N = 10;
// void readBinaryWatchDFS(int n, int start, bitset<N> &bits, vector<bitset<N>> &ans){
//     if(start == N || n == 0){
//         if(n == 0){
//             ans.push_back(bits);
//         }
//         return;
//     }

//     for(int i = start; i < N; i++){
//         bits[i] = true;
//         readBinaryWatchDFS(n-1, i+1, bits, ans);
//         bits[i] = false;
//     }
// }

// vector<string> readBinaryWatch(int num) {
//     string init(N, '0');
//     bitset<N> bits(init);
//     vector<bitset<N>> bits_ans;
//     vector<string> ans;
//     readBinaryWatchDFS(num, 0, bits, bits_ans);
//     for(auto & bits : bits_ans){
//         string s_bits = bits.to_string();
//         bitset<4> hour_bit(s_bits.substr(0, 4)), 
//                   min_bit(s_bits.substr(4, 6));
//         unsigned long hour = hour_bit.to_ulong(),
//                  min = min_bit.to_ulong();
//         string s_hour = hour < 10 ? '0' + to_string(hour) : to_string(hour),
//                s_min = min < 10 ? '0' + to_string(min) : to_string(min);
//         ans.push_back(s_hour + ':' + s_min);
//     }
//     return move(ans);
// }

//79. Word Search
bool existDFS(const vector<vector<char>> &board, const string &word, vector<pair<int, int>> &path){
    if(path.size() == word.size()){
        return true;
    }

    int offset[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    for(int i = 0; i < 4; i++){
        int x = path.back().first + offset[i][0],
            y = path.back().second + offset[i][1];
        if(x < 0 || x >= board.size() || y < 0 || y >= board.at(0).size()){
            continue;
        }
        if(board[x][y] != word[path.size()]){
            continue;   
        }
        auto pos = pair<int, int>(x, y);
        if(find(path.begin(), path.end(), pos) != path.end()){
            continue;
        }
        path.push_back(pos);
        if(existDFS(board, word, path)){
            return true;
        }
        path.pop_back();
    }
    
    return false;
}
bool exist(vector<vector<char>> &board, string word){
    unordered_map<char, vector<pair<int, int>>> start_at;
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            start_at[board[i][j]].push_back(pair<int, int>(i, j));
        }
    }

    for(auto & start : start_at[*word.begin()]){
        vector<pair<int, int>> path{start};
        if(existDFS(board, word, path)){
            return true;
        }
    }

    return false;
}

//212. Word Search II
vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    unordered_map<char, vector<pair<int, int>>> start_at;
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            start_at[board[i][j]].push_back(pair<int, int>(i, j));
        }
    }

    vector<string> ans;
    for(auto & word : words){
        for(auto & start : start_at[*word.begin()]){
            vector<pair<int, int>> path{start};
            if(existDFS(board, word, path)){
                if(find(ans.begin(), ans.end(), word) == ans.end())
                    ans.push_back(word);
            }
        }        
    }

    return move(ans);
}