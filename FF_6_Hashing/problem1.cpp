#include <iostream>
#include <vector>
using namespace std;

class MyHashSet {
  public:
    vector<vector<int>> table;
    int size;
    MyHashSet() : size(1000){
      table.resize(size);
    }
    int hash(int key){
      return key % size;
    }

    void add(int key){ // inserts the value key into the hashset
      int index = hash(key);
      for (int val : table[index]){
        if (val == key) {
          return;
        }
      }
      table[index].push_back(key);
    }

    void remove(int key){
      int index = hash(key);
      vector<int>& bucketofKeys = table[index];

      for(auto currentKeyIterator = bucketofKeys.begin(); currentKeyIterator != bucketofKeys.end(); ) {
        if (*currentKeyIterator == key) {
          currentKeyIterator = bucketofKeys.erase(currentKeyIterator);
        } else {
          ++currentKeyIterator;
        }
      }
    }
    
    bool contains(int key) {
      int index = hash(key);
      for (int val : table[index]) {
        if (val == key) {
          return true;
        }
      }
      return false;
    }
};

int main () {
  MyHashSet myHashSet;
  myHashSet.add(1);
  myHashSet.add(2);
  cout << myHashSet.contains(1) << endl;
  cout << myHashSet.contains(3) << endl;
  myHashSet.add(2);
  cout << myHashSet.contains(2) << endl;
  myHashSet.remove(2);
  cout << myHashSet.contains(2) << endl;
  return 0;
}