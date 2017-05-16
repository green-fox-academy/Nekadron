#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int is_anagram(char* b, char* c){
 int i;
 int j;
 int tmp;
 for(i = 0; i < strlen (b); i++){
    for(j = i + 1; i < strlen(b); ++j){
        if(b[i] > b[j]){
            tmp = b[i];
            b[i] = b[j];
            b[j] = tmp;
              }
            }
         }
     for(i = 0; i < strlen(c); i++){
         for(j = i + 1; i < strlen(b); ++j){
             if(c[i] > c[j]){
                tmp = c[i];
                c[i] = c[j];
                c[j] = tmp;
              }
            }
         }
      for(i = 0; i < strlen(b); i++){
        if(b[i] != c[i]){

        return 0;
        }
      }
      return 1;
}



int main()
{

    char b[] = "greenfox";

    char c[] = "xofenerg";
if(is_anagram(b, c)){

    printf("Anagram");
}
    else{
        printf("notanagram");
    }

    return 0;
}

