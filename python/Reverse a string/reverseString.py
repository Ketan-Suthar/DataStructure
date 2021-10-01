def recursiveReverse(str):
    stack = []
    for i in range(len(str)):
        stack.append(str[i])
     
    for i in range(len(str)):
        str[i] = stack.pop()
 
if __name__ == "__main__":
    str = "HelloWorld"
    str = list(str)
    recursiveReverse(str)
    str = ''.join(str)
    print(str)