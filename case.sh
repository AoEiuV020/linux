#!/bin/sh
#	***************************************************
#		^> File Name: case.sh
#		^> Author: AoEiuV020
#		^> Mail: 490674483@qq.com
#		^> Created Time: 2015/08/07 - 17:48:20
#	***************************************************
case "$1" in
	y|yes) echo ok;;
	n|no) echo oh;;
	*) echo ?
esac
