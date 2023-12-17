Radix Sort

    Radix Sort is a non-comparative sorting algorithm that works by sorting integers based on their individual digits or place values. It sorts the array from the least significant digit to the most significant digit, producing a sorted array at the end of the process. The algorithm is generally efficient for sorting non-negative integers and has a time complexity of O(k * n), where k is the number of digits in the maximum element.

    get_max function:
        This function is used to find the maximum value in the input array. It iterates through the array and keeps track of the maximum value found.

    count_sort function:
        The count_sort function is a component of the Radix Sort algorithm and is used for sorting integers based on a specific digit (power of 10).
        It takes three parameters: array (the array to be sorted), size (the size of the array), and pow (the power of 10 representing the digit to be considered during sorting).
        The function begins by creating a temporary array copy to hold the sorted values.
        It initializes an array called counting with 10 elements, each representing a digit (0 to 9). These elements will be used to count the occurrences of each digit at the specified place value (i.e., the pow digit).
        The function then iterates through the input array, incrementing the count in the counting array corresponding to the digit at the pow position in each element.
        Next, the function adjusts the counting array to represent the cumulative count of elements for each digit. This step ensures that elements with the same digit are correctly placed in the sorted order.
        The function then iterates through the input array in reverse order (from the end towards the beginning). For each element, it calculates the digit at the pow position and uses the counting array to determine the correct position of the element in the copy array.
        After processing all elements, the function copies the sorted values from the copy array back to the original input array.

    radix_sort function:
        This is the main entry point for the Radix Sort algorithm. It takes two parameters: array (the array to be sorted) and size (the size of the array).
        The function starts by checking if the input array is NULL or has fewer than 2 elements. If either condition is met, it returns early since there is no need to sort such an array.
        The function initializes pow to 1 and calculates the maximum value in the array using the get_max function.
        The Radix Sort algorithm involves sorting the array based on each digit (from the least significant to the most significant) using the count_sort function. This process is repeated while increasing the value of pow by a factor of 10 in each iteration.
        After each pass through the array, the print_array function is called to display the current state of the array.

