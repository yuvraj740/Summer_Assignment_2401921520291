class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (const string& word : strs) {
            string signature = word;
            sort(signature.begin(), signature.end());

            groups[signature].emplace_back(word);
        }

        vector<vector<string>> answer;
        
        for (auto& [key, words] : groups) {
            answer.emplace_back(move(words));
        }

        return answer;
    }
};