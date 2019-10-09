###############################################################################
# Copyright (c) 2016-19, Lawrence Livermore National Security, LLC
# and RAJA project contributors. See the RAJA/COPYRIGHT file for details.
#
# SPDX-License-Identifier: (BSD-3-Clause)
###############################################################################
blt_add_executable(
  NAME example.exe
  SOURCES example.cpp
  DEPENDS_ON RAJA)
