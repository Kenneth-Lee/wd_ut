TARGET_DIR=~/work/hisi-repo/linux-kernel-warpdrive
CFLAGS=-O0 --static --coverage -g -I general_stub -D __UT__
COMM_FILES=ut.c comm.h

UACCE_DIR=$(TARGET_DIR)/drivers/uacce
QM_DIR=$(TARGET_DIR)/drivers/crypto/hisilicon

all: uacce.ut qm.ut

uacce.ut: uacce.ut.c $(UACCE_DIR)/uacce.c $(COMM_FILES) prepare
	$(CC) $(CFLAGS) -I $(UACCE_DIR) $< -o $@

qm.ut: qm.ut.c $(QM_DIR)/qm.c $(COMM_FILES) prepare
	$(CC) $(CFLAGS) -I $(QM_DIR) $< -o $@

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
