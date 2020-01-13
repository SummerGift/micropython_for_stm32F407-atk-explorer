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

static const struct pin_config pins[] = {
#ifdef CONFIG_UART_1
	{6, 6},
	{7, 7},
#endif	/* CONFIG_UART_1 */
};

static int pinmux_init()
{
    rt_pinmux_setup_pins(pins, RT_ARRAY_SIZE(pins));

	return 0;
}
INIT_BOARD_EXPORT(pinmux_init);
