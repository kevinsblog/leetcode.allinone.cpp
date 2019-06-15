#include "comm.h"

using namespace std;
//81. Search in Rotated Sorted Array II
/*
[2,5,6,0,0,1,2] 1
*mid = 0 *mid < *beg  second half is ascending
                      else first half is ascending
target > *mid -- second half
              -- first half
*/
// bool search(vector<int>& nums, int target) {
//     int beg = 0, end = nums.size()-1;
//     while(beg <= end){
//         int mid = beg + (end - beg)/2;
//         if(nums[mid] == target || nums[beg] == target || nums[end] == target){
//             return true;
//         } else if (nums[mid] < nums[end]){
//             // break pt at first half and second half is ascend
//             if(nums[mid] < target){
//                 beg = mid + 1;
//             } else {
//                 end = mid - 1;
//             }
//         } else {
//             if(nums[mid] < target){
//                 end = mid - 1;
//             }else{
//                 beg = mid + 1;
//             }
//         }
//     }

//     return false;
// }
bool search(vector<int>& nums, int target){
    if(nums.size() == 0)
        return false;

    auto beg = nums.begin(), end = nums.end() - 1;
    while(beg <= end){
        auto mid = beg + (end - beg)/2;
        if(*mid == target || *beg == target || *end == target){
            return true;
        }

        if(*mid == *end){
            end--;
        }else if(*mid > *end){ //first half is ascending
            if(*beg < target && target < *mid){
                end = mid - 1; //target fulls in first half
            } else {
                beg = mid + 1;
            }
        }else{ //second half is ascending
            if(*mid < target && target < *end){
                beg = mid + 1; //target fulls in second half
            } else {
                end = mid - 1;
            }
        }
    }

    return false;
}