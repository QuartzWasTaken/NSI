import datetime
import sqlite3
from pylab import *
listeX=[1,2,3,4]
listeY2=[0,2,4,2]
listeY1=[1,2,3,4]
plot(listeX,listeY1,'b', label='X1')
plot(listeX,listeY2,'r', label='X2')
legend(loc='upper right')
show()

time="20170801233254"
temps=(datetime.datetime.strptime(time,"%Y%m%d%H%M%S"))
print(temps)

conn = sqlite3.connect('marine.db')
cursor = conn.cursor()
cursor.execute("""
select t, tmer, ff from donnees_marines_201708
where numer_sta = "BATFR17"
""")
reponse=cursor.fetchall()
cursor.close()

for i in reponse:
    pass