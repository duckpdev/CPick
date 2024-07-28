# CPick

### CPick - this is a library which can create console select menu
### This library is written by C, but can used in python

## Build

### Build for python: 
```sh
gcc -shared -o libpath.so -fPIC src/CPick.c
```

### For C you can just include it with
```c
#include "CPick.h"
```

## Syntax:

### Pick syntax

```c
int ResultIndex = Pick(ARRAYWITHOPTIONS, TITLE, StartCursor);
```

### InitDefault (Init default cursor and space)

```c
InitDefault();
```

### SetConfig (Set cursor, space, limit in width and isneedcreatenewline). Leave limit 0 if you don`t need limit
```c
SetConfig(CURSOR,SPACE,LIMIT,ISNEEDTONEWLINE);
```

### Example
```c
SetConfig("=>  ","    ",80,1);
```


## Examples:

### Simple C example
```c
#include "CPick.h"

int main(){
    const char* options[128] = {"\0","Test\n","Default\n","..\n","Exit","No","Yes","q","w","d","a","s",",","m","n","b","v","c","x","a","z","\0"};
    InitDefault();
    int i = Pick(options,"       Example title",1);
    printf("%d",i);
    printf("\n");
    printf(options[i]);
    printf("\n");
}
```

### Simple Python example
```python
import ctypes

def pick(choices: list, title: str, index: int) -> int:
    choices = [bytes(choice, 'utf-8') for choice in choices]
    title = bytes(title, 'utf-8')
    return lib.Pick((ctypes.c_char_p * len(choices))(*choices), title, index)



title = "       Example title"

options = ["\0",'Test',"Quack","\0"]

lib = ctypes.CDLL('./libpath.so') # Insert path to .so lib 

lib.InitDefault()

result = pick(options,title,1)

print(result)
```
## Notes

### You need to mark the beginning and end of the array with "\0"

##### Enjoy
