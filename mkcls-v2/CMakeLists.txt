ADD_EXECUTABLE(mkcls
    GDAOptimization.cpp HCOptimization.cpp Problem.cpp IterOptimization.cpp
    ProblemTest.cpp RRTOptimization.cpp MYOptimization.cpp SAOptimization.cpp
    TAOptimization.cpp Optimization.cpp KategProblemTest.cpp
    KategProblemKBC.cpp KategProblemWBC.cpp KategProblem.cpp StatVar.cpp
    general.cpp mkcls.cpp
    Array.h FixedArray.h FlexArray.h GDAOptimization.h HCOptimization.h
    IterOptimization.h KategProblem.h KategProblemKBC.h KategProblemTest.h
    KategProblemWBC.h MSBOptimization.h MYOptimization.h Optimization.h
    PopOptimization.h Problem.h ProblemTest.h RRTOptimization.h
    SAOptimization.h StatVar.h TAOptimization.h general.h my.h myassert.h
    myleda.h mystl.h)

ADD_DEPENDENCIES(mkcls compat)
TARGET_LINK_LIBRARIES(mkcls compat) 
