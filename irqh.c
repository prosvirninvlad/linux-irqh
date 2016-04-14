#include <linux/module.h>
#include <linux/interrupt.h>

/* Обработка прерываний от клавиатуры */
#define irqh_line_id 1

/* Счетчик обработки прерывания */
static int irqh_handle_n = 0, irqh_dev_id;

static irqreturn_t irqh_handler(int irq, void *dev_id) {

	irqh_handle_n++;
	return IRQ_NONE;

}

static int __init irqh_init(void) {

	int irqh_reg_res = request_irq(irqh_line_id, irqh_handler, IRQF_SHARED, "irqh_handler", &irqh_dev_id);

	if (irqh_reg_res) {
		return -1;
	}

	return 0;

}

static void __exit irqh_exit(void) {

	synchronize_irq(irqh_line_id);
	free_irq(irqh_line_id, &irqh_dev_id);
	printk(KERN_INFO "IRQ Done = %d\n", irqh_handle_n);

}

MODULE_LICENSE("GPL");
module_init(irqh_init);
module_exit(irqh_exit);