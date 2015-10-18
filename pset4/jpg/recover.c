/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef uint8_t  BYTE;

int main(int argc, char* argv[])
{
    if(argc!=1){
        printf("Usage:./recover\n");
        return 1;
    }
    
    BYTE bytes[512];
    BYTE control[4];
    BYTE jpg1[4] = {0xff, 0xd8, 0xff, 0xe0};
    BYTE jpg2[4] = {0xff, 0xd8, 0xff, 0xe1};
    
    FILE* file = fopen("card.raw","r");
    FILE* img;
    
    int count = 0;
    int open = 0;
    char title[8];
     
    while(fread(bytes,sizeof(bytes),1,file) != 0){
        for(int i = 0; i < 4; i++){
            control[i] = bytes[i];
        }
		
		if((memcmp(jpg1, control, 4) == 0 ) || (memcmp(jpg2, control, 4) == 0)){	
            
            sprintf(title,"%03d.jpg",count);
            
            if(open == 0){
                img = fopen(title,"w");
                fwrite(bytes,sizeof(bytes),1,img);
                open = 1;
            }
            if(open == 1){
                fclose(img);
                img = fopen(title,"w");
                fwrite(bytes,sizeof(bytes),1,img);
                count++;
            }
        }else{
            if(open == 1){
                fwrite(bytes,sizeof(bytes),1,img);
            }
        }
    
    }
    if(img){
        fclose(img);
    }
    fclose(file);
    
    return 0;
}
