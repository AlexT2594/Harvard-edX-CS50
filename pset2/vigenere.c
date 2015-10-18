#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(int argc,string argv[]){
    if(argc != 2){
        printf("You inserted none or too many arguments!\n");
        return 1; //error because user inserted none or too many arguments
    }
    string keyword = argv[1];
    int i = 0;
    while(keyword[i]!='\0'){
        if(!isalpha(keyword[i])){
            printf("You entered a non alphabetical keyword!!!\n");
            return 1; //error because user inserted a non alphabetical keyword
        }
        i++;
    }
    int n = strlen(keyword);
    string text = GetString();
    i = 0; //sets the iterator back to 0
    int kcounter = 0; //creates the keyword counter variable
    char new; //variable that will contain the new character
    char key; //key variable
    while(text[i]!='\0'){
        if(isalpha(text[i])){
            if(isupper(text[i])){
                new = text[i] - 65; //convert from ASCII value to alphabetical index
                key = toupper(keyword[kcounter % n]) - 65; //creates the key
                new = ( new + key ) % 26;
                new = new + 65; //back to ASCII value
                kcounter++;
                printf("%c",new);
            }else{
                new = text[i] - 97;
                key = toupper(keyword[kcounter % n]) - 65;
                new = (new + key) % 26;
                new = new + 97;
                kcounter++;
                printf("%c",new);
            }
        }else{
            printf("%c",text[i]);
        }
        i++;
    }
    printf("\n");

    return 0;
}
