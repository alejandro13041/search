#include "buscar.h"

bool search(int ip_num){

	FILE* pointer_file = fopen(DataBase1,"r");

	if (pointer_file == NULL){

		printf("[ERROR] can not open file.\r\n");
		return 0;

	 }

	printf("[OK] database open.\r\n"); 

    char line[size_line];
    struct line line_info;
    	
    while(fgets(line,size_line,pointer_file) != NULL){

    	line_info.lower_rank = atoi(strtok(line,","));
		line_info.upper_rank = atoi(strtok(NULL,","));
		
    	if(ip_num >= line_info.lower_rank && ip_num <= line_info.upper_rank){ 

    		strcpy(line_info.code   ,strtok(NULL,","));
			strcpy(line_info.country,strtok(NULL,","));
			printf("%s\n", line_info.country);
			fclose(pointer_file);
			return true;

		 }
     } 
   
	fclose(pointer_file);
 	return false;

 } 

/*
 * ip_string - convert a "a.b.c.d" formatted string into an ip structure
 * @IP: ip structure where the parsed octets will be stored
 * @line: input string containing the IPv4 address in textual form
 *
 * This function tokenizes the given string using '.' as delimiter and
 * converts each token to an integer using atoi(). The resulting values
 * are stored into the octet1–octet4 fields of the ip structure.
 * Returns the populated ip structure.
 */

struct ip ip_string(struct ip ip, char *line){

	char *p = line;
	char *end;
	long val;

	val = strtol(p, &end, 10);
	ip.octet1 = (int)val;

	if (*end == '.')
		end++;
	val = strtol(end, &end, 10);
	ip.octet2 = (int)val;

	if (*end == '.')
		end++;
	val = strtol(end, &end, 10);
	ip.octet3 = (int)val;

	if (*end == '.')
		end++;
	val = strtol(end, &end, 10);
	ip.octet4 = (int)val;

	return ip;
}

/* database_num - compute a numeric key from an ip structure */

int database_num(struct ip ip){

	return C_DB1 * ip.octet1 +
	       C_DB2 * ip.octet2 +
	       C_DB3 * ip.octet3 +
	       ip.octet4;
 }