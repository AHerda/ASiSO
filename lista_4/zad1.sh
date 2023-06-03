#!/bin/bash


(#echo "Pid|CMD|PPid|State|TTY|RSS|PGid|Sid|No_Files"

pattern="/proc/[0-9]+"

for file in /proc/*
do
	if [[ $file =~ $pattern ]] && [ -d $file ]
	then
		pid=$(cat $file/status | grep "^Pid" | awk '{print $2}')
		cmd=$(cat $file/status | grep "^Name" | awk '{print $2}')
		ppid=$(cat $file/status | grep "^PPid" | awk '{print $2}')
		state=$(cat $file/status | grep "^State" | awk '{print $2}')
		ttynr=$(cat $file/stat | awk '{print $7}')

		if [ $ttynr -eq 0 ]
		then
			tty="0"
		else
			let ttynr=$ttynr-1024
			tty="tty$ttynr"
		fi

		rss=$(cat $file/stat | awk -v x=24 '{print $x}')
		pgid=$(cat $file/status | grep "^NSpgid" | awk '{print $2}')
		sid=$(cat $file/status | grep "^NSsid" | awk '{print $2}')
		nofiles=$(sudo ls -l $file/fd | wc -l)
		
		echo "$pid|$cmd|$ppid|$state|$tty|$rss|$pgid|$sid|$nofiles"
	fi
done) | sort --key=1 -n | column -t -s "|" --table-columns Pid,CMD,PPid,State,TTY,RSS,PGid,Sid,No_Files
