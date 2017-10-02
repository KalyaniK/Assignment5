#include "headerFiles.h"

#define MSG_SIZE 200

typedef struct msgbuf
{
  long mtype;
  char mtext[MSG_SIZE];
} msg_buffer;

int main()
{
    int msqid;
    key_t key;
    msg_buffer rbuf;
    key = 1234;

    msqid = msgget(key, 0666);
    msgrcv(msqid, &rbuf, MSG_SIZE, 1, 0);
    printf("Message Received: %s\n", rbuf.mtext);
    exit(0);
}
