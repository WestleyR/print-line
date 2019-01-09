#!/bin/sh
# Created by: WestleyR
# email: westleyR@nym.hush.com
# Date: Jan 8, 2018
# https://github.com/WestleyR/strcomp
# Version-1.0.0
#
# The Clear BSD License
#
# Copyright (c) 2019 WestleyR
# All rights reserved.
#
# This software is licensed under a Clear BSD License.
#

INFO_FILE="func_info.c"

DATE_INFO=` date `
PWD_INFO=` pwd `

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

    printf("${DATE_INFO}\n");
    printf("HELLO WORLD\n");
    printf("HELLO WORLD\n");

    return;
}

//
// End func_info.c
//

EOF

#
# End Script
#
