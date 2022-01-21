/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 

Example 1:

Input: nums = [1,2,3,1]
Output: true
Example 2:

Input: nums = [1,2,3,4]
Output: false
Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
*/

/* This is question can be done in 3 ways:
1. TC O(N^2) SC O(1)
2. TC O(logn) SC O(1)
3. TC O(N) SC(N)
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hash;
        for(int key : nums)
        {
            if(hash.count(key) > 0)
            {
                return true;
            }
            hash.insert(key);
        }
        return false;
    }
};
