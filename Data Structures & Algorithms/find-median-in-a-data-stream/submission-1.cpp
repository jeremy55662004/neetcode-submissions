class MedianFinder {
private:
    // Max-heap to store the smaller half of the numbers
    // The largest element of the small half is at the top
    priority_queue<int> small; 

    // Min-heap to store the larger half of the numbers
    // The smallest element of the large half is at the top
    priority_queue<int, vector<int>, greater<int>> large; 

public:
    /** initialize your data structure here. */
    MedianFinder() {}
    
    /**
     * Adds a number into the data structure.
     * Efficiency: O(log N)
     */
    void addNum(int num) {
        // Step 1: Add the new number to the small half (max-heap)
        small.push(num);
        
        // Step 2: Sifting - Move the largest element from small to large.
        // This ensures all elements in 'small' are <= elements in 'large'.
        large.push(small.top());
        small.pop();
        
        // Step 3: Rebalancing - Ensure the size property:
        // We want small.size() to be equal to or one greater than large.size().
        if (small.size() < large.size()) {
            small.push(large.top());
            large.pop();
        }
    }
    
    /**
     * Returns the median of current data stream.
     * Efficiency: O(1)
     */
    double findMedian() {
        // If the total count is odd, the middle element is at the top of 'small'
        if (small.size() > large.size()) {
            return (double)small.top();
        } 
        // If the total count is even, the median is the average of the two tops
        else {
            return (small.top() + large.top()) / 2.0;
        }
    }
};