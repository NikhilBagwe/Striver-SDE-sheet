// BRUTE ================================== COUNT SORT ALGO =========== TC = O(n) SC = O(n) ===============================================================

/*
COUNT SORT: 

1. Create a temp array and store frequency of all elements of nums into it 
2. Iterate the temp array and check for:
   - whether '0' is present at any place which gives us the -> Missing number
   - whether '2' is present at any place which gives us the -> Repeating number
*/

int main()
{
    vector<int> nums {3,1,2,5,4,6,7,5};
    int n = nums.size();
     
    vector<int> temp(n, 0);
    
    for(int i = 0; i<n; i++){
        temp[nums[i]]++;
    }
    
    for(int i = 1; i<=n; i++){
        if(temp[i] == 0){
            cout<<"Missing number: "<<i<<endl;
        }
        if(temp[i] > 1){
            cout<<"Repeating number: "<<i<<endl;
        }
    }
    
    return 0;
}
