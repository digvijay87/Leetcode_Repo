/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 * #DailyChallange
 * #Bitwise
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
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n)
        {
            if(n & 1)
            {
                count++;
            }
            n = n >> 1;
        }
        return count;
    }
};
// @lc code=end

