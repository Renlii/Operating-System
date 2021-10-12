
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

#include "a1_lib.h"
#include "frontend.h"

#define BUFSIZE   1024

int main(void) {
  int sockfd, clientfd;
  char msg[BUFSIZE];
  int pid;
  int rval;
  int running = 1;
  
  if ((pid = fork()) == 0){
    sleep(10);
    return 10;
  }
  while(1){
    sleep(1);
    int res = waitpid(pid, &rval, WNOHANG);
    printf(printf("Returned value %d\n", WEXITSTATUS(rval));
  }

  if (create_server("0.0.0.0", 10000, &sockfd) < 0) {
    fprintf(stderr, "oh no\n");
    return -1;
  }

  if (accept_connection(sockfd, &clientfd) < 0) {
    fprintf(stderr, "oh no\n");
    return -1;
  }

  pid = fork();
  if(pid < 0){
    perror("can not create the child process\n ");
    close(sockfd);
    exit(1);
  }else if (pid == 0){
    while (strcmp(inputArray[0], "quit\n")) {
      memset(msg, 0, sizeof(msg));
      /*ssize_t byte_count = recv_message(clientfd, msg, BUFSIZE);
      if (byte_count <= 0) {
        break;
      }*/
      printf("Client: %s\n", msg);
      if(strcmp(inputArray[0],"add")==0){
          int result = addInts(inputArray[1], inputArray[2]);
      }
      if(strcmp(inputArray[0],"multiply")==0){
          int result = multiplyInts(inputArray[1], inputArray[2]);
      }
      if(strcmp(inputArray[0],"divide")==0){
          if (num2 == 0){
              printf("Cannot divide by 0.\n");
          }
          float result = divideFloats(inputArray[1], inputArray[2]);
      }
      if(strcmp(inputArray[0],"sleep")==0){
          sleep(inputArray[1]);
      }
      if(strcmp(inputArray[0],"factorial")==0){
          int result = factorial(inputArray[1]);
      }
      else{
          printf("Unknown operation\n");
      }

      send_message(clientfd, result, strlen(result));
    }
    close(clientfd);
    return 0;
  }else{
    close(clientfd);
  }

  return 0;
}



int addInts(int a, int b){
    return a + b;
}

int multiplyInts(int a, int b){
    return a * b;
}

float divideFloats(float a, float b){
    return a / b;
}

int sleep(int x){
    int i = time(0) + x;
    while (time(0) < i);
    return 0;
}

unit64_t factorial(int x){
    if(x == 0){
        return 1;
    }
    return x * factorial(x - 1);
}
