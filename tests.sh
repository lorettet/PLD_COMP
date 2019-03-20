TESTFILESDIR=./testfiles
BINFILES=./bin
EXE=exe
ERRORCOUNT=0
TESTCOUNT=0

echo "Debut des tests" > resultatsTests.txt

for testFile in "$TESTFILESDIR"/*/*.c
do
  $BINFILES/$EXE $testFile
  RESATTENDU=`cat $testFile.sol`
  gcc main.s
  ./a.out
  RESPROG=$?
  if [ $RESPROG != $RESATTENDU ]
  then
  	((ERRORCOUNT++))
  	echo "Echec test ${testFile}. Attendu ${RESATTENDU}, obtenu ${RESPROG}" >> resultatsTests.txt
  else
  	echo $RESPROG $testFile
  fi
  ((TESTCOUNT++))
done

echo "${ERRORCOUNT} echecs sur ${TESTCOUNT}">> resultatsTests.txt
