#!/bin/bash

DIFF=$(diff <("$1" $2 "$3" 2>&-) <(./ft_"$1" $2 "$3" 2>&-))
if [ "$DIFF" != "" ]
then
	FNAME=$(basename "$3")
	echo "$1" > fails/"$1"/"$FNAME".diff
	echo "$DIFF" >> fails/"$1"/"$FNAME".diff
	exit 1
fi
exit 0
