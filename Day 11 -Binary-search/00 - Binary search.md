```cpp
int binarySearch(int arr[], int n, int key){
    int s=0;
    int e=n;
    
    //check until start point is less than end point
    while(s<=e){
        //finding middle element of array
        int mid= (s+e)/2;
        
        if(arr[mid]==key){
            return mid;
        }
        
        //if mid value is greater then key, it means our key(which we are searching) is present in first half so move our end point backwards
        else if(arr[mid]> key){
            e=mid-1;
        }
        
        //if mid value is less then key, it means our key is present in second half so move our start point forwards
        else{
            s=mid+1;
        }
    }
}

int main()
{
   int n;
   cin>>n;
   
   int arr[n];
   for(int i=0; i<n; i++){
       cin>>arr[i];
   }
   
   int key;
   cin>>key;
    
   cout<<binarySearch(arr,n,key);
    
    return 0;
}
```
