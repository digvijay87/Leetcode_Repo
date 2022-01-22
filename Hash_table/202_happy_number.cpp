/*
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

 

Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
Example 2:

Input: n = 2
Output: false
 

Constraints:

1 <= n <= 231 - 1
*/
/*
Two Different approach :
Approach 1: Using Set
1.Create a set to just keep track whether we have visited this square of number if yes cycle detected and return false.
2. If number is 1 return 1.
*/

class Solution {
public:
    bool isHappy(int n) {
        set<int> st;
        while(1){
            int num = n;
            n = 0;
            int rem = 0;
            while(num){
                rem = num%10;
                n = (rem * rem) + n ;
                num = num/10;
            }
            if(n == 1)
                return true;
            else if(st.count(n) > 0)
                return false;
            else
                st.insert(n);
        }
    }
};

/*
Approach 2 : Floyd's Cycle detection algorithm : Which uses two pointers to traverse slow and fast.
While traversal if they points to same mile stone then they are in a loop.
*/

class Solution {
public:
    int getsumsquare(int n) {
        int sum = 0;
        while(n != 0)
        {
            sum += pow(n % 10,2);
            n = n / 10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        
        int slow=n,fast=n;
        
        while(slow!=1 && fast!=1){
            slow = getsumsquare(slow);
            fast = getsumsquare(getsumsquare(fast));
            if(slow==fast && slow!=1 && fast!=1)
                return false;
        }
        return true;
    }
};
