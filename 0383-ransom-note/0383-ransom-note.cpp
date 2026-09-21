class Solution {
public:
    bool canConstruct(string r, string m) {
        if (r.size() > m.size())
            return false;
        sort(r.begin(), r.end());
        sort(m.begin(), m.end());

        map<char, int> mppr;
        map<char, int> mppm;

        for (char ch : r) {
            mppr[ch]++;
        }
        for (char ch : m) {
            mppm[ch]++;
        }

        for (char ch : r) {
            if (mppr[ch] > mppm[ch])
                return false;
        }
        return true;
    }
};