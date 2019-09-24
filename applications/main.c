/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-11-06     SummerGift   first version
 * 2018-11-19     flybreak     add stm32f407-atk-explorer bsp
 * 2019-09-24     SummerGift   micropython support
 */

#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>
#include <dfs_fs.h>
#include <rtdevice.h>

#define FS_PARTITION_NAME     "W25Q128"

int main(void)
{
    if (dfs_mount(FS_PARTITION_NAME, "/", "elm", 0, 0) == 0)
    {
        rt_kprintf("Filesystem initialized!");
    }
    else
    {
        dfs_mkfs("elm", FS_PARTITION_NAME);
        if (dfs_mount(FS_PARTITION_NAME, "/", "elm", 0, 0) == 0)
        {
            rt_kprintf("Failed to initialize filesystem! The mpy fs module is not available.");
        }
    }

    rt_thread_mdelay(100);

    while(1)
    {
        extern void mpy_main(const char *filename);
        mpy_main(NULL);
    }

    return RT_EOK;
}
