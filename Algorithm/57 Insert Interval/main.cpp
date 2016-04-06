#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Interval 
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution 
{
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) 
    {
        int i = 0;
        int len = intervals.size();
        if(0 == len) 
        { 
                intervals.push_back(newInterval); return intervals;
        }
        vector<Interval> re;
        //find the insert position of start.
        while(i < len && intervals[i].end < newInterval.start)
        {
            re.push_back(intervals[i]);
            ++i;
        }
        //at the right, 
        if(i == len)
        {
            re.push_back(newInterval); return re; 
        }
        int j = i;
        //find the insert position of end.
        while(j < len && intervals[j].end < newInterval.end)
        {
            ++j;
        }
        Interval jion;
        jion.start = min(intervals[i].start, newInterval.start);
        if(j == len)
        {
            jion.end = newInterval.end;
            re.push_back(jion);
            return re;
        }
    
        if(newInterval.end < intervals[j].start)
        {
           --j;
           jion.end = newInterval.end;
           re.push_back(jion);
        } 
        else
        {
            jion.end = intervals[j].end;
            re.push_back(jion);
        }
        ++j;
        while(j < len)
        {
            re.push_back(intervals[j]);
            ++j;
        }
        return re;
    }
};

int main(int argc, char const *argv[])
{
    vector<Interval> intervals;
    intervals.push_back(Interval(1,2));
    intervals.push_back(Interval(3,5));
    intervals.push_back(Interval(6,7));
    intervals.push_back(Interval(8,10));
    intervals.push_back(Interval(12,16));
    Solution sol;
    intervals = sol.insert(intervals,Interval(4,9));
    for(int i=0;i<intervals.size();i++)
    {
        cout<<" ["<<intervals[i].start<<" "<<intervals[i].end<<"] ,";
    }
    return 0;
}