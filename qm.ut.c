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

#define rwlock_t int
struct completion{};
struct pci_dev {
	struct device dev;
	int devfn;
	int is_physfn;
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
#define writel(...)
#define readl_relaxed_poll_timeout(...) 0
#define lower_32_bits(...) 0
#define upper_32_bits(...) 0
#define writeq(...)
#define readl(...) 0
#define read_lock(...)
#define read_unlock(...)
#define write_lock(...)
#define write_unlock(...)
#define dma_rmb(...)
#define find_first_zero_bit(...) 0
#define set_bit(...)
#define dma_alloc_coherent(...) 0
#define	bitmap_clear(...) 0
#define ilog2(...) 0
#define init_completion(...)
#define dma_free_coherent(...)
#define wait_for_completion_timeout(...)
#define pci_set_power_state(...)
#define pci_write_config_word(...)
#define pci_enable_device_mem(...) 0
#define pci_request_mem_regions(...) 0
#define pci_resource_start(...) 0
#define	pci_resource_len(...) 0
#define devm_ioremap(...) 0
#define	dma_set_mask_and_coherent(...)
#define	pci_set_master(...)
#define pci_alloc_irq_vectors(...) 0
#define rwlock_init(...)
#define devm_request_threaded_irq(...) 0
#define pci_irq_vector(...) 0
#define devm_kcalloc(...) 0
#define BITS_TO_LONGS(...) 0
#define max_t(...) 0
#define devm_free_irq(...)
#define pci_free_irq_vectors(...)
#define pci_release_mem_regions(...)
#define pci_disable_device(...)

#define false 0
#define true 1

#define EPOLLIN 1
#define EPOLLRDNORM 2

#define IRQ_WAKE_THREAD 0
#define PCI_D0 0
#define PCI_COMMAND 0
#define PCI_IRQ_MSI 0

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

#include "qm.c"

void case_(void) {
}

int main(void)
{
	test(100, case_);
	return 0;
}
