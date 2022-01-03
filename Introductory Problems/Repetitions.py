from itertools import groupby
a=[len(list(g)) for k,g in groupby(input())]
ans=max(a)
print(ans)
