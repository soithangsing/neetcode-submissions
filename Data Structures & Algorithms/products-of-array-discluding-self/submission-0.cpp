class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix = {};
        int product = 1;

        for (int i = 0; i < nums.size(); ++i) {
            product *= nums[i];
            prefix.push_back(product);
        }
        product = 1;

        vector<int> suffix = {};
        for (int i = nums.size() - 1; i>= 0; --i) {
            product *= nums[i];
            suffix.push_back(product);
        }
        reverse(suffix.begin(), suffix.end());

        product = 1;
        vector<int> ans = {};

        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0) {
                product = suffix[i + 1];
                ans.push_back(product);
                product = 1;
            } else if (i == nums.size() - 1) {
                product = prefix[i - 1];
                ans.push_back(product);
                product = 1;
            } else {
                product = prefix[i-1] * suffix[i + 1];
                ans.push_back(product);
                product = 1;
            }
        }

        return ans;
    }
};
