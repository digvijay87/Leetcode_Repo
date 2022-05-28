/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 * #Monotonicstack #DailyProgramming
 * #Monotonic
907. Sum of Subarray Minimums
496. Next Greater Element I
503. Next Greater Element II
456. 132 Pattern
739. Daily Temperatures
901. Online Stock Span
84. Largest Rectangle in Histogram
85. Maximal Rectangle
42. Trapping Rain Water
316. Remove Duplicate Letters
402. Remove K Digits
321. Create Maximum Number
1130. Minimum Cost Tree From Leaf Values
768. Max Chunks To Make Sorted II
31. Next Permutation 
556. Next Greater Element III

Monotonic Queue
239. Sliding Window Maximum
862. Shortest Subarray with Sum at Least K 
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> st;
        int n = nums.size();
        
        vector<int> right(n, -1);
        
        for(int i = 0; i < n * 2; i++)
        {
            while(!st.empty() and nums[i % n] > nums[st.back()] )
            {
                right[st.back()] = nums[i % n];
                st.pop_back();
            }
            st.push_back(i % n);
        }
        return right;
    }
};
// @lc code=end

