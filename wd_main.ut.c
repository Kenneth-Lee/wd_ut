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

/*
#define vfio_set_irqs_validate_and_prepare(...) 0

#define kzalloc(size, flags) malloc(size)
#define kfree(p) free(p)
#define copy_from_user(from, to, n) memcpy(from, to, n)
#define copy_to_user(to, from, n) memcpy(from, to, n)

#define to_platform_device(dev) 0
#define symbol_get(sym) 0
#define symbol_put(sym)

void *memdup_user(const void __user *src, size_t len) {
	void * p = malloc(len);
	if(p)
		memcpy(p, src, len);

	return p;
}

int vfio_virqfd_enable(void *opaque,
		       int (*handler)(void *, void *),
		       void (*thread)(void *, void *),
		       void *data, struct virqfd **pvirqfd, int fd)
{
	return 0;
}

void vfio_virqfd_disable(struct virqfd **pvirqfd){}

#define mdev_register_device(...) 0
#define mdev_unregister_device(...)
*/

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

long simple_strtol(const char *cp, char **endp, unsigned int base) {
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

int main(void)
{
	//test(100, case_safe_vint);
	return 0;
}
