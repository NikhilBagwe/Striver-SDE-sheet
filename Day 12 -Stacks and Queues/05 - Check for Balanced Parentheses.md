## OPTIMAL - TC = SC = O(n)

- Create a stack
- While iterating the string, if current elememt is any of the opening bracket, then push it into the stack
- If it is a closing bracket, then takeout the top element of the stack (which is an opening bracket) and compare if the current element is it's matching closing bracket.

```cpp
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        
        for(int i = 0; i < n; i++){
            // If s[i] is anyone of the opening bracket, then push it into stack
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }
            
            else{
                // No opening bracket exists for current closing bracket at s[i]
                if(st.empty()) return false;
                
                // takeout the top element from stack
                char c = st.top();
                st.pop();
                
                if((s[i] == ')' && c == '(') || (s[i] == ']' && c == '[') || (s[i] == '}' && c == '{')){
                    continue;
                }
                else return false;
            }
        }
        
        return st.empty();
    }
};
```
