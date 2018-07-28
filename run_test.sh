#!/bin/bash

set -x

function go_to_dirname
{
    echo "Go to working directory..."
    cd $( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
    if [ $? -ne 0 ]
    then
        echo "go_to_dirname failed";
        exit 1
    fi
    echo "-> Current directory is" $(pwd)
}

function all
{
    ./check_makefile.sh
    ./unittesting.sh
}

function main
{
    go_to_dirname
    all
}

main
exit $?