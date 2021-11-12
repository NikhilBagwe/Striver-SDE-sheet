// BRUTE ======================================================================================================================================================

int main()
{
    vector<int> a{2, 5, 1, 3, 4};
    int n =a.size();
    
    int invCount = 0;
    
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(a[i] > a[j]){
                invCount++;
            }
        }
    }
    
    cout<<invCount;

    return 0;
}
