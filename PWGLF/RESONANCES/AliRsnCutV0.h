#ifndef ALIRSNCUTV0_H
#define ALIRSNCUTV0_H

#include <TMath.h>
#include <TString.h>

#include "AliRsnCut.h"
#include "AliPIDResponse.h"

class AliESDtrack;
class AliAODTrack;


class AliRsnCutV0 : public AliRsnCut {

public:


   //AliRsnCutV0(const char *name = "AliRsnCutV0", Int_t hypothesis = kLambda0);
   AliRsnCutV0(const char *name = "AliRsnCutV0", Int_t hypothesis = kLambda0, AliPID::EParticleType pid = AliPID::kProton, AliPID::EParticleType pid2 = AliPID::kPion);
   AliRsnCutV0(const AliRsnCutV0 &copy);
   AliRsnCutV0 &operator=(const AliRsnCutV0 &copy);
   virtual ~AliRsnCutV0() { }

   void           SetESDtrackCuts(AliESDtrackCuts *cuts)   {fESDtrackCuts = cuts;}
   void           SetHypothesis(Int_t code);
   void           SetTolerance(Double_t value)             {fTolerance = value;}
   void           SetMaxDCAVertex(Double_t value)          {fMaxDCAVertex = value;}
   void           SetMinCosPointingAngle(Double_t value)   {fMinCosPointAngle = value;}
   void           SetMaxDaughtersDCA(Double_t value)       {fMaxDaughtersDCA = value;}
   void           SetMaxRapidity(Double_t value)           {fMaxRapidity = value;}

   void           SetPIDCut1(Double_t value)               {fPIDCut1 = value;}
   void           SetPIDCut2(Double_t value)               {fPIDCut2 = value;}
   void           SetPIDCut3(Double_t value)               {fPIDCut3 = value;}

   virtual Bool_t IsSelected(TObject *obj);
   virtual void   Print(const Option_t *option = "") const;

protected:

   Bool_t      CheckESD(AliESDv0 *track);
   Bool_t      CheckAOD(AliAODv0 *track);

   Int_t            fHypothesis;       // PDG code corresponding to expected V0 hypothesis
   Double_t         fMass;             // mass corresponding to hypothesis
   Double_t         fTolerance;        // tolerance in the difference between computed and expected mass
   Double_t         fMaxDCAVertex;     // max allowed DCA from primary vertex
   Double_t         fMinCosPointAngle; // min allowed cosine of pointing angle
   Double_t         fMaxDaughtersDCA;  // max allowed DCA between the two daughers
   Double_t         fMaxRapidity;      // max allowed V0 rapidity

   AliPID::EParticleType fPID;         // PID for track
   AliPID::EParticleType fPID2;        // PID for track

   Double_t         fPIDCut1;          // nsigmas for protons < 600 MeV/c
   Double_t         fPIDCut2;          // nsigmas for protons > 600 MeV/c
   Double_t         fPIDCut3;          // nsigmas for pions


   AliESDtrackCuts *fESDtrackCuts;     // quality cuts for v0 daughters

   ClassDef(AliRsnCutV0, 1)
};

//__________________________________________________________________________________________________
inline void AliRsnCutV0::SetHypothesis(Int_t code)
{
//
// Assign a V0 species hypothesis, which also assign the expected mass
//

   fHypothesis = code;

   switch (fHypothesis) {
      case kLambda0:
         fMass = 1.11568;
         break;
      case kLambda0Bar:
         fMass = 1.11568;
         break;
      case kK0Short:
         fMass = 0.497614;
         break;
      default:
         AliError(Form("You are setting an unexpected hypothesis: %d", fHypothesis));
         fMass = 1E20;
   }
}

#endif
