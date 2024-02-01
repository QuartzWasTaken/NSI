from maximini import *

tup1 = (10, 45)
tup2 = (7, 12)


def fusion(tupleD, tupleG):
    max = maxi( (maxi(tup1), maxi(tup2)) )
    min = mini( (mini(tup1), mini(tup2)) )
    return (min, max)

    
    
print(fusion(tup1, tup2))