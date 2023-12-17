Heap Sort

    Heap Sort is an efficient, in-place, comparison-based sorting algorithm that achieves the best-case, average-case, and worst-case time complexity of O(n log n) for a given array of n elements. It uses a binary heap data structure to maintain the max heap property while sorting the array in ascending order.

    swap function:
        This function is used to swap two integers in an array. It takes two pointers, a and b, as input and swaps the values at those positions.

    heapify function:
        The heapify function rearranges elements in the array to create a max heap, starting from a specific index.
        It takes four parameters: array (the array to be heapified), size (the size of the array), index (the index to start the heapify process), and size_original (the original size of the array for printing purposes).
        The function calculates the left and right child indices based on the given size_original. It also initializes largest to the size_original.
        It then compares the values of the left and right children with the value at the largest index and updates largest if necessary. This step ensures that the largest element is at the root of the sub-heap.
        If largest is not equal to size_original, it means that the root value has changed, so a swap is performed between the values at size_original and largest.
        After the swap, the heapify function is called recursively to continue the heapify process with the subtree rooted at the new largest position.

    heap_sort function:
        This is the main entry point for the Heap Sort algorithm. It takes two parameters: array (the array to be sorted) and size (the size of the array).
        It starts by checking if the input array is NULL or has fewer than 2 elements. If either condition is met, it returns early since there is no need to sort such an array.
        The first phase of Heap Sort involves building a max heap from the array. This is done by iterating from the last parent node (which is at index size / 2 - 1) to the root of the heap. For each parent node, the heapify function is called to ensure that the max heap property is maintained. This phase rearranges the elements to ensure the largest element is at the root of the heap.
        The second phase of Heap Sort is the actual sorting process. It involves repeatedly swapping the root element (the largest in the max heap) with the last unsorted element and then calling heapify to restore the max heap property. This phase starts with the last element and moves toward the beginning of the array. After each swap, the print_array function is called to display the current state of the array.

