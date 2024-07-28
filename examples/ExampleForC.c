#include "CPick.h"

int main(){
    const char* options[128] = {"\0","Test","Default","..","Exit","No","Yes","q","w","d","a","s",",","m","n","b","v","c","x","a","z","\0"}; // add \0 to end and start for correct program work
    InitDefault();
    int i = Pick(options,"       Example title",1);
    printf("%d",i);
    printf("\n");
    printf(options[i]);
    printf("\n");
}