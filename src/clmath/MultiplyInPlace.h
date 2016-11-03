// Copyright Hugh Perkins 2015 hughperkins at gmail
//
// This Source Code Form is subject to the terms of the Mozilla Public License, 
// v. 2.0. If a copy of the MPL was not distributed with this file, You can 
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#include <stdexcept>
#include <string>
#include <iostream>
#include <algorithm>

#include <EasyCL.h>



#define VIRTUAL virtual
#define STATIC static

// simply going to copy from one buffer to another
// nothing complicated :-)
class MultiplyInPlace {
public:
    easycl::EasyCL *cl;
    easycl::CLKernel *kernel;

    // [[[cog
    // import cog_addheaders
    // cog_addheaders.add()
    // ]]]
    // generated, using cog:
    VIRTUAL void multiply(int N, float multiplier, easycl::CLWrapper *data);
    VIRTUAL ~MultiplyInPlace();
    MultiplyInPlace(easycl::EasyCL *cl);

    // [[[end]]]
};

