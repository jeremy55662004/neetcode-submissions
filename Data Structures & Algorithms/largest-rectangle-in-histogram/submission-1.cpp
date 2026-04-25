class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> st;
        int maxArea = 0;

        for (int ix = 0; ix < heights.size(); ix++) {
            while(!st.empty() && heights[ix] < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();

                // Calculate the width of the rectangle with 'h' as its height:
                // i: The current index, which is the "first bar to the right" that is 
                // shorter than our height 'h' (The Right Boundary).
                // st.top(): The index currently at the top of the stack (after pop), 
                // which is the "first bar to the left" that is shorter 
                // than our height 'h' (The Left Boundary).
                // Formula: i - st.top() - 1
                // Why "-1"? Because both boundaries (i and st.top) are strictly shorter 
                // than 'h' and cannot be included in the rectangle's width.
                
                int w = st.empty() ? ix : ix - st.top() - 1;

                maxArea = max(maxArea, w * h);
            }
            st.push(ix);
        }
        return maxArea;
    }
};
