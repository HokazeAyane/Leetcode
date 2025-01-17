#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target){
    vector<vector<int>> result;
    sort(nums.begin(),nums.end());

    int n = nums.size();
    for(int i =0; i < n - 3; ++i){
        if(i>0 && nums[i] == nums[i-1]) continue;  //跳过重复元素

        for(int j = i+1; j < n-2; ++j){
            if(j > i+1 && nums[j] == nums[j-1]) continue;  //跳过重复元素

            int left = j+1;
            int right = n-1;
            while(left < right){
                long sum = nums[i] + nums[j] + nums[left] + nums[right];
                if(sum == target){
                    result.push_back({nums[i],nums[j],nums[left],nums[right]});
                    while(left < right && nums[left] == nums[left + 1]) left++;  //跳过重复元素
                    while(left < right && nums[right] == nums[right - 1]) right--; //跳过重复元素
                    left++;
                    right--;
                }else if(sum <target){
                    left++;
                }else{
                    right--;
                }
               

            }
        }

    }
    return result;
}


int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> result = fourSum(nums, target);
    
    for (const auto& quad : result) {
        cout << "[";
        for (int num : quad) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
