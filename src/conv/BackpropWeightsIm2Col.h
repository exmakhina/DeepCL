#pragma once

#include "BackpropWeights.h"
//#include <EasyCL.h>

#include "DeepCLDllExport.h"

class Im2Col;

#include <EasyCL.h>


#define STATIC static
#define VIRTUAL virtual

class DeepCL_EXPORT BackpropWeightsIm2Col : public BackpropWeights {
    private:
//    easycl::CLKernel * kernelIm2Col;
    Im2Col *im2Col;

    float *columns;
    easycl::CLWrapper *columnsWrapper;
    int numKernels;

    // [[[cog
    // import cog_addheaders
    // cog_addheaders.addv2()
    // ]]]
    // generated, using cog:

    public:
    BackpropWeightsIm2Col(easycl::EasyCL *cl, LayerDimensions dim);
    VIRTUAL ~BackpropWeightsIm2Col();
    VIRTUAL void calcGradWeights(int batchSize, easycl::CLWrapper *gradOutputWrapper, easycl::CLWrapper *inputWrapper, easycl::CLWrapper *gradWeightsWrapper, easycl::CLWrapper *gradBiasWrapper);

    // [[[end]]]
};

