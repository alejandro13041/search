#ifndef _BUSCAR_H
#define _BUSCAR_H

    #include <stdbool.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdio.h>

    /*
     * struct ip - IPv4 address split into octets
     * @octet1: first octet
     * @octet2: second octet
     * @octet3: third octet
     * @octet4: fourth octet
     */

    typedef struct ip{
        int octet1;
        int octet2;
        int octet3;
        int octet4;
     };

     /*
      * constants to search on database, this 
      * is important because is the form that 
      * search in database.
      */ 

    #define C_DB1   16777216    
    #define C_DB2   65536       
    #define C_DB3   256         

    #ifndef DataBase1
    #define DataBase1 "IP2LOCATION-LITE-DB1.csv"

    #define size_line 78 

        /*
         * struct line - single range entry for database lookup
         * @lower_rank: start of IP range (numeric)
         * @upper_rank: end of IP range (numeric)
         * @country:    country name
         * @code:       2-letter country code
         * @latitude:   latitude (for DB5/DB9/DB11)
         * @longitude:  longitude (for DB5/DB9/DB11)
         */

        struct line {
            int   lower_rank;
            int   upper_rank;
            char  country[53];
            char  code[3];
            float latitude;
            float longitude;
        };

    #endif

    #ifndef DataBase3
    #define DataBase3 "IP2LOCATION-LITE-DB3.csv"


    #endif

    #ifndef DataBase5
    #define DataBase5 "IP2LOCATION-LITE-DB5.csv"

    #endif

    #ifndef DataBase9
    #define DataBase9 "IP2LOCATION-LITE-DB9.csv"

    #endif

    #ifndef DataBase11
    #define DataBase11 "IP2LOCATION-LITE-DB11.csv"

    #endif

    extern char ranks_ip[25];

    /* Function prototypes */

    bool search(int rank);
    struct ip ip_string(struct ip ip, char *line);
    int database_num(struct ip ip);

#endif 
