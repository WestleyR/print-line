.PHONY:
static: $(CODE_NAME)
	$(COMPILER) $(FLAG) $(CFLAG) $(STATIC_BUILD_FLAG) -o $(SCRIPT_NAME) $(CODE_NAME) $(INFO_NAME)

