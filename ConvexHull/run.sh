#!/bin/bash

set -e

cd src && g++ -Werror Shapes.cpp main.cpp

if [[ $? == 0 ]]; then
    ./a.out
else
    echo -e "Error:\n$output"
fi