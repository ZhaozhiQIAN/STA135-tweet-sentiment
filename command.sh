#!/bin/bash
date=`date|sed 's/ //g'`
touch "$date"
touch log
echo "$date" >> log
while [ "a" == "a" ]
do
	echo " "
	echo "get up "
	
	num1="`wc -l $date`"
	twurl --host stream.twitter.com --data 'track=:(&language=en' /1.1/statuses/filter.json >>"$date"
	sed '$d' <$date >tmp
	mv tmp "$date"
	num2="`wc -l $date`"
	num3=""
	let "num3=$num2-$num1"
	echo "disconnected--go_to_sleep at `date `"
	echo "This session has added $num3 tweets"
	sleep 1
	echo "sleep end"
done
