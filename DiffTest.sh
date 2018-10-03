#!/bin/bash

DIFF=$(diff <(nm "$1" 2>&-) <(./ft_nm "$1" 2>&-))
if [ "$DIFF" != "" ]
then
	FNAME=$(basename "$1")
	echo "$1" > fails/"$FNAME".diff
	echo "$DIFF" >> fails/"$FNAME".diff
	exit 1
fi
exit 0
