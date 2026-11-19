
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/fs.h>

static dev_t dev_num;
static struct cdev my_cdev;
static struct class *my_class;
static const struct file_operations my_fops = {
    .owner = THIS_MODULE,
};

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

    cdev_init(&my_cdev, &my_fops);
    ret = cdev_add(&my_cdev, dev_num, 1);

    if (ret < 0)
    {
        printk(KERN_ERR "cdev_add failed\n");
        unregister_chrdev_region(dev_num, 1);
        return ret;
    }
    my_class = class_create("mymodule");

    if (IS_ERR(my_class))
    {
        printk(KERN_ERR "class_create failed\n");
        ret = PTR_ERR(my_class);
        cdev_del(&my_cdev);
        unregister_chrdev_region(dev_num, 1);
        return ret;
    }
    if (IS_ERR(device_create(my_class, NULL, dev_num, NULL, "mymodule")))
    {
        printk(KERN_ERR "device_create failed\n");
        class_destroy(my_class);
        cdev_del(&my_cdev);
        unregister_chrdev_region(dev_num, 1);
        return -ENOMEM;
    }

    printk(KERN_INFO "Major number: %d\n", MAJOR(dev_num));

    return 0;
}

static void __exit mymod_exit(void)
{
    device_destroy(my_class, dev_num);
    class_destroy(my_class);



    cdev_del(&my_cdev);
    unregister_chrdev_region(dev_num, 1);

    printk(KERN_INFO "Bye Bye World\n");
}

module_init(mymod_init);
module_exit(mymod_exit);

MODULE_LICENSE("GPL");

