/*
 * @lc app=leetcode id=907 lang=cpp
 *
 * [907] Sum of Subarray Minimums
 * 
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
 */

// @lc code=start
/*
2 concepts :: 1. Monotonic stack 2nd Contributor
Monotonic stack :: the elements in the an monotonic ascending stack keeps an ascending/descending order.

The typical paradigm for monotonic ascending stack:

for(int i = 0; i < A.length; i++){
  while(!stack.isEmpty() && stack.peek() > A[i]){
    stack.pop();
  }
  stack.push(A[i]);
}
What can monotonic ascending stack do?
(1) find the previous less element of each element in a vector with O(n) time:
What is the previous less element of an element?
For example:
[3, 7, 8, 4]
The previous less element of 7 is 3.
The previous less element of 8 is 7.
The previous less element of 4 is 3.
There is no previous less element for 3.

Summary: When do we need MonotonicStack? When we need to find its left and right boundaries. **

 * How can the monotonic ascending stack be applied to this problem?
For example:
Consider the element 3 in the following vector:

                [2, 9, 7, 8, 3, 4, 6, 1]
			     |                    |
	             the previous less       the next less
	                element of 3          element of 3

After finding both NLE and PLE of 3, we can determine the
distance between 3 and 2(previous less) , and the distance between 3 and 1(next less).
In this example, the distance is 4 and 3 respectively.

How many subarrays with 3 being its minimum value?
The answer is 4*3.

9 7 8 3
9 7 8 3 4
9 7 8 3 4 6
7 8 3
7 8 3 4
7 8 3 4 6
8 3
8 3 4
8 3 4 6
3
3 4
3 4 6
How much the element 3 contributes to the final answer?
It is 3*(4*3).
What is the final answer?
Denote by left[i] the distance between element A[i] and its PLE.
Denote by right[i] the distance between element A[i] and its NLE.

The final answer is,
sum(A[i]*left[i]*right[i] )
The last thing that needs to be mentioned for handling duplicate elements:
Method: Set strict less and non-strict less(less than or equal to) for finding NLE and PLE respectively. The order doesn't matter
*/

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int MOD = (int)1000000007;
        int n = arr.size();
        
        vector<int> left(n, -1);
        vector<int> right(n, n);
        
        vector<int> st;
        
        int res = 0;
        
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() and arr[i] < arr[st.back()])
            {
                right[st.back()] = i;
                st.pop_back();
            }
            st.push_back(i);
        }
        st.clear();
        
        for(int i = n-1; i >= 0; i--)
        {
            while(!st.empty() and arr[i] <= arr[st.back()])
            {
                left[st.back()] = i;
                st.pop_back();
            }
            st.push_back(i);
        }
        
        for(int i = 0; i < n; i++)
        {
            long long contributor = ((i - left[i])*(right[i] - i))%MOD;
            
            contributor = (contributor*arr[i])%MOD;
            
            res = (res + contributor)%MOD;
        }
        
        return res;
    }
};
// @lc code=end

