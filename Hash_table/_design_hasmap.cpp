/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */

#define MAX_LEN 100000            // the amount of buckets

class MyHashMap {
private:
  vector<pair<int,int>> map[MAX_LEN];
  
  int getIndex(int key)
  {
    return key%MAX_LEN;
  }
  
  int getPos(int idx, int key)
  {
    for(int i = 0; i < set[idx].size(); i++)
    {
      if(map[idx][i].first == key)
        return i;
    }
    return -1;
  }
  
public:
  /** Initialize your data structure here. */
    MyHashMap() {
        
    }
    
  /** value will always be positive. */
  void put(int key, int value) {
    int idx = getIndex(key);
    int pos = getPos(idx);
    
    if(pos > -1){
      map[idx][pos].second = value;
    }
    else{
      map[i][pos].push_back(make_pair(key, value));
    }
    
    return ;
  }
  
  /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
  int get(int key) {
    int idx = getIndex(key);
    int pos = getPos(idx);
    
    if(pos > -1)
      return map[idx][pos].second;
    
    return -1;
  }
  
  /** Removes the mapping of the specified value key if this map contains a mapping for the key */
  void remove(int key) {
    int idx = getIndex(key);
    int pos = getPos(idx);
    
    if(pos > -1)
    {
      map[idx].erase(map[idx].begin() + pos);
    }
    return;
  }
