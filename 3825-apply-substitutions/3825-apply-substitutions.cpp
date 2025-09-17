class Solution {
public:
    string applySubstitutions(vector<vector<string>>& replacements, string text) {
        // Build dictionary
        unordered_map<string, string> hash;
        for (auto &r : replacements) {
            hash[r[0]] = r[1];
        }

        // Regex to match placeholders like %A% or %Var%
        regex pattern("%([A-Za-z0-9]+)%");

        string result;
        smatch match;

        // Keep substituting until no placeholders remain
        while (regex_search(text, match, pattern)) {
            string var = match[1].str();   // extract variable name
            string replacement = hash[var]; 

            // Replace first occurrence
            text.replace(match.position(0), match.length(0), replacement);
        }

        return text;
    }
};
