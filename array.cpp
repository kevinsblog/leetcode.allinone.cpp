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

void * memcpy_(void *dst, void *src, size_t cnt){
    assert(dst != nullptr && src != nullptr);
    unsigned char *pdst = (unsigned char *)dst;
    const unsigned char *psrc = (const unsigned char *)src;

    //make sure no overlap between two memory region
    assert(!(psrc <= pdst && pdst < psrc + cnt) && 
            !(pdst <= psrc && psrc < pdst + cnt));

    while(cnt--){
        *pdst++ = *psrc++;
    }

    return dst;
}

void memcpyTest(){
    char src[256] = "hello my friend", dst[256];
    cout << (char *)memcpy_(dst, src, strlen(src)+1)<<endl;
}

void *memmove(void *dst, void *src, size_t cnt){
    void *ret = dst;
    unsigned char *pdst = (unsigned char *)dst;
    const unsigned char *psrc = (const unsigned char *)src;

    if(pdst < psrc || pdst >= (psrc + cnt)){ //if overlap not exists
        //copy from start to end
        while(cnt--){
            *pdst++ = *psrc++;
        }
    }else{ //if overlap exists
        pdst += cnt - 1;
        psrc += cnt - 1;
        //copy from end to start
        while(cnt--){
            *pdst-- = *psrc--;
        }
    }

    return ret;
}

void memmoveTest(){
    char buf[256] = "hello my friend";
    char *dst = (char *)memmove(buf + 10, buf, strlen(buf)+1);
    printf("%p->%p: %s\n", buf, dst, dst);
}

void calcAllPermutation(string &s, int from, int to, vector<string> &ans){
    if(to <= 1){ //invalid pos
        return ;
    }else if(from == to){ //valid string found
        ans.push_back(s.substr(0, to + 1));
    }else{
        //permutation for the rest string
        for(int j = from; j <= to; j++){
            swap(s[j], s[from]);
            calcAllPermutation(s, from + 1, to, ans);
            swap(s[j], s[from]);
        }
    }
}

void calcAllPermutation2(string &s, vector<string> &ans){
    do{
        ans.push_back(s);
    }while(next_permutation(s.begin(), s.end()));
    return;
}

bool calcAllPermutation3Helper(string &s, int num){
    int i = 0;
    //find the pos i of last ascending element
    for(i = num - 2; i >= 0 && s[i] >= s[i+1]; i--){}
    if(i < 0){
        return false;
    }

    int k = 0;
    //find the last pos k greater than s[i]
    for(k = num - 1; k > i && s[k] <= s[i]; k--){}
    swap(s[i], s[k]);
    reverse(s.begin() + i + 1, s.begin() + num);
    return true;
}

void calcAllPermutation3(string &s, vector<string> &ans){
    do{
        ans.push_back(s);
    }while(calcAllPermutation3Helper(s, s.size()));
}

void calcAllPermutationTest(){
    string s = "abc";
    vector<string> ans;
    calcAllPermutation(s, 0, s.size()-1, ans);
    print(ans);

    ans.clear();
    calcAllPermutation2(s, ans);
    print(ans);

    s = "abc";
    ans.clear();
    calcAllPermutation3(s, ans);
    print(ans);
}

bool calcPremute(vector<int>& nums, int n){
    int i = 0;
    for(i = n - 2; i >= 0 && nums[i] >= nums[i+1]; i--){}
    if(i < 0){
        return false;
    }

    int k = 0;
    for(k = n - 1; k > i && nums[k] <= nums[i]; k--){}
    swap(nums[i], nums[k]);
    reverse(nums.begin() + i + 1, nums.begin() + n);
    return true;
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    do{
        ans.push_back(nums);
    }while(calcPremute(nums, nums.size()));
    return move(ans);
}