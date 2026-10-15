#!/bin/bash
set -e
g++ -std=c++17 -O2 -pipe grader.cpp porco.cpp -o porco
