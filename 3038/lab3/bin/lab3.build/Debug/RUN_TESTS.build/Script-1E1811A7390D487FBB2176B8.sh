#!/bin/sh
make -C /Users/mp/Documents/uni/3038/lab3/bin -f /Users/mp/Documents/uni/3038/lab3/bin/CMakeScripts/RUN_TESTS_postBuildPhase.make$CONFIGURATION OBJDIR=$(basename "$OBJECT_FILE_DIR_normal") all
