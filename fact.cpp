#include <iostream>
#include "Chapter6.h"

int fact(int val){
        if(val == 1){
                return val;
        }
        else{
                val *= fact(val - 1);
        }
}
