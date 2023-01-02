/*
 * Aktorik.h
 *
 *  Created on: 01.05.2022
 *      Author: Andrei
 */

/* Interrupt numbers  (spruh73l.pdf S.465 ff.) */
#ifndef SORTIERANLAGE_H_
#define SORTIERANLAGE_H_
#define NUM_THREADS 4
#include "ThreadPool.h"
#include "HAL/InterruptHandler.h"
#include "HAL/GPIO.h"
#include <cstddef>
#include <iostream>
#include <stdio.h>
#include <limits.h>

class Sortieranlage{
public:
	//int main();
	Sortieranlage();
	virtual ~Sortieranlage();
	ThreadPool givethreadpool() const;
	ThreadPool threadpool;
};
#endif
