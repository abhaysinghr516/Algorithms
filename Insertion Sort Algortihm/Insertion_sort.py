def insertion_sort(arr):
    n = len(arr)  
      
    if n <= 1:
        return  
 
    for i in range(1, n):  
        pointer = arr[i]  
        j = i-1
        while j >= 0 and pointer < arr[j]:  
            arr[j+1] = arr[j]  
            j -= 1
        arr[j+1] = pointer  
  

arr = [12, 11, 13, 5, 6, 9, 59, 0, 7, 43]
insertion_sort(arr)
print(arr)