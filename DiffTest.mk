FAIL_DIRS	:= fails fails/nm fails/otool
DIFF		:= diff
BIN_DIR		:= /bin /usr/bin /usr/sbin /usr/libexec
LIB_DIR		:= /usr/lib

BINS		:= $(shell find $(BIN_DIR) -type f 2>&-)
LIBS		:= $(shell find $(LIB_DIR) -type f \( -iname '*.dylib' -or -iname '*.so' -or -iname '*.a' \))

NM_BINS		:= $(addprefix nm\ , $(BINS))
NM_LIBS		:= $(addprefix nm\ , $(LIBS))
OTOOL_BINS	:= $(addprefix otool\ , $(BINS))
OTOOL_LIBS	:= $(addprefix otool\ , $(LIBS))

.PHONY: test_all
test_all: test_nm_bin test_nm_libs

.PHONY: test_nm_bin
test_nm_bin: all $(FAIL_DIRS) $(NM_BINS)

.PHONY: test_nm_libs
test_nm_libs: all $(FAIL_DIRS) $(NM_LIBS)

.PHONY: test_otool_bin
test_otool_bin: all $(FAIL_DIRS) $(OTOOL_BINS)

.PHONY: test_otool_libs
test_otool_libs: all $(FAIL_DIRS) $(OTOOL_LIBS)

nm\ /%:
	$(eval DIFF_R := $(shell ./DiffTest.sh nm "" "/$*"; echo $$?))
	@if [ $(DIFF_R) -gt 0 ]; \
	then \
		$(ECHO) "["$(RED)fail$(RESET)"] -" "$@" 1>&2; \
	else \
		$(ECHO) "["$(GREEN)Ok$(RESET)"] -" "$@"; \
	fi

otool\ /%:
	$(eval DIFF_R := $(shell ./DiffTest.sh otool "-t" "/$*"; echo $$?))
	@if [ $(DIFF_R) -gt 0 ]; \
	then \
		$(ECHO) "["$(RED)fail$(RESET)"] -" "$@" 1>&2; \
	else \
		$(ECHO) "["$(GREEN)Ok$(RESET)"] -" "$@"; \
	fi

$(FAIL_DIRS):
	mkdir $@
