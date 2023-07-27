## Print the missing numbers in the array into a new array.

```cpp
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> arr {1, 5, 8, 15};
    vector<int> op;
    
    // cout<<arr.size();
    
    for(int i=1; i<arr.size(); i++)
    {
        if(arr[i] != i)
        {
            for(int j=arr[i-1]; j<arr[i]; j++){
                if(j == arr[i-1]) continue;
                else{
                    op.push_back(j);
                }
            } 
        }
    }
    
    for(auto num: op){
        cout<<num<<" ";
    }

    return 0;
}
```
