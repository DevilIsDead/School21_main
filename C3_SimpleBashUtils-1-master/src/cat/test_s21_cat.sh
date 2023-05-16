#!/bin/bash

TEST_COUNTER=0
COUNTER_SUCCESS=0
COUNTER_FAIL=0
SUCCESS="Файлы result.txt и expected.txt идентичны"

echo "\nTests. 1 file"
echo "================================================================="
    echo "\nTesting without flags test1.txt test2.txt test3.txt....."
    (( TEST_COUNTER = TEST_COUNTER + 1 ))
    ./s21_cat test1.txt test2.txt test3.txt > result.txt
    cat test1.txt test2.txt test3.txt > expected.txt

    DIFF_RES="$(diff -s result.txt expected.txt)"
    if [ "$DIFF_RES" == "$SUCCESS" ]
    then 
        (( COUNTER_SUCCESS = COUNTER_SUCCESS + 1 ))
        echo "was SUCCESSFUL"
    else
        (( COUNTER_FAIL = COUNTER_FAIL + 1 ))
        echo "was NOT SUCCESSFUL"
        echo "$(diff -s result.txt expected.txt)"
    fi
    rm result.txt expected.txt


echo "\nTests. 1 flag, 1 file"
echo "================================================================="
for flag in -b -e -n -s -t -E -T -v
do
    echo "\nTesting flag $flag with test1.txt....."
    (( TEST_COUNTER = TEST_COUNTER + 1 ))
    ./s21_cat $flag test1.txt > result.txt
    cat $flag test1.txt > expected.txt

    DIFF_RES="$(diff -s result.txt expected.txt)"
    if [ "$DIFF_RES" == "$SUCCESS" ]
    then 
        (( COUNTER_SUCCESS = COUNTER_SUCCESS + 1 ))
        echo "was SUCCESSFUL"
    else
        (( COUNTER_FAIL = COUNTER_FAIL + 1 ))
        echo "was NOT SUCCESSFUL"
        #echo "$(diff -s result.txt expected.txt)"
    fi
    rm result.txt expected.txt
done

echo "\nTests. 1 flag, 3 files"
echo "================================================================="
for flag in -b -e -n -s -t -E -T -v
do
    echo "\nTesting flag $flag with test1.txt test2.txt test3.txt....."
    (( TEST_COUNTER = TEST_COUNTER + 1 ))
    ./s21_cat $flag test1.txt test2.txt test3.txt > result.txt
    cat $flag test1.txt test2.txt test3.txt > expected.txt

    DIFF_RES="$(diff -s result.txt expected.txt)"
    if [ "$DIFF_RES" == "$SUCCESS" ]
    then 
        (( COUNTER_SUCCESS = COUNTER_SUCCESS + 1 ))
        echo "was SUCCESSFUL"
    else
        (( COUNTER_FAIL = COUNTER_FAIL + 1 ))
        echo "was NOT SUCCESSFUL"
        #echo "$(diff -s result.txt expected.txt)"
    fi
    rm result.txt expected.txt
done

echo "\nTests. 2 flags, 3 files"
echo "================================================================="
for flag in -b -e -n -s -t
do
    for flagg in -b -e -n -s -t
    do
    echo "\nTesting flag $flag $flagg with test1.txt test2.txt test3.txt....."
    (( TEST_COUNTER = TEST_COUNTER + 1 ))
    ./s21_cat $flag $flagg test1.txt test2.txt test3.txt > result.txt
    cat $flag $flagg test1.txt test2.txt test3.txt > expected.txt

    DIFF_RES="$(diff -s result.txt expected.txt)"
    if [ "$DIFF_RES" == "$SUCCESS" ]
    then 
        (( COUNTER_SUCCESS = COUNTER_SUCCESS + 1 ))
        echo "was SUCCESSFUL"
    else
        (( COUNTER_FAIL = COUNTER_FAIL + 1 ))
        echo "was NOT SUCCESSFUL"
        #echo "$(diff -s result.txt expected.txt)"
    fi
    rm result.txt expected.txt
    done
done

echo "\nTesting empty file..............................................."
(( TEST_COUNTER = TEST_COUNTER + 1 ))
if ./s21_cat test4.txt
then 
    (( COUNTER_SUCCESS = COUNTER_SUCCESS + 1 ))
    echo "was SUCCESSFUL"
else
    (( COUNTER_FAIL = COUNTER_FAIL + 1 ))
    echo "was NOT SUCCESSFUL"
fi

echo "\n================================================================="
echo "RESULT: from $TEST_COUNTER tests"
echo "Successful: $COUNTER_SUCCESS"
echo "Failed: $COUNTER_FAIL"
