#include <artery/application/CaObject.h>
#include <omnetpp.h>
#include <cassert>

namespace artery
{

using namespace vanetza::asn1;

Register_Abstract_Class(CaObject)

CaObject::CaObject(Cam&& cam) :
    m_cam_wrapper(std::make_shared<Cam>(std::move(cam)))
{
}

CaObject& CaObject::operator=(Cam&& cam)
{
    m_cam_wrapper = std::make_shared<Cam>(std::move(cam));
    return *this;
}

CaObject::CaObject(const Cam& cam) :
    m_cam_wrapper(std::make_shared<Cam>(cam))
{
}

CaObject& CaObject::operator=(const Cam& cam)
{
    m_cam_wrapper = std::make_shared<Cam>(cam);
    return *this;
}

CaObject::CaObject(const std::shared_ptr<const Cam>& ptr) :
    m_cam_wrapper(ptr)
{
    assert(m_cam_wrapper);
}

CaObject& CaObject::operator=(const std::shared_ptr<const Cam>& ptr)
{
    m_cam_wrapper = ptr;
    assert(m_cam_wrapper);
    return *this;
}

std::shared_ptr<const Cam> CaObject::shared_ptr() const
{
    assert(m_cam_wrapper);
    return m_cam_wrapper;
}

const vanetza::asn1::Cam& CaObject::asn1() const
{
    return *m_cam_wrapper;
}

omnetpp::cObject* CaObject::dup() const
{
    return new CaObject { *this };
}

using namespace omnetpp;

class CamStationIdResultFilter : public cObjectResultFilter
{
protected:
    void receiveSignal(cResultFilter* prev, simtime_t_cref t, cObject* object, cObject* details) override
    {
        if (auto cam = dynamic_cast<CaObject*>(object)) {
            const auto id = cam->asn1()->header.stationID;
            fire(this, t, id, details);
        }
    }
};

Register_ResultFilter("camStationId", CamStationIdResultFilter)


class CamGenerationDeltaTimeResultFilter : public cObjectResultFilter
{
protected:
    void receiveSignal(cResultFilter* prev, simtime_t_cref t, cObject* object, cObject* details) override
    {
        if (auto cam = dynamic_cast<CaObject*>(object)) {
            const auto genDeltaTime = cam->asn1()->cam.generationDeltaTime;
            fire(this, t, genDeltaTime, details);
        }
    }
};

Register_ResultFilter("camGenerationDeltaTime", CamGenerationDeltaTimeResultFilter)

class CamVelocityResultFilter : public cObjectResultFilter
{
protected:
    void receiveSignal(cResultFilter* prev, simtime_t_cref t, cObject* object, cObject* details) override
    {
        if (auto cam = dynamic_cast<CaObject*>(object)) {
            const auto velocity = cam->asn1()->cam.camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.speed.speedValue;
            fire(this, t, velocity, details);
        }
    }
};
//Velocity wird in cm/s ausgegeben
Register_ResultFilter("camVelocity", CamVelocityResultFilter)

class CamRefPoslongResultFilter : public cObjectResultFilter
{
protected:
    void receiveSignal(cResultFilter* prev, simtime_t_cref t, cObject* object, cObject* details) override
    {
        if (auto cam = dynamic_cast<CaObject*>(object)) {
            const auto RefPoslong = cam->asn1()->cam.camParameters.basicContainer.referencePosition.longitude;
            fire(this, t, RefPoslong, details);
        }
    }
};
//Microdegree nochmal mit 10 multipliziert --> Umrechnung in x,y in Traci Doku nachschauen
Register_ResultFilter("camRefPoslong", CamRefPoslongResultFilter)

class CamRefPoslatResultFilter : public cObjectResultFilter
{
protected:
    void receiveSignal(cResultFilter* prev, simtime_t_cref t, cObject* object, cObject* details) override
    {
        if (auto cam = dynamic_cast<CaObject*>(object)) {
            const auto RefPoslat = cam->asn1()->cam.camParameters.basicContainer.referencePosition.latitude;
            fire(this, t, RefPoslat, details);
        }
    }
};
//Microdegree nochmal mit 10 multipliziert --> Umrechnung in x,y in Traci Doku nachschauen
Register_ResultFilter("camRefPoslat", CamRefPoslatResultFilter)

class CamHeadingResultFilter : public cObjectResultFilter
{
protected:
    void receiveSignal(cResultFilter* prev, simtime_t_cref t, cObject* object, cObject* details) override
    {
        if (auto cam = dynamic_cast<CaObject*>(object)) {
            const auto Heading = cam->asn1()->cam.camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.heading.headingValue;
            fire(this, t, Heading, details);
        }
    }
};
//decidegree, Winkel bezüglich Nordvektor
Register_ResultFilter("camHeading", CamHeadingResultFilter)

class CamLongAccelResultFilter : public cObjectResultFilter
{
protected:
    void receiveSignal(cResultFilter* prev, simtime_t_cref t, cObject* object, cObject* details) override
    {
        if (auto cam = dynamic_cast<CaObject*>(object)) {
            const auto LongAccel = cam->asn1()->cam.camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.longitudinalAcceleration.longitudinalAccelerationValue;
            fire(this, t, LongAccel, details);
        }
    }
};
// Einheit m/s²
Register_ResultFilter("camLongAccel", CamLongAccelResultFilter)

class CamCurvatureResultFilter : public cObjectResultFilter
{
protected:
    void receiveSignal(cResultFilter* prev, simtime_t_cref t, cObject* object, cObject* details) override
    {
        if (auto cam = dynamic_cast<CaObject*>(object)) {
            const auto Curvature = cam->asn1()->cam.camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.curvature.curvatureValue;
            fire(this, t, Curvature, details);
        }
    }
};
//1/meter *10000
Register_ResultFilter("camCurvature", CamCurvatureResultFilter)

class CamYawRateResultFilter : public cObjectResultFilter
{
protected:
    void receiveSignal(cResultFilter* prev, simtime_t_cref t, cObject* object, cObject* details) override
    {
        if (auto cam = dynamic_cast<CaObject*>(object)) {
            const auto YawRate = cam->asn1()->cam.camParameters.highFrequencyContainer.choice.basicVehicleContainerHighFrequency.yawRate.yawRateValue;
            fire(this, t, YawRate, details);
        }
    }
};
// °/s*100
Register_ResultFilter("camYawRate", CamYawRateResultFilter)
} // namespace artery
