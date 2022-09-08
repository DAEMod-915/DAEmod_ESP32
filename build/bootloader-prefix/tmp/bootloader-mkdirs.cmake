# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/opt/esp-idf/components/bootloader/subproject"
  "/mnt/data/school/01/z_connor_work/code/build/bootloader"
  "/mnt/data/school/01/z_connor_work/code/build/bootloader-prefix"
  "/mnt/data/school/01/z_connor_work/code/build/bootloader-prefix/tmp"
  "/mnt/data/school/01/z_connor_work/code/build/bootloader-prefix/src/bootloader-stamp"
  "/mnt/data/school/01/z_connor_work/code/build/bootloader-prefix/src"
  "/mnt/data/school/01/z_connor_work/code/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/mnt/data/school/01/z_connor_work/code/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
