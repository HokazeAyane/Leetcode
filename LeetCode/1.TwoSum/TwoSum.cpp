#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int>& nums,int target){
        unordered_map<int,int> numMap;
        for(int i = 0;i < nums.size(); i++){
            int complement = target - nums[i];
            if(numMap.find(complement) != numMap.end()){
                return {numMap[complement],i}; //返回一对索引 {numMap[complement], i}，代表两个数的位置，这两个数的和等于目标值。
            }
        
        numMap[nums[i]] = i; //将数组 nums 中的当前元素 nums[i] 和它的索引 i 存储在哈希表 numMap 中。
    }
    return {};
    }

};

int main(){
    Solution solution;
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int>  result = solution.twoSum(nums,target);

    for(int index :result){
        cout <<index<<" ";
    }
    cout <<endl;
    return 0;
}

