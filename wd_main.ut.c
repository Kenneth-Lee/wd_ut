#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UT_DUMPSTACK
#include "comm.h"


#define pr_err(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define dev_info(...) 0
#define pr_info(...) 0
#define vfio_set_irqs_validate_and_prepare(...) 0

static inline void *zalloc(ssize_t size) {
	void *p = malloc(size);
	if(p)
		memset(p, 0, size);
	return p;
}
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

int pci_bus_type;
int platform_bus_type;

#define ULONG_MAX       (~0UL)
int kstrtouint(const char *s, unsigned int base, unsigned int *res) {
	*res = strtoul(s, NULL, base);
	if(*res==ULONG_MAX)
		return -1;
	else
		return 0;
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

#include "wd_main.c"

int wd_platform_mmap_mmio(struct wd_platform_region *sinfo, struct vm_area_struct *vma){
	return 0;
}
void wd_platform_mask(struct wd_platform_irq *irq_ctx) {}
int wd_platform_mask_handler(void *opaque, void *unused) {return 0;}
void wd_platform_unmask(struct wd_platform_irq *irq_ctx){}
int wd_platform_unmask_handler(void *opaque, void *unused){return 0;}
irqreturn_t wd_automasked_irq_handler(int irq, void *dev_id) {return 0;}
irqreturn_t wd_platform_irq_handler(int irq, void *dev_id) {return 0;}
struct resource *wd_get_platform_resource(struct platform_device *pdev,
					      int num) {return NULL;}
int wd_get_platform_irq(struct platform_device *pdev, int i) {return 0;}
int wd_platform_set_trigger(struct wd_platform_info *pinfo, int index,
			    int fd, irq_handler_t handler) {return 0;}
int wd_platform_info_init(struct wd_platform_info *pinfo) {return 0;}
void wd_platform_info_clean(struct wd_platform_info *pinfo) {}

void case_safe_vint(void) {
	int a, b, c, d;
	int ret, size;
	char *str;

	str = " 100, 200, 40000, 0 ";
	size = strlen(str);
	ret = safe_get_uintv(" 100, 200, 40000, 0 ", size, 4, &a, &b, &c, &d);
	ut_assert(!ret);

}

int main(void)
{
	test(100, case_safe_vint);
	return 0;
}
