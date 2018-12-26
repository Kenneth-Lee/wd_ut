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
	__GFP_HIGH,
	__GFP_ZERO
} gfp_t;

#define __user
#define PAGE_SHIFT 26
#define PAGE_SIZE 4096
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

struct file {
	const struct file_operations	*f_op;
	void			*private_data;
#if 0
	/*
	 * Protects f_ep_links, f_flags.
	 * Must not be taken from IRQ context.
	 */
	spinlock_t		f_lock;
	enum rw_hint		f_write_hint;
	atomic_long_t		f_count;
	unsigned int 		f_flags;
	fmode_t			f_mode;
	struct mutex		f_pos_lock;
	loff_t			f_pos;
	struct fown_struct	f_owner;
	const struct cred	*f_cred;
	struct file_ra_state	f_ra;

	u64			f_version;
#ifdef CONFIG_SECURITY
	void			*f_security;
#endif

#ifdef CONFIG_EPOLL
	/* Used by fs/eventpoll.c to link all the hooks to this file */
	struct list_head	f_ep_links;
	struct list_head	f_tfile_llink;
#endif /* #ifdef CONFIG_EPOLL */
	struct address_space	*f_mapping;
	errseq_t		f_wb_err;
#endif
};

struct vm_area_struct {
	unsigned int vm_pgoff;
	unsigned int vm_end;
	unsigned int vm_start;
	unsigned int vm_flags;
	void *vm_private_data;
};

struct inode {
#if 0
	umode_t			i_mode;
	unsigned short		i_opflags;
	kuid_t			i_uid;
	kgid_t			i_gid;
	unsigned int		i_flags;

#ifdef CONFIG_FS_POSIX_ACL
	struct posix_acl	*i_acl;
	struct posix_acl	*i_default_acl;
#endif

	const struct inode_operations	*i_op;
	struct super_block	*i_sb;
	struct address_space	*i_mapping;

#ifdef CONFIG_SECURITY
	void			*i_security;
#endif

	/* Stat data, not accessed from path walking */
	unsigned long		i_ino;
	/*
	 * Filesystems may only read i_nlink directly.  They shall use the
	 * following functions for modification:
	 *
	 *    (set|clear|inc|drop)_nlink
	 *    inode_(inc|dec)_link_count
	 */
	union {
		const unsigned int i_nlink;
		unsigned int __i_nlink;
	};
	dev_t			i_rdev;
	loff_t			i_size;
	struct timespec64	i_atime;
	struct timespec64	i_mtime;
	struct timespec64	i_ctime;
	spinlock_t		i_lock;	/* i_blocks, i_bytes, maybe i_size */
	unsigned short          i_bytes;
	u8			i_blkbits;
	u8			i_write_hint;
	blkcnt_t		i_blocks;

#ifdef __NEED_I_SIZE_ORDERED
	seqcount_t		i_size_seqcount;
#endif

	/* Misc */
	unsigned long		i_state;
	struct rw_semaphore	i_rwsem;

	unsigned long		dirtied_when;	/* jiffies of first dirtying */
	unsigned long		dirtied_time_when;

	struct hlist_node	i_hash;
	struct list_head	i_io_list;	/* backing dev IO list */
#ifdef CONFIG_CGROUP_WRITEBACK
	struct bdi_writeback	*i_wb;		/* the associated cgroup wb */

	/* foreign inode detection, see wbc_detach_inode() */
	int			i_wb_frn_winner;
	u16			i_wb_frn_avg_time;
	u16			i_wb_frn_history;
#endif
	struct list_head	i_lru;		/* inode LRU list */
	struct list_head	i_sb_list;
	struct list_head	i_wb_list;	/* backing dev writeback list */
	union {
		struct hlist_head	i_dentry;
		struct rcu_head		i_rcu;
	};
	atomic64_t		i_version;
	atomic_t		i_count;
	atomic_t		i_dio_count;
	atomic_t		i_writecount;
#ifdef CONFIG_IMA
	atomic_t		i_readcount; /* struct files open RO */
#endif
	const struct file_operations	*i_fop;	/* former ->i_op->default_file_ops */
	struct file_lock_context	*i_flctx;
	struct address_space	i_data;
	struct list_head	i_devices;
	union {
		struct pipe_inode_info	*i_pipe;
		struct block_device	*i_bdev;
		struct cdev		*i_cdev;
		char			*i_link;
		unsigned		i_dir_seq;
	};

	__u32			i_generation;

#ifdef CONFIG_FSNOTIFY
	__u32			i_fsnotify_mask; /* all events this inode cares about */
	struct fsnotify_mark_connector __rcu	*i_fsnotify_marks;
#endif

#if IS_ENABLED(CONFIG_FS_ENCRYPTION)
	struct fscrypt_info	*i_crypt_info;
#endif

	void			*i_private; /* fs or device private pointer */
#endif
};
struct poll_table_struct {
};
#define poll_table struct poll_table_struct
typedef int __poll_t;
typedef int fl_owner_t;
struct file_operations {
	struct module *owner;
	loff_t (*llseek) (struct file *, loff_t, int);
	ssize_t (*read) (struct file *, char __user *, size_t, loff_t *);
	ssize_t (*write) (struct file *, const char __user *, size_t, loff_t *);
	__poll_t (*poll) (struct file *, struct poll_table_struct *);
	long (*unlocked_ioctl) (struct file *, unsigned int, unsigned long);
	long (*compat_ioctl) (struct file *, unsigned int, unsigned long);
	int (*mmap) (struct file *, struct vm_area_struct *);
	int (*open) (struct inode *, struct file *);
	int (*flush) (struct file *, fl_owner_t id);
	int (*release) (struct inode *, struct file *);
	int (*fsync) (struct file *, loff_t, loff_t, int datasync);
	int (*fasync) (int, struct file *, int);
	ssize_t (*sendpage) (struct file *, struct page *, int, size_t, loff_t *, int);
	unsigned long (*get_unmapped_area)(struct file *, unsigned long, unsigned long, unsigned long, unsigned long);
	int (*check_flags)(int);
#if 0
	int (*lock) (struct file *, int, struct file_lock *);
	int (*flock) (struct file *, int, struct file_lock *);
	int (*iterate_shared) (struct file *, struct dir_context *);
	int (*iterate) (struct file *, struct dir_context *);
	ssize_t (*read_iter) (struct kiocb *, struct iov_iter *);
	ssize_t (*write_iter) (struct kiocb *, struct iov_iter *);
	unsigned long mmap_supported_flags;
	ssize_t (*splice_write)(struct pipe_inode_info *, struct file *, loff_t *, size_t, unsigned int);
	ssize_t (*splice_read)(struct file *, loff_t *, struct pipe_inode_info *, size_t, unsigned int);
	int (*setlease)(struct file *, long, struct file_lock **, void **);
	long (*fallocate)(struct file *file, int mode, loff_t offset,
			  loff_t len);
	void (*show_fdinfo)(struct seq_file *m, struct file *f);
#ifndef CONFIG_MMU
	unsigned (*mmap_capabilities)(struct file *);
#endif
	ssize_t (*copy_file_range)(struct file *, loff_t, struct file *,
			loff_t, size_t, unsigned int);
	loff_t (*remap_file_range)(struct file *file_in, loff_t pos_in,
				   struct file *file_out, loff_t pos_out,
				   loff_t len, unsigned int remap_flags);
	int (*fadvise)(struct file *, loff_t, loff_t, int);
#endif
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

typedef int vm_fault_t;

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
#define BIT(n) (1<<n)

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

int list_empty(struct list_head *entry)
{
	return entry->next == entry->prev;
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
	dev_t			devt;
	const struct attribute_group **groups;	/* optional groups */

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

	u32			id;	/* device instance */

	spinlock_t		devres_lock;
	struct list_head	devres_head;

	struct klist_node	knode_class;

	struct iommu_group	*iommu_group;

	struct mbi_data		*mbi;

	bool			offline_disabled:1;
	bool			offline:1;
#endif
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

typedef int pgoff_t;
struct vm_fault {
	struct vm_area_struct *vma;	/* Target VMA */
	unsigned int flags;		/* FAULT_FLAG_xxx flags */
	gfp_t gfp_mask;			/* gfp mask to be used for allocations */
	pgoff_t pgoff;			/* Logical page offset based on vma */
	unsigned long address;		/* Faulting virtual address */
	struct page *page;
#if 0
	pmd_t *pmd;			/* Pointer to pmd entry matching
					 * the 'address' */
	pud_t *pud;			/* Pointer to pud entry matching
					 * the 'address'
					 */
	pte_t orig_pte;			/* Value of PTE at the time of fault */

	struct page *cow_page;		/* Page handler may use for COW fault */
	struct mem_cgroup *memcg;	/* Cgroup cow_page belongs to */
	/* These three entries are valid only while holding ptl lock */
	pte_t *pte;			/* Pointer to pte entry matching
					 * the 'address'. NULL if the page
					 * table hasn't been allocated.
					 */
	spinlock_t *ptl;		/* Page table lock.
					 * Protects pte page table if 'pte'
					 * is not NULL, otherwise pmd.
					 */
	pgtable_t prealloc_pte;		/* Pre-allocated pte page table.
					 * vm_ops->map_pages() calls
					 * alloc_set_pte() from atomic context.
					 * do_fault_around() pre-allocates
					 * page table to avoid allocation from
					 * atomic context.
					 */
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

#define mutex_init(lock)
#define mutex_lock(lock)
#define mutex_unlock(lock)

#define EINVAL 1
#define ENODEV 2
#define ENOMEM 3
#define EFAULT 4
#define ERANGE 5
#define EBUSY 6

#define VM_FAULT_SIGBUS 6

struct wait_queue_head {};
typedef struct wait_queue_head wait_queue_head_t;

typedef int pid_t;

struct mm_struct {
	unsigned long data_vm;
	int mmap_sem;
};
struct task_struct {
	struct mm_struct *mm;
};


#endif
