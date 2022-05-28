/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 * #cyclicsort
 */
/* Cyclic sort:
keep moving the the element untill it reaches to its correct location

Questions to practice on cyclic sort.
    
448. Find All Numbers Disappeared in an Array
41. First Missing Positive
442. Find All Duplicates in an Array
268. Missing Number
*/
// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len; 
        len = nums.size();
        vector<int> res{};
        /*[4,3,2,7,8,2,3,1]
        i=0    : [4,3,2,-7,8,2,3,1] 
        i=1    : [4,3,-2,-7,8,2,3,1]
        i=2    : [4,-3,-2,-7,8,2,3,1]
        i=3    : [4,-3,-2,-7,8,2,-3,1]
        i=4    : [4,-3,-2,-7,8,2,-3,-1]
        i=5    : [4,-3,-2,-7,8,2,-3,-1]
        i=6    : [4,-3,-2,-7,8,2,-3,-1]
        i=7    : [-4,-3,-2,-7,8,2,-3,-1]
        */
        for(int i = 0; i < len; i++)
        {
            if(nums[i] >  0)
            {
                if(nums[nums[i] - 1] < 0){
                    continue;
                }
                else
                {
                nums[nums[i] - 1] = nums[nums[i] - 1] * -1;;
                }
            }
            else{
                if(nums[abs(nums[i]) - 1] < 0){
                    continue;
                }
                else
                {
                nums[abs(nums[i]) - 1] = nums[abs(nums[i]) - 1] * -1;
                }
            }
        }
        
        for(int i = 0; i < len; i++)
        {
            if(nums[i] < 0)
            {
                continue;
            }
            else{
                res.push_back(i+1);
            }
        }
        return res;
    }
};
// @lc code=end

