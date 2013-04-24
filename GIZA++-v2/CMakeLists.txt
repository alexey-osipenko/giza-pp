ADD_EXECUTABLE(gizapp
    Parameter.cpp myassert.cpp Perplexity.cpp model1.cpp model2.cpp model3.cpp
    getSentence.cpp TTables.cpp ATables.cpp AlignTables.cpp main.cpp
    NTables.cpp model2to3.cpp collCounts.cpp alignment.cpp vocab.cpp
    MoveSwapMatrix.cpp transpair_model3.cpp transpair_model5.cpp
    transpair_model4.cpp utility.cpp parse.cpp reports.cpp model3_viterbi.cpp
    model3_viterbi_with_tricks.cpp Dictionary.cpp model345-peg.cpp hmm.cpp
    HMMTables.cpp ForwardBackward.cpp
    ATables.h AlignTables.h Array.h Array2.h Array4.h D4Tables.h D5Tables.h
    Dictionary.h FlexArray.h ForwardBackward.h Globals.h HMMTables.h
    MoveSwapMatrix.h NTables.h Parameter.h Perplexity.h Pointer.h TTables.h
    Vector.h WordClasses.h alignment.h collCounts.h defs.h file_spec.h
    getSentence.h hmm.h logprob.h model1.h model2.h model3.h myassert.h
    mymath.h mystl.h transpair_model1.h transpair_model2.h transpair_model3.h
    transpair_model4.h transpair_model5.h transpair_modelhmm.h utility.h
    vocab.h)
    
ADD_DEPENDENCIES(gizapp compat)
TARGET_LINK_LIBRARIES(gizapp compat) 

ADD_EXECUTABLE(plain2snt plain2snt.cpp)
ADD_EXECUTABLE(small_snt2cooc small_snt2cooc.cpp)
ADD_EXECUTABLE(snt2cooc snt2cooc.cpp)
ADD_EXECUTABLE(snt2plain snt2plain.cpp)
