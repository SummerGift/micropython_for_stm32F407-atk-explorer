/*
 * COPYRIGHT (C) 2018, Real-Thread Information Technology Ltd
 * 
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2020-01-08     SummerGift   the first version
 */

#ifndef PINMUX_H__
#define PINMUX_H__

#include <rtthread.h>

#ifdef __cplusplus
extern "C" {
#endif

struct pin_config {
	rt_uint8_t pin_num;
	rt_uint32_t mode;
};

struct pinmux_config {
	rt_uint32_t	base_address;
};

rt_err_t rt_pinmux_setup_pins(const struct pin_config *pinarray, size_t pins);
rt_err_t rt_pinmux_register(rt_err_t *(*pinmux_setup_pins)(), const char *name);

//typedef rt_err_t *(*)(const struct pin_config *, size_t) rt_list_t;  

#define ARRAY_SIZE(array) \
	((long)((sizeof(array) / sizeof((array)[0]))))

#ifdef __cplusplus
}
#endif

#endif /* PINMUX_H__ */
