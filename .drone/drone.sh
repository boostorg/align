#!/bin/bash

# Copyright 2020 Rene Rivera, Sam Darwin
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

set -e
set -x
export TRAVIS_BUILD_DIR=$(pwd)
export DRONE_BUILD_DIR=$(pwd)
export TRAVIS_BRANCH=$DRONE_BRANCH
export VCS_COMMIT_ID=$DRONE_COMMIT
export GIT_COMMIT=$DRONE_COMMIT
export REPO_NAME=$DRONE_REPO
export PATH=~/.local/bin:/usr/local/bin:$PATH

if [ "$DRONE_JOB_BUILDTYPE" == "boost" ]; then

echo '==================================> INSTALL'

cd ..
git clone -b $TRAVIS_BRANCH https://github.com/boostorg/boost
cd boost
git submodule init libs/assert
git submodule init libs/config
git submodule init libs/core
git submodule init libs/static_assert
git submodule init libs/headers
git submodule init tools/build
git submodule init tools/boost_install
git submodule update
cp -R $TRAVIS_BUILD_DIR/* libs/align
./bootstrap.sh
./b2 headers

echo '==================================> SCRIPT'

echo "using $TOOLSET : : $COMPILER ;" > ~/user-config.jam
./b2 libs/align/test toolset=$TOOLSET cxxstd=$STANDARD

fi
