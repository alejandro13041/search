# IP Lookup Tool

A small command-line utility that quickly searches and retrieves information associated with an IPv4 address.  
The tool parses the IP, converts it to its numeric range, and looks it up in the **IP2Location LocationLite** databases.

## Features
- Parse dotted IPv4 addresses (`a.b.c.d`)
- Convert IPs to their numeric form
- Fast lookup using integer range comparison
- Extract country, country code, and optional coordinates (depending on database used)

## Database
This tool uses the **IP2Location-Lite** datasets:
- DB1  
- DB3  
- DB5  
- DB9  
- DB11  

These provide lightweight geolocation data such as:
- Country name  
- Country code  
- Latitude and longitude (in extended databases)

## Future Plans
- Expand support for more LocationLite databases  
- Add additional geolocation fields  
- Improve search method and error handling  
- Add CLI arguments and flags  
- Implement IPv6 support  

## Purpose
This is a simple and fast educational project focused on IP lookup.  
The goal is to keep expanding the dataset support and add more features over time.
