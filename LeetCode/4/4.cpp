// O(log(m+n)) 利用二分查找来缩小搜索空间。通过在较短的数组中进行二分查找，找到一个切分点，使得满足中位数的条件。

#include <iostream>
#include <vector>
#include <climits> // For INT_MAX and INT_MIN

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    if (nums1.size() > nums2.size()) {
        return findMedianSortedArrays(nums2, nums1);
    }

    int x = nums1.size();
    int y = nums2.size();
    int low = 0, high = x;

    while (low <= high) {
        int partitionX = (low + high) / 2;
        int partitionY = (x + y + 1) / 2 - partitionX;

        
        int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];

        int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];

        
        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            
            if ((x + y) % 2 == 0) {
                return (double)(max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2;
            } else {
                return (double)max(maxLeftX, maxLeftY);
            }
        } else if (maxLeftX > minRightY) {
            
            high = partitionX - 1;
        } else {
            
            low = partitionX + 1;
        }
    }

    throw invalid_argument("Input arrays are not sorted.");
}

int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << "Median: " << findMedianSortedArrays(nums1, nums2) << endl;

    vector<int> nums3 = {1, 3,8};
    vector<int> nums4 = {7,9,10,11};
    cout << "Median: " << findMedianSortedArrays(nums3, nums4) << endl;

    return 0;
}



// O(m+n) 使用两个指针逐一比较两个数组的元素，并将较小的元素依次放入新数组中。
// #include <iostream>
// #include <vector>

//     using namespace std;

// double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
// {

//     vector<int> merged;
//     int i = 0, j = 0;

//     while (i < nums1.size() && j < nums2.size())
//     {
//         if (nums1[i] < nums2[j])
//         {
//             merged.push_back(nums1[i++]);
//         }
//         else
//         {
//             merged.push_back(nums2[j++]);
//         }
//     }

//     while (i < nums1.size())
//     {
//         merged.push_back(nums1[i++]);
//     }

//     while (j < nums2.size())
//     {
//         merged.push_back(nums2[j++]);
//     }

//     int n = merged.size();
//     if (n % 2 == 0)
//     {
//         return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
//     }
//     else
//     {
//         return merged[n / 2];
//     }
// }

// int main()
// {
//     vector<int> nums1 = {1, 3};
//     vector<int> nums2 = {2};
//     cout << "Median: " << findMedianSortedArrays(nums1, nums2) << endl;

//     vector<int> nums3 = {1, 2};
//     vector<int> nums4 = {3, 4};
//     cout << "Median: " << findMedianSortedArrays(nums3, nums4) << endl;

//     return 0;
// }
