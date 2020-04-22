#include"item.h"
#include"song.h"

void input_item(item *x){
    input_item_struct(x);
}

void output_item(item x){
    output_item_struct(x);
} 

int compare_item(item x1,item x2){
    return compare_struct(x1,x2);
}