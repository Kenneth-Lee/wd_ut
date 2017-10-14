#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UT_DUMPSTACK
#include "comm.h"

#define pr_err(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define dev_info(...) 0
#define pr_info(...) 0

#define GFP_KERNEL 0
//typedef gfp_t int;
static inline void *kzalloc(ssize_t size, gfp_t gfp) {
	void *p = malloc(size);
	if(p)
		memset(p, 0, size);
	return p;
}
static inline void *kfree(void *p) {
	free(p);
}

#define init_waitqueue_head(...)
#define __module_get(...)
#define module_put(...)
#define wake_up(...)
#define msecs_to_jiffies(...) 0
#define wait_event_interruptible_timeout(...) 0
#define wait_event_interruptible(...) 0
#define dev_driver_string(...) NULL
#define atomic_inc_return(...) 0
#define dev_set_name(...) 0
#define dev_name(...) "dev"
#define device_register(...) 0
#define device_unregister(...)
#define mdev_register_device(...) 0
#define mdev_unregister_device(...)
#define class_create(...) NULL
#define class_destroy(...)
#define PTR_ERR_OR_ZERO(...) 0

#define ATOMIC_INIT(n) (n)
#define _IOW(a, b, type) (100+a+b)

struct device *mdev_parent_dev(struct mdev_device *mdev)
{
	return NULL;
}

static inline int kstrtol(const char *s, unsigned int base, long *res) {
	switch(testcase) {
		case 102:
			return -ERANGE;
		case 103:
			*res = 0;
			break;
		case 104:
			*res = 99;
			break;
		case 105:
			*res = -99;
			break;
		case 106:
			*res = 15;
			break;
	}

	return 0;
}

#define DEVICE_ATTR_RW(_name) \
	struct device_attribute dev_attr_##_name;
#define DEVICE_ATTR_RO(_name) \
	struct device_attribute dev_attr_##_name;

struct mdev_device *mdev_from_dev(struct device *dev)
{
	return NULL;
}

struct task_struct *current;
static inline pid_t task_pid_nr(struct task_struct *tsk) {
	return 0;
}

#include "wd_main.c"

static void case_priority_store(void) {
	struct device dev;
	struct wd_dev wdev;
	size_t s;

	wdev.priority = 50;

	/* no wdev */
	testcase = 101;
	dev.driver_data = NULL;
	s = priority_store(&dev, NULL, "10", 3);
	ut_assert(s == -EINVAL);
	ut_assert(wdev.priority == 50);

	dev.driver_data = &wdev;

	testcase = 102;
	s = priority_store(&dev, NULL, "10", 3);
	ut_assert(s == -EINVAL);
	ut_assert(wdev.priority == 50);

	testcase = 103;
	s = priority_store(&dev, NULL, "10", 3);
	ut_assert(s == 3);
	ut_assert(wdev.priority == 0);

	testcase = 104;
	s = priority_store(&dev, NULL, "10", 3);
	ut_assert(s == 3);
	ut_assert(wdev.priority == 99);

	testcase = 105;
	s = priority_store(&dev, NULL, "10", 3);
	ut_assert(s == 3);
	ut_assert(wdev.priority == -99);

	testcase = 106;
	s = priority_store(&dev, NULL, "10", 3);
	ut_assert(s == 3);
	ut_assert(wdev.priority == 15);
}

int main(void)
{
	test(100, case_priority_store);
	return 0;
}
