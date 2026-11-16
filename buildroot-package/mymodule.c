
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

static int __init mymod_init(void)
{
    printk(KERN_INFO "Hello World\n");
    return 0;
}

static void __exit mymod_exit(void)
{
    printk(KERN_INFO "Bye Bye World\n");
}

module_init(mymod_init);
module_exit(mymod_exit);

MODULE_LICENSE("GPL");
