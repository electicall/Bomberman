#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h> //inet_addr
#include "graphix.c"
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1)+strlen(s2)+1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}


int recvBomber (int *datagramma)
{
  //socket sanjemshanas funkcija
}

int senderBomber(int *datagramma)
{
  //socket suutiishanas funkcija
}

void redraw_Screen()
{
glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
draw_crate(0,0);
glFlush();
}


void initBomberDisplay()
{

  char *myargv [1];
  int myargc=1;
  myargv [0]=strdup ("Tronberman");
  glutInit(&myargc, myargv);         // Initialize GLUT
  glutInitWindowSize(screenWidth, screenHeight);   // Set the window's initial width & height - non-square
  glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
  glutCreateWindow("Tronberman");  // Create window with the given title
  glutDisplayFunc(redraw_Screen);       // Register callback handler for window re-paint event
  glutReshapeFunc(reshape);       // Register callback handler for window re-size event
  initGL();                       // Our own OpenGL initialization
  glutMainLoop();                 // Enter the infinite event-processing loop
}



int main(void)
{
  /*
//game start
int sock, client_sock, c, read_size;
struct sockaddr_in server, client;
char *message,server_reply[2000];
char *playerName[23];
char *joinRequest;


sock=socket(AF_INET, SOCK_STREAM,0);
if (sock==-1)
{
  printf ("Could not make socket");
  return 0;
}
printf ("Socket created\n");

char serverIP[100];
char serverPort[100];
printf("\n\n\n");
printf("%40s",KCYN);
printf ("Tronberman v0.1beta \n");
printf("\n\n\n");
printf("%s",KWHT);
printf ("Enter server IP: ");
scanf("%s",serverIP);
printf ("\nEnter server Port:");
scanf("%s",serverPort);

 server.sin_family = AF_INET;
 server.sin_addr.s_addr = inet_addr(serverIP);
 server.sin_port = htons( atoi(serverPort));

  printf("connecting\n");
  if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        printf("connect failed. Error\n");
        return 1;
    }

    printf("Connected\n");

      printf("Connected\n");

printf("Enter player name [lenght 23]: ");
scanf("%s",playerName);
do {
send(sock, 1,1,0);
send(sock, playerName, strlen(playerName),0);
}while(1);

      message = "GET / HTTP/1.1\r\n\r\n";
   if( send(sock , message , strlen(message) , 0) < 0)
   {
       puts("Send failed");
       return 1;
   }
   puts("Data Send\n");

   //Receive a reply from the server
   if( recv(sock, server_reply , 2000 , 0) < 0)
   {
       puts("recv failed");
   }
   puts("Reply received\n");
   puts(server_reply);
*/
initBomberDisplay();

//display();
//return 0;

}
