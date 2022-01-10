[Problem link](https://takeuforward.org/data-structure/nth-root-of-a-number-using-binary-search/)

## OPTIMAL - TC = N x log(M x 10^d) , SC = O(1)

- TC = n -for multiply func, log(M x 10^d) - as our search space in terms of decimal points upto 10^-6 i.e 'd'

```cpp
#include <bits/stdc++.h>
using namespace std;

double multiply(double num, int n){
    double ans = 1.0;
    for(int i=0; i<n; i++){
        ans = num*ans;
    }
    return ans;
}

double getNthRoot(double n, double m){
    double low = 1, high = m;
    // Take eps = 1e-6, since we have to find answers upto 6 decimal places.
    double eps = 1e-6;
    
    while((high - low) > eps){
        double mid = (low+high)/2;
        
        if(multiply(mid, n) < m){
            low = mid;
        }
        
        else{
            high = mid;
        }
    }
    
    cout<<n<<"th root of "<<m<<" is "<<low<<endl; // low and high will have same answer stored in it
    
    // Just to cross check
    //cout<<pow(m, (double)(1.0/(double)n));
    
    return 0;
}

int main()
{
    double n = 3, m = 27;
    getNthRoot(3, 27);
    return 0;
}
```
