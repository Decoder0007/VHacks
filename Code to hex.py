import pyperclip
import time

while True:
    data = input("Enter Data:  ")
    spaces=1
    for i in range(0,len(data)):
      if(data[i]==' '):
        spaces=spaces+1

    dataconv = data.replace(" ", "\\x")

    print(r"Code:  \x" + dataconv + "\nBytes:  "+str(spaces)+"\nCode copied to clipboard")

    pyperclip.copy(r"\x"+dataconv)
    
