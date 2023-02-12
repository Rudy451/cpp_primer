inline int swap_stuff(int *first, int *second){
	int temp = *first;
	*first = *second;
	*second = temp;
	return 0;
}
