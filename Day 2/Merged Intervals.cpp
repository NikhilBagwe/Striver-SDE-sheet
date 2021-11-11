// BRUTE ======================================================= O(n^2) ====================================================================

int main()
{
    vector<vector<int>> intervals {{1, 3}, {2, 6}, {8, 10}, {9, 12}, {15, 18}};
    int n = intervals.size();
    
    vector<vector<int>> mergedIntervals;
    vector<int> tempInterval;
    
    // Iterate over the vector intervals for each interval to find a matching interval
    for(int i=0; i<n; i++){
        tempInterval = intervals[i];
        
        for(int j=i+1; j<n; j++){
            vector<int> curInterval = intervals[j];
            
            if(curInterval[0] <= tempInterval[1]){
                tempInterval[1] = max(curInterval[1], tempInterval[1]);
            }
            
            else{
                mergedIntervals.push_back(tempInterval);
                // Bring 'i' to the position of 'j-1' to avoid duplicate intervals pushed into mergedIntervals
                i = j-1;
                break;
            }
        }
    }
    
    // Push the last resultant interval 
    mergedIntervals.push_back(tempInterval);
    
    for(auto it:mergedIntervals){
        for(auto num : it){
            cout<<num<<" ";
        }
    }

    return 0;
}

// OPTIMAL =============================================================== TC = O(nlogn) + O(n) , SC = O(n) ==================================================================

int main()
{
    vector<vector<int>> intervals {{1, 3}, {2, 6}, {8, 10}, {9, 12}, {15, 18}};
    int n = intervals.size();
    
    vector<vector<int>> mergedIntervals;
    
    // Just in case the given 'intervals' vector was empty, return empty mergedIntervals vector or '0'
    if(intervals.size() == 0) return 0;
    
    // If the 'intervals' was not sorted just in case, sort it 
    sort(intervals.begin(), intervals.end());
    
    // Assign the 1st interval to tempInterval
    vector<int> tempInterval = intervals[0];
    
    for(auto it : intervals){
        // Compare the FIRST element of current interval with the LAST element of tempInterval
        if(it[0] <= tempInterval[1]){
            tempInterval[1] = max(it[1], tempInterval[1]);
        }
        else{
            mergedIntervals.push_back(tempInterval);
            // Reassign/update the tempInterval with the current interval pointed by 'it'
            tempInterval = it;
        }
    }
    
    // Push the last resultant interval 
    mergedIntervals.push_back(tempInterval);
    
    for(auto it:mergedIntervals){
        cout<<"[";
        for(auto num : it){
            cout<<num<<" ";
        }
        cout<<"]";
    }

    return 0;
}
