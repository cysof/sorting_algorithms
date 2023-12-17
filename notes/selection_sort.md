Selection Sort

    Selection Sort works by dividing the input array into two parts: the sorted portion and the unsorted portion. In each iteration, it finds the minimum element in the unsorted portion and swaps it into the sorted portion. This process continues until the entire array is sorted.

    selection_sort is a function that takes two parameters: an array of integers (array) and the size of the array (size).

    The function uses two nested loops. The outer loop (for (i = 0; i < size - 1; i++)) controls the current element being considered for placement, ranging from the first element to the second-to-last element. This loop selects the minimum element from the unsorted portion of the array in each iteration.

    Inside the outer loop, a variable min_int is initialized to the index i. This variable is used to keep track of the index of the minimum element found in the unsorted portion of the array. Initially, it's assumed that the current element (array[i]) is the minimum.

    The inner loop (for (j = i + 1; j < size; j++)) is used to iterate over the remaining unsorted elements to find the index of the minimum element. It starts from i + 1 to avoid comparing the element at index i with itself.

    Inside the inner loop, there's a comparison: if (array[j] < array[min_int]). If the element at index j is smaller than the element at the current min_int index, it means that array[j] is the new minimum, and min_int is updated to j.

    After the inner loop completes, min_int holds the index of the minimum element in the unsorted portion of the array.

    If the min_int is not equal to i, it means that the minimum element found in the inner loop is different from the current element at index i. In this case, a swap is performed:
        temp is used as a temporary variable to hold the value of the element at index i.
        array[i] is updated with the value of the minimum element at array[min_int].
        array[min_int] is updated with the value previously held in temp.

    After each swap, the print_array function is called to display the current state of the array. This is typically done to visualize the sorting process step by step.

    The process repeats for each element in the array, with the minimum element being selected and swapped into its correct position in each iteration.

    After the outer loop completes (i.e., all elements have been considered and the minimum element in the remaining unsorted portion is selected and placed in the sorted portion), the entire array is sorted in ascending order.

