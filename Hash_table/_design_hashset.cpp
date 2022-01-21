/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */
/* TC for insert and contain = O(1)
   TC for remove O(N) it can be achived to O(1) by using linked list
*/

#define MAX_LEN 100000          // the amount of buckets
class MyHashSet {
private:
  vector<int> set[MAX_LEN];
  
  int getIndex(int key){
    return key%MAX_LEN;
  }
  
  int getPos(int idx, int key){
    for(int i = 0; i < set[idx].size(); i++)
    {
      if(set[idx][i] == key)
      {
        return i;
      }
    }
    return -1;
  }
public:
  /** Initialize your data structure here. */
    MyHashSet() {
        
    }
  
  void add(int key) {
    int idx = getIndex(key);
    int pos = getPos(idx, key);
    
    if(set[idx][pos] < 0)
    {
      set[idx][pos].push_back(key);
    }
    return;
  }
  
  void remove(int key) {
    int idx = getIndex(key);
    int pos = getPos(idx, key);
    
    if(pos > -1)
    {
      set[idx].erase(set[idx].begin() + pos);
    }
    return;
  }
  
  bool contains(int key) {
    int idx = getIndex(key);
    int pos = getPos(idx, key);
    if(pos > -1)
    {
      return true;
    }
    return false;
  }
    
