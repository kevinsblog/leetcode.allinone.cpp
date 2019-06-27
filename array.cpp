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
/*vector<int> twoSum(vector<int>& nums, int target) {
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
}*/

int sockMerchant(int n, vector<int> ar) {
    unordered_map<int, int> freq;
    for(auto & a : ar){
        freq[a]++;
    }

    int sum = 0;
    for(auto & f : freq){
        sum += f.second/2;
    }
    return sum;
}

int countingValleys(int n, string s) {
    vector<int> altitude(s.size()+1, 0);
    for(int i = 0; i < s.size(); i++){
        altitude[i+1] = altitude[i] + (s[i] == 'U' ? 1 : -1);
    }
    int ans = 0;
    for(int i = 0; i < altitude.size(); i++){
        //introudce new valley is altitude is below sea level
        if(i>0 && altitude[i-1] >= 0 && altitude[i] < 0){
            ans++;
        }
    }

    //if the hiker can not reach above sea, the last valley is not valid
    if(altitude.back() < 0){
        ans--;
    }

    return ans;
}

long repeatedString(string s, long n) {
    vector<int> freq; //count the occurrance of first letter at certain index
    int occ = 0;
    for(auto & c : s){
        if(c == *s.begin()){
            freq.push_back(++occ); //occurrance plus one
        }else{
            freq.push_back(occ);
        }
    }

    int times = n / s.size(),
        remain = n % s.size();
    //mind the priority of ? :, the closure must be there, otherwise,
    //  compiler would interpert like (a + b) ? xx ? xxx;
    return times*occ + (remain > 0 ? freq[remain] : 0 );
}