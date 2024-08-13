#!/bin/bash
make clean -f makefile_wii_text
make -f makefile_wii_text
rm -rf wii_builds/texttris_wii
mkdir -p wii_builds/texttris_wii/apps/texttris
cp texttris.dol wii_builds/texttris_wii/apps/texttris/boot.dol
cp resources/meta/texttris_wii/* wii_builds/texttris_wii/apps/texttris
cp -r resources/sounds wii_builds/texttris_wii/apps/texttris
