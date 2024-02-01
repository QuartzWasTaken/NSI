def maxi(liste):
    
    # CONDITION D'ARRÊT
    
    if(len(liste) == 1): # Si il reste 1 élément, c'est forcément le max
        return liste[0]
    
    elif(len(liste) == 2): # Si il en reste 2, prendre le max de ces deux éléments
        if(liste[0] > liste[1]):
            return liste[0]
        return liste[1]
    
    
    # RETURN
    maxG = maxi(liste[len(liste)//2:]) # Construire le maximum gauche et droite (moitié gauche & droite de la liste)
    maxD = maxi(liste[:len(liste)//2])
    
    if(maxG < maxD): # Déterminer la valeur à renvoyer
        return maxD
    return maxG
        
def mini(liste):
    
    # CONDITION D'ARRÊT
    
    if(len(liste) == 1): # Si il reste 1 élément, c'est forcément le min
        return liste[0]
    
    elif(len(liste) == 2): # Si il en reste 2, prendre le min de ces deux éléments
        if(liste[0] > liste[1]):
            return liste[1]
        return liste[0]
    
    
    # RETURN
    minG = mini(liste[len(liste)//2:]) # Construire le minimum gauche et droite (moitié gauche & droite de la liste)
    minD = mini(liste[:len(liste)//2])
    
    if(minG < minD): # Déterminer la valeur à renvoyer
        return minG
    return minD

def min_max(liste):
    min = mini(liste)
    max = maxi(liste)
    return (min, max)