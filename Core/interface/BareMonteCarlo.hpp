#ifndef BARE_MONTECARLO_H
#define BARE_MONTECARLO_H

#include "NeroProducer/Core/interface/BareCollection.hpp"
#include "NeroProducer/Core/interface/BareP4.hpp"


class BareMonteCarlo : virtual public BareP4
{
    public:
        BareMonteCarlo();
        ~BareMonteCarlo();
        void init() override;
        void clear() override;
        void defineBranches(TTree*) override;
        void defineBranches(TTree* t, std::string) override { defineBranches(t); }
        void setBranchAddresses(TTree*) override;
        void setBranchAddresses(TTree* t, std::string) override { setBranchAddresses(t); }
        inline string name() { return "BareMonteCarlo"; }
        void compress() override;

        // -- variables
        //TClonesArray *p4{0}; // gen particles
        vector<int>  *pdgId{0};

        // genjets
        TClonesArray *jetP4{0};

        //
        int puTrueInt;
        //
        float mcWeight ;
        float qScale   ;
        float alphaQED ;
        float alphaQCD ;
        float x1       ;
        float x2       ;
        int   pdf1Id   ;
        int   pdf2Id   ;
        float scalePdf ;

        // QCD scale reweights
        float r2f1;
        float r5f1;
        float r1f2;
        float r2f2;
        float r1f5;
        float r5f5;
    
        // PDF reweights
        std::vector<float> *pdfRwgt{0};

};
#endif
// Local Variables:
// mode:c++
// indent-tabs-mode:nil
// tab-width:4
// c-basic-offset:4
// End:
// vim: tabstop=4 expandtab shiftwidth=4 softtabstop=4
