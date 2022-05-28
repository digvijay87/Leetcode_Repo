/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */
/*
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
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int, int> right;
        
        stack<int> st;
        
        for(int i = n-1; i >= 0; i--)
        {
            int num = nums2[i];
            while(!st.empty() and num >= st.top())
            {
                st.pop();
            }
            if(!st.empty()) right[num] = st.top();
            st.push(num);
        }
        vector<int> ans;
        
        for(int i = 0; i < nums1.size(); i++)
        {
            int num = nums1[i];
            if(right.count(num) > 0)
            {
                ans.push_back(right[num]);
            }else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
// @lc code=end

