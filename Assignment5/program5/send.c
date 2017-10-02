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
    msg_buffer sbuf;
    size_t buf_length;
    key = 1234;

    msqid = msgget(key, IPC_CREAT | 0666);
    sbuf.mtype = 1;
    strcpy(sbuf.mtext, "Hello, how are you?");
    buf_length = strlen(sbuf.mtext) + 1;
    msgsnd(msqid, &sbuf, buf_length, IPC_NOWAIT);
    printf("Message: \"%s\" Sent\n", sbuf.mtext);

    return 0;
}
