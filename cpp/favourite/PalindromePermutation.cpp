class Solution {
public:
    bool canPermutePalindrome(string s) {
        bitset<256>m;
        for(auto a:s) {
            m.flip(a);
        }
        return m.count() <2;
    }
};