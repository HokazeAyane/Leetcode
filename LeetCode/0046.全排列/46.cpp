#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> permute(vector<int>& nums){
        vector<vector<int>> result;
        permuteDFS(nums,0,result);
        return result;
    }

private:
    permuteDFS(vector<int>& nums, int start,vector<vector<int>>& result){
        if(start >= nums.size()){
            result.push_back(nums);
            return;
        }
        for(int i = start; i < nums.size() i++){
            swap(nms[start],nums[i]);
            permuteDFS(nums,start +1,result);
            swap(nums[start],nums[i]);
        }
    }
}

