QuickSort

    The Quick Sort algorithm divides the array into smaller partitions using the Lomuto partition scheme, and then recursively sorts each partition. The use of the swap function and printing the array at each step allows for visualization of the sorting process. This results in an efficient and in-place sorting algorithm.

    Using helper functions seem to be the reasonable way to go about it. For readability and a better visual code flow:

    swap function:
        swap is a helper function that takes two integer pointers, a and b, and swaps the values they point to. Used it for swapping elements in the array.

    lomuto_partition function:
        lomuto_partition takes four parameters: array, low, high, and size. It partitions the array using the Lomuto partition scheme and returns the index of the pivot element.
        low and high are the indices specifying the range of the array to be partitioned.
        The function selects the pivot element as the last element in the given range (i.e., array[high]).
        It initializes i to low - 1, which represents the index where elements less than the pivot will be placed.
        A loop iterates from low to high - 1 (inclusive) to compare each element with the pivot.
        If an element is less than the pivot, it is swapped with the element at index i + 1, and i is incremented.
        After each swap, the array is printed to visualize the partitioning process.
        Finally, the pivot is swapped with the element at index i + 1, placing the pivot in its correct position within the partition. The function returns the index i + 1 as the new pivot index.

    quick_sort_recursive function:
        quick_sort_recursive is a recursive function that sorts the array using the quicksort algorithm.
        It takes four parameters: array, low, high, and size. low and high specify the range of the array to be sorted.
        Inside this function, it first checks if low is less than high, which ensures that there is more than one element in the range to be sorted.
        It calls lomuto_partition to partition the array and retrieve the pivot index.
        Then, it recursively sorts the subarrays on both sides of the pivot index: the elements before the pivot and the elements after the pivot.

    quick_sort function:
        quick_sort is the main entry point for the quicksort algorithm.
        It takes two parameters: array and size.
        It checks if the input array is NULL or if the size is less than 2 (no sorting needed for 0 or 1 element), and if so, it returns early.
        Otherwise, it calls the quick_sort_recursive function to start the sorting process from the entire array.

    int lomuto_partition(int *array, int low, int high, size_t size)
    {
    	int pivot = array[high];
    	int j, i = low - 1;
    	size_t k;

    	for (j = low; j <= high - 1; j++)
    	{
    		if (array[j] < pivot)
    		{
    			i++;
    			swap(&array[i], &array[j]);
    			for (k = 0; k < size; k++)
    			{
    				printf("%d", array[k]);
    				if (k < size - 1)
    				{
    					printf(", ");
    				}
    			}
    			printf("\n");
    		}
    	}

    	swap(&array[i + 1], &array[high]);
    	for (k = 0; k < size; k++)
    	{
    		printf("%d", array[k]);
    		if (k < size - 1)
    		{
    			printf(", ");
    		}
    	}
    	printf("\n");

    	return (i + 1);
    }

    So I had to refactor the code cuz I was getting some red checks. Now I see that my lomuto partition function had some unnecessary loop implementation and I sort of printed out the array by "hand" when I could have used the default print_array.c function. Plus some other things sha.
    The previous version, I considered only if array[j] < pivot instead of the condition array[j] <= pivot that should be used to determine whether an element is less than or equal to the pivot, and it triggers swaps when needed.
        Note to self: for loops should not always be the go-to.🤥😇
    And now, I've added another check for when performing a swap, there's an additional check if (i != j) to ensure that an unnecessary swap is avoided if i and j are already pointing to the same position.
    The partitioning process now works with both greater-than and less-than comparisons, enhancing its stability. (For reference the previous lomuto_partion code is included in this markdown.)
    So....

    lomuto_partition function: modified
        lomuto_partition takes four parameters: array, low, high, and size. It partitions the array using the Lomuto partition scheme and returns the index of the pivot element.
        low and high are the indices specifying the range of the array to be partitioned.
        The function selects the pivot element as the last element in the given range (i.e., array[high]).
        It initializes two indices, i and j, with i pointing to one position before the low index.
        The partitioning process is performed using a single loop, which goes from low to high-1 (inclusive).
        Within the loop:
            If the current element (array[j]) is less than or equal to the pivot element, it performs the following actions:
                Increments i to move it one step to the right.
                If i is different from j, it swaps the elements at positions i and j and prints the array to visualize the swap.
            Increments j to continue scanning through the array.
        After the loop, the pivot element is swapped with the element at index i + 1, placing the pivot in its correct position.
        The function returns i + 1 as the new pivot index.

