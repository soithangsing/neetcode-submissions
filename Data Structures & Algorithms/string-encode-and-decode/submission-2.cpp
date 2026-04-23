class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";

        for (string &str: strs) {
            s+=str+'\t';
        }

        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans = {};
        string str = "";

        for(char c: s) {
            if (c != '\t') {
                str += c;
            } else {
                ans.push_back(str);
                str = "";
            }
        }

        return ans;
    }
};
