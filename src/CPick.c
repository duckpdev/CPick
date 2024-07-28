#include "CPick.h"


char GetKey(int a){
    int ch;
    for(int i=0;i < a; i++)
        #ifdef _WIN32
            ch = _getch();
        #else
            system("stty raw -echo");
            ch = getchar();
            system("stty cooked echo");
        #endif

    return ch;
}

int limi = 0;

void clear() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}


char GetKeyChar(){
    int ch;
    #ifdef _WIN32
        ch = _getch();
    #else
        system("stty raw -echo");
        ch = getchar();
        system("stty cooked echo");
    #endif
    return ch;
}

const char* cursor;
const char* space;

int GetArrow(){
    int c = GetKey(1);
    if(c == Enter){
        return Enter;
    }
    c = GetKeyChar();c = GetKeyChar();
    switch(c) {
        case 65:
            return KeyUP;
            break;
        case 66:
            return KeyDown;
            break;
        case 67:
            return KeyRight;
            break;
        case 68:
            return KeyLeft;
            break;
        case Enter:
            return Enter;
            break;
        default:
            break;
    }
    switch(c) {
        case WinUp:
            return KeyUP;
            break;
        case WinDown:
            return KeyDown;
            break;
        case WinRight:
            return KeyRight;
            break;
        case WinLeft:
            return KeyLeft;
            break;
        default:
            break;
    }
    return 0;
}

int getSize(void* arr){
    return sizeof(arr) / sizeof(arr[0]);
}

int GetSizeTwo(const char** arr){
    int size = 0;
    for(int i = 0;i < arr; i++){
        if(arr[i] != '\0'){
            size++;
        }
        else{
            return size;
        }
    }
    return size;
}

int newline = 1;

void display(const char** options, const char* title, int size, int indx) {
    int index = indx;
    printf(title); printf("\n\n");

    int height = getConsoleHeight() - 3;
    int start_index = index - height / 2;
    int end_index = start_index + height - 1;

    if (start_index < 0) {
        start_index = 0;
        end_index = height - 1;
    }
    if (end_index >= size) {
        end_index = size - 1;
        start_index = end_index - height + 1;
    }

    for (int i = start_index; i <= end_index; i++) {
        if (i == index) {
            printf(cursor);
        } else {
            printf(space);
        }
        if (i >= 0 && i < size) {
            if(newline == 0)
                if(limi==false){
                    printf(options[i]);
                }
                else{
                    printf("%.*s", limi, options[i]);
                }
            else{
                if(limi==false){
                    printf(options[i]);printf("\n");
                }
                else{
                    printf("%.*s\n", limi, options[i]);
                }
            }
        }
        
    }
}


void InitDefault(){
    cursor = "=>  ";
    space  = "    ";
    limi = false;
    newline = 1;
}




void SetConfig(const char* a, const char* b, int limit,int newlin){
    cursor = a;
    space = b;
    limi = limit;
    newline = newlin;
}

int Pick(const char** options,const char* title,int indx){
    int index = indx;
    int size = GetSizeTwo(options) - 1;
    printf("%d \n", size);
    while(true){
        int code;
        clear();
        display(options,title,size,index);
        code = GetArrow();
        
        
        if(code == KeyUP){
            if(index != 1){
                index = index - 1;
            }
        }
        else if(code == KeyDown) {
            if(index != size - 1){
                index = index + 1;
            }
            
        }
        else if(code == Enter){
            return index;
        }
    }
    return index ;
}