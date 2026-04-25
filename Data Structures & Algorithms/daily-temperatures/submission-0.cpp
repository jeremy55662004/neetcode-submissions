class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> stack; // pair: {temp, index}

        for (int ix = 0; ix < temperatures.size(); ix++) {
            int t = temperatures[ix];

            while (!stack.empty() && t > stack.top().first) {
                auto pair = stack.top();
                res[pair.second] = ix - pair.second;
                stack.pop();
            }
            stack.push({t, ix});
        }
        return res;
    }
};
