class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2);
        int difference;
        unordered_map<int,int> hashmap;

        for (int i = 0; i < nums.size(); ++i) {

            difference = target - nums[i];

            if (hashmap.find(difference) != hashmap.end()) {
                if(hashmap[difference] < i) {
                    result[0] = hashmap[difference];
                    result[1] = i;
                } else {
                    result[0] = i;
                    result[1] = hashmap[difference];
                }
            }

            hashmap[nums[i]] = i;
        }

        return result;
    }
};
