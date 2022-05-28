/*
 * @lc app=leetcode id=401 lang=cpp
 *
 * [401] Binary Watch
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
class Solution 
{
    vector<int> hour = {1, 2, 4, 8}, minute = {1, 2, 4, 8, 16, 32};
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        helper(res, {0,0}, num, 0);
        return res;
    }
    
    void helper(vector<string>& res, pair<int, int> time, int num, int start) {
        if (num == 0) {
            res.push_back(to_string(time.first) +  (time.second < 10 ?  ":0" : ":") + to_string(time.second));
            return;
        }
        for (int i = start; i < hour.size() + minute.size(); i ++)
            if (i < hour.size()) {    
                time.first += hour[i];
                if (time.first < 12)     helper(res, time, num - 1, i + 1);     // Hours can be 11:59 max.
                time.first -= hour[i];
            } else {     
                time.second += minute[i - hour.size()];
                if (time.second < 60)    helper(res, time, num - 1, i + 1);     // minuts can be 59 max.
                time.second -= minute[i - hour.size()];
            }
    }
};
// @lc code=end

