#include <linux/module.h>

static int __init irqh_init(void) {

	return 0;

}

static void __exit irqh_exit(void) {

	return;

}

MODULE_LICENSE("GPL");
module_init(irqh_init);
module_exit(irqh_exit);