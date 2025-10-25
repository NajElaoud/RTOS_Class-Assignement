#!/bin/bash
CurrentPath=$(pwd)
ParentFolder=$(echo $CurrentPath | sed -e 's;\/[^/]*$;;') # cut away "/file.txt";'$' is end of string
#echo "Parent folder $ParentFolder"
#LAB=$(echo $ParentFolder | sed -e 's;.*\/;;')  # cut away "/a/b/c/"

LAB=$(echo $CurrentPath | sed -e 's;.*\/;;')
#echo $LAB

MANIP=LabCont
#echo $MANIP

REPORT="./$(whoami)-REPORT--$MANIP-$LAB.log"
echo "Generating : $REPORT report ..." && sleep 5
{
	echo "==============================="
	echo "Lab     : $LAB"
	echo "Manip   : $MANIP"
	echo "Student : $(whoami)"
	echo "Date    : $(date)"
	echo "==============================="
	echo "========== Folders ============" &&
	echo $CurrentPath
	ls -l .. && tree ..
	echo "============ zsh ==============" &&
	cat ~/.history-zsh
	echo "==============================="
} > $REPORT 2>&1
echo $(md5sum $REPORT)+++ >> $REPORT
