class File():
    def __init__(self, listeFile=[]): # Inverser la liste passée en paramètre
        # Début = Entrée
        # Fin = Sortie
        self.listeFile = listeFile[::-1]
        
    def __str__(self): # Ajouter des espaces entre chaque nombre
        strRet = ""
        for i in range(len(self.listeFile)):
            strRet += str(self.listeFile[i])
            strRet += " "
        return(strRet)
        
    def __repr__(self):
        return str(list(self.listeFile))
    
    def __add__(self, file): # Inverser les deux, puis les ajouter ensemble
        nouvelleListe = self.listeFile[::-1] + file.listeFile[::-1]
        return nouvelleListe[::-1]
        
    
    def enfile(self, valeur):
        self.listeFile.insert(0, valeur)
        
    def is_empty(self):
        if(len(self.listeFile) == 0):
            return True
        return False
    
    def defile(self):
        return self.listeFile.pop()
    
    def voirSortie(self):
        if(not self.is_empty()):
            return self.listeFile[-1]
        return None
        
    def taille(self):
        return len(self.listeFile)
    
def créationSoldats(nbSoldats):
    liste = []
    for i in range(nbSoldats):
        liste.append(i+1)
    return liste

def créationDico(liste):
    dico = dict()
    for  i in range(len(liste)):
        dico[i] = [f"Soldat {i}"]
    return dico

def problèmeJosèphe(file, inter, restants):
    
    for i in range(file.taille()-restants):
        for j in range(inter - 1):
            soldat = file.voirSortie()
            file.defile()
            file.enfile(soldat)
        file.defile()
    return file

def problèmeJosèpheDico(dico, inter, restants):
    pass

listeSoldats = créationSoldats(70)
dicoSoldats = créationDico(listeSoldats)
print(dicoSoldats)
fileSoldats = File(listeSoldats)
print(problèmeJosèphe(fileSoldats, 3, 1))