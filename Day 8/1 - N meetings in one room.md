## OPTIMAL -  TC = O(n) +O(n log n) + O(n) = O(n log n) , SC = O(n)

- Time Complexity: O(n) to iterate through every position and insert them in a data structure. O(n log n)  to sort the data structure in ascending order of end time.
  O(n)  to iterate through the positions and check which meeting can be performed.
- Store all the meeting details into a DS in form of structs.
- Sort them in ascending order using comparator
- Set the ending time of 1st meeting as the 'limit'
- 'limit' is the time after which the next meeting should start. No meeting can start before 'limit' time.
- In order a meeting to be performed, start time of curret meeting should be greater than the ending time of previous meeting

```cpp
class Solution
{
    public:
    
    struct meeting{
        int start;
        int end;
        int pos;
    };
    
    bool static comparator(struct meeting m1, meeting m2){
        if(m1.end < m2.end) return true;
        else if(m1.end > m2.end) return false;
        else if (m1.pos < m2.pos) return true;
        return false;
    }
    
    int maxMeetings(int s[], int e[], int n)
    {
        struct meeting meet[n];
        
        // Store all the meetings details into meet DS
        for(int i = 0; i < n; i++){
            meet[i].start = s[i], meet[i].end = e[i], meet[i].pos = i+1;
        }
        
        sort(meet, meet+n, comparator);
        
        vector<int> answer;
        
        // Set the ending time of 1st meeting as limit
        int limit = meet[0].end;
        
        // The first meeting is going to take place any how so put it into 'answer'
        answer.push_back(meet[0].pos);
        
        for(int i = 1; i < n; i++){
            // If start time of curret meeting is greater than the ending time of previous meeting, means we can perform that meeting
            if(meet[i].start > limit){
                // Update the limit and add meeting no.
                limit = meet[i].end;
                answer.push_back(meet[i].pos);
            }
        }
        
        return answer.size();
    }
};
```
