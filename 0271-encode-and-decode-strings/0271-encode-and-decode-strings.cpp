class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encodedString = "";
        for (const string& str : strs) {
            encodedString += to_string(str.length()) + "#" + str;
        }
        return encodedString;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decodedStrings;
        int i = 0;
        while (i < s.length()) {
            int j = i;
            // Find the position of the delimiter '#'
            while (s[j] != '#') {
                j++;
            }
            int length = stoi(s.substr(i, j - i)); // length of string
            string str = s.substr(j + 1, length);  // extract actual string
            decodedStrings.push_back(str);
            i = j + 1 + length; // move to the next encoded segment
        }
        return decodedStrings;
    }
};
