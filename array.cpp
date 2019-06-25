#include "comm.h"

using namespace std;
//134. Gas Station
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int remain = 0, start = 0, lack = 0;
    for(int i = 0; i < gas.size(); i++){
        remain += gas[i] - cost[i];
        if(remain < 0){
            //if remained power less than 0, one need to restart from i
            //  and make up the lack in future (next loop)
            start = i;
            lack += remain;
            remain = 0; //start with 0 power left
        }
    }

    return remain + lack >= 0 ? start : -1;
}

//1. Two Sum
vector<int> twoSum(vector<int>& nums, int target) {
    auto nums_cp = nums;;
    sort(nums.begin(), nums.end());
    auto beg = nums.begin(), end = nums.end()-1;
    while(beg < end){
        int sum = *beg + *end;
        if(sum == target){
            auto first = find(nums_cp.begin(), nums_cp.end(), *beg);
            auto second = find(first + 1, nums_cp.end(), *end);
            return vector<int>{first - nums_cp.begin(), second - nums_cp.begin()};
        }else if (sum < target) {
            beg++;
        }else{
            end--;
        }
    }

    return vector<int>{-1, -1};
}