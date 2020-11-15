#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>  //inet_addr
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<netdb.h>

int main(int argc, char*argv[]){


int socket_desc;
char*server_reply;
struct sockaddr_in server;
char*message;


//create socket
socket_desc = socket(AF_INET, SOCK_STREAM, 0);
if(socket_desc == -1){
printf("Socket could not be created");

}

server.sin_addr.s_addr = inet_addr("192.168.43.219"); //server ip address
server.sin_family = AF_INET;
server.sin_port = htons(8888);

//connect to remote server
if(connect(socket_desc, (struct sockaddr*)&server, sizeof(server))<0){

puts("connect error");
return 1;
}

puts("Connected!\n");
//send some data

message = "Connect";
if(send(socket_desc, message, strlen(message), 0)<0){

puts("Send Failed");
return 1;
}
puts("Data send \n");
//receive a reply from the server

if(recv(socket_desc,server_reply,2000,0) < 0){
puts("Receicved Failed \n");

}

puts("Reply  received \n");
puts(server_reply);

//close(socket_desc);

return 0;
}
