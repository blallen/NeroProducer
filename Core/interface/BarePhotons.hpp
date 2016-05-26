#ifndef BARE_PHOTONS_H
#define BARE_PHOTONS_H

#include "NeroProducer/Core/interface/BareCollection.hpp"
#include "NeroProducer/Core/interface/BareP4.hpp"


class BarePhotons : virtual public BareP4
{
    public:
        enum Selection{
            PhoBaseline = 1UL << 0,
            PhoLoose  = 1UL << 3, 
            PhoMedium = 1UL << 4,
            PhoTight  = 1UL << 5,
            PhoElectronVeto = 1UL << 7,
            PhoPixelSeedVeto = 1UL << 8,

            // NONPOG
            PhoVLoose50 = 1UL << 100, // loose, no-sieie, looser ph-iso
            PhoVLoose25 = 1UL << (PhoVLoose50 + 1), // loose + no-sieie, looser ph-iso
            PhoHighPt = 1UL << (PhoVLoose50 + 2),
            PhoLooseNoEVeto = 1UL << (PhoVLoose50 + 3),
            PhoMediumNoEVeto = 1UL << (PhoVLoose50 + 4),
            PhoTightNoEVeto = 1UL << (PhoVLoose50 + 5)
        };

        BarePhotons();
        ~BarePhotons();
        void init() override;
        void clear() override;
        void defineBranches(TTree*) override;
        void defineBranches(TTree* t, std::string) override { defineBranches(t); }
        void setBranchAddresses(TTree*) override;
        void setBranchAddresses(TTree* t, std::string) override { setBranchAddresses(t); }
        inline string name() override { return "BarePhotons"; }

        bool inline passSelection(const unsigned &idx, const Selection &sel) const  { return (selBits->at(idx) & sel) != 0; }
        // -- variables
        //TClonesArray *p4{0};
        vector<float> *sieie{0};
        
        vector<float> *iso{0};
        vector<unsigned> *selBits{0};

        vector<float> *chIso{0};
        vector<float> *chIsoRC{0};
        vector<float> *nhIso{0};
        vector<float> *nhIsoRC{0};
        vector<float> *phoIso{0};
        vector<float> *phoIsoRC{0};
        vector<float> *puIso{0};
        vector<float> *puIsoRC{0};

        // EXTENDED VARIABLES
        vector<float> *rawpt{0};
        vector<float> *e55{0};

        vector<float> *hOverE{0};
        vector<float> *chWorstIso{0};
        vector<float> *chIsoMax{0};
    
        vector<float> *sipip{0};
        vector<float> *sieip{0};
        vector<float> *r9{0};
        vector<float> *s4{0};

        vector<float> *mipEnergy{0};

        vector<float> *time{0};
        vector<float> *timeSpan{0};
    
        vector<short> *genMatched{0};
};

#endif
// Local Variables:
// mode:c++
// indent-tabs-mode:nil
// tab-width:4
// c-basic-offset:4
// End:
// vim: tabstop=4 expandtab shiftwidth=4 softtabstop=4
