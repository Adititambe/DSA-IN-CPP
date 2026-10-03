class Solution {
public:
    bool isValid(string s) {

        // Stack :to store opening brackets
        stack<char> st;

        // Traverse the string 
        for (int i = 0; i < s.size(); i++) {

            //  Opening bracket
            // Push it into the stack
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }

            //  Closing bracket
            else {

                // If stack is empty  there is no opening bracket to match
                if (st.empty()) {
                    return 0;
                }

                // If closing bracket is ')'
                else if (s[i] == ')') {

                    // Top must be '('
                    if (st.top() != '(') {
                        return 0;
                    }
                    else {
                        st.pop();
                    }
                }

                // If closing bracket is '}'
                else if (s[i] == '}') {

                    // Top must be '{'
                    if (st.top() != '{') {
                        return 0;
                    }
                    else {
                        st.pop();
                    }
                }

                // If closing bracket is ']'
                else {

                    // Top must be '['
                    if (st.top() != '[') {
                        return 0;
                    }
                    else {
                        st.pop();
                    }
                }
            }
        }

        // If stack is empty → all brackets matched
        // If stack is not empty → some opening brackets remain
        return st.empty();
    }
};