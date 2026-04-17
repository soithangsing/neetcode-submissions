class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
// Sol 2: Loop through the array and store each element in a hash set and compare the return 
// value of each insert operation to see if a duplicate has already been stored.

unordered_set<int> mySet;

for (int &x: nums) {
    auto[it,success] = mySet.insert(x);
    if (!success) return true;
}

return false;

    }
};