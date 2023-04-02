#!/bin/bash

wypiszWykresPobrane () {
	(for j in {1..10}
	do
		local liczba=$(echo "$max_pobrane/10*(10-$j)" | bc)
		echo -n "$liczba-|"
		for i in "${pobrane[@]}"
		do
			if [[ $i -gt $liczba ]]
			then
				echo -en "\e[102m \e[40m"
			else
				echo -en "\e[107m \e[40m"
			fi
		done
		echo -en "\n"
	done
	echo "|------------------------------") | column -t -s "|" -o "|"
}

wypiszWykresWyslane () {
	(for j in {1..10}
	do
		local liczba=$(echo "$max_wyslane/10*(10-$j)" | bc)
		echo -n "$liczba-|"
		for i in "${wyslane[@]}"
		do
			if [[ $i -gt $liczba ]]
			then
				echo -en "\e[102m \e[40m"
			else
				echo -en "\e[107m \e[40m"
			fi
		done
		echo -en "\n"
	done
	echo "|------------------------------") | column -t -s "|" -o "|"
}

declare -a pobrane
declare -a wyslane
declare -i iwyslane
declare -i ipobrane
declare -i ipobrane_stare
declare -i iwyslane_stare

ipobrane_stare=$(cat /proc/net/dev | grep "enp0" | awk '{print $2}')
iwyslane_stare=$(cat /proc/net/dev | grep "enp0" | awk -v x=10 '{print $x}')

for i in  {0..29}
do
	pobrane[i]=0
	wyslane[i]=0
done


linia="---------------------------------------------|--------"
while true
do
	clear

	# Wypisywanie uptime
	
	uptime=$(cat /proc/uptime | awk '{print $1}')
	(echo -e "\e[33mUpTime\e[37m"
	echo "Days:|" $(echo "$uptime/86400" | bc)
	echo "Hours:|" $(echo "$uptime%86400/3600" | bc)
	echo "Minute:|" $(echo "$uptime%86400%3600/60" | bc)
	echo "Seconds:|" $(echo "$uptime%86400%3600%60" | bc)

	echo "$linia"

	# Wypisywanie baterii

	echo -en "\e[33mBateria:\e[37m|"
	baterie=$(cat /sys/class/power_supply/BAT0/uevent | grep "POWER_SUPPLY_ENERGY_FULL=" | awk -F "=" '{print $2}')
	actual_baterie=$(cat /sys/class/power_supply/BAT0/uevent | grep "POWER_SUPPLY_ENERGY_NOW=" | awk -F "=" '{print $2}')
	sto=100
	echo -e $(echo "scale=1 ; $actual_baterie/$baterie*100" | bc -l) "%\n$linia"

	# Wypisywanie obiciazenie systemu

	echo -e "\e[33mSrednie obciazenie systemu\e[37m"
	echo "Z ostatniej minuty:|" $(cat /proc/loadavg | awk '{print $1}')
	echo "Z ostatnich 5 minut:|" $(cat /proc/loadavg | awk '{print $2}')
	echo -e "Z ostatnich 15 minut:|" $(cat /proc/loadavg | awk '{print $3}') "\n$linia"

	# Wypisywanie pamieci

	mem_total=$(cat /proc/meminfo | grep "^MemTotal" | awk '{print $2}')
	mem=$(cat /proc/meminfo | grep "^MemFree" | awk '{print $2}')
	echo -e "\e[33mAktualne wykorzystanie pamieci:\e[37m|" $(echo "scale=1; ($mem_total-$mem)/$mem_total*100" | bc -l) "%"
	
	echo "$linia"

	# Wypisywanie wykorzystania procesora

	echo -e "\n\e[33mWykorzystanie CPU\e[37m"

	notidle=$(sed '2q;d' /proc/stat | awk '{print $2+$3+$4+$6+$7+$8}')
	total=$(sed '2q;d' /proc/stat | awk '{print $2+$3+$4+$5+$6+$7+$8}')
	cpu0=$(echo "x=($notidle/$total)*100; scale=2; x/1" | bc)

	cherce=$(cat /proc/cpuinfo | grep "MHz" | awk '{print $4}')

	echo "CPU0:|${cpu0}% $cherce MHz") | column -t -s "|" -o "|"
	
	# Wykres danych z sieci

	echo -e "\n\e[33mWykres danych sieci\e[37m"

	ipobrane=$(cat /proc/net/dev | grep "enp0" | awk '{print $2}')
	iwyslane=$(cat /proc/net/dev | grep "enp0" | awk -v x=10 '{print $x}')

	max_pobrane=0
	avg_wyslane=0
	max_wyslane=0
	avg_pobrane=0

	for i in {29..0}
	do
		avg_pobrane=$(echo "$avg_pobrane+${pobrane[i]}" | bc)
		avg_wyslane=$(echo "$avg_wyslane+${wyslane[i]}" | bc)
		if [ $i -ne 0 ]
		then
			pobrane[i]=${pobrane[i-1]}
			wyslane[i]=${wyslane[i-1]}
		else
			pobrane[i]=$(echo "$ipobrane-$ipobrane_stare" | bc)
			wyslane[i]=$(echo "$iwyslane-$iwyslane_stare" | bc)
		fi
		
		if [[ ${pobrane[i]} -gt $max_pobrane ]]
		then
			max_pobrane=${pobrane[i]}
		fi

		if [[ ${wyslane[i]} -gt $max_wyslane ]]
		then
			max_wyslane=${wyslane[i]}
		fi
	done

	echo -e "\e[33m	Wykres danych pobranych\e[37m"
	echo -n "	Srednia danych pobranych: "
	avg=$(echo "scale=2; $avg_pobrane/30" | bc -l)
	if (( $avg < 1000 ))
	then
		echo "${avg}B/s"
	elif (( $avg < 1000000 ))
	then
		avg=$(echo "$avg/1000; scale=1" | bc -l)
		echo "${avg}kB/s"
	else
		avg=$(echo "$avg/1000000; scale=1" | bc -l)
		echo "${avg}MB/s"
	fi
	wypiszWykresPobrane
	echo -e "\e[33m	Wykres danych wyslanych\e[37m"
	echo -n "	Srednia danych wyslanych: "
	avg=$(echo "scale=2; $avg_wyslane/30" | bc -l)
	if (( $avg < 1000 ))
	then
		echo "${avg}B/s"
	elif (( $avg < 1000000 ))
	then
		avg=$(echo "$avg/1000; scale=1" | bc -l)
		echo "${avg}kB/s"
	else
		avg=$(echo "$avg/1000000; scale=1" | bc -l)
		echo "${avg}MB/s"
	fi
	wypiszWykresWyslane
	
	ipobrane_stare=$ipobrane
	iwyslane_stare=$iwyslane
	sleep 1
done
