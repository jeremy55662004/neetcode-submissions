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

                // Calculate the width:
                // If stack is empty: the current bar is the shortest so far, width is 'i'.
                // If stack is not empty: width is the distance between the current index 
                // and the new stack top (left boundary).
                int w = st.empty() ? ix : ix - st.top() - 1;

                maxArea = max(maxArea, w * h);
            }
            st.push(ix);
        }
        return maxArea;
    }
};
