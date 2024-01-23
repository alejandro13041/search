#include "buscar.h"

/*
int countRows(char *nameFile){

	FILE* pointerFile = fopen(nameFile,"r");

	if(pointerFile == NULL){

		printf("[INFO] can not open File: %s\r\n",nameFile);
		exit(0);

	 } 

	int numberRows = 0; 
	char c = fgetc(pointerFile);

	while(!feof(pointerFile)){

		if( c=='\n'){ 

			numberRows++;

		 }

		c = fgetc(pointerFile);

	 }

	fclose(pointerFile);
	return numberRows; 
 }
*/
/* 
void search(int IPnum,int sizeDatabase){

	FILE* pointerFile = fopen(RANKS_IP,"r");

	if (pointerFile == NULL){

		printf("[ERROR] can not open file.\r\n");
		exit(0); 
	 }

	char line[100];
    char code[3];
    char country[100];  

    int lowerRank;
    int upperRank;

	for (int id = 0; id < 500; id++){
	
		fgets(line,100,pointerFile);
		
		lowerRank = atoi(strtok(line,","));
		upperRank = atoi(strtok(NULL,","));
		strcpy(code,strtok(NULL,","));
		strcpy(country,strtok(NULL,","));

		if(IPnum >= lowerRank && IPnum <= upperRank){ 

			printf("%s\n", country);
					
		 }      
	 }	 

	fclose(pointerFile);
 
 } 

 


int IPtoString(char* IP){

	int octet1 = atoi(strtok(IP,".")); 
	int octet2 = atoi(strtok(NULL,".")); 
	int octet3 = atoi(strtok(NULL,".")); 
	int octet4 = atoi(strtok(NULL,".")); 

	int IPnum = (16777216 * octet1) + (65536 * octet2) + (256 * octet3) + octet4;
	return IPnum;    
 }
*/
int main(){

	printf("hola mundo\n");

	/*

    char IP[16];
    printf("[+] IP search:\n");
    scanf("%s",IP);

    int sizeDatabase = countRows(RANKS_IP);
    printf("%d\n",sizeDatabase);

    */
  
  return 0;
 } 
