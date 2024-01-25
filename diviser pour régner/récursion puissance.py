from time import time
def puissance(x, n):
    if(n == 0):
        return 1
    return x * puissance(x, n-1)

tDebutD = time()
for i in range(20000):
    puissance(2, 1000)
tFinD = time()

print("temps récursif : ", tFinD - tDebutD)