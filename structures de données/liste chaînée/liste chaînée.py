class Maillon:
    def __init__(self, valeur, suivant = None):
        self.valeur = valeur
        self.suivant = suivant
    
    def __repr__(self):
        if(self.suivant != None):
            return f"{self.valeur} > {self.suivant}"
        return str(self.valeur)
    
    def __str__(self):
        if(self.suivant != None):
            return f"{self.valeur} > {self.suivant}"
        return str(self.valeur)
    
    def longueur(self):
        if(self.suivant == None):
            return 1
        return self.suivant.longueur() + 1
    
    def affiche(self):
        print(self.valeur)
        return self.valeur

    def affichePosition(self, n):
        if(n == 0): # Quand on est arrivé, return la valeur
            return self.valeur
        
        if(n > self.longueur()): # Si le n dépasse de la liste, return None
            return None
        
        return self.suivant.affichePosition(n-1) # Afficher la position de celui d'après

    def insere(self, valeur):
        if(self.suivant != None):
            self.suivant.insere(valeur)
            return None
        self.suivant = Maillon(valeur)
        return None

    def insereDebut(self, valeur):
        maillon = Maillon(self.valeur, self.suivant)
        self.valeur=valeur
        self.suivant=maillon
    
    
    
    def insereEnPosition(self, n, v):
        if(n > self.longueur()):
            self.insere(v)
            return None
        if n==0:
            self.insereDebut(v)
            return
        if(n == 1):
            maillon=Maillon(v, self.suivant)
            self.suivant = maillon
            return None
        return self.suivant.insereEnPosition(n-1, v)
        
        
    def supprime(self,n):
        
        if n>self.longueur() or n==0:
            return None

        if n==2:
            self.suivant=self.suivant.suivant
            return None
         
        if n==1:
            self.valeur = self.suivant.affiche()
            self.suivant = Maillon(self.suivant.suivant)
           
        return self.suivant.supprime(n-1)   
        
    def remplaceValeur(self, n, v):
        if(n > self.longueur() or n == 0):
            return None
        if(n == 1):
            self.valeur = v
        return self.suivant.remplaceValeur(n-1, v)
    
    def occurrences(self, v):
        if(self.valeur == v):
            return self.suivant.occurrences(v) + 1
        return 0
    
    def premiereOccurrence(self, v):
        
        
listeChainee = Maillon(5, Maillon(12, Maillon(15, Maillon(26, Maillon(6)))))
print(listeChainee.longueur())


"""print(listeChainee)
listeChainee.insere(50)
print(listeChainee)
listeChainee.insereDebut(10)
print(listeChainee)
"""

print(listeChainee)
listeChainee.supprime(3)
print(listeChainee)
listeChainee.remplaceValeur(2, 7)
print(listeChainee)
 

"""        if(self.suivant == None):
            print(self.valeur)
            return self.valeur
        return self.suivant.affiche() """