#!/bin/bash
TESTFILESDIR=./testfiles
BINFILES=./bin
EXE=exe
ERRORCOUNT=0
TESTCOUNT=0
REDCOLOR='\033[0;31m'
RESETCOLOR='\033[0m'
GREENCOLOR='\033[0;32m'
BOLDFONT=$(tput bold)
RESETFONT=$(tput sgr0)
echo "Debut des tests" > resultatsTests.txt

for directory in "$TESTFILESDIR"/*
do
	echo "----------------------- ${BOLDFONT}${directory}${RESETFONT} --------------------" >> resultatsTests.txt
	errorCountCategory=0
	testCountCategory=0
	for testFile in "$directory"/*.c	
	do
        $BINFILES/$EXE $testFile 2> temperr.txt > temp.txt
		RESATTENDU=`cat $testFile.sol`
		if [ -s "temperr.txt" ]
		then
		 cmp --silent temperr.txt $testFile.sol
		    if [ $? -eq 0 ]
			then
			  echo -e $GREENCOLOR"                  ${BOLDFONT}PASSED${RESETFONT}$GREENCOLOR : ${testFile}"$RESETCOLOR
			else
				echo -e $REDCOLOR"                  ${BOLDFONT}FAILED${RESETFONT}$REDCOLOR : ${testFile}"$RESETCOLOR
				echo -e $REDCOLOR"${BOLDFONT}Echec test ${RESETFONT}$REDCOLOR${testFile}.$RESETCOLOR Attendu ${RESATTENDU}, obtenu " >> resultatsTests.txt
				cat temperr.txt >> resultatsTests.txt
	    		((ERRORCOUNT++))
	    		((errorCountCategory++))
			fi
	    else
			gcc main.s
		    ./a.out
			RESPROG=$?
			if [ $RESPROG != $RESATTENDU ]
			then
			  ((ERRORCOUNT++))
			  echo -e $REDCOLOR"                  ${BOLDFONT}FAILED${RESETFONT}$REDCOLOR : ${testFile}"$RESETCOLOR
			  echo -e $REDCOLOR"${BOLDFONT}Echec test ${RESETFONT}$REDCOLOR${testFile}. Attendu ${RESATTENDU}, obtenu ${RESPROG}" >> resultatsTests.txt
			  ((errorCountCategory++))
			else
			    echo -e $GREENCOLOR"                  ${BOLDFONT}PASSED${RESETFONT}$GREENCOLOR : ${testFile}"$RESETCOLOR
			fi
			rm a.out main.s
		fi
		rm temperr.txt temp.txt
		((TESTCOUNT++))
		((testCountCategory++))
	done
	echo "">> resultatsTests.txt
	if [ "${errorCountCategory}" -ne 0 ]
	then
	    echo -e $REDCOLOR"${BOLDFONT}${errorCountCategory} echecs${RESETFONT} sur ${testCountCategory} dans ${directory}"$RESETCOLOR >> resultatsTests.txt
	else
	    echo -e $GREENCOLOR"${BOLDFONT}${errorCountCategory} echecs${RESETFONT} sur ${testCountCategory} dans ${directory}"$RESETCOLOR >> resultatsTests.txt
	fi
	echo "">> resultatsTests.txt
done
echo "---------------------------------- ${BOLDFONT}TOTAL${RESETFONT} ----------------------------------" >> resultatsTests.txt
if [ "${ERRORCOUNT}" -ne 0 ]
then
    echo -e $REDCOLOR"${BOLDFONT}${ERRORCOUNT} echecs${RESETFONT} sur ${TESTCOUNT}" >> resultatsTests.txt
else
    echo -e $GREENCOLOR"${BOLDFONT}${ERRORCOUNT} echecs${RESETFONT} sur ${TESTCOUNT}" >> resultatsTests.txt
fi
