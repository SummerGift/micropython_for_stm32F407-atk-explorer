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

rt_err_t *(*_pinmux_setup_pins)(const struct pin_config *, size_t) = RT_NULL;

rt_err_t rt_pinmux_setup_pins(const struct pin_config *pinarray, size_t pins)
{
    return *_pinmux_setup_pins(pinarray, pins);
}

rt_err_t rt_pinmux_register(rt_err_t *(*pinmux_setup_pins)(), const char *name)
{
    rt_err_t result = RT_EOK;
    _pinmux_setup_pins = pinmux_setup_pins;
}