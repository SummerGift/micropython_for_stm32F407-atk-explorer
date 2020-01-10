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

extern rt_err_t _rt_pinmux_setup_pins(const struct pin_config *pinarray, size_t pins);

rt_err_t rt_pinmux_setup_pins(const struct pin_config *pinarray, size_t pins)
{
    return _rt_pinmux_setup_pins(pinarray, pins);
}
