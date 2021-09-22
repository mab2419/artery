#ifndef POLICESERVICESTORYBOARD_H_
#define POLICESERVICESTORYBOARD_H_

#include "PoliceService2.h"

// Extends PoliceService which should be used with the storyboard feature
class PoliceServiceStoryboard2 : public PoliceService2
{
    public:
        void initialize() override;
        void trigger() override;
        void receiveSignal(omnetpp::cComponent*, omnetpp::simsignal_t, omnetpp::cObject*, omnetpp::cObject*) override;

    private:
        bool activatedSiren = false;
};

#endif /* POLICESERVICESTORYBOARD_H_ */
