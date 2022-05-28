/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */
/* Bit wise or Bit manipulation 

Similar Question 
231. Power of Two
191. Number of 1 Bits
338. Counting Bits
693. Binary Number with Alternating Bits 
762. Prime Number of Set Bits in Binary Representation
401. Binary Watch
*/
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            res[i] = res[i >> 1] + (i & 1);
        }
        return res;
    }
};
// @lc code=start

// @lc code=end

