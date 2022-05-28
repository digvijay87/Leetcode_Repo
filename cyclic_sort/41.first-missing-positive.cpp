/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
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
    int firstMissingPositive(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0; i <arr.size(); i++)
        {
            while(arr[i] > 0 && arr[i] <= n && arr[arr[i] - 1] != arr[i])
            {
                swap(arr[i],arr[arr[i] - 1]);
            }
            
            
        }
        for(int i = 0; i < arr.size(); i++)
        {
                if(arr[i] != i+1)
                    return i+1;
        }
        
     
        return n + 1;
        
    }
};
// @lc code=end

