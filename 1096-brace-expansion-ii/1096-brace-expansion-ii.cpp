
class Solution {
public:

    // Returns the set of strings represented by the expression
    // starting from index i.
    set<string> parse(string& s, int& i) {

        set<string> result;

        while (i < s.size() && s[i] != '}') {

            // Parse one part of the expression
            set<string> current;

            if (s[i] == '{') {
                // Skip '{'
                i++;

                // Parse everything inside braces
                current = parse(s, i);

                // Skip '}'
                i++;
            }
            else {
                // A single lowercase letter
                current.insert(string(1, s[i]));
                i++;
            }

            // If result is empty, this is the first part
            if (result.empty()) {
                result = current;
            }
            else {
                // Concatenation:
                // combine every string in result
                // with every string in current
                set<string> temp;

                for (string a : result) {
                    for (string b : current) {
                        temp.insert(a + b);
                    }
                }

                result = temp;
            }

            // If we have a comma, the next part is a union.
            if (i < s.size() && s[i] == ',') {
                i++;

                set<string> next = parse(s, i);

                // Union result and next
                for (string word : next) {
                    result.insert(word);
                }
            }
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> result = parse(expression, i);

        // set already keeps strings sorted
        return vector<string>(result.begin(), result.end());
    }
};

