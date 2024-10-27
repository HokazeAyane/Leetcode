//-数组-双指针-排序
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib> 

using namespace std;

int threeSumClosest(vector<int>& nums,int target){
    sort(nums.begin(),nums.end());
    int closestSum = nums[0] + nums[1] + nums[2];

    for(int i =0; i < nums.size() - 2; ++i){
        int left = i +1;
        int right = nums.size() - 1;

        while(left < right){
            int currentSum = nums[i] + nums[left] + nums[right];
            if(abs(currentSum - target) < abs(closestSum - target)){
                closestSum = currentSum;
            }

            if(currentSum < target){
                ++left;
            }else if(currentSum > target){
                --right;
            }else{
                return currentSum;
            }
        }
    }
    
    return closestSum;
}


int main() {
    vector<int> nums1 = {-1, 2, 1, -4};
    int target1 = 1;
    cout << "Output for example 1: " << threeSumClosest(nums1, target1) << endl;

    vector<int> nums2 = {0, 0, 0};
    int target2 = 1;
    cout << "Output for example 2: " << threeSumClosest(nums2, target2) << endl;

    return 0;
}