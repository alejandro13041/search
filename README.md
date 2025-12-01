IP Lookup Tool

This project is a small command-line executable designed to quickly search information associated with an IPv4 address.
It parses the IP, converts it to its numeric range, and retrieves related data from the IP2Location LocationLite databases.

Features

Convert a dotted IPv4 string (a.b.c.d) into numeric form

Search the IP in the LocationLite CSV databases

Extract country, coordinates and other available metadata

Very fast lookup using integer range comparison

Current Database

The tool uses the IP2Location-Lite datasets (DB1, DB3, DB5, DB9, DB11).
These provide lightweight geolocation data such as:

Country name

Country code

Latitude / longitude (depending on database version)

Future Plans

Expand the supported databases

Add more detailed geolocation fields

Implement better error handling and range searching

Add IPv6 support

Improve the CLI interface and add flags for queries

Notes

This is an educational and lightweight utility focused on speed and simplicity.
Future updates aim to turn it into a more complete and flexible IP lookup engine.
