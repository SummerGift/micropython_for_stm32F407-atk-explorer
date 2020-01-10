/*
 * COPYRIGHT (C) 2018, Real-Thread Information Technology Ltd
 * 
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2020-01-08     SummerGift   the first version
 */

/**
 * @brief
 *
 * A common driver for STM32 pinmux. Each SoC must implement a SoC
 * specific part of the driver.
 */

#include "pinmux.h"

static int stm32_pinmux_pin_enable(rt_uint32_t pin)
{
    return 0;
}

static int stm32_pinmux_pin_configure(rt_uint8_t pin, rt_uint8_t mode)
{
    return 0;
}

static int stm32_pinmux_pin_set(rt_uint32_t pin, rt_uint8_t mode)
{
    // call rt_pinmux_enable_port
    stm32_pinmux_pin_enable(pin);

    // call rt_pinmux_pin_configure
    stm32_pinmux_pin_configure(pin, mode);

    return 0;
}

rt_err_t _rt_pinmux_setup_pins(const struct pin_config *pinarray, size_t pins)
{
    // loop call rt_pinmux_pin_set
    for (int i = 0; i < pins; i++)
    {
        stm32_pinmux_pin_set(pinarray[i].pin_num, pinarray[i].mode);
    }

    return 0;
}





