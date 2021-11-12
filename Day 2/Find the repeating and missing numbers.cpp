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

// OPTIMAL ================================== XOR =========== TC = O(n) =============================================================================================

/*
LOGIC:

eg: a[] = {4, 3, 6, 2, 1, 1}

1. XOR all the elements of array and store the result in xor1 variable. In our eg, its xor1=3
2. Now, take XOR of elements from 1 to n with xor1. In our eg, its xor1=4.
3. Now the '4' that we got is nothing but result of (X^Y) where X = missing no., Y = repeating no.
4. When you perform, 
    (xor of all array elements) ^ (xor of elements from 1 to n) = (4^3^6^2^1^1) ^ (1^2^3^4^5^6) 
   on cancelling terms you will get '5' and '1' which are the required no.s 
5. Next we have to find the bit that is set in '4' i.e binary of 4 = '100'
6. So for '4' the rightmost bit is set. That bit is set, means either X is 0 or 1, OR Y is 0 or 1(from point 3), 
   since only different bits on doing XOR gives '1'.
7. Separate the elements form array into 2 buckets:
   bucket 1 = contains elements whose 1st bit from rightmost is set.
   bucket 2 = contains elements whose 1st bit from rightmost is not set
8. After iterating the array using set_bit:
   bucket 1 = 4, 6
   bucket 2 = 3, 2, 1, 1
9. Again iterate from 1 to n using set_bit:
   bucket 1 = 4, 6 | 4, 5, 6
   bucket 2 = 3, 2, 1, 1 | 1, 2, 3 
   On cancellation, you will get 5 and 1 as answer.
*/
