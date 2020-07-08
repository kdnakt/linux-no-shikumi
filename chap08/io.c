#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <err.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <linux/fs.h>

#define PART_SIZE (1024*1024*1024)
#define ACCESS_SIZE (64*1024*1024)

static char *progname;

int main(int argc, char *argv[]) {
    progname = argv[0];
    if (argc != 6) {
        fprintf(stderr, "usage: %s <filename> <kernel's help> <r/w> <access pattern> <block size[KB]>\n", progname);
        exit(EXIT_FAILURE);
    }

    char *filename = argv[1];

    bool help;
    if (!strcmp(argv[2], "on")) {
        help = true;
    } else if (!strcmp(argv[2], "off")) {
        help = false;
    } else {
        fprintf(stderr, "kernel's help should be 'on' or 'off': %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    int write_flg;
    if (!strcmp(argv[3], "r")) {
        write_flg = false;
    } else if (!strcmp(argv[3], "w")) {
        write_flg = true;
    } else {
        fprintf(stderr, "r/w should be 'r' or 'w': %s\n", argv[3]);
        exit(EXIT_FAILURE);
    }

    bool random;
    if (!strcmp(argv[4], "seq")) {
        random = false;
    } if (!strcmp(argv[4], "rand")) {
        random = true;
    } else {
        fprintf(stderr, "access pattern should be 'seq' or 'rand': %s\n", argv[4]);
        exit(EXIT_FAILURE);
    }
    
}