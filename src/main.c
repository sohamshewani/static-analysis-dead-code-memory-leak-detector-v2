#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "parser.h"
#include "cfg.h"
#include "analyzer.h"
#include "reporter.h"
#include "config.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    parse_file(argv[1]);
    analyze_code();
    report_results();

    return 0;
}
