import sys
from time import *
sys.setrecursionlimit(10000)
sys.set_int_max_str_digits(100000)

def puissanceD(x, n):
    if(n == 0):
        return 1
    if(n%2 == 0):
        return puissanceD(x, n//2)**2
    return puissanceD(x,(n-1)//2)**2*x

def puissanceR(x, n):
    if(n == 0):
        return 1
 
    return x * puissanceR(x, n-1)

tDebutR = time()
for i in range(5000):
    puissanceR(2, 2000)
tFinR = time()

tDebutD = time()
for i in range(5000):
    puissanceD(2, 2000)
tFinD = time()

print("temps divisé : ", tFinD - tDebutD)
print("temps récursif : ", tFinR - tDebutR)
print("différence de temps : ",abs((tFinD - tDebutD) - (tFinR - tDebutR)))
print("division : ", (tFinR - tDebutR) / (tFinD - tDebutD) ) # Temps total R / Temps total D