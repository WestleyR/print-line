.PHONY:
all: $(CODE_NAME)
	chmod +x $(GEN_SCRIPT)
	./$(GEN_SCRIPT)
	$(COMPILER) $(FLAG) $(CFLAG) -o $(SCRIPT_NAME) $(CODE_NAME) $(INFO_NAME)
	@rm -f $(INFO_NAME)
	@echo
	@echo "Done."
	@echo ">> Do:"
	@echo "  $$ sudo make install"

