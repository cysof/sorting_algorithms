Merge Sort

    Merge Sort is a divide-and-conquer sorting algorithm that works by repeatedly dividing the array into smaller subarrays, sorting those subarrays, and then merging them back together. The algorithm's efficiency and stability make it a popular choice for sorting.

    print_parts function:
        This function is used to print a portion of the array, specified by the min and max indices. It prints the elements between these indices, separated by commas.

    top_down function:
        This function performs the merging step of the Merge Sort algorithm using a top-down approach.
        It takes four parameters: A, B, min, mid, and max. A is the original array, B is a temporary array used for merging, and min, mid, and max represent the indices that define the left and right subarrays to be merged.
        The function starts by printing a message to indicate that a merge is happening and displays the left and right subarrays with the print_parts function.
        Two pointers, i and j, are used to iterate through the left and right subarrays, respectively.
        The function then compares elements at the i and j positions in the subarrays and selects the smaller element to place in the merged array. It updates the i or j pointer accordingly.
        The merged elements are stored in the B array.
        After the merge is complete, the function prints the merged portion with the message "[Done]" and updates the corresponding portion in the original array A.

    top_down_split function:
        This function is responsible for splitting the array and initiating the merging process.
        It takes four parameters: A, B, min, and max. A is the original array, B is the temporary array, and min and max represent the range of the array to be split and merged.
        The function first checks if the range has less than 2 elements (base case for recursion). If the range has 1 or 0 elements, it returns without any further action.
        If there are more than 1 element in the range, it calculates the mid index as the average of min and max.
        The function then recursively splits and merges the left and right subarrays by calling itself with the appropriate parameters.
        After splitting, it calls the top_down function to merge the subarrays.

    merge_sort function:
        This is the main entry point for the Merge Sort algorithm. It takes two parameters: array (the array to be sorted) and size (the size of the array).
        It starts by checking if the input array is NULL or has fewer than 2 elements. If either condition is met, it returns without attempting to sort the array.
        A new temporary array newlist is created with the same size as the input array using dynamic memory allocation.
        The function then calls top_down_split to initiate the merge sort process. Once the sorting is complete, it frees the memory allocated for the temporary array.

