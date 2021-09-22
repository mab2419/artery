#include "PoliceServiceStoryboard2.h"
#include <artery/application/StoryboardSignal.h>

using namespace omnetpp;

// register signal to recieve signal from Storyboard
static const simsignal_t storyboardSignal = cComponent::registerSignal("StoryboardSignal");

Define_Module(PoliceServiceStoryboard2)

void PoliceServiceStoryboard2::initialize()
{
    PoliceService2::initialize();
    subscribe(storyboardSignal);
    activatedSiren = false;
}

void PoliceServiceStoryboard2::trigger()
{
    Enter_Method("PoliceServiceStoryboard trigger");
    if (activatedSiren) {
        PoliceService2::trigger();
    }
}

// is triggered when any signal is recieved
void PoliceServiceStoryboard2::receiveSignal(omnetpp::cComponent*, omnetpp::simsignal_t sig, omnetpp::cObject* sigobj, omnetpp::cObject*)
{
    // start the PoliceService after receiving Storyboard Signal
    if (sig == storyboardSignal) {
        auto storysig = dynamic_cast<artery::StoryboardSignal*>(sigobj);
        if (storysig && storysig->getCause() == "siren on") {
            activatedSiren = true;
        }
    }
}
