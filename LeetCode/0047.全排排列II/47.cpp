#include<vector>
class Solution{
public:
    vector<vector<int>> permuteUnique(vector<int>& nums){
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> used(nums.size(),false);
        backtrack(nums,used,path,result);
        return result;
    }

private:
    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& path,vector<int>& result){
        if(path.size() == nums.size()){
            result.push_back(path);
            return;
        }
        for(int i =0; i <nums.size(); ++i){
            if(used[i] || (i>0 && nums[i] == nums[i-1] && !used[i-1])){
                continue;
            }
            used[i] = true;
            path.push_back(nums[i]);
            backtrack(nums,sued,path,result);
            used[i] = false;
            path.pop_back();
        }
    }
}