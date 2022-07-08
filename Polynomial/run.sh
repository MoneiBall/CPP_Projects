#!/bin/bash

set -e

cd src && g++ -w polynomial.cpp menu.cpp main.cpp -o polynomial && ./polynomial