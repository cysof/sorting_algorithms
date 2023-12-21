#ifndef SORT_H_
#define SORT_H_

#include <stdio.h>
#include <stdlib.h>

/* Data Structure for Doubly Linked List */

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Function Prototypes */
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void swap(int *a, int *b);
int lomuto_partition(int *array, int low, int high, size_t size);
void quick_sort_recursive(int *array, int low, int high, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_nodes(listint_t **list, listint_t *a, listint_t *b);
void counting_sort(int *array, size_t size);
void print_parts(int *array, size_t min, size_t max);
void top_down(int *A, int *B, size_t min, size_t mid, size_t max);
void top_down_split(int *A, int *B, size_t min, size_t max);
void merge_sort(int *array, size_t size);
void heapify(int *array, size_t size, size_t index, size_t size_original);
void heap_sort(int *array, size_t size);
int get_max(int *array, size_t size);
void count_sort(int *array, size_t size, int pow);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void bitonic_sort_recursive(int *array, size_t size, size_t low, size_t dir);
void bitonic_compare(int *array, size_t size, size_t low, size_t dir);
void quick_sort_hoare(int *array, size_t size);
void quicksort(int *array, int low, int high, size_t size);
int hoare_partition(int *array, size_t low, size_t high, size_t size);

#endif /*SORT_H_*/
