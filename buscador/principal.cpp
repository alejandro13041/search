#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <vector>
#include <algorithm>
#include <iterator>
#include <array>
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

char NOMBRE_ARCHIVO[] = "IP2LOCATION-LITE-DB1.csv";	


/*
Esta es la funcion para contar 
las filas del archivo csv.
*/
int countRows(char *nombreArch){

    FILE *pa = fopen(nombreArch,"r");

    if(pa == NULL){

        cout<<"Problema al abrir el archivo "<<nombreArch<<endl;
        exit(-1);

     } 

    int n = 0; 
    char c = fgetc(pa);

    while(!feof(pa)){

        if(c=='\n') n++;
        c = fgetc(pa);

     }

    fclose(pa);
    return n; 

 }

const int n = countRows(NOMBRE_ARCHIVO);//variables con el numero de filas
 
void getValues(string& linea,int unsigned &lowerValue,int unsigned &higherValue,string& country){
 
  string aux1;
  string aux2;

  aux1 = linea.substr(0, linea.find_first_of(','));
  linea.erase(0, linea.find_first_of(',') + 1);
  

  aux2 = linea.substr(0, linea.find_first_of(','));
  linea.erase(0, linea.find_first_of(',') + 1);
  

  country = linea.substr(0, linea.find_first_of(','));
  linea.erase(0, linea.find_first_of(',') + 1);
  linea.erase(0, linea.find_first_of("\n"));

  lowerValue  = stoll(aux1);
  higherValue = stoll(aux2);
  

 } 
void getDatabase(int unsigned& IPn,string& IPd){

	FILE *p = fopen(NOMBRE_ARCHIVO,"r");

	char line[100];
	string country;
	int unsigned lowerValue = 0;
	int unsigned higherValue = 0;
	string linea;	

	//Creacion De Vectores

	vector<int unsigned> v1(n);	
  vector<int unsigned> v2(n);
  vector<string> v3(n);

	for (int j = 0; j < n; ++j){

		fgets(line,100,p);
  		strtok(line,"\n");
  		linea = line;
  		getValues(linea,lowerValue,higherValue,country);
  		
  		v1[j] = lowerValue;
  		v2[j] = higherValue;
  		v3[j] = country;
  		lowerValue = 0;
		higherValue = 0; 

	 }

	

	

		for (int j = 0; j < n; ++j){

			if(IPn >= v1[j] && IPn<=v2[j]){ 

				IPd = v3[j];	

	 		 }

		 }

     cout<<"[+] result:"<<IPd<<'\n';
	 

 }
void convert(string& s){

  int unsigned IPn;
  string IPd;

  int n1 = 0;
  int n2 = 0;
  int n3 = 0;
  int n4 = 0;

  string s1;
  string s2;
  string s3;
  string s4;

    s1 = s.substr(0, s.find_first_of('.'));
    s.erase(0, s.find_first_of('.') + 1);

    s2 = s.substr(0, s.find_first_of('.'));
    s.erase(0, s.find_first_of('.') + 1);

    s3 = s.substr(0, s.find_first_of('.'));
    s.erase(0, s.find_first_of('.') + 1);

    s4 = s.substr(0, s.find_first_of(' '));
    s.erase(0, s.find_first_of('\n') + 1);

    n1 = stoi(s1);
    n2 = stoi(s2);
    n3 = stoi(s3);
    n4 = stoi(s4);

    IPn = (16777216 * n1) + (65536 * n2) + (256 * n3) + n4;

    getDatabase(IPn,IPd);

 }
int main(){

 cout<<"[+] ingrese la direccion ip:"<<'\n';
  
	while(true){

    string s;
    
    cin>>s;
		convert(s);

		
		}

  return 0;
 }

