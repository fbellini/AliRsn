#ifndef __CINT__
#endif
Int_t AddRsnDaughterCutsLambda(AliPID::EParticleType type1,AliPID::EParticleType type2,TString opt,Bool_t isRsnMini=kFALSE,AliRsnInputHandler *rsnIH=0,AliAnalysisTaskSE *task=0)
{

   if (!rsnIH) return 0;

   Bool_t valid = kTRUE;
   Int_t isPP = AliAnalysisManager::GetGlobalInt("rsnIsPP",valid);

   Bool_t usePPCut = kFALSE;

   if (isPP && (opt.Contains("usePP"))) usePPCut = kTRUE;


   // === USER HAS TO SET CORRECT NUMBER OF CUTS SETS =====
   Int_t numberOfCuts = 2;

   //---------------------------------------------
   //  Define single cutsP
   //---------------------------------------------

   Printf("AliRsnCutPIDNSigma Option : %s",opt.Data());

   Double_t nSigmaTPC_P=3.0;
   Double_t nSigmaTPC_K=3.0;
   Double_t nSigmaTOF_P=3.0;
   Double_t nSigmaTOF_K=3.0;
   Double_t etaRange=0.8;

   if (opt.Contains("TPCPsigma1")) nSigmaTPC_P = 1.0;
   if (opt.Contains("TPCPsigma2")) nSigmaTPC_P = 2.0;
   if (opt.Contains("TPCPsigma3")) nSigmaTPC_P = 3.0;

   if (opt.Contains("TPCKsigma1")) nSigmaTPC_K = 1.0;
   if (opt.Contains("TPCKsigma2")) nSigmaTPC_K = 2.0;
   if (opt.Contains("TPCKsigma3")) nSigmaTPC_K = 3.0;

   if (opt.Contains("TOFPsigma1")) nSigmaTOF_P = 1.0;
   if (opt.Contains("TOFPsigma2")) nSigmaTOF_P = 2.0;
   if (opt.Contains("TOFPsigma3")) nSigmaTOF_P = 3.0;

   if (opt.Contains("TOFKsigma1")) nSigmaTOF_K = 1.0;
   if (opt.Contains("TOFKsigma2")) nSigmaTOF_K = 2.0;
   if (opt.Contains("TOFKsigma3")) nSigmaTOF_K = 3.0;

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

   // PROTON SETTINGS ===========================================

   TString scheme="";
   TString cutname = "protonLambda";
   if (!opt.IsNull()) cutname += Form("_%s",opt.Data());
   AliRsnCutSet *cutsP = new AliRsnCutSet(cutname.Data(), AliRsnTarget::kDaughter);
   
   AliRsnCutTrackQuality *qualityCutP = new AliRsnCutTrackQuality("cutQuatity{");
   qualityCutP->SetDefaults2010();
   cutsP->AddCut(qualityCutP);
   if (!scheme.IsNull()) scheme += "&";
   scheme += qualityCutP->GetName();
   
   AliRsnCutPIDNSigma *cutPTPC = new AliRsnCutPIDNSigma("cutNSigmaTPCP",AliPID::kProton,AliRsnCutPIDNSigma::kTPC);
   cutPTPC->SinglePIDRange(nSigmaTPC_P);
   cutsP->AddCut(cutPTPC);
   if (!scheme.IsNull()) scheme += "&";
   scheme += cutPTPC->GetName();

   AliRsnCutPIDNSigma *cutPTOF = new AliRsnCutPIDNSigma("cutNSigmaTOFP",AliPID::kProton,AliRsnCutPIDNSigma::kTOF);
   cutPTOF->SinglePIDRange(nSigmaTOF_P);
   cutsP->AddCut(cutPTOF);
   if (!scheme.IsNull()) scheme += "&";
   scheme += cutPTOF->GetName();

   if (useEta) {
      AliRsnValueDaughter *valEtaP = new AliRsnValueDaughter(Form("val%sETA%s",AliPID::ParticleName(type1),opt.Data()),AliRsnValueDaughter::kEta);
      AliRsnCutValue *cutEtaP = new AliRsnCutValue(Form("cut%sETA%s",AliPID::ParticleName(type1),opt.Data()),-etaRange,etaRange);
      cutEtaP->SetTargetType(AliRsnTarget::kDaughter);
      cutEtaP->SetValueObj(valEtaP);
      cutsP->AddCut(cutEtaP);
      if (!scheme.IsNull()) scheme += "&";
      scheme += cutEtaP->GetName();
   }
   if (usePDG) {
      AliRsnCutPID *cutPDGP = new AliRsnCutPID(Form("cut%sPDG%s",AliPID::ParticleName(type1),opt.Data()),type1,0.0,kTRUE);
      cutsP->AddCut(cutPDGP);
      if (!scheme.IsNull()) scheme += "&";
      scheme += cutPDGP->GetName();
   }

   Printf ("CUT Scheme for PROTON is '%s'",scheme.Data());
   cutsP->SetCutScheme(scheme.Data());

   // END PROTON =======================================
   
   // KAON SETTINGS =======================================
   scheme="";
   cutname = "kaonLambda";
   if (!opt.IsNull()) cutname += Form("_%s",opt.Data());
   AliRsnCutSet *cutsK = new AliRsnCutSet(cutname.Data(), AliRsnTarget::kDaughter);
   
   AliRsnCutTrackQuality *qualityCutK = new AliRsnCutTrackQuality("cutQuatityK");
   qualityCutK->SetDefaults2010();
   cutsK->AddCut(qualityCutK);
   if (!scheme.IsNull()) scheme += "&";
   scheme += qualityCutK->GetName();
   
   AliRsnCutPIDNSigma *cutKTPC = new AliRsnCutPIDNSigma("cutNSigmaTPCK",AliPID::kKaon,AliRsnCutPIDNSigma::kTPC);
   cutKTPC->SinglePIDRange(nSigmaTPC_K);
   cutsK->AddCut(cutKTPC);
   if (!scheme.IsNull()) scheme += "&";
   scheme += cutKTPC->GetName();

   AliRsnCutPIDNSigma *cutKTOF = new AliRsnCutPIDNSigma("cutNSigmaTOFK",AliPID::kKaon,AliRsnCutPIDNSigma::kTOF);
   cutKTOF->SinglePIDRange(nSigmaTOF_K);
   cutsK->AddCut(cutKTOF);
   if (!scheme.IsNull()) scheme += "&";
   scheme += cutKTOF->GetName();

   if (useEta) {
      AliRsnValueDaughter *valEtaK = new AliRsnValueDaughter(Form("val%sETA%s",AliPID::ParticleName(type2),opt.Data()),AliRsnValueDaughter::kEta);
      AliRsnCutValue *cutEtaK = new AliRsnCutValue(Form("cut%sETA%s",AliPID::ParticleName(type2),opt.Data()),-etaRange,etaRange);
      cutEtaK->SetTargetType(AliRsnTarget::kDaughter);
      cutEtaK->SetValueObj(valEtaK);
      cutsK->AddCut(cutEtaK);
      if (!scheme.IsNull()) scheme += "&";
      scheme += cutEtaK->GetName();
   }
   if (usePDG) {
      AliRsnCutPID *cutPDGK = new AliRsnCutPID(Form("cut%sPDG%s",AliPID::ParticleName(type2),opt.Data()),type2,0.0,kTRUE);
      cutsK->AddCut(cutPDGK);
      if (!scheme.IsNull()) scheme += "&";
      scheme += cutPDGK->GetName();
   }

   Printf ("CUT Scheme for KAON is '%s'",scheme.Data());
   cutsK->SetCutScheme(scheme.Data());

   // END KAON =======================================
   
   if (opt.Contains("mon")) {
      AddMonitorOutput(cutsP->GetMonitorOutput(),opt);
      AddMonitorOutput(cutsK->GetMonitorOutput(),opt);
   }
   if (isRsnMini) {
      AliRsnMiniAnalysisTask *taskRsnMini = dynamic_cast<AliRsnMiniAnalysisTask *>(task);
      if (taskRsnMini) {
         taskRsnMini->AddTrackCuts(cutsP);
         taskRsnMini->AddTrackCuts(cutsK);
      }
   } else {
      AliRsnDaughterSelector *sel = rsnIH->GetSelector();
//       sel->SetLabelCheck(kFALSE);
      sel->Add(cutsP, kTRUE);
      sel->Add(cutsK, kTRUE);
   }
   return numberOfCuts;

}
