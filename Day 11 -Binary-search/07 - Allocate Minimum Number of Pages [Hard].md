## OPTIMAL - TC = O(n x logn) , SC = O(1)

- TC = Binary search takes O(log N). For every search, we are checking if an allocation is possible or not. Checking for allocation takes O(N).
- Refer notes

```cpp
int isPossible(vector < int > &arr, int mid, int students) {
    int studAllocated = 0; // No. of students required to allocate the given books
    int pageCount = 0;

    for(int i = 0; i < arr.size(); i++){
        // If current book has more pages than the limit i.e mid, means we cannot alocate books to students
        if(arr[i] > mid) return false;
        
        // If no. of pages of books assigned to student1 + current book pages is more then mid, 
        // then assign the current book to new student2
        if(pageCount + arr[i] > mid){
            studAllocated++;
            pageCount = arr[i];
        }
        // Assign book to current student 
        else{
            pageCount += arr[i];
        }
    }

    // If all books are allocated to given no. of students, then return true
    if(studAllocated < students) return true;
    return false;
}
int Solution::books(vector<int> &A, int B) {
    // If no. of students are more and books to be allocated(i.e size of array is less) are less, return -1
    if(A.size() < B) return -1;

    int low = A[0];
    int high = 0;

    //to find minimum value and sum of all pages for our search space
    // Eg = [12,34,67,90] -> Search space = 12...to...203
    for(int i = 0; i < A.size(); i++){
        high += A[i];
        low = min(low, A[i]);
    }

    // binary search
    while(low <= high){
        int mid = (low+high)/2;
        
        // Check whether we can allocate books to given no. of students i.e B 
        if(isPossible(A, mid, B)){
            // reduce the search space
            high = mid-1;
        }
        else{
            // increase the search space
            low = mid+1;
        }
    }

    return low;
}

```
