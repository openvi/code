/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
         vector<Interval> ret;
         if (intervals.size()==0) {
             ret.push_back(newInterval);
             return ret;
         }
         bool inserted = false;
         for (int i=0; i<intervals.size();i++) {
             if (intervals[i].start>newInterval.end) {
                 if (!inserted) {
                     ret.push_back(newInterval);
                     inserted = true;

                 }
                 ret.push_back(intervals[i]);
             } else  if (intervals[i].end<newInterval.start) {
                 ret.push_back(intervals[i]);
             } else {
                 newInterval.start = min(newInterval.start, intervals[i].start);
                 newInterval.end = max(newInterval.end, intervals[i].end);
                 
             }
             
             
         }
         if (!inserted) {
             ret.push_back(newInterval);
         }
         return ret;
        
    }
};