/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
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
// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        return !(n & n-1);
    }
};
// @lc code=end

