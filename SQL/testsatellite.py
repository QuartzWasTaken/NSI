import os
import folium

keysc = map(os.getenv, ['HEREMAPS_APP_ID', 'HEREMAPS_APP_CODE'])

tiles = (
    'https://1.base.maps.api.here.com/maptile/2.1/maptile/newest/normal.day/{z}/{x}/{y}/256/png8?'
    'lg=eng&'
    'app_id={app_id}&'
    'app_code={app_code}'
)

carte = folium.Map(location=(42, -42), tiles=tiles, zoom_start=10, attr='HERE.com')
carte.save("carteSat.html")