import folium
import sqlite3
listeLon = []
listeLat = []

carte=folium.Map(location=[0, 0],zoom_start=1)



conn = sqlite3.connect('marine.db') #Commencer la communication avec la DB
cursor = conn.cursor()
cursor.execute("""select latitude, longitude, nom from liste_postes""")
reponse = cursor.fetchall()
for i in range(len(reponse)):
    folium.Marker([reponse[i][0], reponse[i][1]],popup=reponse[i][2]).add_to(carte)
    
carte.save("carte.html")