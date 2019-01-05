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

struct sysfs_ops {
	ssize_t	(*show)(struct kobject *, struct attribute *, char *);
	ssize_t	(*store)(struct kobject *, struct attribute *, const char *, size_t);
};

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
#define remap_pfn_range(vma, addr, pfn, size, prot) 0
#define page_to_pfn(page) 0
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
#define alloc_chrdev_region(...) 0
#define	unregister_chrdev_region(devt, b)
#define WARN_ON(...)
#define sprintf(...) 0

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
	if (testcase==400)
		return NULL;

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

struct page case201_pages[4];
struct page *alloc_pages(gfp_t gfp_mask, unsigned int order)
{
	switch(testcase) {
	case 200:
		ut_assert(false);
		break;
	case 201:
	case 202:
		return case201_pages;
	}

	return NULL;
}

struct page *alloc_page(gfp_t gfp_mask)
{
	switch(testcase) {
	case 200:
	case 202:
		return (struct page *)1;
	case 201:
		ut_assert(false);
	}

	return NULL;
}

void *kcalloc(size_t n, size_t size, gfp_t flags) {
	if (testcase==202) {
		return NULL;
	}

	return calloc(n, size);
}

int case202_free = 0;
void __free_pages(struct page *page, unsigned int order)
{
	case202_free++;
}

static int vma_pages_ret = 0;
int vma_pages(struct vm_area_struct *vma) {
	return vma_pages_ret;
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
	uacce_iommu_unmap_qfr(&q, &qfr);
	ut_check_cnt_var_range(100, 110, get_page, 0);
	ut_check_cnt_var_range(100, 110, iommu_map, 0);

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

void case_qfr_alloc_pages(void)
{
	int ret;
	struct uacce_qfile_region qfr;
	struct page *pages[10];

	qfr.pages = pages;
	qfr.nr_pages = 10;

	/* test to pass - non-cont page */
	qfr.flags = 0;
	ret = uacce_qfr_alloc_pages(&qfr);
	ut_assert(!ret);

	/* test to pass - cont page */
	testcase = 201;
	qfr.flags |= UACCE_QFRF_CONT_PAGE;
	ret = uacce_qfr_alloc_pages(&qfr);
	ut_assert(!ret);

	/* test to fail - kcalloc fail and free cont page */
	testcase = 202;
	qfr.flags |= UACCE_QFRF_CONT_PAGE;
	ret = uacce_qfr_alloc_pages(&qfr);
	ut_assert(ret);
	ut_assert(case202_free==1);

	/* todo: more test to fail case */
}

void case_qfr_string(void) {
	struct uacce_qfile_region qfr;
	qfr.type = 10; /* use an error type to see if it is crash */
	uacce_qfrt_str(&qfr);
}

void case_map_qfr(void) {
	struct uacce uacce;
	struct uacce_ops ops;
	struct uacce_queue q;
	struct uacce_qfile_region qfr;
	struct page *pages[10];
	int ret;

	q.uacce = &uacce;
	uacce.ops = &ops;
	qfr.pages = pages;
	qfr.nr_pages = 10;

	/* no map req */
	ret = uacce_queue_map_qfr(&q, &qfr);
	ut_assert(!ret);
	uacce_queue_unmap_qfr(&q, &qfr);

	qfr.flags = UACCE_QFRF_MAP;
	ret = uacce_queue_map_qfr(&q, &qfr);
	ut_assert(ret);
	uacce_queue_unmap_qfr(&q, &qfr);
}

void case_create_region(void) {
	struct uacce_queue q;
	struct uacce_qfile_region *qfr;
	struct vm_area_struct vma;
	int ret;

	qfr = uacce_create_region(&q, &vma, 0, 0);
	ut_assert(qfr);
	uacce_destroy_region(qfr);
}

int case_start_queue_check = 0;
int start_queue_case_start_queue(struct uacce_queue *q) {
	if (testcase == 601) {
		return -1;
	}

	case_start_queue_check++;
	return 0;
}

void case_start_queue(void) {
	struct uacce_queue q;
	struct uacce uacce;
	struct uacce_ops ops;
	int ret, i;

	q.uacce = &uacce;
	uacce.ops = &ops;
	ops.start_queue = start_queue_case_start_queue;

	for (i=0; i<UACCE_QFRT_MAX; i++)
		q.qfrs[i] = NULL;

	ret = uacce_start_queue(&q);
	ut_assert(case_start_queue_check==1);
	ut_assert(!ret);

	testcase = 601;
	ret = uacce_start_queue(&q);
	ut_assert(ret);
}

void case_get_region_type(void) {
	enum uacce_qfrt type;
	struct uacce uacce;
	struct uacce_ops ops;
	struct vm_area_struct vma;
	int i;

#define CLEAR_QFRS do { \
	for (i=0; i<UACCE_QFRT_MAX; i++) \
		ops.qf_pg_start[i] = UACCE_QFR_NA; \
	ops.flags = 0; \
}while(0)

	uacce.ops = &ops;

	vma.vm_pgoff = 10; /* 10 page as start */
	vma_pages_ret = 20; /* size is 20 page */

	/* All invalid */
	CLEAR_QFRS;
	type = uacce_get_region_type(&uacce, &vma);
	ut_assert(type == UACCE_QFRT_INVALID);

	/* only ss, not in range */
	CLEAR_QFRS;
	ops.qf_pg_start[UACCE_QFRT_SS] = 30;
	type = uacce_get_region_type(&uacce, &vma);
	ut_assert(type == UACCE_QFRT_INVALID);

	/* only ss, in range */
	CLEAR_QFRS;
	ops.qf_pg_start[UACCE_QFRT_SS] = 10;
	type = uacce_get_region_type(&uacce, &vma);
	ut_assert(type == UACCE_QFRT_SS);

	/* only mmio ss, in mmio */
	CLEAR_QFRS;
	ops.qf_pg_start[UACCE_QFRT_MMIO] = 10;
	ops.qf_pg_start[UACCE_QFRT_SS] = 30;
	ops.mmap = (int (*)(struct uacce_queue *q,
		struct vm_area_struct *vma,
		struct uacce_qfile_region *qfr))1;
	type = uacce_get_region_type(&uacce, &vma);
	ut_assert_str(type == UACCE_QFRT_MMIO, "type=%d", type);

	/* only mmio ss, in mmio, bad size */
	CLEAR_QFRS;
	ops.qf_pg_start[UACCE_QFRT_MMIO] = 10;
	ops.qf_pg_start[UACCE_QFRT_SS] = 40;
	ops.mmap = (int (*)(struct uacce_queue *q,
		struct vm_area_struct *vma,
		struct uacce_qfile_region *qfr))1;
	type = uacce_get_region_type(&uacce, &vma);
	ut_assert_str(type == UACCE_QFRT_INVALID, "type=%d", type);

	/* only dko ss, in dko, good size */
	CLEAR_QFRS;
	ops.qf_pg_start[UACCE_QFRT_DKO] = 10;
	ops.qf_pg_start[UACCE_QFRT_SS] = 30;
	type = uacce_get_region_type(&uacce, &vma);
	ut_assert_str(type == UACCE_QFRT_DKO, "type=%d", type);

	/* only dko ss, in dko, bad size */
	CLEAR_QFRS;
	ops.qf_pg_start[UACCE_QFRT_DKO] = 10;
	ops.qf_pg_start[UACCE_QFRT_SS] = 40;
	type = uacce_get_region_type(&uacce, &vma);
	ut_assert_str(type == UACCE_QFRT_INVALID, "type=%d", type);

	/* have all, in dus, good size */
	CLEAR_QFRS;
	ops.qf_pg_start[UACCE_QFRT_MMIO] = 0;
	ops.qf_pg_start[UACCE_QFRT_DKO] = 2;
	ops.qf_pg_start[UACCE_QFRT_DUS] = 10;
	ops.qf_pg_start[UACCE_QFRT_SS] = 30;
	type = uacce_get_region_type(&uacce, &vma);
	ut_assert_str(type == UACCE_QFRT_DUS, "type=%d", type);
}

int main(void)
{
	test(100, case_iommu_map_qfr);
	test(200, case_qfr_alloc_pages);
	test(300, case_qfr_string);
	test(400, case_map_qfr);
	test(500, case_create_region);
	test(600, case_start_queue);
	test(700, case_get_region_type);
	return 0;
}
