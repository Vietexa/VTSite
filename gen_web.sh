#!/bin/bash

emcmake cmake -DCMAKE_POLICY_VERSION_MINIMUM=3.5 -S . -B build  -DCMAKE_BUILD_TYPE=Release
cmake --build build