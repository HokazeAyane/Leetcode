#include <iostream>
#include <vector>
#include <algorithm>


class Solution{
public:
    int maxArea(std::vector<int>& height){
        int left = 0;
        int right = height.size()-1;
        int maxWater = 0;

        while(left < right){
            int width = right -left;
            int currentHeight = std::min(height[left],height[right]);
            int currentWater = width * currentHeight;

            maxWater = std::max(maxWater,currentWater);

            if(height[left] < height[right]){
                ++left;
            }else{
                --right;
            }
        }
        return maxWater;
    }
};

int main() {

    std::vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    Solution solution;
    int maxWater = solution.maxArea(height);

    std::cout << "The maximum water that can be contained is: " << maxWater << std::endl;
    return 0;
}