cdef class TrainingContext:
    cdef cDeepCL.TrainingContext *thisptr
    def __cinit__(self, int epoch, int batch):
        self.thisptr = new cDeepCL.TrainingContext(epoch, batch)
    def __dealloc__(self):
        del self.thisptr

cdef class SGD(Trainer): 
    cdef cDeepCL.SGD *thisptr
    def __cinit__( self, DeepCL cl, learningRate, momentum=0.0 ):
        self.thisptr = new cDeepCL.SGD(cl.thisptr)
        self.thisptr.setLearningRate(learningRate)
        self.thisptr.setMomentum(momentum)
        self.baseptr = self.thisptr
    def __dealloc__(self):
        del self.thisptr
    def setLearningRate(self, float learningRate):
        self.thisptr.setLearningRate(learningRate)
    def setMomentum(self, float momentum):
        self.thisptr.setMomentum(momentum)
    def setWeightDecay(self, float weightDecay):
        self.thisptr.setWeightDecay(weightDecay)
    def train(self, NeuralNet net, TrainingContext context,
        inputdata, float[:] expectedOutput ):
        cdef float[:] inputdata_ = inputdata.reshape(-1)
        cdef cDeepCL.BatchResult result = self.thisptr.train(
            net.thisptr, context.thisptr, &inputdata_[0], &expectedOutput[0])
        return result.getLoss()
    def trainFromLabels(self, NeuralNet net, TrainingContext context,
        inputdata, int[:] labels):
        cdef float[:] inputdata_ = inputdata.reshape(-1)
        cdef cDeepCL.BatchResult result = self.thisptr.trainFromLabels(
            net.thisptr, context.thisptr, &inputdata_[0], &labels[0])
        return ( result.getLoss(), result.getNumRight() )
