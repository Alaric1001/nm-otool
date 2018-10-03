FAIL_DIR	:= fails
DIFF		:= diff
BIN_DIR		:= /bin /usr/bin
LIB_DIR		:= /usr/lib

BINS		:= $(shell find $(BIN_DIR) -type f)
LIBS		:= $(shell find $(LIB_DIR) -type f \( -iname '*.dylib' -or -iname '*.so' \))

.PHONY: test_all
test_all: test_bin test_libs

.PHONY: test_bin
test_bin: all $(FAIL_DIR) $(BINS)

.PHONY: $(BINS)
$(BINS):
	$(eval DIFF_R := $(shell ./DiffTest.sh "$@"; echo $$?))
	@if [ $(DIFF_R) -gt 0 ]; \
	then \
		$(ECHO) "["$(RED)fail$(RESET)"] -" "$@" 1>&2; \
	else \
		$(ECHO) "["$(GREEN)Ok$(RESET)"] -" "$@"; \
	fi

$(FAIL_DIR):
	mkdir $@
