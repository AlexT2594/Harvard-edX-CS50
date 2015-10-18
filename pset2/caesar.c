#include <stdio.h> //to use printf
#include <stdlib.h> //to use atoi
#include <cs50.h> //to use GetString
#include <ctype.h> //to use isalpha and isupper

int main(int argc,string argv[]){
    if(argc != 2){
        printf("You inserted none or too many arguments!\n");
        return 1; //error because user inserted none or too many arguments
    }
    int k = atoi(argv[1]); //convert string argument to int
    string text = GetString();
    int i = 0; //create my iteration variable
    char new; //create a variable that I'm going to use later
    while(text[i]!='\0'){  //iterates until string is finished
        if(isalpha(text[i])){
            if(isupper(text[i])){
                new = text[i] - 65; //convert from ASCII value to alphabetical index
                new = ( new + k ) % 26; //cyphers it
                new = new + 65; //back to ASCII value
                printf("%c",new);
            }else{ //it's a lower case
                new = text[i] - 97; //same but with lower case letters
                new = ( new + k ) % 26;
                new = new + 97;
                printf("%c",new);
            }
        }else{ //if not alphabetical
            printf("%c",text[i]);
        }
        i++;
    }
    printf("\n");

    return 0;
}
