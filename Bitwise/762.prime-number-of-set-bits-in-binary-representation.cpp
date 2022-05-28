/*
 * @lc app=leetcode id=762 lang=cpp
 *
 * [762] Prime Number of Set Bits in Binary Representation
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
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        set<int> primes = {2,3,5,7,11,13,17,19,23};
        for(int i = left; i <=right; i++)
        {
            int bits = 0;
            int n = i;
            while(n)
            {
                if((n & 1) == 1){
                    bits++;
                }
                n = n >> 1;
            }
            count += primes.count(bits);
        }
        return count;
    }
};
// @lc code=end

