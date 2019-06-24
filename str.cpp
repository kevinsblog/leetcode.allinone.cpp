#include "comm.h"

using namespace std;
//131. Palindrome Partitioning
void partitionDFS(const string &s, int start, vector<string> &path,
                    vector<vector<string>> &ans){
    auto isPalindrome = [](const string &word, int start, int end){
        while(start < end){
            if(word[start] != word[end])
                return false;
            start++;
            end--;
        }
        return true;
    };
    
    
    if(start == s.size()){
        ans.push_back(path);
        return;
    }

    for(int i = start; i < s.size(); i++){
        if(!isPalindrome(s, start, i))
            continue;

        path.push_back(s.substr(start, i - start + 1));
        partitionDFS(s, i + 1, path, ans);
        path.pop_back();
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> path;
    partitionDFS(s, 0, path, ans);
    return move(ans);
}