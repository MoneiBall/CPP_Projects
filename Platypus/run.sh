#!/bin/bash

set -e

cd src && g++ -w platypus.cpp test.cpp main.cpp -o platypus && ./platypus