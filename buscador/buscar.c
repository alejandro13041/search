#include "buscar.h"

int main(void){

    /* Buffer for user-provided IPv4 address */

    char string_ip[16];

    /*IPv4 address as integer octets*/

    struct ip ip_info;

    /*number search in database*/

    int ip_num;

    /*start search*/

    printf("IP:\n");

    if (scanf("%15s", string_ip) != 1){
        printf("input error\n");
        return 1;
     }

    /*convert string to octets*/ 

    ip_info = ip_string(ip_info, string_ip);

    /* Get number to search on database */

    ip_num = database_num(ip_info);

    if (!search(ip_num))
        printf("error\n");

    return 0;
}
