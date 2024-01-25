#|-------------------------------------------|
#|                                           |
#|     MON CODE A MOI, PERSONNE D'AUTRE      |
#|                                           |
#|-------------------------------------------|


liste = [0, 1, 2, 3, 4, 5, 6, 7, 8]

def recherche(liste, n):
    # Si la liste est vide, le nombre n'est pas dedans
    if(len(liste) == 0):
        return False
    
    # Si il ne reste qu'un élément, tester si c'est celui qu'on cherche
    elif(len(liste) == 1):
        if(liste[0] == n):
            return True
        return False
    
    # Couper la liste en deux et exécuter la fonction sur les deux moitiés de la liste
    if(recherche(liste[:len(liste)//2:], n) or recherche(liste[len(liste)//2::], n)):
        return True
    
    # Si le code arrive jusqu'ici, le nombre n'est pas dedans
    return False

def rechercheGD(liste, n, g, d):
        # Si la liste est vide, le nombre n'est pas dedans
    if(len(liste) == 0):
        return False
    
    # Si il ne reste qu'un élément, tester si c'est celui qu'on cherche
    elif(len(liste) == 1):
        if(liste[0] == n):
            return g
        return False

    
    # Si le code arrive jusqu'ici, le nombre n'est pas dedans
    return False

#print(recherche(liste, 3))
print(rechercheGD(liste, 1, 0, len(liste)-1))

le push a marché