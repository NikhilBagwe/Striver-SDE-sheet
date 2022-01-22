## OPTIMAL :

1. get(key) -> gets the value of key if it exists or returns -1
2. put(key, value) :
   - Updates the value of key if present
   - OR inserts the key if not present
   - When the cache is full, it removes the LFU one.
   - IF there are multiple LFU elements i.e there is a tie, then removes the LRU one
   
### Put algo:
1. Check if the given key exists or not in keynode hashmap.
2. Check if the capacity of cache is full or not. 
3. If the key dosen't exists in keynode and there is still space in cache, insert the given key into freqlist to corresponding frequency '1' and insert new node in DLL using LRU cache logic i.e as first node in DLL after head.

