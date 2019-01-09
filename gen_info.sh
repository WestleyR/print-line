#!/bin/sh
#
#
#

INFO_FILE="func_info.c"

DATE_INFO=` date `
PWD_INFO=` pwd `

cat << EOF > "$INFO_FILE"
#include <stdio.h>
#include "func_info.h"

void print_info() {

    printf("${DATE_INFO}\n");
    printf("HELLO WORLD\n");
    printf("HELLO WORLD\n");

    return;
}

//
// End print_info
//

EOF

#
# End Script
#
