#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){

	string s;
	cout<<"[+] ingrese la direccion ip:"<<'\n';
	cin>>s;

	int n1,n2,n3,n4;
    string s1,s2,s3,s4;


	s1 = s.substr(0, s.find_first_of('.'));
    s.erase(0, s.find_first_of('.') + 1);

    s2 = s.substr(0, s.find_first_of('.'));
    s.erase(0, s.find_first_of('.') + 1);

    s3 = s.substr(0, s.find_first_of('.'));
    s.erase(0, s.find_first_of('.') + 1);

    s4 = s.substr(0, s.find_first_of('.'));
    s.erase(0, s.find_first_of('.') + 1);
  	 
    n1 = stoi(s1);
    n2 = stoi(s2);
    n3 = stoi(s3);
    n4 = stoi(s4);

    cout<<"[+] 1 octeto"<<n1+1<<'\n';
    cout<<"[+] 2 octeto"<<n2+1<<'\n';
    cout<<"[+] 3 octeto"<<n3+1<<'\n';
    cout<<"[+] 4 octeto"<<n4+1<<'\n';

	return 0; 
 }
