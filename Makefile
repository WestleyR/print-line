# Created by: Westley K
# email: westleyr@nym.hush.com
# Date: Jan 7, 2018
# https://github.com/WestleyR/????
# Version-1.0.0
#
# The Clear BSD License
#
# Copyright (c) 2018 WestleyR
# All rights reserved.
#
# This software is licensed under a Clear BSD License.
#

CODE_NAME = main-print-line.c
SCRIPT_NAME = pl
INFO_NAME = func_info.c
GEN_SCRIPT = gen_info.sh
DEFALT_INSTALL = /usr/local/bin/
#MAN_LOCATION = man/man1/ecgo.1.gz
#MAN_INSTALL = /usr/share/man/man1/

INSTALL_TO = $(prefix)

ifeq ($(prefix),)
INSTALL_TO = $(DEFALT_INSTALL)
endif

all: $(CODE_NAME)
	@chmod +x $(GEN_SCRIPT)
	@./$(GEN_SCRIPT)
	@echo "Compileing code..."
	gcc -o $(SCRIPT_NAME) $(CODE_NAME) $(INFO_NAME)
	@rm -f $(INFO_NAME)
	@echo "Done."
	@echo ">> Do:"
	@echo "  $$ sudo make install"

install:
	@echo "installing to:" $(INSTALL_TO)
	chmod +x $(SCRIPT_NAME)
	cp -f $(SCRIPT_NAME) $(INSTALL_TO)
#	cp -f $(MAN_LOCATION) $(MAN_INSTALL)

update:
	rm -f $(SCRIPT_NAME)
	git pull origin master

clean:
	rm -f $(SCRIPT_NAME)

uninstall:
	rm $(INSTALL_TO)$(SCRIPT_NAME)

#
# End Makefile
#
