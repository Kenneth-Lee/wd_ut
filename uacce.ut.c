#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UT_DUMPSTACK
#include "comm.h"

#define pr_err(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define dev_info(...) 0
#define pr_info(...) 0
#define pr_debug(...) 0

#define GFP_KERNEL 0
static inline void *kzalloc(ssize_t size, gfp_t gfp) {
	void *p = malloc(size);
	if(p)
		memset(p, 0, size);
	return p;
}
static inline void *kfree(void *p) {
	free(p);
}

struct vm_operations_struct {
	vm_fault_t (*fault)(struct vm_fault *vmf);
};

#define VM_DONTCOPY 1
#define VM_DONTEXPAND 2

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
#define class_create(...) NULL
#define class_destroy(...)
#define PTR_ERR_OR_ZERO(...) 0
#define wake_up_interruptible(wait)
#define iommu_get_domain_for_dev(dev) NULL
#define get_page(page)
#define put_page(page)
#define iommu_map(domain, addr, phy, size, prot) 0
#define iommu_unmap(domain, addr, size)
#define page_to_phys(page) 0
#define down_read(lock)
#define up_read(lock)
#define down_write(lock)
#define up_write(lock)
#define read_lock_irq(lock)
#define read_unlock_irq(lock)
#define write_lock_irq(lock)
#define write_unlock_irq(lock)
#define get_order(size) 0
#define alloc_pages(gfp_mask, order) 0
#define kcalloc(n, bs, gfp_mask) NULL
#define alloc_page(gfp_mask) NULL
#define __free_pages(pages, order)
#define remap_pfn_range(vma, addr, pfn, size, prot) 0
#define page_to_pfn(page) 0
#define vma_pages(vma) 0
#define vunmap(kaddr)
#define fget(fd) NULL
#define vmap(pages, nr_pages, f1, f2) NULL
#define atomic_set(var, data)
#define atomic_cmpxchg(var, v1, v2) 0
#define idr_find(idr, id) NULL
#define iminor(inode) 0
#define atomic_read(var) 0
#define rlimit(type) 0
#define poll_wait(file, wait, time);
#define idr_alloc(idr, uacce, a, b, gfp) 0
#define	cdev_init(cdev, fops)
#define	device_initialize(dev)
#define	MKDEV(major, minior) 0
#define	MAJOR(devt) 0
#define	cdev_device_add(cdev, dev) 0
#define	idr_remove(idr, dev_id)
#define	idr_destroy(idr)
#define	cdev_device_del(cdev, dev)
#define class_for_each_device(uacce_class, a, pdev, match) 0
#define iommu_domain_alloc(bus) NULL
#define iommu_attach_device(domain, dev) 0
#define	iommu_detach_device(domain, pdev)
#define iommu_capable(bus, a) 0
#define iommu_domain_free(domain)
#define alloc_chrdev_region(devt, a, b, name) 0
#define	unregister_chrdev_region(devt, b)

#define false 0
#define true 1

#define EPOLLIN 1
#define EPOLLRDNORM 2

#define IOMMU_READ 1
#define IOMMU_WRITE 2
#define IOMMU_CACHE 4
#define S_IRUGO 0

#define VM_MAP 0

#define ATOMIC_INIT(n) (n)
#define _IOW(a, b, type) (100+a+b)

#define DEVICE_ATTR(a, b, c, d) struct device_attribute dev_attr_##a
#define DEVICE_ATTR_RW(name) DEVICE_ATTR(name, 0, 0, 0)
#define DEVICE_ATTR_RO(name) DEVICE_ATTR(name, 0, 0, 0)

struct task_struct *current;
struct cdev{
	struct module *owner;
#if 0
	struct kobject kobj;
	const struct file_operations *ops;
	struct list_head list;
	dev_t dev;
	unsigned int count;
#endif
};

#define DEFINE_IDR(name) int name
#define DEFINE_MUTEX(name) int name
#define DECLARE_RWSEM(name) int name
#define DEFINE_RWLOCK(name) int name


#include "uacce.c"

int main(void)
{
	return 0;
}
