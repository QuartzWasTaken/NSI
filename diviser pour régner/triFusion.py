import fusion as fus

def triFusion(liste):
    if(len(liste) <= 1):
        return liste
    listeG = liste[len(liste)//2:]
    listeD = liste[:len(liste)//2]
    return fus.fusionner(triFusion(listeG), triFusion(listeD))

print(triFusion([2, 9, 8, 7, 6, 5, 9, 7, 3, 1, 5, 0]))