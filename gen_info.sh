#!/bin/sh
# Created by: WestleyR
# email: westleyr@nym.hush.com
# Date: Jan 15, 2018
# https://github.com/WestleyR/strcomp
# Version-1.0.1
#
# The Clear BSD License
#
# Copyright (c) 2019 WestleyR
# All rights reserved.
#
# This software is licensed under a Clear BSD License.
#

INFO_FILE="func_info.c"

DATE_INFO=` date "+%B %d, %Y, %I:%M:%S %p" `
WHO=` whoami `
ON=` hostname `
WHERE=` pwd `
KERN=` uname -r `
ARCH=` uname -m `

cat << EOF > "$INFO_FILE"
// created by: WestleyR
// email: westleyr@nym.hush.com
// https://github.com/WestleyR/print-line
// date: Jan 8, 2018
// version-1.0.0
//
// The Clear BSD License
//
// Copyright (c) 2019 WestleyR
// All rights reserved.
//
// This software is licensed under a Clear BSD License.
//

#include <stdio.h>
#include "func_info.h"

void print_info() {

    printf("Compiled on        : ${DATE_INFO}\n");
    printf("Compiled by        : ${WHO}\n");
    printf("Compiled on        : ${ON}\n");
    printf("Compiled in        : ${WHERE}\n");
    printf("Compiled on kernel : ${KERN}\n");
    printf("Compiled on arch   : ${ARCH}\n");

    return;
}

//
// End func_info.c
//

EOF

#
# End Script
#
