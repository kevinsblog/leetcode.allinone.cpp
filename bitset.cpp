#include "comm.h"

using namespace std;
vector<string> readBinaryWatch(int num){
    vector<string> ans;
    for(unsigned long h = 0; h < 12; h++){
        for(unsigned long m = 0; m < 59; m++){
            bitset<4> hour(h);
            bitset<6> min(m);
            if(hour.count() + min.count() == num){
                ans.push_back(to_string(h) + ":" + (m < 10 ? '0' + to_string(m) : to_string(m)));
            }
        }
    }
    return move(ans);
}