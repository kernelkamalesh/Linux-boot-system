#include "strchr.h"

char *strchr(const char *str, char ch){
    int i;
    for(i = 0; str[i]; i++){
        if(str[i]== ch){
            return &str[i];
        }
    
    }
    return 0;
}