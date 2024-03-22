global  _start
_start: 
        INP
        STA NUM1
        INP
        STA NUM2
        LDA NUM1
        ADD NUM2
        STA RESULT
        OUT
        HLT
NUM1    DAT
NUM2    DAT
RESULT  DAT