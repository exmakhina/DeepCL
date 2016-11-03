// Copyright Hugh Perkins 2014 hughperkins at gmail
//
// This Source Code Form is subject to the terms of the Mozilla Public License, 
// v. 2.0. If a copy of the MPL was not distributed with this file, You can 
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#include "DeepCLDllExport.h"

#define VIRTUAL virtual
#define STATIC static

#include <EasyCL.h>


class DeepCL_EXPORT PoolingForward {
public:
    easycl::EasyCL *cl;

    const bool padZeros;
    const int numPlanes;
    const int inputSize;
    const int poolingSize;

    const int outputSize;

    virtual ~PoolingForward() {}
    inline int getInputIndex(int n, int plane, int row, int col) {
        return (( n
            * numPlanes + plane)
            * inputSize + row)
            * inputSize + col;
    }
    inline int getResultIndex(int n, int plane, int row, int col) {
        return (( n
            * numPlanes + plane)
            * outputSize + row)
            * outputSize + col;
    }

    // [[[cog
    // import cog_addheaders
    // cog_addheaders.add()
    // ]]]
    // generated, using cog:
    PoolingForward(easycl::EasyCL *cl, bool padZeros, int numPlanes, int inputSize, int poolingSize);
    STATIC PoolingForward *instance(easycl::EasyCL *cl, bool padZeros, int numPlanes, int inputSize, int poolingSize);
    STATIC PoolingForward *instanceForTest(easycl::EasyCL *cl, bool padZeros, int numPlanes, int inputSize, int poolingSize);
    STATIC PoolingForward *instanceSpecific(int idx, easycl::EasyCL *cl, bool padZeros, int numPlanes, int inputSize, int poolingSize);
    VIRTUAL void forward(int batchSize, easycl::CLWrapper *inputData, easycl::CLWrapper *selectors, easycl::CLWrapper *outputData);
    VIRTUAL void forward(int batchSize, float *input, int *selectors, float *output);
    VIRTUAL int getInputNumElements(int batchSize);
    VIRTUAL int getOutputNumElements(int batchSize);

    // [[[end]]]
};

