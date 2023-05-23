#!/bin/bash

TEST_COUNTER=0
COUNTER_SUCCESS=0
COUNTER_FAIL=0
SUCCESS="Files result.txt and expected.txt are identical"


echo "Tests. Part #1"
echo "================================================================="
echo "Testing grep with test1.txt without flags...................."
(( TEST_COUNTER = TEST_COUNTER + 1 ))
./s21_grep hello test1.txt > result.txt
grep hello test1.txt > expected.txt

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

echo "Tests. Part #2"
echo "================================================================="
echo "Testing grep with test1.txt with 1 flag...................."

for flag in -e -i -v -c -l -n
do
(( TEST_COUNTER = TEST_COUNTER + 1 ))
./s21_grep hello test1.txt > result.txt
grep hello test1.txt > expected.txt

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
done

echo "Tests. Part #3"
echo "================================================================="
echo "Testing grep with test1.txt with 2 flags...................."

for flag in -i -v -c -l -n 
do
    for flagg in -i -v -c -l -n 
    do
        (( TEST_COUNTER = TEST_COUNTER + 1 ))
        ./s21_grep hello test1.txt > result.txt
        grep hello test1.txt > expected.txt

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
    done
done

echo "Tests. Part #4"
echo "================================================================="
echo "Testing grep with test1.txt with 3 flags...................."

for flag in -i -v -c -l -n 
do
    for flagg in -i -v -c -l -n 
    do
        for flaggg in -i -v -c -l -n 
        do
        (( TEST_COUNTER = TEST_COUNTER + 1 ))
        ./s21_grep hello test1.txt > result.txt
        grep hello test1.txt > expected.txt

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
        done
    done
done

echo "Tests. Part #5"
echo "================================================================="
echo "Testing grep with test1.txt test2.txt test3.txt with 3 flags...................."

for flag in -i -v -c -l -n 
do
    for flagg in -i -v -c -l -n 
    do
        for flaggg in -i -v -c -l -n 
        do
        (( TEST_COUNTER = TEST_COUNTER + 1 ))
        ./s21_grep hello test1.txt test2.txt test3.txt > result.txt
        grep hello test1.txt test2.txt test3.txt > expected.txt

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
        done
    done
done

echo "Tests. Part #6"
echo "================================================================="
echo "Testing grep with 3 files 3 flags and 2 templates...................."

for flag in -i -v -c -l -n 
do
    for flagg in -i -v -c -l -n 
    do
        for flaggg in -i -v -c -l -n 
        do
        (( TEST_COUNTER = TEST_COUNTER + 1 ))
        ./s21_grep -e hello -e alloha test1.txt test2.txt test3.txt > result.txt
        grep -e hello -e alloha test1.txt test2.txt test3.txt > expected.txt

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
        done
    done
done


echo "Testing with empty file.........................................."
(( TEST_COUNTER = TEST_COUNTER + 1 ))
if ./s21_grep hello test4.txt
then 
    (( COUNTER_SUCCESS = COUNTER_SUCCESS + 1 ))
    echo "was SUCCESSFUL"
else
    (( COUNTER_FAIL = COUNTER_FAIL + 1 ))
    echo "was NOT SUCCESSFUL"
fi

echo "================================================================="
echo "RESULT: from $TEST_COUNTER tests"
echo "Successful: $COUNTER_SUCCESS"
echo "Failed: $COUNTER_FAIL"
