// SPDX-License-Identifier: GPL-2.0
#include "buscar.h"

int main(void)
{
        char string_ip[16];
        struct ip ip_info;
        int ip_num;

        printf("[+] IP search:\n");

        if (scanf("%15s", string_ip) != 1) {
                printf("input error\n");
                return 1;
        }

        ip_info = ip_string(ip_info, string_ip);
        ip_num = database_num(ip_info);

        if (!search(ip_num))
                printf("error\n");

        return 0;
}
