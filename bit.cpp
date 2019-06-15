#include "comm.h"

using namespace std;
//89
vector<int> grayCode(int n) {
    vector<int> ans = {0};
    for(int i = 0; i < n; i++){
        int len = ans.size();
        for(int j = len - 1; j >= 0; j--){
            ans.push_back(ans[j] | 1 << i);
        }
    }
    return move(ans);
}