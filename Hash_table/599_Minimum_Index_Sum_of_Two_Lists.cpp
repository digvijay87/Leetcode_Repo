/*
Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants represented by strings.

You need to help them find out their common interest with the least list index sum. If there is a choice tie between answers, output all of them with no order requirement. You could assume there always exists an answer.

 

Example 1:

Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"]
Output: ["Shogun"]
Explanation: The only restaurant they both like is "Shogun".
Example 2:

Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["KFC","Shogun","Burger King"]
Output: ["Shogun"]
Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).
 

Constraints:

1 <= list1.length, list2.length <= 1000
1 <= list1[i].length, list2[i].length <= 30
list1[i] and list2[i] consist of spaces ' ' and English letters.
All the stings of list1 are unique.
All the stings of list2 are unique.
*/

/* Using HashMap:
TC O(l1+l2) l1 is length of list1 and l2 is length of l2
SC O(l1)
*/

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> map;
        int ret = 0;
        int sum = 0;
        int min = INT_MAX;
        vector<string> res;
        for(int i = 0; i <list1.size(); i++)
        {
            map[list1[i]] = i;
        }
        for(int i = 0; i <list2.size(); i++)
        {
            if(map.count(list2[i])){
                ret = map[list2[i]];
                sum = ret + i;
                if(min > sum){
                    res.clear();
                    res.push_back(list2[i]);
                    min = sum;
                }else if(min == sum){
                    res.push_back(list2[i]);
                }
                
            }
        }
        return res;
    }
};
