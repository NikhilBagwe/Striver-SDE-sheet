// BRUTE ===================================================================== TC = O(n) =====================================================================

// This method fails when you try to convert '-2,147,483,648' to abs(-2,147,483,648) as it overflows because the positive range is '2,147,483,647'

int main()
{
    double x = 2.00000;
    int n = -4, n1 = 0, flag = 0;
    double ans = 1;
    
    // Checking whether the 'n' is a negative or positive no.
    if(n < 0){
        // Consider the absolute value of 'n'
        n1 = abs(n);
        flag = 1;
    }
    else n1 = n;
    
    // Calculate the x^n1 
    for(int i = 0; i < n1; i++){
        ans *= x;
    }
    
    if(flag == 0){
        cout<<fixed<<setprecision(4)<<ans;
    }
    // If 'n' was negative then divide the 'ans' from 1 as "x^(-n) = 1 / x^n"
    else{
        cout<<fixed<<setprecision(4)<<1/ans;
    }

    return 0;
}

// OPTIMAL ===================================================================== TC = O(logn) =====================================================================

// O(logn) as 'n' is getting divided by '2'

int main()
{
    double x = 2.00000;
    int n = -4, n1 = 0;
    double ans = 1.0;
    
    // Checking whether the power i.e 'n' is a negative or positive no.
    if(n < 0) n1 = abs(n);
    else n1 = n;
    
    // Until 'n1' becomes '0'
    while(n1){
        // When power is odd 
        if(n1 % 2){
            ans *= x;
            n1 -= 1;
        }
        
        // When power is even
        else{
            x *= x;
            n1 = n1/2;
        }
    }
    
    if(n > 0){
        cout<<fixed<<setprecision(4)<<ans;
    }
    // If 'n' was negative then divide the 'ans' from 1 as "x^(-n) = 1 / x^n"
    else{
        cout<<fixed<<setprecision(4)<<1/ans;
    }

    return 0;
}
