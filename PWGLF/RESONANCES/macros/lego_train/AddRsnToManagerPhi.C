#ifndef __CINT__
#endif
Bool_t AddRsnToManagerPhi(TList *listRsn) {
   // This will use AddRsnPairs<Name>.C
   // and for cuts AddRsnDaughterCuts<CutName>.C
   // and <opt> string is passed to AddRsnDaughterCuts<CutName>.C
   // so you can control different cut settings
   // string "<Name>:mon" means that it will add monitoring histograms from cuts
   // Note : for now you have to set gRsnUseMiniPackage = 0 to have mon histograms
   //    listRsn->Add(new TNamed("<Name>:mon","<CutName>:<opt>"));

   // default NSigma -> TPC=3 and TOF=3
   listRsn->Add(new TNamed("Phi","PhiNSigma"));

// //    qualityonly
//    listRsn->Add(new TNamed("Phi","PhiNSigma:qualityonly"));
//
// //    TPC only (Nsigma=1.5)
//    listRsn->Add(new TNamed("Phi","PhiNSigma:KTPCnsig15"));
//
// //    TOF only (NSigma=2.0)
//    listRsn->Add(new TNamed("Phi","PhiNSigma:KTOFnsig20"));


   return kTRUE;
}
