#!/bin/bash


# Wypisywanie uptime

linia="---------------------------------------------|--------"
uptime=$(cat /proc/uptime | awk '{print $1}')
(echo -e "\e[33mUpTime\e[37m"
echo "Days:|" $(echo "$uptime/86400" | bc)
echo "Hours:|" $(echo "$uptime%86400/3600" | bc)
echo "Minute:|" $(echo "$uptime%86400%3600/60" | bc)
echo "Seconds:|" $(echo "$uptime%86400%3600%60" | bc)

echo "$linia"

# Wypisywanie baterii

echo -n "Bateria:|"
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
echo -e "Aktualne wykorzystanie pamieci:|" $(echo "scale=1; ($mem_total-$mem)/$mem_total*100" | bc -l) "%") | column -t -s "|" -o "|"
