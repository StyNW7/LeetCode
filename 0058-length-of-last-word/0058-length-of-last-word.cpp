class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int len = 0;
        int last = len;

        for (int i = 0; i < s.size(); i++){
            if (s[i] != ' ') {
                len++;
            }
            else {
                if (len != 0) last = len;
                len = 0;
            }
        }

        if (len == 0) return last;
        else return len;

    }
};