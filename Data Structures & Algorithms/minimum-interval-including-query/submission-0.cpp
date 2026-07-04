class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size();
        int q_size = queries.size();
        
        // 1. Store queries with their original indices and sort them in ascending order
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < q_size; ++i) {
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());
        
        // 2. Sort intervals based on their start points in ascending order
        sort(intervals.begin(), intervals.end());
        
        // 3. Create a Min-Heap storing pair<interval_length, right_endpoint>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        
        vector<int> res(q_size);
        int i = 0; // Pointer to track the current interval
        
        // Iterate through each sorted query
        for (auto& [q, originalIndex] : sortedQueries) {
            
            // Step 1: Add all intervals whose start point <= q into the Min-Heap
            while (i < n && intervals[i][0] <= q) {
                int length = intervals[i][1] - intervals[i][0] + 1;
                minHeap.push({length, intervals[i][1]});
                i++;
            }
            
            // Step 2: Remove all expired intervals whose end point < q from the Min-Heap
            while (!minHeap.empty() && minHeap.top().second < q) {
                minHeap.pop();
            }
            
            // Step 3: The top of the Heap is now the shortest valid interval containing q
            if (!minHeap.empty()) {
                res[originalIndex] = minHeap.top().first;
            } else {
                res[originalIndex] = -1; // No valid interval found for this query
            }
        }
        
        return res;
    }
};