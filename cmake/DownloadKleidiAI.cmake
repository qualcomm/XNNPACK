# Copyright (c) Facebook, Inc. and its affiliates.
# All rights reserved.
#
# Copyright 2019 Google LLC
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree.

CMAKE_MINIMUM_REQUIRED(VERSION 3.5 FATAL_ERROR)

PROJECT(kleidiai-download NONE)

# Set file timestamps to the time of extraction.
IF(POLICY CMP0135)
  CMAKE_POLICY(SET CMP0135 NEW)
ENDIF()

# LINT.IfChange
INCLUDE(ExternalProject)
ExternalProject_Add(kleidiai
        #URL https://gitlab.arm.com/kleidi/kleidiai/-/archive/847ebd19d0192528659b0a0fa2c6057eed674c6a/kleidiai-847ebd19d0192528659b0a0fa2c6057eed674c6a.zip
  URL https://gitlab.arm.com/kleidi/kleidiai/-/archive/73d1e85dba909be752031407cc97ca0b3a614343/kleidiai-73d1e85dba909be752031407cc97ca0b3a614343.zip
  #  URL_HASH SHA256=ac8c946803bed3fa2e53bc88284f9d07787b9aa4
  SOURCE_DIR "${CMAKE_BINARY_DIR}/kleidiai-source"
  BINARY_DIR "${CMAKE_BINARY_DIR}/kleidiai"
  CONFIGURE_COMMAND ""
  PATCH_COMMAND ${CMAKE_COMMAND} -E echo "Applying patch..." && 
  ${CMAKE_COMMAND} -E chdir <SOURCE_DIR> patch -p1 < ${CMAKE_SOURCE_DIR}/patches/kleidiai-sme1.patch
  BUILD_COMMAND ""
  INSTALL_COMMAND ""
  TEST_COMMAND ""
)
# LINT.ThenChange(../MODULE.bazel:kleidiai)
