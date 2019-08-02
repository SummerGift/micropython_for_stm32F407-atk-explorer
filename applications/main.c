/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-11-06     SummerGift   first version
 * 2018-11-19     flybreak     add stm32f407-atk-explorer bsp
 */

#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>
#include <dfs_fs.h>
#include <rtdevice.h>

#define FS_PARTITION_NAME     "W25Q128"

/* defined the LED0 pin: PF9 */
#define LED0_PIN    GET_PIN(F, 9)

int main(void)
{
    if (dfs_mount(FS_PARTITION_NAME, "/", "elm", 0, 0) == 0)
    {
        rt_kprintf("Filesystem initialized!");
    }

    rt_thread_mdelay(100);

    extern void mpy_main(const char *filename);
    mpy_main(NULL);

    rt_kprintf("You can enter repl mode by typing python commands.");
    return RT_EOK;
}
