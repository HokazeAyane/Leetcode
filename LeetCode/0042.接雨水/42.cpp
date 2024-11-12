#include <vector>
#include <algorithm>

using namespace std;

int trap(vector<int>& height){
    int left = 0, right = height.size() - 1;
    int maxLeft = 0, maxRight = 0;
    int volume = 0;

    while(left < right){
        if(height[left] <= height[right]){
            maxLeft = max(maxLeft,height[left])
            volume += maxLeft - height[left];
            ++left;
        }else{
            maxRight = max(maxRight,height[right]);
            volume += maxRight - height[right];
            --right;
        }
    }

    return volume;
}