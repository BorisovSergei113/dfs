cmake -H. -B_builds -DBUILD_TESTS=ON
cmake --build _builds
cmake --build _builds --target test -- ARGS=--verbose

[![Build Status](https://travis-ci.org/BorisovSergei113/dfs.svg?branch=master)](https://travis-ci.org/BorisovSergei113/dfs)
