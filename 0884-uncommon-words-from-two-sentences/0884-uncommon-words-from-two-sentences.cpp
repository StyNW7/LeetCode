class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> wordCount;
        vector<string> result;

        // Helper function to count words from a sentence
        auto countWords = [&](string sentence) {
            stringstream ss(sentence);
            string word;
            while (ss >> word) {
                wordCount[word]++;
            }
        };

        // Count words from both sentences
        countWords(s1);
        countWords(s2);

        // Find words that appear exactly once
        for (const auto& entry : wordCount) {
            if (entry.second == 1) {
                result.push_back(entry.first);
            }
        }

        return result;
    }
};