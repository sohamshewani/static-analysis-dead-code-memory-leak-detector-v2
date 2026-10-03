#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "parser.h"
#include "cfg.h"
#include "config.h"

int parse_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("fopen");
        return -1;
    }

    char buffer[MAX_STRING_LENGTH];
    while (fgets(buffer, MAX_STRING_LENGTH, file)) {
        // Parse line and build CFG
        build_cfg(filename);
    }

    fclose(file);
    return 0;
}
