#ifndef LAR_PANDORA_DETECTOR_TYPE_H
#define LAR_PANDORA_DETECTOR_TYPE_H 1


#include "larcore/Geometry/Geometry.h"

namespace lar_pandora{

    class LArDetectorGap;
    typedef std::vector<LArDetectorGap> LArDetectorGapList;

    class LArPandoraDetectorType {
    public:
        virtual geo::View_t TargetViewU(const geo::TPCID::TPCID_t tpc, const geo::CryostatID::CryostatID_t cstat) const = 0;
        virtual geo::View_t TargetViewV(const geo::TPCID::TPCID_t tpc, const geo::CryostatID::CryostatID_t cstat) const = 0;
        virtual geo::View_t TargetViewW(const geo::TPCID::TPCID_t tpc, const geo::CryostatID::CryostatID_t cstat) const = 0;
        virtual float WirePitchU() const = 0;
        virtual float WirePitchV() const = 0;
        virtual float WirePitchW() const = 0;
        virtual float WireAngleU(const int tpc, const int cstat) const = 0;
        virtual float WireAngleV(const int tpc, const int cstat) const = 0;
        virtual float WireAngleW(const int tpc, const int cstat) const = 0;
        virtual bool ShouldSwitchUV(const unsigned int tpc, const unsigned int cstat) const = 0;
        virtual void LoadDetectorGaps(LArDetectorGapList& listOfGaps) = 0;
    };

    LArPandoraDetectorType *GetDetectorType();
}
#endif
