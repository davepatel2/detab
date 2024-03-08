#include <stdio.h>
#define TABLENGTH 8

int main(int argc, char *argv[]){
    int currentchar = getchar(); 
    int count = 0;
    int linecount = 0;
    int manyspace = 0; 
    
    while (currentchar != EOF){
        if (currentchar == '\t'){
            manyspace = TABLENGTH - (count % TABLENGTH);
            while(manyspace > 0){
                putchar(' ');
                manyspace--; 
                linecount++;
            }
            count = 0;
            currentchar = getchar();
            continue;
        }
        if (currentchar == '\n' || currentchar == '\r'){
            count = 0;
            linecount = 0; 
            putchar(currentchar);
            currentchar = getchar();
            continue;
        }
        if(currentchar == '\b'){
            if(count == 0){
                count = 7; 
            }else{
                count--;
            }
            if(linecount <= 0){
                count = 0;
            }
            linecount--;
            putchar(currentchar);
            currentchar = getchar();
            continue;
        }
        putchar(currentchar);
        linecount++;
        count++;
        currentchar = getchar();
        
    }

    return 0;
}