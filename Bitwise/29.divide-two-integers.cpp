/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 * #DailyChallange #Bitwise
 */

// @lc code=start
/*
Bassically we need something like below;
dividend = (something * divisor) + reminder;
So we will need to find something. 
example dividend = 14 divisior = 3

we will run while dividend >= divisior

15 and 3

3 << 0 3 (3) < 14
3 << 1 6 (6) < 14
3 << 2 12 (12) < 14
3 << 3 24 which is not < 14 so we will stop

something is 2^2 + (14 - 12 new value of dividend to calculate )

3 << 0 3 (3) > 2 so it will not be calculated.
So answer is 2^2 which is 4
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;

        int sign = (dividend > 0 ^ divisor > 0) ? -1 : 1;
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        unsigned int dvd = abs(dividend);
        unsigned int dvs = abs(divisor);
        unsigned int ans =0;

        while(dvd >= dvs)
        {
            short quo = 0;
            while(dvd > (dvs << (quo + 1)))
            {
                quo++;
            }
            ans += 1 << quo;

            dvd -= dvs << quo;
        }
        if(ans == (1<<31) and sign == 1)   
            return INT_MAX;
        return (sign == 1) ? ans : -ans;
       
    }
};
// @lc code=end
/*
15 and 3

3 << 0 3 3) < 15
3 << 1 6 (6) < 15
3 << 2 12 < 15

2^2 * 3 + 3
3 << 3 24 > 15

1100

*/

