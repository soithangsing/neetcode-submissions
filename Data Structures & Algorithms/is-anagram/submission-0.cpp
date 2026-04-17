class Solution {
public:
    bool isAnagram(string s, string t) {
        //Sol: Create a frequency counter to increment values and second loop to
        //decrement the counter. At the end if any counter is more than 0 or negative,
        //then strings are not anagrams. 

        if (s.size() != t.size()) return false;

        unordered_map<char, int> counter;

        for (int i = 0; i < s.size(); ++i) {
            counter[s[i]]++;
        }

        for (int i = 0; i < t.size(); ++i) {
            if (counter.find(t[i]) != counter.end()) {
                counter[t[i]]--;
            } else {
                return false;
            }
        }

        for (const auto&[character, count] : counter) {
            if(count != 0) return false;
        }

        return true;

        
    }
};
