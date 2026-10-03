class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            st.push(s[i]);
        }
        int i=0;
        while(!st.empty()){
            s[i]=st.top();
            st.pop();
            i++;

        }
        
    }
};

/*
create stack,traverse string,push elements of string onto stack,for reversal till stack is empty push elements of stack onto string,pop stack element,incrementation for next element of stack*/

