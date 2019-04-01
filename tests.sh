#!/bin/bash
TESTFILESDIR=./testfiles
BINFILES=./bin
EXE=exe
ERRORCOUNT=0
TESTCOUNT=0
REDCOLOR='\033[0;31m'
RESETCOLOR='\033[0m'
GREENCOLOR='\033[0;32m'
echo "Debut des tests" > resultatsTests.txt

for directory in "$TESTFILESDIR"/*
do
	echo "-------------------------- ${directory} -----------------------" >> resultatsTests.txt
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
			  echo -e $GREENCOLOR"                                    PASSED : ${testFile}"$RESETCOLOR
			else
				echo -e $REDCOLOR"                                    FAILED : ${testFile}"$RESETCOLOR
				echo -e $REDCOLOR"Echec test ${testFile}. Attendu ${RESATTENDU}, obtenu "$RESETCOLOR >> resultatsTests.txt
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
			  echo -e $REDCOLOR"                                    FAILED : ${testFile}"$RESETCOLOR
			  echo -e $REDCOLOR"Echec test ${testFile}. Attendu ${RESATTENDU}, obtenu ${RESPROG}"$RESETCOLOR >> resultatsTests.txt
			  ((errorCountCategory++))
			else
			    echo -e $GREENCOLOR"                                    PASSED : ${testFile}"$RESETCOLOR
			fi
			rm a.out main.s
		fi
		rm temperr.txt temp.txt
		((TESTCOUNT++))
		((testCountCategory++))
	done
	echo "">> resultatsTests.txt
	if ["${errorCountCategory}" -ne "${testCountCategory}" ]
	then
	    echo -e $REDCOLOR"${errorCountCategory} echecs sur ${testCountCategory} dans ${directory}"$RESETCOLOR >> resultatsTests.txt
	else
	    echo -e $GREENCOLOR"${errorCountCategory} echecs sur ${testCountCategory} dans ${directory}"$RESETCOLOR >> resultatsTests.txt
	fi
	echo "">> resultatsTests.txt
done
echo "-------------------------------------------------" >> resultatsTests.txt
if ["${ERRORCOUNT}" -ne "${TESTCOUNT}" ]
then
    echo -e $REDCOLOR"${ERRORCOUNT} echecs sur ${TESTCOUNT}"$RESETCOLOR >> resultatsTests.txt
else
    echo -e $GREENCOLOR"${ERRORCOUNT} echecs sur ${TESTCOUNT}"$RESETCOLOR >> resultatsTests.txt
fi
