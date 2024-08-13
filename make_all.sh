#!/bin/bash
make clean -f Makefile_mingw
make -f Makefile_mingw

./make_wii.sh

./make_wii_text.sh
