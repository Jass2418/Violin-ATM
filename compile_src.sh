#!/bin/bash
# Compile Source Files

set -xe

PLATFORMS="argon"

LIBS="
src
"


for platform in $PLATFORMS; do
    particle --no-update-check compile $platform $LIBS --saveTo firmware.bin
done