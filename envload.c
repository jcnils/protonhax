#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "%s <dump_file> <cmd> [args...]\n", argv[0]);
        return 1;
    }

    FILE *fd = fopen(argv[1], "rb");

    fseek(fd, 0, SEEK_END);
    long int env_len = ftell(fd);
    fseek(fd, 0, SEEK_SET);

    char* env = (char*)malloc(env_len);
    fread(env, sizeof(char), env_len, fd);
    fclose(fd);

    unsigned int envp_count = 0;
    for (char* ev = env; *ev != 0; ev++) {
        envp_count++;
        ev += strlen(ev);
    }

    char** envp = (char**)malloc((envp_count + 1) * sizeof(char*));
    char* ev = env;
    for (unsigned int i = 0; i < envp_count; i++) {
        envp[i] = ev;
        ev += strlen(ev) + 1;
    }
    envp[envp_count] = (char*)NULL;

    int eargc = argc - 2;
    char** eargv = (char**)malloc((eargc + 1) * sizeof(char*));
    for (int i = 0; i < eargc; i++)
        eargv[i] = argv[i + 2];
    eargv[eargc] = (char*)NULL;

    execve(argv[2], eargv, envp);

    int e = errno;
    fprintf(stderr, "Failed to exec!\n");
    fprintf(stderr, "%d %s\n", e, strerror(e));
    return e;
}
