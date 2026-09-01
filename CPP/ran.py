import random
import time
import matplotlib.pyplot as plt

# The sizes of the lists we want to test
list_sizes = [100, 200, 300, 400, 500]
stopwatch_times = []

# We will do EVERYTHING inside this one main loop!
for size in list_sizes:
    
    # ---------------------------------------------------------
    # STEP A: Create the list of random numbers
    # ---------------------------------------------------------
    numbers_to_sort = []
    
    for step in range(size):
        random_num = random.randint(1, 100)
        numbers_to_sort.append(random_num)
        
    # ---------------------------------------------------------
    # STEP B: Start the stopwatch
    # ---------------------------------------------------------
    start = time.time()
    
    # ---------------------------------------------------------
    # STEP C: Sort the numbers (The Bubble Sort)
    # ---------------------------------------------------------
    total_items = len(numbers_to_sort)
    
    for i in range(total_items):
        for j in range(total_items - 1):
            
            # If the left number is bigger than the right number...
            if numbers_to_sort[j] > numbers_to_sort[j+1]:
                
                # ...swap them using a temporary holding box
                temp = numbers_to_sort[j]
                numbers_to_sort[j] = numbers_to_sort[j+1]
                numbers_to_sort[j+1] = temp
                
    # ---------------------------------------------------------
    # STEP D: Stop the stopwatch and save the time
    # ---------------------------------------------------------
    end = time.time()
    
    time_taken = end - start
    stopwatch_times.append(time_taken)

# ---------------------------------------------------------
# STEP E: Draw the graph (happens after the big loop finishes)
# ---------------------------------------------------------
plt.plot(list_sizes, stopwatch_times)
plt.title('Execution Time of Bubble Sort')
plt.xlabel('Array Size')
plt.ylabel('Time in seconds')
plt.show()