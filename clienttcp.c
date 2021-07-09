#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main()
{
	int network_socket;
	network_socket = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9008);
	server_address.sin_addr.s_addr = INADDR_ANY;
	int conn = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address)); 
	if (conn == -1)
	{
		printf("Error\n");
		return 1;
	}
	else
	{
		printf("Connection estabilished enter 0 to exit and 1 to start\n");
	}
	for (;;)
	{
		int n;
		int model;
		scanf("%d", &n);
		if (n==0)
		{
			close(network_socket);
			break;
		}
		else
		{
			printf("choose the following:\n2-apple\n3-samsung\n4-nokia\nenter 0 to exit\n");
			scanf("%d", &model);
			send(network_socket, &model, sizeof(model), 0);
		}
	}
	
	return 0;
}
