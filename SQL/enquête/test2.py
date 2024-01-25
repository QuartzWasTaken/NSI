import mysql.connector
cnx = mysql.connector.connect(user="user", password="nsi",
                              host="172.16.122.230",
                              database="bdd_police")
cursor = cnx.cursor()
cursor.execute("""
SHOW TABLES;""")
reponse=cursor.fetchall()
print (reponse)
print("")
cursor.execute("""
select * from interview
where person_id=10010
""")
reponse=cursor.fetchall()
for i in reponse:
    print(i)
    
cnx.close()

