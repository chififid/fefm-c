#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        return 0;
    }

    const char *in_name = argv[1];
    const char *out_name = argv[2];
    int key = atoi(argv[3]);

    FILE *in = fopen(in_name, "r");
    if (!in) return 0;
    FILE *out = fopen(out_name, "w");
    if (!out) { fclose(in); return 0; }

    int c;
    while ((c = fgetc(in)) != EOF) {
        char enc = (char)(c + key);
        fputc(enc, out);
    }

    fclose(in);
    fclose(out);
    return 0;
}


