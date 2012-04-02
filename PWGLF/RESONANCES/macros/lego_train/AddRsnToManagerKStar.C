#ifndef __CINT__
#endif
Bool_t AddRsnToManagerKStar(TList *listRsn) {
   // This will use AddRsnPairs<Name>.C
   // and for cuts AddRsnDaughterCuts<CutName>.C
   // and <opt> string is passed to AddRsnDaughterCuts<CutName>.C
   // so you can control different cut settings
   // string "<Name>:mon" means that it will add monitoring histograms from cuts
   // Note : for now you have to set gRsnUseMiniPackage = 0 to have mon histograms
   //    listRsn->Add(new TNamed("<Name>:mon","<CutName>:<opt>"));

   listRsn->Add(new TNamed("KStar","KStarNsigma"));
   listRsn->Add(new TNamed("KStar","KStarNsigma:qualityonly"));
   
   // this is TPC only
   listRsn->Add(new TNamed("KStar","KStarNsigma:PiTPCnsig10_KTPCnsig20"));
// 
//    // this is TOF only
//    listRsn->Add(new TNamed("KStar","KStarNsigma:PiTOFnsig20_KTOFnsig20"));
// 
//    // this is TPC only for KAON and TOF only for PI
//    listRsn->Add(new TNamed("KStar","KStarNsigma:PiTPCnsig20_KTOFnsig30"));

   return kTRUE;
}
