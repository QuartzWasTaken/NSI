def fusionner(listeGauche, listeDroite):
    iG = 0
    iD = 0
    
    listeR = list()
    
    while(iG != len(listeGauche) and iD != len(listeDroite)):
        
        if(listeGauche[iG] <= listeDroite[iD]): # Si la liste 1 est plus grande, ajouter a la listeR
            listeR.append(listeGauche[iG])
            iG+=1
        else:
            listeR.append(listeDroite[iD])
            iD+=1
    
    if(iG == len(listeGauche)): # Si la liste gauche a fini en premier, ajouter la fin de la liste droite
        listeR.extend(listeDroite[iD:])
            
    if(iD == len(listeDroite)): # Si la liste droit finit en premier, ajouter la liste gauche
        listeR.extend(listeGauche[iG:])
    return listeR