def printArr(arr):
    for i in range(len(arr)):
        print(arr[i])
grayCode=['0','1']
n=int(input())
if n==1:
    printArr(grayCode)
else:
    for i in range(2,n+1):
        grayCode+=['1' + '0'*(i-1-len(x))+x for x in grayCode[::-1]]
    numCode = [int(x,2) for x in grayCode]
    binaryCode=[bin(int(i))[2:].zfill(n) for i in numCode]
    printArr(binaryCode)
