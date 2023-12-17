Shell Sort

    Shell Sort works by repeatedly sorting elements that are separated by a gap. It starts with a large gap and gradually reduces the gap until it reaches 1, effectively performing insertion sort on a partially sorted array. This combination of gap-based sorting and insertion sort leads to a more efficient sorting algorithm compared to pure insertion sort, especially for large arrays.

    shell_sort is a function that takes two parameters: an array of integers (array) and the size of the array (size).

    The function performs some initial checks to ensure that the array is not NULL and that it has at least two elements. If not, it returns early since there's no need to sort such an array.

    The algorithm begins by calculating the initial gap value using the Knuth sequence. The Knuth sequence calculates the gap values used for insertion sort within the Shell Sort algorithm. The initial gap is set to 1 and is then calculated as gap = (gap * 3) + 1 until it exceeds one-third of the array's size.

    The main loop iterates while the gap is greater than 0, effectively decreasing the gap with each iteration.

    Within each iteration of the main loop, the algorithm performs an insertion sort within the current gap.

        It starts at the gap index and selects the element at that position (temp).

        Then, it performs an insertion sort on the subarray, considering every gap-th element (i.e., the elements that are gap positions apart). It compares each element (array[j - gap]) to the temp value and shifts elements to the right if they are greater than temp until it finds the correct position for temp.

        The loop variable j is decremented by gap in each step to move backward within the subarray.

        When the correct position for temp is found, it is placed in that position in the array.

    After sorting within the current gap, the print_array function is called to display the current state of the array. This step is included to visualize the sorting process after each decreasing interval.

    The gap is then decreased according to the Knuth sequence (gap /= 3) to prepare for the next iteration of the main loop with a smaller gap.

    The process continues, gradually decreasing the gap and sorting the array with insertion sort until the gap becomes 0, at which point the array is fully sorted in ascending order.

