#!/bin/bash

set -e

cd src && g++ -w Bag.cpp Menu.cpp main.cpp -o bag && ./bag