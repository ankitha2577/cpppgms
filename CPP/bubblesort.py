
# BUBBLE SORT TIMING ASSIGNMENT


import random   
import time     
import matplotlib.pyplot as plt   



def bubble_sort(arr):
    n = len(arr)  

    for i in range(n):
       
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

    return arr



def create_random_array(n):
   
    return [random.randint(1, 10000) for _ in range(n)]



sizes = []          
execution_times = []  


start_size = 10000
end_size = 20000
step = 500

for n in range(start_size, end_size + 1, step):
    
    arr = create_random_array(n)


    start_time = time.time()

    
    bubble_sort(arr)

   
    end_time = time.time()

    
    time_taken = end_time - start_time

   
    sizes.append(n)
    execution_times.append(time_taken)

    
    print(f"Size: {n:5d} | Time taken: {time_taken:.4f} seconds")



plt.plot(sizes, execution_times, marker='o', color='blue')
plt.title("Bubble Sort: Execution Time vs Array Size")
plt.xlabel("Array Size (n)")
plt.ylabel("Execution Time (seconds)")
plt.grid(True)
plt.show()