#include <linux/module.h>
#include <linux/init.h>

static int __init test_init(void)
{
	char buf[] = "This is a test\nand this should print\neach line separately\nor else";

	char *tmpbuf = buf, c;

	int used = sizeof(buf), size_pr;
	int max_iterations = 20, iter = 0;
 	printk ("My module worked!\n");
	pr_alert("%d\n", used);
	while (used > 0 && iter < max_iterations) {
		iter++;
		size_pr = strcspn(tmpbuf, "\n");
		c = tmpbuf[size_pr + 1];
		tmpbuf[size_pr + 1] = '\0';
		pr_alert("used: %d\nsize_pr before: %d\n", used, size_pr);
		size_pr = pr_alert("%s", tmpbuf);
		pr_alert("size_pr pr_alert: %d\n", size_pr);
		size_pr = printk(KERN_ALERT "%s", tmpbuf);
		pr_alert("size_pr printk: %d\n", size_pr);
		tmpbuf[size_pr + 1] = c;
		used -= (size_pr + 1);
		tmpbuf  += size_pr + 1;
	}
	return 0;
}

static void __exit test_exit(void)
{
 printk ("Unloading my module.\n");
        return;
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
