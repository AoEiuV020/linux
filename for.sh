#!/bin/sh
#	***************************************************
#		^> File Name: for.sh
#		^> Author: AoEiuV020
#		^> Mail: 490674483@qq.com
#		^> Created Time: 2015/08/07 - 17:16:34
#	***************************************************
for file in *
do
	echo $file
	echo a
	break
	echo b
done
for i in {1..4}
do
	echo -n $i,
done
echo 
for((i=0;i<5;++i))
do
	echo -n $i.
done
echo 
i=0
while (($i<6))
do
	echo -n $i,
	i=$(($i+1))
done
echo 
i=0
while [ "$i" != "7" ]
do
	echo -n $i,
	i=$(($i+1))
done
echo 
