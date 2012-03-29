PACKAGE = PWGLFresonances

include Makefile.arch

SRCS = RESONANCES/AliRsnDaughter.cxx RESONANCES/AliRsnMother.cxx RESONANCES/AliRsnEvent.cxx RESONANCES/AliRsnDaughterDef.cxx RESONANCES/AliRsnPairDef.cxx RESONANCES/AliRsnTarget.cxx RESONANCES/AliRsnValue.cxx RESONANCES/AliRsnAction.cxx RESONANCES/AliRsnCut.cxx RESONANCES/AliRsnValueDaughter.cxx RESONANCES/AliRsnValuePair.cxx RESONANCES/AliRsnValueEvent.cxx RESONANCES/AliRsnCutPrimaryVertex.cxx RESONANCES/AliRsnCutTrackQuality.cxx RESONANCES/AliRsnCutTrue.cxx RESONANCES/AliRsnCutValue.cxx RESONANCES/AliRsnCutPID.cxx RESONANCES/AliRsnCutPIDITS.cxx RESONANCES/AliRsnCutPIDTPC.cxx RESONANCES/AliRsnCutPIDTOF.cxx RESONANCES/AliRsnPIDRange.cxx RESONANCES/AliRsnCutPIDNSigma.cxx RESONANCES/AliRsnCutMomentumComparison.cxx RESONANCES/AliRsnCutKaonForPhi2010.cxx RESONANCES/AliRsnCutKaonForPhi2010PP.cxx RESONANCES/AliRsnCutPion2010PP.cxx RESONANCES/AliRsnCutProton2010PP.cxx RESONANCES/AliRsnCutDaughterKStar2010PP.cxx RESONANCES/AliRsnCutDaughterLStar2010.cxx RESONANCES/AliRsnCutV0.cxx RESONANCES/AliRsnCutSet.cxx RESONANCES/AliRsnExpression.cxx RESONANCES/AliRsnVariableExpression.cxx RESONANCES/AliRsnCutManager.cxx RESONANCES/AliRsnListOutput.cxx RESONANCES/AliRsnLoop.cxx RESONANCES/AliRsnLoopDaughter.cxx RESONANCES/AliRsnLoopPair.cxx RESONANCES/AliRsnLoopEvent.cxx RESONANCES/AliRsnLoopEff.cxx RESONANCES/AliRsnLoopEffPair.cxx RESONANCES/AliRsnDaughterSelector.cxx RESONANCES/AliRsnInputHandler.cxx RESONANCES/AliRsnAnalysisTask.cxx RESONANCES/AliRsnMiniParticle.cxx RESONANCES/AliRsnMiniPair.cxx RESONANCES/AliRsnCutMiniPair.cxx RESONANCES/AliRsnMiniEvent.cxx RESONANCES/AliRsnMiniAxis.cxx RESONANCES/AliRsnMiniOutput.cxx RESONANCES/AliRsnMiniValue.cxx RESONANCES/AliRsnMiniMonitor.cxx RESONANCES/AliRsnMiniAnalysisTask.cxx RESONANCES/AliRsnMiniMonitorTask.cxx RESONANCES/AliRsnCutKaon.cxx RESONANCES/AliRsnCutPion.cxx RESONANCES/AliRsnCutDaughterSigmaStar2010PP.cxx
HDRS = RESONANCES/AliRsnDaughter.h RESONANCES/AliRsnMother.h RESONANCES/AliRsnEvent.h RESONANCES/AliRsnDaughterDef.h RESONANCES/AliRsnPairDef.h RESONANCES/AliRsnTarget.h RESONANCES/AliRsnValue.h RESONANCES/AliRsnAction.h RESONANCES/AliRsnCut.h RESONANCES/AliRsnValueDaughter.h RESONANCES/AliRsnValuePair.h RESONANCES/AliRsnValueEvent.h RESONANCES/AliRsnCutPrimaryVertex.h RESONANCES/AliRsnCutTrackQuality.h RESONANCES/AliRsnCutTrue.h RESONANCES/AliRsnCutValue.h RESONANCES/AliRsnCutPID.h RESONANCES/AliRsnCutPIDITS.h RESONANCES/AliRsnCutPIDTPC.h RESONANCES/AliRsnCutPIDTOF.h RESONANCES/AliRsnPIDRange.h RESONANCES/AliRsnCutPIDNSigma.h RESONANCES/AliRsnCutMomentumComparison.h RESONANCES/AliRsnCutKaonForPhi2010.h RESONANCES/AliRsnCutKaonForPhi2010PP.h RESONANCES/AliRsnCutPion2010PP.h RESONANCES/AliRsnCutProton2010PP.h RESONANCES/AliRsnCutDaughterKStar2010PP.h RESONANCES/AliRsnCutDaughterLStar2010.h RESONANCES/AliRsnCutV0.h RESONANCES/AliRsnCutSet.h RESONANCES/AliRsnExpression.h RESONANCES/AliRsnVariableExpression.h RESONANCES/AliRsnCutManager.h RESONANCES/AliRsnListOutput.h RESONANCES/AliRsnLoop.h RESONANCES/AliRsnLoopDaughter.h RESONANCES/AliRsnLoopPair.h RESONANCES/AliRsnLoopEvent.h RESONANCES/AliRsnLoopEff.h RESONANCES/AliRsnLoopEffPair.h RESONANCES/AliRsnDaughterSelector.h RESONANCES/AliRsnInputHandler.h RESONANCES/AliRsnAnalysisTask.h RESONANCES/AliRsnMiniParticle.h RESONANCES/AliRsnMiniPair.h RESONANCES/AliRsnCutMiniPair.h RESONANCES/AliRsnMiniEvent.h RESONANCES/AliRsnMiniAxis.h RESONANCES/AliRsnMiniOutput.h RESONANCES/AliRsnMiniValue.h RESONANCES/AliRsnMiniMonitor.h RESONANCES/AliRsnMiniAnalysisTask.h RESONANCES/AliRsnMiniMonitorTask.h RESONANCES/AliRsnCutKaon.h RESONANCES/AliRsnCutPion.h RESONANCES/AliRsnCutDaughterSigmaStar2010PP.h
DHDR = PWGLFresonancesLinkDef.h

ifndef PACKCXXFLAGS
   PACKCXXFLAGS = $(CXXFLAGS)
endif

ALICEINC = -I.
ALICEINC += -I$(PACKAGE)

ALIPARLIBS = -L$(ROOTLIBDIR) -lMinuit -lTree -lXMLParser -lVMC -lMinuit -lEG -lGeom

# ALICELIBS += -L$(ALICE_ROOT)/lib/tgt_$(shell $(RC) --arch) 

ifneq ($(STEERBase_INCLUDE),)
   ALICEINC += -I../$(STEERBase_INCLUDE)
   ALIPARLIBS += $(STEERBase_LIBS)
else
   ALICELIBS += -lSTEERbase
endif

ifneq ($(ESD_INCLUDE),)
   ALICEINC += -I../$(ESD_INCLUDE)
   ALIPARLIBS += $(ESD_LIBS)
else
   ALICELIBS += -lESD
endif

ifneq ($(AOD_INCLUDE),)
   ALICEINC += -I../$(AOD_INCLUDE)
   ALIPARLIBS += $(AOD_LIBS)
else
   ALICELIBS += -lAOD
endif

ifneq ($(ANALYSIS_INCLUDE),)
   ALICEINC += -I../$(ANALYSIS_INCLUDE)
   ALIPARLIBS += $(ANALYSIS_LIBS)
else
   ALICELIBS += -lANALYSIS
endif

ifneq ($(ANALYSISalice_INCLUDE),)
   ALICEINC += -I../$(ANALYSISalice_INCLUDE)
   ALIPARLIBS += $(ANALYSISalice_LIBS)
else
   ALICELIBS += -lANALYSISalice
endif

ifneq ($(EventMixing_INCLUDE),)
   ALICEINC += -I../$(EventMixng_INCLUDE)
   ALIPARLIBS += $(EventMixing_LIBS)
else
   ALICELIBS += -lEventMixing
endif

ifneq ($(PWGLFresonances_INCLUDE),)
   ALICEINC += -I../$(PWGLFresonances_INCLUDE)
   ALIPARLIBS += $(PWGLFresonances_LIBS)
else
   ALICELIBS += -lPWGLFresonances
endif

ifneq ($(PWGLFresonancesdev_INCLUDE),)
   ALICEINC += -I../$(PWGLFresonancesdev_INCLUDE)
   ALIPARLIBS += $(PWGLFresonancesdev_LIBS)
else
   ALICELIBS += -lPWGLFresonances
endif

# only if no par file was loaded before
ifeq ($(ALICEINC),-I.)
  ifneq ($(ALICE_ROOT),)
    ALICEINC += -I$(ALICE_ROOT)/include
    ALIPARLIBS += -L$(ALICE_ROOT)/lib/tgt_$(shell $(RC) --arch) $(ALICELIBS)
  endif
endif

ALICEINC += -I$(ALICE_ROOT)/include

ifeq ($(PLATFORM),macosx)
ROOTLIBDIR     := $(shell $(RC) --libdir)
# ALIROOTLIBDIR  := $(ALICE_ROOT)/lib/tgt_$(shell $(RC) --arch)


PACKLDFLAGS = $(ALIPARLIBS) -L$(ROOTLIBDIR) -lMinuit -lTree -lXMLParser -lVMC -lMinuit -lEG -lGeom

# ifeq ($(PACKAGE),STEERBase)
#    PACKLDFLAGS = -L$(ROOTLIBDIR)  -lVMC -lMinuit -lEG -lGeom
# endif
# ifeq ($(PACKAGE),ESD)
#    PACKLDFLAGS = $(ALIPARLIBS) -L$(ALIROOTLIBDIR) -L$(ROOTLIBDIR) -lVMC -lEG -lGeom
# endif
# ifeq ($(PACKAGE),AOD)
#    PACKLDFLAGS = $(STEERBase_LIBS) -L$(ALIROOTLIBDIR) -L$(ROOTLIBDIR) -lEG -lGeom
# endif
# ifeq ($(PACKAGE),CDB)
#    PACKLDFLAGS = $(STEERBase_LIBS) -L$(ALIROOTLIBDIR) -L$(ROOTLIBDIR) -lMinuit -lTree -lXMLParser
# endif
# ifeq ($(PACKAGE),ANALYSIS)
#    PACKLDFLAGS =  $(AOD_LIBS) $(ESD_LIBS) $(STEERBase_LIBS) -L$(ALIROOTLIBDIR) -L$(ROOTLIBDIR) -lMinuit -lTree -lXMLParser
# endif
# ifeq ($(PACKAGE),ANALYSISalice)
#    PACKLDFLAGS =  $(ANALYSIS_LIBS) $(AOD_LIBS) $(ESD_LIBS) $(STEERBase_LIBS) -L$(ALIROOTLIBDIR) -L$(ROOTLIBDIR) -lMinuit -lTree -lXMLParser
# endif
# ifeq ($(PACKAGE),EventMixng)
#    PACKLDFLAGS =  $(ANALYSISalice_LIBS)  $(ANALYSIS_LIBS) $(AOD_LIBS) $(ESD_LIBS) $(STEERBase_LIBS) -L$(ALIROOTLIBDIR) -L$(ROOTLIBDIR) -lTree
# endif
# ifeq ($(PACKAGE),PWGLFresonances)
#    PACKLDFLAGS =  $(EventMixng_LIBS) $(ANALYSISalice_LIBS)  $(ANALYSIS_LIBS) $(AOD_LIBS) $(ESD_LIBS) $(STEERBase_LIBS) -L$(ALIROOTLIBDIR) -L$(ROOTLIBDIR) -lTree
# endif
# 
# ifeq ($(PACKAGE),PWGLFresonancesdev)
#    PACKLDFLAGS =  $(PWGLFresonances_LIBS) $(EventMixng_LIBS) $(ANALYSISalice_LIBS)  $(ANALYSIS_LIBS) $(AOD_LIBS) $(ESD_LIBS) $(STEERBase_LIBS) -L$(ALIROOTLIBDIR) -L$(ROOTLIBDIR) -lTree
# endif

endif


CXXFLAGS += $(ALICEINC) -g

SRCS         += G__$(PACKAGE).cxx
OBJS          = $(SRCS:.cxx=.o)

lib$(PACKAGE).so: $(OBJS)
	@echo "Linking" $@ ...
	@/bin/rm -f $@
ifeq ($(PLATFORM),macosx)
	$(LD) $(SOFLAGS)$@ $(LDFLAGS) $^ $(OutPutOpt) $@ $(PACKLDFLAGS) $(EXPLLINKLIBS)
else
	$(LD) $(SOFLAGS) $(LDFLAGS) $^ $(OutPutOpt) $@ $(PACKLDFLAGS) $(EXPLLINKLIBS)
endif
	@chmod a+x $@
	@echo "done"

%.o:    %.cxx %.h
	$(CXX) $(PACKCXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) *.so G__$(PACKAGE).*

G__$(PACKAGE).cxx G__$(PACKAGE).h: $(HDRS) $(DHDR)
	@echo "Generating dictionaries ..." $(ALICEINC)
	rootcint -f $@ -c $(CINTFLAGS) $(ALICEINC) $^

