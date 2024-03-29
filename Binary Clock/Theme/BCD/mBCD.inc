;Measures Hour==================================================================

[mHour]
Measure=Time
Format=%H

[mHourTens]
Measure=Calc
Formula=(Trunc(mHour * 0.1))

[mHourOnes]
Measure=Calc
Formula=mHour % 10

[mHourTens1]
Measure=Calc
Formula=(mHourTens & 1) ? 1 : 0

[mHourTens2]
Measure=Calc
Formula=(mHourTens & 2) ? 1 : 0

[mHourOnes1]
Measure=Calc
Formula=(mHourOnes & 1) ? 1 : 0

[mHourOnes2]
Measure=Calc
Formula=(mHourOnes & 2) ? 1 : 0

[mHourOnes4]
Measure=Calc
Formula=(mHourOnes & 4) ? 1 : 0

[mHourOnes8]
Measure=Calc
Formula=(mHourOnes & 8) ? 1 : 0

;Measures Minutes===============================================================

[mMin]
Measure=Time
Format=%M

[mMinTens]
Measure=Calc
Formula=(Trunc(mMin * 0.1))

[mMinOnes]
Measure=Calc
Formula=mMin % 10

[mMinTens1]
Measure=Calc
Formula=(mMinTens & 1) ? 1 : 0

[mMinTens2]
Measure=Calc
Formula=(mMinTens & 2) ? 1 : 0

[mMinTens4]
Measure=Calc
Formula=(mMinTens & 4) ? 1 : 0

[mMinOnes1]
Measure=Calc
Formula=(mMinOnes & 1) ? 1 : 0

[mMinOnes2]
Measure=Calc
Formula=(mMinOnes & 2) ? 1 : 0

[mMinOnes4]
Measure=Calc
Formula=(mMinOnes & 4) ? 1 : 0

[mMinOnes8]
Measure=Calc
Formula=(mMinOnes & 8) ? 1 : 0
