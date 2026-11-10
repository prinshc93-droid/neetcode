
class Solution {
public:

    // Encode: List of strings -> Single string
        string encode(vector<string>& strs) {
                string result = "";

                        for (string& s : strs) {
                                    result += to_string(s.size()) + "#" + s;
                                            }

                                                    return result;
                                                        }

                                                            // Decode: Single string -> List of strings
                                                                vector<string> decode(string s) {
                                                                        vector<string> result;

                                                                                int i = 0;

                                                                                        while (i < s.size()) {
                                                                                                    int j = i;

                                                                                                                // Find separator '#'
                                                                                                                            while (s[j] != '#') {
                                                                                                                                            j++;
                                                                                                                                                        }

                                                                                                                                                                    // Extract string length
                                                                                                                                                                                int len = stoi(s.substr(i, j - i));

                                                                                                                                                                                            // Extract original string
                                                                                                                                                                                                        string str = s.substr(j + 1, len);

                                                                                                                                                                                                                    result.push_back(str);

                                                                                                                                                                                                                                // Move to next encoded string
                                                                                                                                                                                                                                            i = j + 1 + len;
                                                                                                                                                                                                                                                    }

                                                                                                                                                                                                                                                            return result;
                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                };
                                                                                                                                                                                                                                                                
