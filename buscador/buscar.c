// SPDX-License-Identifier: GPL-2.0-or-later

//1 size: 585.701 bytes
//2 size: 585.325

/*
 * Copyright 1997-1998 José Alejandro Varon Carreño -- All Rights Reserved
 * Copyright 1999-2000 José Alejandro Varon Carreño <alejandrovaron272006@gmail.com>
 * 


 */

#include "buscar.h"
 
bool search(int ip_num){

	FILE* pointer_file = fopen(RANKS_IP,"r");

	if (pointer_file == NULL){

		printf("[ERROR] can not open file.\r\n");
		return 0;

	 }

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
struct ip ip_string(struct ip IP,char* line){

	IP.octet1 = atoi(strtok(line,".")); 
	IP.octet2 = atoi(strtok(NULL,".")); 
	IP.octet3 = atoi(strtok(NULL,".")); 
	IP.octet4 = atoi(strtok(NULL,".")); 
	
	return IP;

 }

int database_num(struct ip ip){
	 
	return (16777216 * ip.octet1) + 
			  (65536 * ip.octet2) + 
			    (256 * ip.octet3) + 
			           ip.octet4;

 }

int main(){

	int ip_num = 0;
    char string_ip[16];
    struct ip ip_info;

    printf("[+] IP search:\n");
    scanf("%s",string_ip);
    ip_info = ip_string(ip_info,string_ip);
    ip_num = database_num(ip_info);
    
    if (search(ip_num) != true){

    	printf(" error\n");

     }



  return 0;
 } 
