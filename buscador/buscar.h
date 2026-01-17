#ifndef _BUSCAR_H
#define _BUSCAR_H

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
* IPv4-to-integer conversion constants.
*
* These values represent the positional weight of each IPv4 octet
* when converting a dotted-decimal address into a single 32-bit
* integer, as used by the IP2Location databases.
*
* ip_num = o1 * C_DB1 + o2 * C_DB2 + o3 * C_DB3 + o4
*
* This numeric representation allows fast range comparisons
* against the database lower/upper bounds.
*/

#define C_DB1   16777216  /* 256^3 */
#define C_DB2   65536     /* 256^2 */
#define C_DB3   256       /* 256^1 */        

/* IPv4 address split into octets */

struct ip{
    int octet1;
    int octet2;
    int octet3;
    int octet4;
 };

#ifndef DataBase1

    #define DataBase1 "IP2LOCATION-LITE-DB1.CSV"
    #define size_line 128

    /* Single IP range entry from IP2Location CSV*/

    struct line {
        int   lower_rank;
        int   upper_rank;
        char  country[53];
        char  code[3];
    };

#endif

#ifndef DataBase3
#define DataBase3 "IP2LOCATION-LITE-DB3.csv"

    struct db3_entry {
        uint32_t lower_rank;
        uint32_t upper_rank;
        char country_code[3];
        char country_name[64];
        char region[64];
        char city[64];
    };


#endif

#ifndef DataBase5
#define DataBase5 "IP2LOCATION-LITE-DB5.csv"

    struct db5_entry {
        uint32_t lower_rank;
        uint32_t upper_rank;
        char country_code[3];
        char country_name[64];
        char region[64];
        char city[64];
        float latitude;
        float longitude;
    };

#endif

#ifndef DataBase9
#define DataBase9 "IP2LOCATION-LITE-DB9.csv"

    struct db9_entry {
        uint32_t lower_rank;
        uint32_t upper_rank;
        char country_code[3];
        char country_name[64];
        char region[64];
        char city[64];
        float latitude;
        float longitude;
        char zip_code[16];
    };

#endif

#ifndef DataBase11
#define DataBase11 "IP2LOCATION-LITE-DB11.csv"

    struct db11_entry {
        uint32_t lower_rank;
        uint32_t upper_rank;
        char country_code[3];
        char country_name[64];
        char region[64];
        char city[64];
        float latitude;
        float longitude;
        char zip_code[16];
        char time_zone[8];   
    };

#endif

    bool search(int rank);
    struct ip ip_string(struct ip ip, char *line);
    int database_num(struct ip ip);

#endif 
