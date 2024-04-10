#ifndef BUSCAR_H
#define BUSCAR_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define size_line 78

#define DB1  "IP2LOCATION-LITE-DB1.csv"
#define DB3  "IP2LOCATION-LITE-DB3.csv"
#define DB5  "IP2LOCATION-LITE-DB5.csv"
#define DB9  "IP2LOCATION-LITE-DB9.csv"
#define DB11 "IP2LOCATION-LITE-DB11.csv"

struct ip{

    int octet1;
    int octet2;
    int octet3;
    int octet4;

 };

struct line{

    int  lower_rank;
    int  upper_rank;
    char country[53];  
    char code[3];

    float latitude;
    float longitude;
    
 }; 

char RANKS_IP[25] = "IP2LOCATION-LITE-DB1.csv";

bool search(int);
struct ip ip_string(struct ip,char*);
int database_num(struct ip);

#endif
