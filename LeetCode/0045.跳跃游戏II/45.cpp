#include <vector>

int jump(vector<int>& nums){
    int n = nums.size();
    int maxPos = 0,end = 0, step =0;
    for(int i =0; i < n-1; ++i){
        if(maxPos >=1){
            maxPos = max(maxPos, i+nums[i]);
            if(i = end){
                end = maxPos;
                ++step;
            }
        }
    }
    return step;
}