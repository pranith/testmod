/*
 * test.c: A sample module to test small pieces of kernel code
 *
 * Author: Pranith Kumar <bobby.prani@gmail.com>
 * License: GPLv2+
 */

#include <linux/module.h>
#include <linux/init.h>

static int __init test_init(void)
{
	atomic_t i = ATOMIC_INIT(0);
	pr_info("Loading test module\n");

	smp_mb__before_atomic();
	atomic_inc(&i);
	smp_mb__after_atomic();

	atomic_add_return(1, &i);
	
	pr_info("val is %d\n", atomic_read(&i));

	return 0;
}

static void __exit test_exit(void)
{
	pr_info("Unloading test module.\n");
        return;
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
