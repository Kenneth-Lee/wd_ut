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

struct iommu_domain {};
struct iommu_domain _iommu_domain;
struct iommu_domain *iommu_get_domain_for_dev(struct device *dev)
{
	return &_iommu_domain;
}

static ut_cnt_def_range(100, 110, iommu_map);
typedef u64 phys_addr_t;
int iommu_map(struct iommu_domain *domain, unsigned long iova,
	      phys_addr_t paddr, size_t size, int prot)
{
	static int case101_cnt = 0;
	static int case103_cnt = 0;

	if (testcase==101)
		if (case101_cnt++==7)
			return -1;

	if (testcase==102)
		return -1;

	if (testcase==103) {
		if (case103_cnt==9)
			return -1;
		case103_cnt++;
	}

	ut_cnt_add_range(100, 110, iommu_map);
	return 0;
}
size_t iommu_unmap(struct iommu_domain *domain, unsigned long iova, size_t size)
{
	ut_cnt_sub_range(100, 110, iommu_map);
}

static ut_cnt_def_range(100, 110, get_page);
void get_page(struct page *page)
{
	ut_cnt_add_range(100, 110, get_page);
}

void put_page(struct page* page)
{
	ut_cnt_sub_range(100, 110, get_page);
}

#include "uacce.c"

void case_iommu_map_qfr(void)
{
	int ret;
	struct uacce uacce;
	struct uacce_queue q;
	struct uacce_qfile_region qfr;
	struct page *pages[10];

	q.uacce = &uacce;
	qfr.pages = pages;
	qfr.nr_pages = 10;

	/* test to pass */
	ret = uacce_iommu_map_qfr(&q, &qfr);
	ut_assert(!ret);
	ut_check_cnt_var_range(100, 110, get_page, 10);
	ut_check_cnt_var_range(100, 110, iommu_map, 10);

	/* fail in the middle */
	testcase = 101;
	ut_cnt_val_range(100, 110, get_page)=0;
	ut_cnt_val_range(100, 110, iommu_map)=0;
	ret = uacce_iommu_map_qfr(&q, &qfr);
	ut_assert(ret==-1);
	ut_check_cnt_range(100, 110, get_page);
	ut_check_cnt_range(100, 110, iommu_map);

	/* fail in the begining */
	testcase = 102;
	ut_cnt_val_range(100, 110, get_page)=0;
	ut_cnt_val_range(100, 110, iommu_map)=0;
	ret = uacce_iommu_map_qfr(&q, &qfr);
	ut_assert(ret==-1);
	ut_check_cnt_range(100, 110, get_page);
	ut_check_cnt_range(100, 110, iommu_map);

	/* fail in the end */
	testcase = 103;
	ut_cnt_val_range(100, 110, get_page)=0;
	ut_cnt_val_range(100, 110, iommu_map)=0;
	ret = uacce_iommu_map_qfr(&q, &qfr);
	ut_assert(ret==-1);
	ut_check_cnt_range(100, 110, get_page);
	ut_check_cnt_range(100, 110, iommu_map);
}

int main(void)
{
	test(100, case_iommu_map_qfr);
	return 0;
}
