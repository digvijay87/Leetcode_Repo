/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 * #CyclicSort
 */

// @lc code=start
/* Cyclic sort:
keep moving the the element untill it reaches to its correct location

Questions to practice on cyclic sort.
    
448. Find All Numbers Disappeared in an Array
41. First Missing Positive
442. Find All Duplicates in an Array
*/


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ret = 0;
        int n = nums.size();
        int i = 0;
        while(i < n)
        {
           if (nums[i] < n && nums[i] != i) {
                swap(nums[i],nums[nums[i]]);
            }else{
                i++;
            }
        } 
    
        for(int i = 0; i < n; i++)
        {
            if(i != nums[i])
            {
                return i;
            }
        }
        return n;
    }
};
// @lc code=end
