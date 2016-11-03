// Copyright Hugh Perkins 2014 hughperkins at gmail
//
// This Source Code Form is subject to the terms of the Mozilla Public License, 
// v. 2.0. If a copy of the MPL was not distributed with this file, You can 
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#include <iostream>
#include <string>

#include <EasyCL.h>

#include "activate/ActivationFunction.h"
#include "conv/LayerDimensions.h"
#include "DeepCLDllExport.h"

#define STATIC static
#define VIRTUAL virtual

class DeepCL_EXPORT BackpropWeights {
public:
    easycl::EasyCL *cl;
    LayerDimensions dim;
    bool debug; // = false;

    virtual ~BackpropWeights() {}
    virtual void calcGradWeights(int batchSize, easycl::CLWrapper *gradOutputWrapper, easycl::CLWrapper *inputsWrapper, easycl::CLWrapper *gradWeightsWrapper, easycl::CLWrapper *gradBiasWrapper) = 0;

    // [[[cog
    // import cog_addheaders
    // cog_addheaders.add()
    // ]]]
    // generated, using cog:
    BackpropWeights(easycl::EasyCL *cl, LayerDimensions layerDimensions);
    STATIC BackpropWeights *instance(easycl::EasyCL *cl, LayerDimensions dim);
    STATIC int getNumImplementations();
    STATIC bool plausiblyOptimal(int index, int batchSize, LayerDimensions dim);
    STATIC BackpropWeights *instanceForTest(easycl::EasyCL *cl, LayerDimensions layerDimensions);
    STATIC BackpropWeights *instanceSpecific(int idx, easycl::EasyCL *cl, LayerDimensions layerDimensions);
    VIRTUAL void calcGradWeights(int batchSize, float *gradOutput, float *inputs, float *gradWeights, float *gradBias);
    float learningRateToMultiplier(int batchSize);

    // [[[end]]]
};

