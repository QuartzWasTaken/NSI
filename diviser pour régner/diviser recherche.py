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

def rechercheDichotomique(liste, valeur, g, d): 
    # Condition d'arrêt
    if len(liste[g:d+1]) == 1:
        
        if liste[g:d+1][0] == valeur:
            return g
        
        else:
            return None

    # Recursivité
    else:
        # Test moitié droite
        if liste[(d+g)//2] >= valeur:
            if rechercheTriee(liste, valeur, g, (d+g)//2) != None:
                return rechercheTriee(liste, valeur, g, (d+g)//2)
        # Test moitié gauche
        if liste[(d+g+2)//2] <= valeur:
            if rechercheTriee(liste, valeur, (d+g+2)//2, d) != None:
                return rechercheTriee(liste, valeur, (d+g+2)//2, d)
        # Si tous les tests ont raté, la valeur n'est pas dans la liste
        else:
            return None
        
print(rechercheGD(liste, 1, 0, len(liste)-1))