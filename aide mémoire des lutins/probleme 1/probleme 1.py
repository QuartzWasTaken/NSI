liste = []
f = open("document.txt", "r")
contenu = f.read()
liste.append(contenu.split("\n"))
f.close()


for i in range(len(liste[0])):
    for j in liste[0][i]:
        try:
            if(type(int(j)) is int):
                print(j, end = "")
        except ValueError:
            pass
    print("")
        
