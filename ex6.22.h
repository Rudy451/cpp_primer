int switch_values(int* value_1, int *value_2){

        int value_3 = *value_2;
        *value_2 = *value_1;
        *value_1 = value_3;
        return 0;

}

