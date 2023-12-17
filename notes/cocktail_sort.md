Cocktail Shaker Sort

    The Cocktail Shaker Sort, also known as the Bidirectional Bubble Sort or Shaker Sort, is a variation of the Bubble Sort algorithm. It sorts the list by comparing and swapping adjacent elements in both directions (from left to right and from right to left) to ensure that the largest and smallest elements "bubble" to their correct positions in each pass. This process continues until the list is sorted, and it is generally more efficient than standard Bubble Sort.

    cocktail_sort_list is a function that takes a double pointer to a linked list, listint_t **list, as its parameter. The double pointer is used because the function may need to modify the head of the linked list if elements are swapped.

    The function begins with several checks to ensure the input list is valid and not empty. If list is NULL, or the list is empty (i.e., *list is NULL), or the list has only one element (i.e., (*list)->next is NULL), the function returns early because there is nothing to sort.

    The main sorting logic is executed using a loop. The algorithm continues until no more swaps are made, indicating that the list is fully sorted.

    The loop is structured as follows:
        It initializes a variable swapped to 1, which will be used to check whether any swaps were made during the loop.
        The loop first iterates through the list from the beginning to the end. In this phase, it compares adjacent elements, and if the current element (current) is greater than the next element (current->next), a swap is performed. The function swap_nodes is called to swap the nodes, and swapped is set to 1 to indicate that a swap was made. The print_list function is called to print the state of the list after each swap.

    After one pass from the beginning to the end of the list, if no swaps were made (swapped is still 0), it means that the list is already sorted. In this case, the algorithm breaks out of the loop.

    The algorithm then proceeds in the opposite direction:
        It resets swapped to 0.
        It iterates through the list from the end to the beginning. In this phase, it compares adjacent elements, and if the current element (current) is smaller than the previous element (current->prev), a swap is performed. The function swap_nodes is called to swap the nodes, and swapped is set to 1 to indicate that a swap was made. The print_list function is called to print the state of the list after each swap.

    After a pass from the end to the beginning of the list, if no swaps were made (swapped is still 0), it means that the list is already sorted. In this case, the algorithm breaks out of the loop.

    The loop continues alternating between these two phases (from beginning to end and from end to beginning) until no swaps are made in both phases, indicating that the list is fully sorted.

    The swap_nodes function is used to swap two nodes in a doubly linked list. It takes three parameters: list (a pointer to the head of the list), a (the first node to be swapped), and b (the second node to be swapped). The function correctly updates the previous and next pointers of the nodes being swapped.

