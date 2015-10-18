#include <stdio.h>
#include <cs50.h>
#include <ctype.h>

int main(){
    string s = GetString();
    printf("%c",toupper(s[0]));
    int i = 1;
    while(s[i+1]!='\0'){
        if(s[i]==' '){
            printf("%c",toupper(s[i+1]));
        }
        i++;
    }
    printf("\n");

    return 0;
}
