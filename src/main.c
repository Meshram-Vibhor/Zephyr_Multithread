/*
 * Copyright (c) 2017 Linaro Limited
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <device.h>
#include <drivers/gpio.h>
#include <sys/printk.h>
#include <sys/__assert.h>
#include <string.h>

/* size of stack area used by each thread */
#define STACKSIZE 1024

/* scheduling priority used by each thread */
#define PRIORITY 7


K_FIFO_DEFINE(printk_fifo);		//For sending messages from thread 1 to thread 2

int sleepTime = 1000;			//initial time in milliseconds
int message = 1;			//Fifo message
void thread1(void)
{
	while(1)
	{
		printk("Thread 1\n");
		//printk("SleepTime = %d\n", sleepTime);
		
		k_msleep(sleepTime);
		sleepTime = sleepTime+1000;
		if(sleepTime>10000)			//Reset time after 10 seconds
		{
			sleepTime=1000;
		}
		k_fifo_put(&printk_fifo, &message);
		
	}
}

void thread2(void)
{
	while(1)
	{
		int *receivedMessage = k_fifo_get(&printk_fifo, K_FOREVER);
		//printk("%d\n", *receivedMessage);
		printk("Thread 2\n");
	}
}

K_THREAD_DEFINE(thread1_id, STACKSIZE, thread1, NULL, NULL, NULL,
		PRIORITY, 0, 0);
K_THREAD_DEFINE(thread2_id, STACKSIZE, thread2, NULL, NULL, NULL,
		PRIORITY, 0, 0);

