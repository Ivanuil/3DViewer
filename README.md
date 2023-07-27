# 3DViewer

[![wakatime](https://wakatime.com/badge/gitlab/students/C8_3DViewer_v1.0.ID_353532/Team__TL__fondaata_student.21_school.ru_.mVeQ_Jb_ReWH_NVhujHenA/C8_3DViewer_v1.0-1.svg)](https://wakatime.com/badge/gitlab/students/C8_3DViewer_v1.0.ID_353532/Team__TL__fondaata_student.21_school.ru_.mVeQ_Jb_ReWH_NVhujHenA/C8_3DViewer_v1.0-1)

## Contents

0. [Description](#description)
1. [Screenshots](#screenshots)
2. [How to run](#how-to-run)
3. [Contacts](#contacts)

## Description

A simple implementation of a program for viewing 3D wireframe models in C and C++ programming languages.

Features:
 - Saving model as JPEG or PNG image
 - Recording a short GIF video of a model

GUI is created with QT framework and C++ language. File parsing and affine transformations (move, rotate and scale object) are created with C language. \
Internal tests are implemented with Check.h library.
GIF recording feature is implemented with [GIFLIB](https://giflib.sourceforge.net/) library.

Project was developed by a student of School 21 as an implementation of School 21's project task.

## Screenshots

Interface of a program:\
![](misc/images/readme/screenshot_1.png "Interface of a program")

Example of program's output BMP: \
![](misc/images/readme/screenshot_2.bmp "Example of program's output")

Example of program's output GIF: \
![](misc/images/readme/gif_1.gif "Example of program's output GIF")

## How to run

To build program in **src** folder run: \
`` make install `` \
it will build a program to **build** directory. Please notice that in order to build project you must have QT, Cmake and C/C++ compatible compiler (gcc is recommended) installed. </br></br>

All default GNU Make stages are supported. Also this stages are available:
 - ``test`` Build and run internal tests. (Requirements: Check.h library)
 - ``gcov_report`` Same as **test**, but also generates gcov report, with line coverage data. (Requirements: Check.h library, lcov tool)
 - ``codestyle`` Performs code style tests using clang-format tool. (Requirements: clang-format tool)

To export documentation to html and latex run: \
`` make dvi `` \
Doxygen tool is required. Resulting documentation can be found in **documentation** directory.

## Contacts

With any questions/suggestions/other contact </br>
 - Mail: [ivo-pronin@yandex.ru](mailto:ivo-pronin@yandex.ru).
