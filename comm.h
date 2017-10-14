#ifndef _COMM_H
#define _COMM_H

#include "ut.c"

typedef long long __le64;
typedef short __le16;
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;
typedef signed long long s64;

typedef u8 __u8;
typedef u16 __u16;
typedef u32 __u32;
typedef u64 __u64;

typedef s32 __s32;
typedef s64 __s64;

typedef u32 uint32_t;
typedef u8 uint8_t;


typedef unsigned long long dma_addr_t;
typedef int bool;
typedef unsigned long size_t;
typedef int irqreturn_t;
typedef int atomic_t;

typedef enum {
	GFP_KERNEL,
	GFP_ATOMIC,
	__GFP_HIGHMEM,
	__GFP_HIGH
} gfp_t;

#define __user
#define PAGE_SHIFT 26
#define VM_SHARED 1
#define PAGE_MASK 0xffff
#define VM_READ 0xf
#define VM_WRITE 0x10
#define VFIO_IRQ_SET_ACTION_TYPE_MASK 0x200

#define THIS_MODULE 0
#define MODULE_VERSION(...)
#define module_init(...)
#define module_exit(...)
#define MODULE_LICENSE(...)
#define MODULE_AUTHOR(...)
#define MODULE_DESCRIPTION(...)
#define MODULE_VERSION(...)
#define MODULE_ALIAS(...)
#define EXPORT_SYMBOL(...)

struct page {
};

typedef irqreturn_t (*irq_handler_t)(int, void *);

struct vfio_device_info {
	__u32	argsz;
	__u32	flags;
#define VFIO_DEVICE_FLAGS_RESET	(1 << 0)	/* Device supports reset */
#define VFIO_DEVICE_FLAGS_PCI	(1 << 1)	/* vfio-pci device */
#define VFIO_DEVICE_FLAGS_PLATFORM (1 << 2)	/* vfio-platform device */
#define VFIO_DEVICE_FLAGS_AMBA  (1 << 3)	/* vfio-amba device */
	__u32	num_regions;	/* Max region index + 1 */
	__u32	num_irqs;	/* Max IRQ index + 1 */
};

struct mutex {};
struct kobject {
	const char		*name;
};

typedef int spinlock_t;
typedef size_t resource_size_t;

#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
#define container_of(ptr, type, member) ({                      \
	const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
	(type *)( (char *)__mptr - offsetof(type,member) );})

#define __iomem


enum dma_data_direction {
	DMA_BIDIRECTIONAL = 0,
	DMA_TO_DEVICE = 1,
	DMA_FROM_DEVICE = 2,
	DMA_NONE = 3,
};

#define DMA_TO_DEVICE 1
#define DMA_FROM_DEVICE 2
#define DMA_BIDIRECTIONAL 3

#define IRQ_HANDLED 1

#define HZ 1

#define IFF_UNICAST_FLT 1
#define NETIF_F_IP_CSUM 0x1 
#define NETIF_F_IPV6_CSUM 0x2
#define NETIF_F_RXCSUM 0x4
#define NETIF_F_SG 0x8
#define NETIF_F_GSO 0xf
#define NETIF_F_GRO 0x10

#define DMA_BIT_MASK(val) (val)

unsigned long jiffies;

//-------real list stub----------------------
struct list_head {
	        struct list_head *next, *prev;
};

#define LIST_HEAD_INIT(name) { &(name), &(name) }

#define LIST_HEAD(name) \
		struct list_head name = LIST_HEAD_INIT(name)

static inline void INIT_LIST_HEAD(struct list_head *list)
{
		list->next = list;
			list->prev = list;
}


#define list_entry(ptr, type, member) \
	        container_of(ptr, type, member)
#define list_first_entry(ptr, type, member) \
	list_entry((ptr)->next, type, member)
#define list_next_entry(pos, member) \
	list_entry((pos)->member.next, typeof(*(pos)), member)
#define list_for_each_entry_rcu(pos, head, member)				\
	for (pos = list_first_entry(head, typeof(*pos), member);	\
	     &pos->member != (head);					\
	     pos = list_next_entry(pos, member))
#define list_for_each(pos, head) \
	for (pos = (head)->next; pos != (head); pos = pos->next)
static inline void list_del_rcu(struct list_head * entry)
{
	entry->prev->next = entry->next;
	entry->next->prev = entry->prev;
}
static inline void list_add_tail_rcu(struct list_head *new, struct list_head *head) {
	new->next = head;
	new->prev = head->prev;
	head->prev->next = new;
	head->prev = new;
}

static inline void __list_add(struct list_head *new, struct list_head *prev,
		struct list_head *next)
{
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}
static inline void list_add(struct list_head *new, struct list_head *head)
{
	__list_add(new, head, head->next);
}
static inline void __list_del(struct list_head * prev, struct list_head * next)
{
	next->prev = prev;
	prev->next = next;
}
static inline void list_del(struct list_head * entry)
{
	__list_del(entry->prev, entry->next);
}



struct hlist_node {};
struct ifreq {};
struct ethtool_cmd {};
struct module {};
struct device_node{};
struct of_device_id
{
	char	name[32];
	char	type[32];
	char	compatible[128];
	const void *data;
};

struct device {
	struct device_node	*of_node; /* associated device tree node */
	void		*driver_data;
	void *bus;
	void *iommu_fwspec;
	struct device		*parent;
	struct class		*class;
	void	(*release)(struct device *dev);

#if 0
	struct device_private	*p;

	struct kobject kobj;
	const char		*init_name;
	const struct device_type *type;

	struct mutex		mutex;

	struct bus_type	*bus;
	struct device_driver *driver;
	void		*platform_data;
	struct dev_pm_info	power;
	struct dev_pm_domain	*pm_domain;

#ifdef CONFIG_PINCTRL
	struct dev_pin_info	*pins;
#endif

#ifdef CONFIG_NUMA
	int		numa_node;	/* NUMA node this device is close to */
#endif
	u64		*dma_mask;	/* dma mask (if dma'able device) */
	u64		coherent_dma_mask;/* Like dma_mask, but for
					     alloc_coherent mappings as
					     not all hardware supports
					     64 bit addresses for consistent
					     allocations such descriptors. */
	unsigned long	dma_pfn_offset;

	struct device_dma_parameters *dma_parms;

	struct list_head	dma_pools;	/* dma pools (if dma'ble) */

	struct dma_coherent_mem	*dma_mem; /* internal for coherent mem
					     override */
#ifdef CONFIG_DMA_CMA
	struct cma *cma_area;		/* contiguous memory area for dma
					   allocations */
#endif
	/* arch specific additions */
	struct dev_archdata	archdata;

	struct acpi_dev_node	acpi_node; /* associated ACPI device node */

	dev_t			devt;	/* dev_t, creates the sysfs "dev" */
	u32			id;	/* device instance */

	spinlock_t		devres_lock;
	struct list_head	devres_head;

	struct klist_node	knode_class;
	const struct attribute_group **groups;	/* optional groups */

	struct iommu_group	*iommu_group;

	struct mbi_data		*mbi;

	bool			offline_disabled:1;
	bool			offline:1;
#endif
};

struct mdev_device {
	struct device dev;
	void *driver_data;
};

struct device *mdev_dev(struct mdev_device *mdev)
{
	return &mdev->dev;
}

struct vm_area_struct {
	unsigned int vm_pgoff;
	unsigned int vm_end;
	unsigned int vm_start;
	unsigned int vm_flags;
	void *vm_private_data;
};

#define SET_NETDEV_DEV(ndev, dev)

struct skb_frag_struct {
	struct {
		struct page *p;
	} page;
	u16 page_offset;
	u16 size;
};

struct platform_device {
        struct device   dev;
#if 0
        const char      *name;
        int             id;
        bool            id_auto;
        u32             num_resources;
        struct resource *resource;

        const struct platform_device_id *id_entry;
        char *driver_override; /* Driver name to force a match */

        /* MFD cell pointer */
        struct mfd_cell *mfd_cell;

        /* arch specific additions */
        struct pdev_archdata    archdata;
#endif
};

struct platform_driver {
        int (*probe)(struct platform_device *);
        int (*remove)(struct platform_device *);
        void (*shutdown)(struct platform_device *);
	/* I don't use this
        int (*suspend)(struct platform_device *, pm_message_t state);
        int (*resume)(struct platform_device *);
        struct device_driver driver;
        const struct platform_device_id *id_table;
	*/
        bool prevent_deferred_probe;
};

#define MODULE_DEVICE_TABLE(a, b)
#define module_platform_driver(str) 

#define likely(str) (str)
#define unlikely(str) (str)

void wmb(void){}
void rmb(void){}

struct sockaddr {
	//sa_family_t	sa_family;	/* address family, AF_xxx	*/
	char		sa_data[14];	/* 14 bytes of protocol address	*/
};

struct phy_device {};

//functions
int dev_emerg(const struct device *dev, const char *fmt, ...)
{ return 0; }
int dev_crit(const struct device *dev, const char *fmt, ...)
{ return 0; }
int dev_alert(const struct device *dev, const char *fmt, ...)
{ return 0; }
int dev_err(const struct device *dev, const char *fmt, ...)
{ return 0; }
int dev_warn(const struct device *dev, const char *fmt, ...)
{ return 0; }
int dev_dbg(const struct device *dev, const char *fmt, ...)
{ return 0; }

#define setup_timer(timer, fn, data)
#define INIT_WORK(_work, _func)
#define DEFINE_SPINLOCK(lock) int lock

struct dev_pm_ops {
	int (*prepare)(struct device *dev);
	void (*complete)(struct device *dev);
	int (*suspend)(struct device *dev);
	int (*resume)(struct device *dev);
	int (*freeze)(struct device *dev);
	int (*thaw)(struct device *dev);
	int (*poweroff)(struct device *dev);
	int (*restore)(struct device *dev);
	int (*suspend_late)(struct device *dev);
	int (*resume_early)(struct device *dev);
	int (*freeze_late)(struct device *dev);
	int (*thaw_early)(struct device *dev);
	int (*poweroff_late)(struct device *dev);
	int (*restore_early)(struct device *dev);
	int (*suspend_noirq)(struct device *dev);
	int (*resume_noirq)(struct device *dev);
	int (*freeze_noirq)(struct device *dev);
	int (*thaw_noirq)(struct device *dev);
	int (*poweroff_noirq)(struct device *dev);
	int (*restore_noirq)(struct device *dev);
	int (*runtime_suspend)(struct device *dev);
	int (*runtime_resume)(struct device *dev);
	int (*runtime_idle)(struct device *dev);
};

struct attribute {              
	const char *name;
	int	mode;
};

struct device_attribute {
	struct attribute	attr;
	ssize_t (*show)(struct device *dev, struct device_attribute *attr,
			char *buf);
	ssize_t (*store)(struct device *dev, struct device_attribute *attr,
			 const char *buf, size_t count);
};

#define __ATTR(_name, _mode, _show, _store) {                           \
	.attr = {.name = #_name,                            \
	.mode = (_mode) },             \
	.show   = _show,                                                \
	.store  = _store,                                               \
}
#define DEVICE_ATTR(_name, _mode, _show, _store) \
	struct device_attribute dev_attr_##_name = __ATTR(_name, _mode, _show, _store)

struct attribute_group {
	const char              *name;
	struct attribute        **attrs;
};

typedef struct pm_message {
	        int event;
} pm_message_t;

struct class {
	const char		*name;
//	struct module		*owner;

	struct class_attribute		*class_attrs;
	const struct attribute_group	**dev_groups;
//	struct kobject			*dev_kobj;

//	int (*dev_uevent)(struct device *dev, struct kobj_uevent_env *env);
//	char *(*devnode)(struct device *dev, umode_t *mode);

	void (*class_release)(struct class *class);
	void (*dev_release)(struct device *dev);

//	int (*suspend)(struct device *dev, pm_message_t state);
	int (*resume)(struct device *dev);

	const struct kobj_ns_type_operations *ns_type;
	const void *(*namespace)(struct device *dev);

	const struct dev_pm_ops *pm;

	struct subsys_private *p;
};

struct vfio_region_info {
	__u32	argsz;
	__u32	flags;
#define VFIO_REGION_INFO_FLAG_READ	(1 << 0) /* Region supports read */
#define VFIO_REGION_INFO_FLAG_WRITE	(1 << 1) /* Region supports write */
#define VFIO_REGION_INFO_FLAG_MMAP	(1 << 2) /* Region supports mmap */
#define VFIO_REGION_INFO_FLAG_CAPS	(1 << 3) /* Info supports caps */
	__u32	index;		/* Region index */
	__u32	cap_offset;	/* Offset within info struct of first cap */
	__u64	size;		/* Region size (bytes) */
	__u64	offset;		/* Region offset from start of device fd */
};

struct vfio_irq_info {
	__u32	argsz;
	__u32	flags;
#define VFIO_IRQ_INFO_EVENTFD		(1 << 0)
#define VFIO_IRQ_INFO_MASKABLE		(1 << 1)
#define VFIO_IRQ_INFO_AUTOMASKED	(1 << 2)
#define VFIO_IRQ_INFO_NORESIZE		(1 << 3)
	__u32	index;		/* IRQ index */
	__u32	count;		/* Number of IRQs within this index */
};

struct vfio_irq_set {
	__u32	argsz;
	__u32	flags;
#define VFIO_IRQ_SET_DATA_NONE		(1 << 0) /* Data not present */
#define VFIO_IRQ_SET_DATA_BOOL		(1 << 1) /* Data is bool (u8) */
#define VFIO_IRQ_SET_DATA_EVENTFD	(1 << 2) /* Data is eventfd (s32) */
#define VFIO_IRQ_SET_ACTION_MASK	(1 << 3) /* Mask interrupt */
#define VFIO_IRQ_SET_ACTION_UNMASK	(1 << 4) /* Unmask interrupt */
#define VFIO_IRQ_SET_ACTION_TRIGGER	(1 << 5) /* Trigger interrupt */
	__u32	index;
	__u32	start;
	__u32	count;
	__u8	data[];
};

#define __init
#define __exit
#define subsys_initcall(str)

#define MAX_ERRNO	4095
#define IS_ERR_VALUE(x) ((x) >= (unsigned long)-MAX_ERRNO)

static inline void * ERR_PTR(long error)
{
	return (void *) error;
}

static inline long PTR_ERR(const void *ptr)
{
	return (long) ptr;
}

static inline bool IS_ERR(const void *ptr)
{
	return IS_ERR_VALUE((unsigned long)ptr);
}

static inline bool IS_ERR_OR_NULL(const void *ptr)
{
	return !ptr || IS_ERR_VALUE((unsigned long)ptr);
}

struct timer_list {};
struct work_struct {};

#define CHECKSUM_NONE           0
#define CHECKSUM_UNNECESSARY    1
#define CHECKSUM_COMPLETE       2
#define CHECKSUM_PARTIAL        3

#define EXPORT_SYMBOL_GPL(cls)

struct mdev_type_attribute {
	struct attribute attr;
	ssize_t (*show)(struct kobject *kobj, struct device *dev, char *buf);
	ssize_t (*store)(struct kobject *kobj, struct device *dev,
			 const char *buf, size_t count);
};
#define MDEV_TYPE_ATTR_RW(_name) \
	struct mdev_type_attribute mdev_type_attr_##_name
#define MDEV_TYPE_ATTR_RO(_name) \
	struct mdev_type_attribute mdev_type_attr_##_name
#define MDEV_TYPE_ATTR_WO(_name) \
	struct mdev_type_attribute mdev_type_attr_##_name

struct mdev_parent_ops {
	struct module   *owner;
	const struct attribute_group **dev_attr_groups;
	const struct attribute_group **mdev_attr_groups;
	struct attribute_group **supported_type_groups;

	int     (*create)(struct kobject *kobj, struct mdev_device *mdev);
	int     (*remove)(struct mdev_device *mdev);
	int     (*open)(struct mdev_device *mdev);
	void    (*release)(struct mdev_device *mdev);
	ssize_t (*read)(struct mdev_device *mdev, char __user *buf,
			size_t count, loff_t *ppos);
	ssize_t (*write)(struct mdev_device *mdev, const char __user *buf,
			 size_t count, loff_t *ppos);
	long	(*ioctl)(struct mdev_device *mdev, unsigned int cmd,
			 unsigned long arg);
	int	(*mmap)(struct mdev_device *mdev, struct vm_area_struct *vma);
};

#define offsetofend(TYPE, MEMBER) (offsetof(TYPE, MEMBER)	+ sizeof(((TYPE *)0)->MEMBER))

#define mutex_init(lock)
#define mutex_lock(lock)
#define mutex_unlock(lock)

#define EINVAL 1
#define ENODEV 2
#define ENOMEM 3
#define EFAULT 4
#define ERANGE 5

struct virqfd{};

void mdev_set_drvdata(struct mdev_device *mdev, void *data)
{
	mdev->driver_data = data;
} 
void *mdev_get_drvdata(struct mdev_device *mdev)
{
	return mdev->driver_data;
}


#define VFIO_DEVICE_GET_INFO 1
#define VFIO_DEVICE_GET_REGION_INFO 2
#define VFIO_DEVICE_GET_IRQ_INFO 3
#define VFIO_DEVICE_SET_IRQS 4
#define VFIO_DEVICE_RESET 5

struct wait_queue_head {};
typedef struct wait_queue_head wait_queue_head_t;

typedef int pid_t;

struct task_struct {};
#endif
