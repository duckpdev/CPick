import ctypes

def pick(choices: list, title: str, index: int) -> int:
    choices = [bytes(choice, 'utf-8') for choice in choices]
    title = bytes(title, 'utf-8')
    return lib.Pick((ctypes.c_char_p * len(choices))(*choices), title, index)



title = "       Example title"

options = ["\0"] + open('testdisk.log','r+').readlines() + ["\0"]

lib = ctypes.CDLL('./libpath.so') # Insert path to so lib 

lib.InitDefault()

result = pick(options,title,1)

print(result)