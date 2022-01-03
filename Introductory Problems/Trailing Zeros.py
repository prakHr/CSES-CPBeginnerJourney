mod = 1000000007
n=int(input())
# because 2 is smaller than 5
# we have to find x in 2^x*5^y
# if n=28 then ans = n/5+n/25
ans= 0
while n!=0:
    n=n//5
    ans+=n

print(ans)
