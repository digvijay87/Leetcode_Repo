/*
 * @lc app=leetcode id=693 lang=cpp
 *
 * [693] Binary Number with Alternating Bits
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
    bool hasAlternatingBits(int n) {
        int prev = (n & 1);
        while((n & 1) == prev)
        {
            prev = 1 - prev;
            n = n >> 1;
        }
        return n == 0;
    }
};
// @lc code=end

