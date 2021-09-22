#include "ClearLaneService2.h"
#include "police2_msgs/PoliceClearLane2_m.h"
#include "artery/traci/VehicleController.h"

using namespace omnetpp;
using namespace vanetza;

Define_Module(ClearLaneService2)

void ClearLaneService2::initialize()
{
    ItsG5BaseService::initialize();
    mVehicleController = &getFacilities().get_mutable<traci::VehicleController>();
}

void ClearLaneService2::indicate(const vanetza::btp::DataIndication& ind, omnetpp::cPacket* packet)
{
    Enter_Method("ClearLaneService2 indicate");
    auto clearLaneMessage = check_and_cast<const PoliceClearLane2*>(packet);

    const std::string id = mVehicleController->getVehicleId();
    auto& vehicle_api = mVehicleController->getTraCI()->vehicle;
    if (vehicle_api.getRoadID(id) == clearLaneMessage->getEdgeName()) {
        if (vehicle_api.getLaneIndex(id) != clearLaneMessage->getLaneIndex()) {
            slowDown();
        }
    }

    delete clearLaneMessage;
}

void ClearLaneService2::slowDown()
{
    mVehicleController->setMaxSpeed(25 * units::si::meter_per_second);
}
