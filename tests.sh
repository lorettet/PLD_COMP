#!/bin/bash
TESTFILESDIR=./testfiles
BINFILES=./bin
EXE=exe
ERRORCOUNT=0
TESTCOUNT=0

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
			  echo "                                    PASSED : ${testFile}"
			else
				echo "                                    FAILED : ${testFile}"
				echo "Echec test ${testFile}. Attendu ${RESATTENDU}, obtenu " >> resultatsTests.txt
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
			  echo "                                    FAILED : ${testFile}"
			  echo "Echec test ${testFile}. Attendu ${RESATTENDU}, obtenu ${RESPROG}" >> resultatsTests.txt
			  ((errorCountCategory++))
			else
			    echo "                                    PASSED : ${testFile}"
			fi
				rm a.out main.s
		fi
		rm temperr.txt temp.txt
		((TESTCOUNT++))
		((testCountCategory++))
	done
	
	echo "">> resultatsTests.txt
	echo "${errorCountCategory} echecs sur ${testCountCategory} dans ${directory}">> resultatsTests.txt
	echo "">> resultatsTests.txt
done
echo "-------------------------------------------------" >> resultatsTests.txt
echo "${ERRORCOUNT} echecs sur ${TESTCOUNT}">> resultatsTests.txt
