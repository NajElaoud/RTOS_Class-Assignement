#!/bin/bash
CurrentPath=$(pwd)
ParentFolder=$(echo $CurrentPath | sed -e 's;\/[^/]*$;;') # cut away "/file.txt";'$' is end of string
#echo "Parent folder $ParentFolder"
LAB=$(echo $ParentFolder | sed -e 's;.*\/;;')  # cut away "/a/b/c/"
#echo $LAB

MANIP=$(echo $CurrentPath | sed -e 's;.*\/;;')
#MANIP=MakePrj
#echo $MANIP

echo "Generating : ./$(whoami)-REPORT--$MANIP-$LAB report ..." && sleep 5
REPORT="./$(whoami)-REPORT--$MANIP-$LAB.log"
{
	echo "==============================="
	echo "Lab     : $LAB"
	echo "Manip   : $MANIP"
	echo "Student : $(whoami)"
	echo "Date    : $(date)"
	echo "==============================="
	echo "========== Folders ============" &&
	echo $CurrentPath
	ls -l . && tree -L 2 .
	echo "========= src Files ===========" &&
	for fn in $(find ./ -type f); do
		printf "\n::::::::::::::::\n$fn\n::::::::::::::::\n";
		cat -n "$fn";
	done
	echo "============ zsh ==============" &&
	cat ~/.history-zsh
	echo "==============================="
} > $REPORT 2>&1
echo $(md5sum $REPORT)+++ >> $REPORT
