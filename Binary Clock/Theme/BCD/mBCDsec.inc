;Measures Seconds===============================================================

[mSec]
Measure=Time
Format=%S

[mSecTens]
Measure=Calc
Formula=(Trunc(mSec * 0.1))

[mSecOnes]
Measure=Calc
Formula=mSec % 10

[mSecTens1]
Measure=Calc
Formula=(mSecTens & 1) ? 1 : 0

[mSecTens2]
Measure=Calc
Formula=(mSecTens & 2) ? 1 : 0

[mSecTens4]
Measure=Calc
Formula=(mSecTens & 4) ? 1 : 0

[mSecOnes1]
Measure=Calc
Formula=(mSecOnes & 1) ? 1 : 0

[mSecOnes2]
Measure=Calc
Formula=(mSecOnes & 2) ? 1 : 0

[mSecOnes4]
Measure=Calc
Formula=(mSecOnes & 4) ? 1 : 0

[mSecOnes8]
Measure=Calc
Formula=(mSecOnes & 8) ? 1 : 0
