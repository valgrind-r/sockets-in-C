#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main()
{
	int network_socket;
	network_socket = socket(AF_INET, SOCK_DGRAM, 0);
	struct sockaddr_in server_address;
	int server_len = sizeof(server_address);
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9008);
	server_address.sin_addr.s_addr = INADDR_ANY;
	if (network_socket < 0)
	{
		printf("Error\n");
		return 1;
	}
	for (;;)
	{
		int n, s;
		scanf("%d", &n);
		if (n==0)
		{
			close(network_socket);
			break;
		}
		sendto(network_socket, &n, sizeof(n), 0, (struct sockaddr *) &server_address, server_len);
		recvfrom(network_socket, &s, sizeof(s), 0, (struct sockaddr *) &server_address, &server_len);
		if (s==1)
		{
			printf("Not prime\n");
		}
		else
		{
			printf("prime\n");
		}
	}
	
	return 0;
}
