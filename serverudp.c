#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int prime(int num)
{
	for (int i=2; i<num; i++)
	{
		if (num%i==0)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	int server_socket;
	server_socket = socket(AF_INET, SOCK_DGRAM, 0);
	struct sockaddr_in server_address, client_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9008);
	server_address.sin_addr.s_addr = INADDR_ANY;
	bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));
	printf("Running...\n");
	int n, res;
	if (server_socket < 0)
	{
		printf("error\n");
	}
	for(;;)
	{
		recvfrom(server_socket, &n, sizeof(n), 0, (struct sockaddr *) &client_address, sizeof(client_address));
		res = prime(n);
		sendto(server_socket, &res, sizeof(res), 0, (struct sockaddr *) &client_address, sizeof(client_address));
	}
	return 0;
}	
