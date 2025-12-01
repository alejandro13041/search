/* SPDX-License-Identifier: GPL-2.0 */
/*
 * buscar.h - simple IPv4 parsing and database lookup support
 *
 * This header defines the IPv4 structure, range database structure,
 * and helpers used for converting dotted IPv4 strings to numeric form
 * for range-based lookup.
 */

#ifndef _BUSCAR_H
#define _BUSCAR_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define SIZE_LINE       78

#define DB1     "IP2LOCATION-LITE-DB1.csv"
#define DB3     "IP2LOCATION-LITE-DB3.csv"
#define DB5     "IP2LOCATION-LITE-DB5.csv"
#define DB9     "IP2LOCATION-LITE-DB9.csv"
#define DB11    "IP2LOCATION-LITE-DB11.csv"

#define C_DB1   16777216    /* 256^3 */
#define C_DB2   65536       /* 256^2 */
#define C_DB3   256         /* 256^1 */

/*
 * struct ip - IPv4 address split into octets
 * @octet1: first octet
 * @octet2: second octet
 * @octet3: third octet
 * @octet4: fourth octet
 */
struct ip {
        int octet1;
        int octet2;
        int octet3;
        int octet4;
};

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

/*
 * NOTE:
 * Torvalds would NOT put global variables in a header,
 * much less initialized ones. So this is only declared.
 */
extern char ranks_ip[25];

/* Function prototypes */
bool search(int rank);
struct ip ip_string(struct ip ip, char *line);
int database_num(struct ip ip);

#endif /* _BUSCAR_H */
