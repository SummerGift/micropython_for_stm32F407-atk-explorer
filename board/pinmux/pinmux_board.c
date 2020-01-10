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
	{STM32_PIN_PA2, STM32F4_PINMUX_FUNC_PA2_USART2_TX},
	{STM32_PIN_PA3, STM32F4_PINMUX_FUNC_PA3_USART2_RX},
#endif	/* CONFIG_UART_2 */
#ifdef CONFIG_I2C_1
	{STM32_PIN_PB8, STM32F4_PINMUX_FUNC_PB8_I2C1_SCL},
	{STM32_PIN_PB9, STM32F4_PINMUX_FUNC_PB9_I2C1_SDA},
#endif /* CONFIG_I2C_1 */
#ifdef CONFIG_I2C_2
	{STM32_PIN_PB10, STM32F4_PINMUX_FUNC_PB10_I2C2_SCL},
	{STM32_PIN_PB3, STM32F4_PINMUX_FUNC_PB3_I2C2_SDA},
#endif /* CONFIG_I2C_2 */
#ifdef CONFIG_I2C_3
	{STM32_PIN_PA8, STM32F4_PINMUX_FUNC_PA8_I2C3_SCL},
	{STM32_PIN_PB4, STM32F4_PINMUX_FUNC_PB4_I2C3_SDA},
#endif /* CONFIG_I2C_3 */
#ifdef CONFIG_SPI_1
#ifdef CONFIG_SPI_STM32_USE_HW_SS
	{STM32_PIN_PA4, STM32F4_PINMUX_FUNC_PA4_SPI1_NSS},
#endif /* CONFIG_SPI_STM32_USE_HW_SS */
	{STM32_PIN_PA5, STM32F4_PINMUX_FUNC_PA5_SPI1_SCK},
	{STM32_PIN_PA6, STM32F4_PINMUX_FUNC_PA6_SPI1_MISO},
	{STM32_PIN_PA7, STM32F4_PINMUX_FUNC_PA7_SPI1_MOSI},
#endif	/* CONFIG_SPI_1 */
};

static int pinmux_init()
{
    rt_pinmux_setup_pins(pinconf, ARRAY_SIZE(pinconf));

	return 0;
}
INIT_BOARD_EXPORT(pinmux_init);
