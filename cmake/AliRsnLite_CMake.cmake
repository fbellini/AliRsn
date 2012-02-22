# AliRsnLite build system utility macro and fixes

cmake_minimum_required(VERSION 2.8.4 FATAL_ERROR)

macro(ALIROOT_CMAKE_Sync)

    # append AliRoot cmake dir
    file(COPY ${ALICE_ROOT}/cmake/ DESTINATION ${CMAKE_SOURCE_DIR}/cmake/cmake_AliRoot/ PATTERN *.cmake)
    file(COPY ${ALICE_ROOT}/cmake/ DESTINATION ${CMAKE_SOURCE_DIR}/cmake/cmake_AliRoot/ PATTERN *.tmp)
    file(REMOVE_RECURSE ${CMAKE_SOURCE_DIR}/cmake/cmake_AliRoot/.svn)    
    set(PAR PWGLFresonances)
    if(EXISTS ${CMAKE_SOURCE_DIR}/PWGLF/PROOF-INF.${PAR})
      message(STATUS "PROOF-INF was found.")
    else(EXISTS ${CMAKE_SOURCE_DIR}/PWGLF/PROOF-INF.${PAR})
      GeneratePROOF_INF(${CMAKE_SOURCE_DIR}/PWGLF/PROOF-INF.${PAR} ${PAR})
    endif(EXISTS ${CMAKE_SOURCE_DIR}/PWGLF/PROOF-INF.${PAR})
endmacro(ALIROOT_CMAKE_Sync)

macro(ALICE_CheckModule)
  # dummy ALICE_CheckModule
endmacro(ALICE_CheckModule)

macro(AliRsn_KDevelop)

  FIND_PROGRAM(KDEVELOP_EXECUTABLE kdevelop)
  if(KDEVELOP_EXECUTABLE)
    message(STATUS "Generatiing KDevelop settings ...")
    file(COPY ${CMAKE_SOURCE_DIR}/cmake/AliRsn.kdev4 DESTINATION ${CMAKE_SOURCE_DIR}/)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/kdev_include_paths.tmp ${CMAKE_SOURCE_DIR}/.kdev_include_paths)
  endif(KDEVELOP_EXECUTABLE)

endmacro(AliRsn_KDevelop)

function (GeneratePROOF_INF path parname)
  if(parname)
    message(STATUS "Generating ${parname} ${PARINCLUDE}")
    file(MAKE_DIRECTORY ${path})
    execute_process(COMMAND sh ${CMAKE_SOURCE_DIR}/cmake/scripts/generatePARbase.sh ${path} ${parname})
  endif(parname)
endfunction (GeneratePROOF_INF)
