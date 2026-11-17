
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>

static dev_t dev_num;

static int __init mymod_init(void)
{
    int ret;

    printk(KERN_INFO "Hello World\n");

    ret = alloc_chrdev_region(&dev_num, 0, 1, "mymodule");

    if (ret < 0)
    {
        printk(KERN_ERR "Device registration failed\n");
        return ret;
    }

    printk(KERN_INFO "Major number: %d\n", MAJOR(dev_num));

    return 0;
}

static void __exit mymod_exit(void)
{
    unregister_chrdev_region(dev_num, 1);

    printk(KERN_INFO "Bye Bye World\n");
}

module_init(mymod_init);
module_exit(mymod_exit);

MODULE_LICENSE("GPL");

