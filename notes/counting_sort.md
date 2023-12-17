Counting Sort

    Counting Sort is an efficient sorting algorithm for a range of input values. It counts the occurrences of each value in the input array and uses this information to directly place the values in their correct sorted positions. It is particularly useful when sorting a range of integers with limited variation in values, such as non-negative integers.

    counting_sort is a function that takes two parameters: an array of integers (array) and the size of the array (size).

    The function begins with checks to ensure that the input array is not NULL and that it has at least two elements. If not, it returns early since there's no need to sort such an array.

    The function finds the maximum value in the input array (max_value) and determines the range of values to be sorted. This is crucial for the counting sort algorithm since it relies on counting the occurrences of each value in a specific range.

    It dynamically allocates memory for two additional arrays: counting and copy. counting is used to store the counts of each value in the input array, while copy is used to create a copy of the input array.

    The next steps involve initializing and populating the counting array:
        The function initializes all elements in the counting array to 0 to prepare for counting.
        It then iterates through the input array and increments the count in the counting array for each value encountered. This step counts the occurrences of each value in the input array.

    The print_array function is called to display the state of the counting array after counting the occurrences of each value.

    After counting the occurrences, the function modifies the counting array to store the cumulative counts of values. This is done by adding each count to the previous count. This step prepares the counting array for the placement of elements in the sorted order.

    The function now initializes a temporary variable temp and iterates through the copy of the input array (copy). It uses the values in the counting array to determine the correct position of each element in the array such that the array becomes sorted in ascending order. The temp variable holds the value from the copy array, and counting[temp] determines where this value should be placed in the array.

    The counting value for the current temp is decremented, ensuring that if there are duplicate values, they are correctly placed in the sorted array.

    Finally, the memory allocated for the counting and copy arrays is freed to prevent memory leaks.

