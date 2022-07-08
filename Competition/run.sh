#!/bin/bash

set -e

cd src && g++ -w angler.cpp championship.cpp main.cpp -o competition && ./competition