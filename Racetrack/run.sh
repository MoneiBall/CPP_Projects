#!/bin/bash

set -e

cd src && g++ -std=c++0x -w day.cpp main.cpp -o racetrack && ./racetrack