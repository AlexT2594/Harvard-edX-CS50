#include <stdio.h>
#include <cs50.h>

int main(){
    int h;
    while(1){
        printf("Height:");
        h = GetInt();
        if(h>-1 && h<24){
            break;
        }
    }
    int i, tag , space;
    int height = h;
    for(i=0;i<height;i++,h--){
        for(space = 0;space<h-1;space++){
            printf(" ");
        }
        for(tag=0;tag<i+2;tag++){
            printf("#");
        }
        printf("\n");
    }
    return 0;
}
