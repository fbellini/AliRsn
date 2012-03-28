PACKAGE = PWGLFresonances

include Makefile.arch

SRCS = 
HDRS = 
DHDR = 

ifndef PACKCXXFLAGS
   PACKCXXFLAGS = $(CXXFLAGS)
endif

ALICEINC = -I.
ALICEINC += -I./$(PACKAGE)/

ifneq ($(ESD_INCLUDE),)
   ALICEINC += -I../$(ESD_INCLUDE) 
endif

ifneq ($(AOD_INCLUDE),)
   ALICEINC += -I../$(AOD_INCLUDE) 
endif

ifneq ($(STEERBase_INCLUDE),)
   ALICEINC += -I../$(STEERBase_INCLUDE)
endif

ifneq ($(ANALYSIS_INCLUDE),)
   ALICEINC += -I../$(ANALYSIS_INCLUDE)
endif

ifneq ($(ANALYSISalice_INCLUDE),)
   ALICEINC += -I../$(ANALYSISalice_INCLUDE)
endif

ifneq ($(EventMixing_INCLUDE),)
   ALICEINC += -I../$(EventMixng_INCLUDE)
endif

# only if no par file was loaded before
#ifeq ($(ALICEINC),-I.)
  ifneq ($(ALICE_ROOT),)
    ALICEINC += -I$(ALICE_ROOT)/include
  endif
#endif

ifeq ($(PLATFORM),macosx)
ROOTLIBDIR     := $(shell $(RC) --libdir)
ifeq ($(PACKAGE),STEERBase)
   PACKLDFLAGS = -L$(ROOTLIBDIR)  -lVMC -lMinuit -lEG -lGeom
endif
ifeq ($(PACKAGE),ESD)
   PACKLDFLAGS = $(STEERBase_LIBS) -L$(ROOTLIBDIR) -lVMC -lEG -lGeom
endif
ifeq ($(PACKAGE),AOD)
   PACKLDFLAGS = $(STEERBase_LIBS) -L$(ROOTLIBDIR) -lEG -lGeom
endif
ifeq ($(PACKAGE),CDB)
   PACKLDFLAGS = $(STEERBase_LIBS) -L$(ROOTLIBDIR) -lMinuit -lTree -lXMLParser
endif
ifeq ($(PACKAGE),ANALYSIS)
   PACKLDFLAGS =  $(AOD_LIBS) $(ESD_LIBS) $(STEERBase_LIBS) -L$(ROOTLIBDIR) -lMinuit -lTree -lXMLParser
endif
ifeq ($(PACKAGE),ANALYSISalice)
   PACKLDFLAGS =  $(ANALYSIS_LIBS) $(AOD_LIBS) $(ESD_LIBS) $(STEERBase_LIBS) -L$(ROOTLIBDIR) -lMinuit -lTree -lXMLParser
endif
ifeq ($(PACKAGE),EventMixng)
   PACKLDFLAGS =  $(ANALYSISalice_LIBS)  $(ANALYSIS_LIBS) $(AOD_LIBS) $(ESD_LIBS) $(STEERBase_LIBS) -L$(ROOTLIBDIR) -lTree
endif
ifeq ($(PACKAGE),PWGLFresonances)
   PACKLDFLAGS =  $(EventMixng_LIBS) $(ANALYSISalice_LIBS)  $(ANALYSIS_LIBS) $(AOD_LIBS) $(ESD_LIBS) $(STEERBase_LIBS) -L$(ROOTLIBDIR) -lTree
endif

ifeq ($(PACKAGE),PWGLFresonancesdev)
   PACKLDFLAGS =  $(PWGLFresonances_LIBS) $(EventMixng_LIBS) $(ANALYSISalice_LIBS)  $(ANALYSIS_LIBS) $(AOD_LIBS) $(ESD_LIBS) $(STEERBase_LIBS) -L$(ROOTLIBDIR) -lTree
endif

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

