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