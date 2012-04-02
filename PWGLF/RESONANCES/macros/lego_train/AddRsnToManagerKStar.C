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

//    listRsn->Add(new TNamed("KStar","KStar2010"));
//    listRsn->Add(new TNamed("KStar","BPID:mon"));

//    listRsn->Add(new TNamed("KStar","KStar"));
//    listRsn->Add(new TNamed("KStar","KStar:TPCTOFpidDefaultKstarPP2010_mon"));
//    listRsn->Add(new TNamed("KStar","KStar:FastTPCpid1point5sigma_mon"));
//    listRsn->Add(new TNamed("KStar","KStar:FastTPCpid2sigma_mon"));

   return kTRUE;
}
