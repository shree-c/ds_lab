all:
	cc binary_search_tree.c -o binary_search_tree.bin
	cc binary_tree_traversal.c -o binary_tree_traversal.bin
	cc bin_search.c -o bin_search.bin
	cc bubblesort.c -o bubblesort.bin
	cc circular_simple_queue.c -o circular_simple_queue.bin
	cc double_ended_queue.c -o double_ended_queue.bin
	cc doubly_linked_list.c -o doubly_linked_list.bin
	cc emp_data.c -o emp_data.bin
	cc friends_party.c -o friends_party.bin
	cc hanoi.c -o hanoi.bin
	cc infix_to_postfix.c -o infix_to_postfix.bin
	cc infix_to_prefix.c -o infix_to_prefix.bin
	cc linked_list.c -o linked_list.bin
	cc mergesort.c -o mergesort.bin
	cc priority_queue.c -o priority_queue.bin
	cc queue.c -o queue.bin
	cc quicksort.c -o quicksort.bin
	cc stack.c -o stack.bin
	cc stringlen.c -o stringlen.bin
	cc ./easy_infix_to_prefix.c -o easy_inf_pre.bin
	cc ./easy_infix_to_postfix.c -o easy_inf_pos.bin

clean:
	rm *.bin
