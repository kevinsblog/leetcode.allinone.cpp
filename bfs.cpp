#include "comm.h"

using namespace std;
//127. Word Ladder
// void ladderLengthDFS(const string &endWord, string &curWord, int idx, unordered_map<string, bool> &visited, 
//                 vector<string> &path, vector<int> &ans){
//     //take the reference of visited
//     auto isValidWord = [&](const string &w){
//         if(visited.count(w) > 0 && !visited[w])
//             return true;
//         else
//             return false;
//     };
    
//     if(idx == curWord.size()){
//         return;
//     }

//     const string word = curWord;
//     //bfs
//     for(char c = 'a'; c <= 'z'; c++){
//         curWord[idx] = c;
//         if(curWord == endWord){
//             ans.push_back(path.size());
//             break;
//         }

//         if(word == curWord || !isValidWord(word))
//             continue;

//         path.push_back(curWord);
//         visited[curWord] = true;
//         ladderLengthDFS(endWord, curWord, idx + 1, visited, path, ans);
//         visited[curWord] = false;
//         path.pop_back();
//     }
//     curWord = word;
// }

// int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//     //build dict
//     unordered_map<string, bool> dict;
//     for(auto const & word : wordList){
//         dict[word] = false;
//     }

//     //bfs, change word to another
//     vector<string> path;
//     vector<int> ans;
//     ladderLengthDFS(endWord, beginWord, 0, dict, path, ans);
//     if(ans.size() == 0)
//         return 0;
//     else
//         return *min_element(ans.begin(), ans.end());
// }

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    auto isSuccessor = [](const string &first, const string &second){
        if(first.size() != second.size()) return false;
        int diff = 0;
        for(int i = 0; i < first.size(); i++){
            if(first[i] != second[i])
                diff++;
        }
        return diff == 1;
    };

    queue<string> Q;
    Q.push(beginWord);
    int steps = 0;
    while(!Q.empty()){
        int num = Q.size();
        while(num-- > 0){
            string word = Q.front();
            Q.pop();
            if(word == endWord){
                return steps;
            }
            for(auto it = dict.begin(); it != dict.end();){
                if(isSuccessor(word, *it)){
                    Q.push(*it);
                    it = dict.erase(it);
                }else{
                    ++it;
                }
            }
        }
        steps++;
    }

    return 0;
}

void ladderLength(){
    vector<string> dict = {"hot","dot","dog","lot","log","cog"};
    cout << ladderLength("hit", "cog", dict) << endl;
}

void solve(vector<vector<char>>& board) {
    int m = board.size();
    if(m == 0){
        return;
    }
    int n = board[0].size();
    queue<pair<int, int>> Q;
    //save the boundary element
    for(int i = 0; i < m; i++){
        if(board[i][0] == 'O'){
            board[i][0] = '*';
            Q.push(pair<int, int>(i, 0));
        }

        if(board[i][n-1] == 'O'){
            board[i][n-1] = '*';
            Q.push(pair<int, int>(i, n-1));
        }        
    }

    for(int j = 1; j < n; j++){
        if(board[0][j] == 'O'){
            board[0][j] = '*';
            Q.push(pair<int, int>(0, j));
        }

        if(board[m-1][j] == 'O'){
            board[m-1][j] = '*';
            Q.push(pair<int, int>(m-1, j));
        }
    }

    //search the four direction
    pair<int, int> offset[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while(!Q.empty()){
        int num = Q.size();
        while(num-- > 0){
            pair<int, int> pos = Q.front();
            Q.pop();
            for(int i = 0; i < 4; i++){
                int x = pos.first + offset[i].first,
                    y = pos.second + offset[i].second;
                if(x < 0 || x >= m || y < 0 || y >= n)
                    continue;
                if(board[x][y] == 'O'){
                    board[x][y] = '*';
                    Q.push(pair<int, int>(x, y));
                }
            }
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == '*'){
                board[i][j] = 'X';
            }
        }
    }

    return;
}