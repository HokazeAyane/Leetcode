#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums){
    vector<vector<int>> result; //初始化了一个二维向量，用于存储所有满足条件的三元组。
    if(nums.size() < 3) return result;

    sort(nums.begin(),nums.end());

    for(int i =0; i < nums.size() - 2; ++i){   //如果 i 到达倒数第二个位置，就不可能再有两个元素供 left 和 right 指针使用了。

        if(i>0 && nums[i] == nums[i-1]) continue;  //跳过重复元素。如果当前元素 nums[i] 和前一个元素相同，就跳过这个循环的迭代。这样可以避免生成重复的三元组。

        int left = i+1;
        int right = nums.size() -1;

        while(left < right){
            int sum = nums[i] + nums[left] + nums[right];
            if(sum == 0){
                result.push_back({nums[i],nums[left],nums[right]});
                while(left < right && nums[left] == nums[left +1]) ++left;
                while(left < right && nums[right] == nums[right-1]) --right;

                ++left;
                --right;
            }else if (sum < 0){
                ++left;
            }else{
                --right;
            }
        }
    }
    return result;
}

int main() {
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    vector<int> nums2 = {0, 1, 1};
    vector<int> nums3 = {0, 0, 0};

    vector<vector<int>> result1 = threeSum(nums1);
    vector<vector<int>> result2 = threeSum(nums2);
    vector<vector<int>> result3 = threeSum(nums3);


    for (const auto& triplet : result1) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "] ";
    }
    cout << endl;

    for (const auto& triplet : result2) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "] ";
    }
    cout << endl;

    for (const auto& triplet : result3) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "] ";
    }
    cout << endl;

    return 0;
}
