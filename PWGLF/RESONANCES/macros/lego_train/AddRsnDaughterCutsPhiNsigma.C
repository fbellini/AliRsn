#ifndef __CINT__
#endif
Int_t AddRsnDaughterCutsPhiNsigma(AliPID::EParticleType type1,AliPID::EParticleType type2,TString opt,Bool_t isRsnMini=kFALSE,AliRsnInputHandler *rsnIH=0,AliAnalysisTaskSE *task=0)
{

   if (!rsnIH) return 0;

   Bool_t valid = kTRUE;
   Int_t isPP = AliAnalysisManager::GetGlobalInt("rsnIsPP",valid);

   Bool_t usePPCut = kFALSE;

   if (isPP && (opt.Contains("usePP"))) usePPCut = kTRUE;


   // === USER HAS TO SET CORRECT NUMBER OF CUTS SETS =====
   Int_t numberOfCuts = 1;

   //---------------------------------------------
   //  Define single cuts
   //---------------------------------------------

   Printf("AliRsnCutPIDNSigma Option : %s",opt.Data());

   Double_t nSigmaTPC=3.0;
   Double_t nSigmaTOF=3.0;
   Double_t etaRange=0.8;

   if (opt.Contains("TPCsigma1")) nSigmaTPC = 1.0;
   if (opt.Contains("TPCsigma2")) nSigmaTPC = 2.0;
   if (opt.Contains("TPCsigma3")) nSigmaTPC = 3.0;

   if (opt.Contains("TOFsigma1")) nSigmaTOF = 1.0;
   if (opt.Contains("TOFsigma2")) nSigmaTOF = 2.0;
   if (opt.Contains("TOFsigma3")) nSigmaTOF = 3.0;

   Bool_t usePDG=kFALSE;
   if (opt.Contains("pdg")) {
      Printf("Using PDG");
      usePDG = kTRUE;
   }

   Bool_t useEta = kFALSE;
   if (opt.Contains("eta")) {
      Printf("Using ETA range (%.2f,%.2f)",-etaRange,etaRange);
      useEta = kTRUE;
   }

//---------------------------------------------
//  Combine cuts
//---------------------------------------------

   TString cutname = "pionRho";
   if (!opt.IsNull()) cutname += Form("_%s",opt.Data());
   AliRsnCutSet *cuts = new AliRsnCutSet(cutname.Data(), AliRsnTarget::kDaughter);

   TString scheme="";

   AliRsnCutTrackQuality *qualityCut = new AliRsnCutTrackQuality("cutQuatity");
   qualityCut->SetDefaults2010();
   cuts->AddCut(qualityCut);
   if (!scheme.IsNull()) scheme += "&";
   scheme += qualityCut->GetName();
   
   AliRsnCutPIDNSigma *cutPiTPC = new AliRsnCutPIDNSigma("cutPIDNSigmaTPC",AliPID::kKaon,AliRsnCutPIDNSigma::kTPC);
   cutPiTPC->SinglePIDRange(nSigmaTPC);
   cuts->AddCut(cutPiTPC);
   if (!scheme.IsNull()) scheme += "&";
   scheme += cutPiTPC->GetName();

   AliRsnCutPIDNSigma *cutPiTOF = new AliRsnCutPIDNSigma("cutPIDNSigmaTOF",AliPID::kKaon,AliRsnCutPIDNSigma::kTOF);
   cutPiTOF->SinglePIDRange(nSigmaTOF);
   cuts->AddCut(cutPiTOF);
   if (!scheme.IsNull()) scheme += "&";
   scheme += cutPiTOF->GetName();

   if (useEta) {
      Printf("Adding ETA ...");
      AliRsnValueDaughter *valEta = new AliRsnValueDaughter(Form("val%sETA%s",AliPID::ParticleName(type1),opt.Data()),AliRsnValueDaughter::kEta);
      AliRsnCutValue *cutEta = new AliRsnCutValue(Form("cut%sETA%s",AliPID::ParticleName(type1),opt.Data()),-etaRange,etaRange);
      cutEta->SetTargetType(AliRsnTarget::kDaughter);
      cutEta->SetValueObj(valEta);
      cuts->AddCut(cutEta);
      if (!scheme.IsNull()) scheme += "&";
      scheme += cutEta->GetName();
   }
   if (usePDG) {
      Printf("Adding PDG ...");
      AliRsnCutPID *cutPDG = new AliRsnCutPID(Form("cut%sPDG%s",AliPID::ParticleName(type1),opt.Data()),type1,0.0,kTRUE);
      cuts->AddCut(cutPDG);
      if (!scheme.IsNull()) scheme += "&";
      scheme += cutPDG->GetName();
   }

   Printf ("CUT Scheme is '%s'",scheme.Data());
   cuts->SetCutScheme(scheme.Data());

   if (opt.Contains("mon")) {
      AddMonitorOutput(cuts->GetMonitorOutput(),opt);
   }
   if (isRsnMini) {
      AliRsnMiniAnalysisTask *taskRsnMini = dynamic_cast<AliRsnMiniAnalysisTask *>(task);
      if (taskRsnMini) {
         taskRsnMini->AddTrackCuts(cuts);
      }
   } else {
      AliRsnDaughterSelector *sel = rsnIH->GetSelector();
//       sel->SetLabelCheck(kFALSE);
      sel->Add(cuts, kTRUE);
   }
   return numberOfCuts;

}

