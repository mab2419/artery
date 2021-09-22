#include "PoliceServiceEnvmod2.h"
#include "artery/envmod/LocalEnvironmentModel.h"

using namespace omnetpp;

Define_Module(PoliceServiceEnvmod2)

void PoliceServiceEnvmod2::initialize()
{
    PoliceService2::initialize();
    localEnvmod = &getFacilities().get_const<artery::LocalEnvironmentModel>();
    skippedTrigger = 0;
}

void PoliceServiceEnvmod2::trigger()
{
    Enter_Method("PoliceServiceEnvmod2 trigger");
    const auto& objects = localEnvmod->allObjects();
    if (objects.size() > 0 || skippedTrigger >= 4) {
        PoliceService2::trigger();
        skippedTrigger = 0;
    } else {
        ++skippedTrigger;
    }
}
