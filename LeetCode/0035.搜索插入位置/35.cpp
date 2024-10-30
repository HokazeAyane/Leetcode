#include <vector>
#include <algorithm>


using namespace std;
class Solution{
public:
    int searchInsert(vector<int>& nums,int target){

        int left = 0;
        int right = nums.size(); //插入尾部


        while(left < right){
            int mid = left + (right - left) / 2; //避免溢出
            if(nums[mid] == target){
                return mid;
            }else if (nums[mid] <target){
                left = mid +1;
            }else{
                right = mid;  //正确返回插入位置
            }

        }

        return left;

    }
};