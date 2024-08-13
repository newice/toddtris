#!/bin/bash
make clean -f makefile_wii
make -f makefile_wii
rm -rf wii_builds/toddtris_wii
mkdir -p wii_builds/toddtris_wii/apps/toddtris
cp toddtris.dol wii_builds/toddtris_wii/apps/toddtris/boot.dol
cp resources/meta/toddtris_wii/* wii_builds/toddtris_wii/apps/toddtris
cp -r resources/images wii_builds/toddtris_wii/apps/toddtris
cp -r resources/sounds/ wii_builds/toddtris_wii/apps/toddtris
