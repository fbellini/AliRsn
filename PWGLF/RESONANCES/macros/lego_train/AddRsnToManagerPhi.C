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

   listRsn->Add(new TNamed("Phi","PhiNsigma"));
//    listRsn->Add(new TNamed("Phi","PhiNsigma:qualityonly"));
//    listRsn->Add(new TNamed("Phi","PhiNsigma:KTPCnsig10"));
//    listRsn->Add(new TNamed("Phi","PhiNsigma:KTPCnsig25"));
   
   //    listRsn->Add(new TNamed("Phi","PhiDev"));

   return kTRUE;
}
