class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> maskMap; // map to store the first occurrence of each bitmask
        maskMap[0] = -1; // Initial bitmask (all vowels have appeared 0 times)
        int mask = 0; // bitmask to track vowel parity
        int maxLength = 0;

        for (int i = 0; i < s.size(); ++i) {
            // Update the bitmask based on the current character
            if (s[i] == 'a') mask ^= (1 << 0);
            else if (s[i] == 'e') mask ^= (1 << 1);
            else if (s[i] == 'i') mask ^= (1 << 2);
            else if (s[i] == 'o') mask ^= (1 << 3);
            else if (s[i] == 'u') mask ^= (1 << 4);

            // If the same mask has been seen before, update the maxLength
            if (maskMap.find(mask) != maskMap.end()) {
                maxLength = max(maxLength, i - maskMap[mask]);
            } else {
                // If this is the first time we see this mask, store its index
                maskMap[mask] = i;
            }
        }

        return maxLength;
    }
};