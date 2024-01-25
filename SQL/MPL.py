import datetime
import sqlite3
from pylab import *

listeDate=[] # Définir les listes vides à utiliser
listeT=[]
listeTMer=[]
listeVitVent=[]

conn = sqlite3.connect('marine.db') #Commencer la communication avec la DB
cursor = conn.cursor()
cursor.execute("""
select t, tmer, ff, date from donnees_marines_201701 
where numer_sta = "BATFR17" and ff != "mq" and t != "mq"
UNION
select t, tmer, ff, date from donnees_marines_201702
where numer_sta = "BATFR17" and ff != "mq" and t != "mq"
UNION
select t, tmer, ff, date from donnees_marines_201703
where numer_sta = "BATFR17" and ff != "mq" and t != "mq"
UNION
select t, tmer, ff, date from donnees_marines_201704
where numer_sta = "BATFR17" and ff != "mq" and t != "mq"
UNION
select t, tmer, ff, date from donnees_marines_201705
where numer_sta = "BATFR17" and ff != "mq" and t != "mq"
UNION
select t, tmer, ff, date from donnees_marines_201706
where numer_sta = "BATFR17" and ff != "mq" and t != "mq"
order by date asc
""") # Sélectionner les lignes dont on a besoin
reponse=cursor.fetchall()
cursor.close()

for i in range(len(reponse)): # Affecter chacune des parties de la réponse à la requête à une des listes
    listeT.append(reponse[i][0]-273)
    listeTMer.append(reponse[i][1]-273)
    listeVitVent.append(reponse[i][2])
    listeDate.append(datetime.datetime.strptime(reponse[i][3],"%Y%m%d%H%M%S"))

plot(listeDate,listeT,'b', label='temp air') # Mettre ces listes sur la courbe
plot(listeDate,listeTMer,'r', label='temp mer')
plot(listeDate,listeVitVent,'g', label='vit vent')
legend(loc='upper right')
show()

# time="20170801233254"
# temps=(datetime.datetime.strptime(time,"%Y%m%d%H%M%S"))
# print(temps)



