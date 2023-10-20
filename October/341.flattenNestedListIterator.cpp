/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> integer;
    vector<int> solve(vector<NestedInteger> &nestedList){
        vector<int> intList;
        for(auto &it : nestedList){
            if(it.isInteger()){
                intList.push_back(it.getInteger());
            }else{
                vector<int> v = solve(it.getList());
                for(auto i : v){
                    intList.push_back(i);
                }
            }
        }
        return intList;
    }
    int i;
    NestedIterator(vector<NestedInteger> &nestedList) {
        integer = solve(nestedList);
        i=0;
    }
    
    int next() {
        return integer[i++];
        
    }
    
    bool hasNext() {
        if(i>=integer.size()){
            return false;
        }
        return true;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
