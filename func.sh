#!/bin/sh
#	***************************************************
#		^> File Name: func.sh
#		^> Author: AoEiuV020
#		^> Mail: 490674483@qq.com
#		^> Created Time: 2015/08/07 - 17:45:58
#	***************************************************
func ()
{
	echo a
	echo b
	return 1
}
func
echo $?
echo $(func)
