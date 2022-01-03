from itertools import permutations,combinations,combinations_with_replacement

string=input()
stringList=list(string)
#print("stringList :- ",stringList)
seq = sorted(list(set(list(permutations(stringList)))))
print(len(seq))
#s =set()
for p in seq:
    #print(p)
    print(''.join(list(p)))
    #s.add(''.join(list(p)))
#print(len(s))
