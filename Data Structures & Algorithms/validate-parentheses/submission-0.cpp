class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        unordered_map<char, char> closeToOpen = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char c : s) {
            /* Check if c is a key of unordered_map closeToOpen */
            if (closeToOpen.count(c)) {
                if (!stack.empty() && stack.top() 
                    == closeToOpen[c]) {
                    stack.pop();
                } else {
                    return false;
                }
            } else {
                stack.push(c);
            }
        }
        return stack.empty();
    }
};