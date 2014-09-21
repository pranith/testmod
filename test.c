/*
 * test.c: A sample module to test small pieces of kernel code
 *
 * Author: Pranith Kumar <bobby.prani@gmail.com>
 * License: GPLv2+
 */

#include <linux/module.h>
#include <linux/init.h>
#include <linux/atomic.h>

int val = 0;

static int __init test_init(void)
{
	atomic_t i = ATOMIC_INIT(1);
	pr_info("Loading test module\n");

	smp_mb__before_atomic();
	val = atomic_read(&i);
	smp_mb__after_atomic();

	//val = atomic_add_return(0, &i);
	
	pr_info("val is %d\n", val);

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
