#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

void shop(int s)
{
	int count[3] = {5,5,5};
	if (s==1)
	{
		count[0]--;
		printf("stock left %d\n", count[0]);
	}
	if (s==2)
	{
		count[1]--;
		printf("stock left %d\n", count[1]);
	}
	if (s==3)
	{
		count[2]--;
		printf("stock left %d\n", count[2]);
	}
}

int main()
{
	int server_socket;
	server_socket = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9008);
	server_address.sin_addr.s_addr = INADDR_ANY;
	bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));
	listen(server_socket, 5);
	printf("Running...\n");
	int client_socket;
	int arg;
	client_socket = accept(server_socket, NULL, NULL);
	if (client_socket != -1)
	{
		printf("Connection estabilished with client\n");
	}
	else
	{
		printf("error\n");
	}
	for(;;)
	{
		recv(client_socket, &arg, sizeof(arg), 0);
		shop(arg);
	}
	return 0;
}	
