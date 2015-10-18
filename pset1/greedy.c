#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(){
    float change;
    while(1){
        printf("O hai! How much change is owed?\n");
        change = GetFloat();
        if(change>=0){
            break;
        }
    }
    int coins = 0;
    double d = (double)change;
    d = round(d * 100);
    int c = (int)d;
    while(c!=0){
        if(c>=25){
            c -=25;
            coins++;
        }else if(c>=10){
            c -=10;
            coins++;
        }else if(c>=5){
            c -=5;
            coins++;
        }else{
            c -=1;
            coins++;
        }
    }
    printf("%d\n",coins);
    return 0;
}
