class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        vector<vector<int>> buckets(n + 1);

        unordered_map<int, int> map; 

        for (int i = 0; i < n; ++i) {
            map[nums[i]]++;
        }

        for (auto e : map) {
            int index = e.second;
            buckets[index].push_back(e.first);
        }

        vector<int> result = {};

        int counter = k;

        for (int i = buckets.size() - 1; i >= 0; --i) {
            if (buckets[i].size() == 0) continue;

            for (int j = 0; j < buckets[i].size(); ++j) {
                if (counter <= 0) break;
                result.push_back(buckets[i][j]);
                counter--;
            }
        }

        return result;
    }
};
