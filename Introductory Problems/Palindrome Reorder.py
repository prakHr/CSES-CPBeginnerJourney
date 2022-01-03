from collections import Counter
my_dict = dict(Counter(input()))
oddCnt=0
oddNum,evenNum=[],[]
for k,v in my_dict.items():
    if v%2==1:
        oddNum.append(k*v)
        oddCnt+=1
    else:
        evenNum.append(k*v)
if oddCnt>1:
    #print(oddNum)
    print("NO SOLUTION")
else:
    ans=''
    n=len(evenNum)
    for i in range(n):
        evenString = evenNum[i]
        l = len(evenString)
        ans+=evenString[:l//2]
    for i in range(len(oddNum)):
        ans+=oddNum[i]
    for i in range(n):
        evenString = evenNum[n-i-1]
        l = len(evenString)
        ans+=evenString[:l//2]
    print(ans)

        
