TARGET_DIR=~/work/hisi-repo/kernel-dev/drivers/crypto/hisilicon/wd
CFLAGS=-O0 --coverage -g -I general_stub -I $(TARGET_DIR) 
COMM_FILES=ut.c comm.h

all: wd_main.ut

wd_main.ut: wd_main.ut.c $(TARGET_DIR)/wd_main.c $(COMM_FILES)
	$(CC) $(CFLAGS) $< -o $@

test: all
	@./wd_main.ut 2> ut.log
	@!(sed '/^[^0]/d' ut.log |addr2line -e wd_main.ut |grep -v "ut/ut.c")

clean:
	@rm -f *.ut *.o *.log *.out core *.gcda *.gcno lcov.log
	@rm -rf out

.PHONY: clean test all
