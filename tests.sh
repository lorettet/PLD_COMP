#!/bin/bash
TESTFILESDIR=./testfiles
BINFILES=./bin
EXE=exe
ERRORCOUNT=0
TESTCOUNT=0

echo "Debut des tests" > resultatsTests.txt

for testFile in "$TESTFILESDIR"/*/*.c
do
  $BINFILES/$EXE $testFile 2> temperr.txt > temp.txt
  RESATTENDU=`cat $testFile.sol`
  if [ -s "temperr.txt" ]
  then
	  cmp --silent temperr.txt $testFile.sol
  		if [ $? -eq 0 ]
  		then
	      echo "                                    ${testFile}     : PASSED"
    	else
    		echo "                                    ${testFile}     : FAILED"
    		echo "Echec test ${testFile}. Attendu ${RESATTENDU}, obtenu " >> resultatsTests.txt
    		cat temperr.txt >> resultatsTests.txt
    		((ERRORCOUNT++))
    	fi
  else
	  gcc main.s
	  ./a.out
	  RESPROG=$?
	  if [ $RESPROG != $RESATTENDU ]
	  then
	  	((ERRORCOUNT++))
	  	echo "                                    ${testFile}     : FAILED"
	  	echo "Echec test ${testFile}. Attendu ${RESATTENDU}, obtenu ${RESPROG}" >> resultatsTests.txt
	  else
	    echo "                                    ${testFile}     : PASSED"
	  fi
	    rm a.out main.s
	fi
  rm temperr.txt
  ((TESTCOUNT++))

done

echo "${ERRORCOUNT} echecs sur ${TESTCOUNT}">> resultatsTests.txt
