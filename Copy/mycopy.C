#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *Fopen(const char *filename, const char *mode){
    FILE *fp;

    if ((fp = fopen(filename, mode)) == NULL) {
        printf("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }
    return fp;
}

int main(int argc, char **argv){
    const size_t BUFSIZE = 8192;

    FILE *src, *dest;
    char buf[BUFSIZE];
    size_t n;

    src = Fopen(argv[1], "rb");
    dest = Fopen(argv[2], "w+b");

    while ((n = fread(buf, 1, BUFSIZE, src)) > 0)
        fwrite(buf, 1, n, dest);

    fclose(src);
    fclose(dest);
    return 0;
}
