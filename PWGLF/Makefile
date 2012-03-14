# $Id: Makefile 50266 2011-06-24 09:37:46Z pulvir $

include $(ROOTSYS)/etc/Makefile.arch

PACKAGE = PWGLFresonances

default-target: lib$(PACKAGE).so 

ALICEINC      = -I. -I$(ALICE_ROOT)/TOF -I$(ALICE_ROOT)/ANALYSIS/EventMixing

### define include dir for local case and par case
ifneq ($(ESD_INCLUDE),)
   ALICEINC += -I../$(ESD_INCLUDE)
   ALICEINC += -I../$(AOD_INCLUDE)
   ALICEINC += -I../$(STEERBase_INCLUDE)
   ALICEINC += -I../$(ANALYSIS_INCLUDE)
   ALICEINC += -I../$(ANALYSISalice_INCLUDE)
 else
    ifneq ($(ALICE_ROOT),)
       ALICEINC += -I$(ALICE_ROOT)/include -I$(ALICE_ROOT)/PWG2
     endif
endif

ifneq ($(CORRFW_INCLUDE),)
  ALICEINC += -I../$(CORRFW_INCLUDE)
endif

ifneq ($(PWGLFresonances_INCLUDE),)
  ALICEINC += -I../$(PWGLFresonances_INCLUDE)
 else
    ifneq ($(ALICE_ROOT),)
       ALICEINC += -I$(ALICE_ROOT)/PWGLF/RESONANCES
     endif
endif

# only if no par file was loaded before
ifeq ($(ALICEINC),-I.)
  ifneq ($(ALICE_ROOT),)
    ALICEINC += -I$(ALICE_ROOT)/include
  endif
endif

ifneq ($(EINCLUDE),)
  ALICEINC += $(EINCLUDE:%=-I$(ALICE_ROOT)/%)
endif

CXXFLAGS     += $(ALICEINC) -g
F77FLAGS     += $(ALICEINC) -g -fPIC

DHDR = PWGLFresonancesLinkDef.h
HDRS = RESONANCES/AliRsnDaughter.h RESONANCES/AliRsnMother.h RESONANCES/AliRsnEvent.h RESONANCES/AliRsnDaughterDef.h RESONANCES/AliRsnPairDef.h RESONANCES/AliRsnTarget.h RESONANCES/AliRsnValue.h RESONANCES/AliRsnCut.h RESONANCES/AliRsnValueDaughter.h RESONANCES/AliRsnValuePair.h RESONANCES/AliRsnValueEvent.h RESONANCES/AliRsnCutPrimaryVertex.h RESONANCES/AliRsnCutTrackQuality.h RESONANCES/AliRsnCutTrue.h RESONANCES/AliRsnCutValue.h RESONANCES/AliRsnCutPID.h RESONANCES/AliRsnCutPIDITS.h RESONANCES/AliRsnCutPIDTPC.h RESONANCES/AliRsnCutPIDTOF.h RESONANCES/AliRsnCutPIDNSigma.h RESONANCES/AliRsnCutMomentumComparison.h RESONANCES/AliRsnCutKaonForPhi2010.h RESONANCES/AliRsnCutKaonForPhi2010PP.h RESONANCES/AliRsnCutPion2010PP.h RESONANCES/AliRsnCutProton2010PP.h RESONANCES/AliRsnCutDaughterKStar2010PP.h RESONANCES/AliRsnCutDaughterLStar2010.h RESONANCES/AliRsnCutV0.h RESONANCES/AliRsnCutSet.h RESONANCES/AliRsnExpression.h RESONANCES/AliRsnVariableExpression.h RESONANCES/AliRsnCutManager.h RESONANCES/AliRsnListOutput.h RESONANCES/AliRsnLoop.h RESONANCES/AliRsnLoopDaughter.h RESONANCES/AliRsnLoopPair.h RESONANCES/AliRsnLoopEvent.h RESONANCES/AliRsnLoopEff.h RESONANCES/AliRsnLoopEffPair.h RESONANCES/AliRsnDaughterSelector.h RESONANCES/AliRsnInputHandler.h RESONANCES/AliRsnAnalysisTask.h RESONANCES/AliRsnMiniParticle.h RESONANCES/AliRsnMiniPair.h RESONANCES/AliRsnCutMiniPair.h RESONANCES/AliRsnMiniEvent.h RESONANCES/AliRsnMiniAxis.h RESONANCES/AliRsnMiniOutput.h RESONANCES/AliRsnMiniValue.h RESONANCES/AliRsnMiniMonitor.h RESONANCES/AliRsnMiniAnalysisTask.h RESONANCES/AliRsnMiniMonitorTask.h
SRCS = RESONANCES/AliRsnDaughter.cxx RESONANCES/AliRsnMother.cxx RESONANCES/AliRsnEvent.cxx RESONANCES/AliRsnDaughterDef.cxx RESONANCES/AliRsnPairDef.cxx RESONANCES/AliRsnTarget.cxx RESONANCES/AliRsnValue.cxx RESONANCES/AliRsnCut.cxx RESONANCES/AliRsnValueDaughter.cxx RESONANCES/AliRsnValuePair.cxx RESONANCES/AliRsnValueEvent.cxx RESONANCES/AliRsnCutPrimaryVertex.cxx RESONANCES/AliRsnCutTrackQuality.cxx RESONANCES/AliRsnCutTrue.cxx RESONANCES/AliRsnCutValue.cxx RESONANCES/AliRsnCutPID.cxx RESONANCES/AliRsnCutPIDITS.cxx RESONANCES/AliRsnCutPIDTPC.cxx RESONANCES/AliRsnCutPIDTOF.cxx RESONANCES/AliRsnCutPIDNSigma.cxx RESONANCES/AliRsnCutMomentumComparison.cxx RESONANCES/AliRsnCutKaonForPhi2010.cxx RESONANCES/AliRsnCutKaonForPhi2010PP.cxx RESONANCES/AliRsnCutPion2010PP.cxx RESONANCES/AliRsnCutProton2010PP.cxx RESONANCES/AliRsnCutDaughterKStar2010PP.cxx RESONANCES/AliRsnCutDaughterLStar2010.cxx RESONANCES/AliRsnCutV0.cxx RESONANCES/AliRsnCutSet.cxx RESONANCES/AliRsnExpression.cxx RESONANCES/AliRsnVariableExpression.cxx RESONANCES/AliRsnCutManager.cxx RESONANCES/AliRsnListOutput.cxx RESONANCES/AliRsnLoop.cxx RESONANCES/AliRsnLoopDaughter.cxx RESONANCES/AliRsnLoopPair.cxx RESONANCES/AliRsnLoopEvent.cxx RESONANCES/AliRsnLoopEff.cxx RESONANCES/AliRsnLoopEffPair.cxx RESONANCES/AliRsnDaughterSelector.cxx RESONANCES/AliRsnInputHandler.cxx RESONANCES/AliRsnAnalysisTask.cxx RESONANCES/AliRsnMiniParticle.cxx RESONANCES/AliRsnMiniPair.cxx RESONANCES/AliRsnCutMiniPair.cxx RESONANCES/AliRsnMiniEvent.cxx RESONANCES/AliRsnMiniAxis.cxx RESONANCES/AliRsnMiniOutput.cxx RESONANCES/AliRsnMiniValue.cxx RESONANCES/AliRsnMiniMonitor.cxx RESONANCES/AliRsnMiniAnalysisTask.cxx RESONANCES/AliRsnMiniMonitorTask.cxx
FSRCS = 

DHDR_PWG2 := $(DHDR)
HDRS_PWG2 := $(HDRS)
SRCS_PWG2 := $(SRCS) G__$(PACKAGE).cxx
FSCRS_PWG2 := $(FSRCS)
OBJS_PWG2 := $(SRCS_PWG2:.cxx=.o) $(FSRCS:.F=.o)

PARFILE       = $(PACKAGE).par

lib$(PACKAGE).so: $(OBJS_PWG2)
	@echo "Linking" $@ ...
	@/bin/rm -f $@
ifeq ($(PLATFORM),macosx)
# We need to make both the .dylib and the .so
		$(LD) $(SOFLAGS)$@ $(LDFLAGS) $^ $(OutPutOpt) $@
ifneq ($(subst $(MACOSX_MINOR),,1234),1234)
ifeq ($(MACOSX_MINOR),4)
		ln -sf $@ $(subst .$(DllSuf),.so,$@)
else
		$(LD) -bundle -undefined $(UNDEFOPT) $(LDFLAGS) $^ \
		   $(OutPutOpt) $(subst .$(DllSuf),.so,$@)
endif
endif
else
ifeq ($(PLATFORM),win32)
		bindexplib $* $^ > $*.def
		lib -nologo -MACHINE:IX86 $^ -def:$*.def \
		   $(OutPutOpt)$(EVENTLIB)
		$(LD) $(SOFLAGS) $(LDFLAGS) $^ $*.exp $(LIBS) \
		   $(OutPutOpt)$@
else
		$(LD) $(SOFLAGS) $(LDFLAGS) $^ $(OutPutOpt) $@ $(EXPLLINKLIBS)
endif
endif
	@chmod a+x $@
	@echo "done"

%.o:    %.cxx %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o:    %.F
	$(F77) $(F77FLAGS) -c $< -o $@

G__$(PACKAGE).h:G__$(PACKAGE).cxx
	@if test -f $@ ; then : ; else rm -f $< ; $(MAKE) $@ ; fi

G__$(PACKAGE).cxx: $(HDRS_PWG2) $(DHDR_PWG2)
	@echo "Generating dictionary ..."
	rootcint -f $@ -c $(CINTFLAGS) $(ALICEINC) $^

clean:
	@rm -f $(OBJS_PWG2) *.so G__$(PACKAGE).* $(PARFILE)

### CREATE PAR FILE

$(PARFILE): $(patsubst %,$(PACKAGE)/%,$(filter-out G__%, $(HDRS_PWG2) $(SRCS_PWG2) $(DHDR_PWG2) Makefile Makefile.arch PROOF-INF))
	@echo "Creating archive" $@ ...
	@tar cfzh $@ $(PACKAGE)
	@rm -rf $(PACKAGE)
	@echo "done"

$(PACKAGE)/Makefile: Makefile #.$(PACKAGE)
	@echo Copying $< to $@ with transformations
	@[ -d $(dir $@) ] || mkdir -p $(dir $@)
	@sed 's/include \$$(ROOTSYS)\/test\/Makefile.arch/include Makefile.arch/' < $^ > $@

$(PACKAGE)/Makefile.arch: $(ROOTSYS)/test/Makefile.arch
	@echo Copying $< to $@
	@[ -d $(dir $@) ] || mkdir -p $(dir $@)
	@cp -a $^ $@

$(PACKAGE)/PROOF-INF: PROOF-INF.$(PACKAGE)
	@echo Copying $< to $@
	@[ -d $(dir $@) ] || mkdir -p $(dir $@)
	@cp -a -r $^ $@

$(PACKAGE)/%: %
	@echo Copying $< to $@
	@[ -d $(dir $@) ] || mkdir -p $(dir $@)
	@cp -a $< $@

test-%.par: %.par
	@echo "INFO: The file $< is now tested, in case of an error check in par-tmp."
	@mkdir -p par-tmp
	@cd par-tmp; tar xfz ../$<;	cd $(subst .par,,$<); PROOF-INF/BUILD.sh
	@rm -rf par-tmp
	@echo "INFO: Testing succeeded (already cleaned up)"
