#!/bin/sh
for filename in *.txt
do
	echo "File name: $filename"
	sed -i -e 's/<[^>]*>//g' $filename						# Handles Tags
	sed -i -e 's/fcb/football club barcelona/g' $filename	# Acronym
	sed -i -e 's/rma/real madrid/g' $filename				# Acronym
	# input=`expr $filename`

	numbers=$(grep -E -o '[0-9]+' $filename)
	for num in $numbers
	do
		perl -i -p -e "s/$num/$(perl -e 'use Lingua::EN::Numbers qw(num2en);print num2en('$num')')/g;" $filename
	done
done