#!/bin/bash
set -e
g++ -std=c++17 -O2 -I . -o karel karel.cpp grader.cpp
