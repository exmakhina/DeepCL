// Copyright Hugh Perkins 2015 hughperkins at gmail
//
// This Source Code Form is subject to the terms of the Mozilla Public License, 
// v. 2.0. If a copy of the MPL was not distributed with this file, You can 
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#include <EasyCL.h>

class PrintBuffer {
public:
    static void printFloats( easycl::EasyCL *cl, easycl::CLWrapper *buffer, int rows, int cols );
    static void printInts( easycl::EasyCL *cl, easycl::CLWrapper *buffer, int rows, int cols );
};

