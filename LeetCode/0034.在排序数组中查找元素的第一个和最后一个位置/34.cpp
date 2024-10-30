#include <vector>

using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()){
            return{-1,-1};
        }

        int leftBoundary = findBound(nums,target,true);
        if(leftBoundary == -1){
            return{-1,-1};
        }

        int rightBoundary = findBound(nums,target,false);
        return{leftBoundary,rightBoundary};
        
    }

    int findBound(const vector<int>& nums,int target, bool isLeft){
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            int mid = left + (right - left)/2;

            if(nums[mid] < target){
                left = mid + 1;
            }else if(nums[mid] > target){
                right = mid - 1;
            }else{

                if(isLeft){
                    if(mid ==0 || nums[mid - 1] != target){
                        return mid;
                    }
                    right = mid -1;
                }else{
                    if (mid == nums.size() - 1 || nums[mid + 1] != target) {
                        return mid;
                    }
                    left = mid + 1;
                }
            }
        }
        return - 1;
    }
    
};