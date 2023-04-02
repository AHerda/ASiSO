ls
echo "usuwanie starych plikow"

for file in ./*
do
	if [ "$file" != ./zadanie7.sh ]
	then
		rm -r "$file"
	fi
done
ls
echo "Tworzenie nowych plikow"

touch -- " ABC    DEF" "-AbC dEf" "--ABC DEF" Pliczek PlIK_pRoBNy
mkdir FoLdER_prOBny
ls

echo "Zmienianie na mniejsze litery"

#find . -type f -name "*" -exec bash -c 'mv -v "$1" "$(echo "$1" | tr [:upper:] [:lower:])"' _ {} \;
#find . -type f -print0 | xargs -0 -tI x bash -c 'mv "$1" "$(echo "$1" | tr [:upper:] [:lower:])"' - x 
find . -type f -print0 | xargs -0 -tI x bash -c 'mv "x" "$(echo "x" | tr [:upper:] [:lower:])"'
#find . -type f -print0 | xargs -0 -tn 1 bash -c 'mv "$1" "$(echo "$1" | tr [:upper:] [:lower:])"' _

ls
