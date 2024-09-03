class Solution {
public:
    int strStr(string haystack, string needle) {
        int index = 0;
        int size = needle.length();
        int flag = false;

        for (int i = 0; i < haystack.length(); i++){
            if (haystack[i] == needle[index]){
                int test = i;
                for (int x = 0; x < size; x++){
                    if (haystack[test] == needle[x]) flag = true;
                    else {
                        flag = false;
                        break;
                    }
                    test++;
                }
            }
            if (flag) return i;
        }
        return -1;
    }
};