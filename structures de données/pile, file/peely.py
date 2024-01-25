class Pile:

    def __init__(self,listepile=[]):
        self.listepile=listepile
        
    def empile(self,valeur):
        if type(valeur) is int:
            self.listepile.append(valeur)
            return 
        self.listepile+=valeur.listepile
    
    def depile(self):
        if len(self.listepile)==0:
            return None
        else:
            self.listepile.pop()
            
    def is_empty(self):
        if len(self.listepile)==0:
            return True
        return False
    
    def voirSommet(self):
        if self.is_empty()==True:
            return None
        return self.listepile[-1]
    
    def taillePile(self):
        return len(self.listepile)
    
    def __repr__(self):
        return f"la pile:{self.listepile}"
    
    def __str__(self):
        strg=""
        for i in range(len(self.listepile)):
            strg += str(self.listepile[i])
            strg += "\n"
        return strg
    
    def add(self):
        self.listepile.append(self.listepile.pop()+self.listepile.pop())
        return pile
    
    def sub(self):
        self.listepile.append(self.listepile.pop()-self.listepile.pop())
        return pile
    
    def mul(self):
        self.listepile.append(self.listepile.pop()*self.listepile.pop())
        return pile
    
    def div(self):
        self.listepile.append(self.listepile.pop()/self.listepile.pop())
        return pile
            
    
    
def polonaiseInverse(liste):
    pile = Pile()
    for i in range(len(liste)):
        if(liste[i] == "+"):
            pile.add()
        elif(liste[i] == "-"):
            pile.sub()
        elif(liste[i] == "*"):
            pile.mul()
        elif(liste[i] == "/"):
            pile.div()
        else:
            pile.empile(int(liste[i]))
    return pile.voirSommet()

pile=Pile([1,4,7,6,4,2])
pile2=Pile([6,7,3,1])

# print(pile)
# pile2=Pile([6,7,3,1])
# pile.empile(pile2)
# print("pile+pile2: \n",pile)
# print("----------------- add  vv")
# print(pile.add())
# print("----------------- sub  vv")
# print(pile.sub())
# print("----------------- mul  vv")
# print(pile.mul())
# print("----------------- div  vv")
# print(pile.div())

ope = str(input("Entrez une opération ici : "))
spl = ope.split()
print(polonaiseInverse(spl))



