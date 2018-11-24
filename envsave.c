#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv, char **envp) {
    if (argc < 2) {
        fprintf(stderr, "%s <dump_file> [cmd [args...]]\n", argv[0]);
        return 1;
    }

    FILE *fd = fopen(argv[1], "wb");
    for (char** ev = envp; *ev != 0; ev++) {
        fwrite(*ev, sizeof(char), strlen(*ev) + 1, fd);
    }
    fputc(0, fd);
    fclose(fd);

    if (argc > 2)
        return execv(argv[2], argv+2);
    else
        return 0;
}
