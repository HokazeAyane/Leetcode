#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    void nextPermutation(vector<int>& nums){
        int n = nums.size();
        int i = n-2;
        //1.找到第一个下降的元素
        while( i >=0 && nums[i] >= nums[i+1]){
            i--;
        }
        //2.找到比num[i]大的最小元素
        if(i>=0){
            int j = n -1;
            while(nums[j] <= nums[i]){
                j--;
            }
            swap(nums[i],nums[j]);
        }
        
        reverse(nums.begin()+i+1,nums.end());
    }
};