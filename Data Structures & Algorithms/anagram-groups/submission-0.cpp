class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 1) return {{strs[0]}};

        vector<vector<string>> result = {};

        map<vector<int>, vector<string>> hashmap;

        for(int i = 0; i < strs.size(); ++i) {
            vector<int> counter(26, 0);

            for (int j = 0; j < strs[i].length(); ++j) {
                counter[strs[i][j] - 'a']++;
            }

            if (hashmap.find(counter) != hashmap.end()) {
                hashmap[counter].push_back(strs[i]);
            } else {
                hashmap[counter] = {strs[i]};
            }
        }    

        for(const auto& [key, arr]: hashmap) {
            result.push_back(arr);
        }       

        return result;

    }
};