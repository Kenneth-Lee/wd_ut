TARGET_DIR=~/work/hisi-repo/linux-kernel-warpdrive
TESTED_DIR=$(TARGET_DIR)/drivers/uacce
TESTED_DIR1=$(TARGET_DIR)/drivers/crypto/hisilicon
CFLAGS=-O0 --static --coverage -g -I general_stub -I $(TESTED_DIR) -I $(TESTED_DIR1) -D __UT__
COMM_FILES=ut.c comm.h

all: uacce.ut qm.ut

%.ut: %.ut.c
	$(CC) $(CFLAGS) $< -o $@

uacce.ut: uacce.ut.c $(TESTED_DIR)/uacce.c $(COMM_FILES) prepare
qm.ut: qm.ut.c $(TESTED_DIR)/uacce.c $(COMM_FILES) prepare

test: all
	@echo "test uacce:"
	@(./uacce.ut 2> ut.log)
	@!(sed '/^[^0]/d' ut.log |addr2line -e uacce.ut |grep -v "ut/ut.c")
	@echo "test qm:"
	@(./qm.ut 2> ut.log)
	@!(sed '/^[^0]/d' ut.log |addr2line -e uacce.ut |grep -v "ut/ut.c")

clean:
	@rm -f *.ut *.o *.log *.out core *.gcda *.gcno lcov.log ut.info
	@rm -rf testreport

prepare:
	ln -sf $(TARGET_DIR)/include/linux/uacce.h general_stub/linux/uacce.h
	ln -sf $(TARGET_DIR)/include/uapi/linux/uacce.h general_stub/uapi/linux/uacce.h

report:
	lcov -c -d . -o ut.info
	genhtml ut.info -o testreport

.PHONY: clean test all prepare report
