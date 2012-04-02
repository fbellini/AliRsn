#ifndef __CINT__
#endif
Bool_t AddRsnToManagerLambda(TList *listRsn) {
   // This will use AddRsnPairs<Name>.C
   // and for cuts AddRsnDaughterCuts<CutName>.C
   // and <opt> string is passed to AddRsnDaughterCuts<CutName>.C
   // so you can control different cut settings
   // string "<Name>:mon" means that it will add monitoring histograms from cuts
   // Note : for now you have to set gRsnUseMiniPackage = 0 to have mon histograms
   //    listRsn->Add(new TNamed("<Name>:mon","<CutName>:<opt>"));

   listRsn->Add(new TNamed("Lambda","Lambda"));
//    listRsn->Add(new TNamed("Lambda","Lambda:TPCPsigma2_TPCKsigma1"));

   return kTRUE;
}
