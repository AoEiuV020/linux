#!/bin/sh
#	***************************************************
#		^> File Name: fifo.sh
#		^> Author: AoEiuV020
#		^> Mail: 490674483@qq.com
#		^> Created Time: 2015/10/09 - 13:16:59
#	***************************************************
fifoout="fifoout"
if [ ! -p ${fifoout} ]; then
	mkfifo ${fifoout} -m 666
fi
ls -al $fifoout
