/*
 * COPYRIGHT (C) 2018, Real-Thread Information Technology Ltd
 * 
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2020-01-08     SummerGift   the first version
 */


#include "pinmux.h"

#define CONFIG_UART_1 1

/* pin assignments for NUCLEO-F411RE board */
static const struct pin_config pinconf[] = {
#ifdef CONFIG_UART_1
	{6, 6},
	{7, 7},
#endif	/* CONFIG_UART_1 */
#ifdef CONFIG_UART_2
	{8, 8},
	{8, 8},
#endif	/* CONFIG_UART_1 */
};

static int pinmux_init()
{
    rt_pinmux_setup_pins(pinconf, ARRAY_SIZE(pinconf));

	return 0;
}
INIT_BOARD_EXPORT(pinmux_init);
