/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& x, auto& y){
            return x.start < y.start;
        });

        for (int ix = 1; ix < intervals.size(); ix++) {
            if (intervals[ix].start < intervals[ix - 1].end) {
                return false;
            }
        }
        return true; 
    }
};
