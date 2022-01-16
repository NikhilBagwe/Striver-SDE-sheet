## OPTIMAL : TC = O(1)

```cpp
class Queue {
    int arr[5000];
    int rear, start, count, n;
    
	public:
        Queue() {
            rear = -1;
            start = -1;
            // indicates current capacity of queue
            count = 0;
            // Max capacity of queue i.e array
            n = 5000;
        }

        bool isEmpty() {
            // If start and rear are pointing to same location, queue is empty
            return (start == rear);
        }

    	// Push 
        void enqueue(int data) {
            // If queue's capacity is full, exit(1)
            // exit(1) means the abnormal termination of the program, i.e. some error or interrupt has occurred. We can 
            // use different integer other than 1 to indicate different types of errors
            if(count == n) exit(1);
            
            // As we have to insert element into queue
            if (rear == -1) {
               start = 0;
               rear = 0;
            }
            
            // If queue has capacity, then insert element
            if(count != n){
               // We are running the queue in circular fashion, i.e when we 'end' ptr reaches last index we go 
               // back to 0th index as per the result of 'rear%n'
               arr[rear%n] = data;
               // increase the rear pointer
               rear++;
               // increase the capacity
               count++;
           }  
        }

        int dequeue() {
            if(isEmpty()) return -1;
            
            // store the element to be popped as we have to return it
            int popped = arr[start];
            // Put a dummy element into it
            arr[start%n] = -1;
            start++;
            count--;
            return popped;
        }

        int front() {
            if(isEmpty()) return -1;
            return arr[start%n];
        }
};
```
