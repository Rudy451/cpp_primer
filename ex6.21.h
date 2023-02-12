int compare_values(const int *value_1, int value_2){
	int result = ((*(value_1) > value_2) ? *(value_1) : value_2);
	return result;
}
