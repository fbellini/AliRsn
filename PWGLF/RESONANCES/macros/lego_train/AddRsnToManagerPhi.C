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

   //    listRsn->Add(new TNamed("Phi","Phi2010"));
// //    listRsn->Add(new TNamed("Phi","Phi2010:trackPtMax18"));
//    listRsn->Add(new TNamed("Phi","Phi2010:usePP"));
// //    listRsn->Add(new TNamed("Phi","Phi2010:usePP_trackPtMax18"));
//    listRsn->Add(new TNamed("Phi","Phi2010:tpconly_TPCsigma3"));
//    listRsn->Add(new TNamed("Phi","Phi2010:tofonly_TOFsigma3"));
//    listRsn->Add(new TNamed("Phi","Phi2010:qualityonly"));


//    listRsn->Add(new TNamed("Phi","Phi2010:tpconly_TPCsigma1"));
//    listRsn->Add(new TNamed("Phi","Phi2010:tpconly_TPCsigma1.5"));
//    listRsn->Add(new TNamed("Phi","Phi2010:tpconly_TPCsigma2"));
//    listRsn->Add(new TNamed("Phi","Phi2010:tpconly_TPCsigma2.5"));
//    listRsn->Add(new TNamed("Phi","Phi2010:tpconly_TPCsigma3"));


//    listRsn->Add(new TNamed("Phi","Phi2010:pdg"));
//    listRsn->Add(new TNamed("Phi","Phi2010:usePP_pdg"));
// //    listRsn->Add(new TNamed("Phi","Phi2010:trackPtMax18_pdg"));
// //    listRsn->Add(new TNamed("Phi","Phi2010:usePP_trackPtMax18_pdg"));
//    listRsn->Add(new TNamed("Phi","Phi2010:tpconly_TPCsigma3_pdg"));
//    listRsn->Add(new TNamed("Phi","Phi2010:tofonly_TOFsigma3_pdg"));
//    listRsn->Add(new TNamed("Phi","Phi2010:qualityonly_pdg"));
//
//    listRsn->Add(new TNamed("Phi","PDG:NoTOFSIGMA"));

//    listRsn->Add(new TNamed("Phi","Phi2010:tpconly_TPCsigma1_pdg"));
//    listRsn->Add(new TNamed("Phi","Phi2010:tpconly_TPCsigma1.5_pdg"));
//    listRsn->Add(new TNamed("Phi","Phi2010:tpconly_TPCsigma2_pdg"));
//    listRsn->Add(new TNamed("Phi","Phi2010:tpconly_TPCsigma2.5_pdg"));
//    listRsn->Add(new TNamed("Phi","Phi2010:tpconly_TPCsigma3_pdg"));

// //    listRsn->Add(new TNamed("Phi","Phi2010:tofonly_TOCsigma3_trackPtMax18"));
// //    listRsn->Add(new TNamed("Phi","Phi2010:tofonly_TOCsigma3_trackPtMax18_pdg"));
//
//
// //   listRsn->Add(new TNamed("Phi","BPID"));
//
// //   listRsn->Add(new TNamed("Phi","Phi2010:tpcptMax05"));
// //   listRsn->Add(new TNamed("Phi","Phi2010:tpcptMax06"));
// //   listRsn->Add(new TNamed("Phi","Phi2010:tpcptMax07"));
// //   listRsn->Add(new TNamed("Phi","Phi2010:tpcptMax08"));
// //   listRsn->Add(new TNamed("Phi","Phi2010:TPCsigma1_tpcptMax06"));
// //   listRsn->Add(new TNamed("Phi","Phi2010:TPCsigma1_tpcptMax08"));

   //    listRsn->Add(new TNamed("Phi","PhiDev"));

   return kTRUE;
}
