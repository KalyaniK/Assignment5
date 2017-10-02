#include "headerFiles.h"

#define SHM_SIZE 27

int main()
{
    char c;
    int shmid;
    key_t key;
    char *shm, *s;

    key = 5678;

    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0)
    {
        perror("shmget");
        exit(1);
    }

    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1)
    {
        perror("shmat");
        exit(1);
    }

    s = shm;

    for (c = 'a'; c <= 'z'; c++)
    {
      *s++ = c;
    }
    *s = NULL;

    while (*shm != '*')
    {
      sleep(1);
    }

    printf("Finished\n");
    exit(0);
}
