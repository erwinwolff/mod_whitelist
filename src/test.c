#include <stdio.h>
#include "get_ip_list.h"

int main()
{
	printf("Initializing whitelist test... \n");

	int result = ipaddress_is_in_list("Server=localhost;Database=TestDb;User=test;Password=test;Port=3306", "SELECT Ip FROM allowedips", "127.0.0.1");

	if(result == 1)
		printf("localhost record found!\0");
}
