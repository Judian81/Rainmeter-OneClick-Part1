;Measures Hour==================================================================

[mHour]
Measure=Time
Format=%H

[mHour1]
Measure=Calc
Formula=(mHour & 1) ? 1 : 0

[mHour2]
Measure=Calc
Formula=(mHour & 2) ? 1 : 0

[mHour4]
Measure=Calc
Formula=(mHour & 4) ? 1 : 0

[mHour8]
Measure=Calc
Formula=(mHour & 8) ? 1 : 0

[mHour16]
Measure=Calc
Formula=(mHour & 16) ? 1 : 0

;Measures Minutes===============================================================

[mMin]
Measure=Time
Format=%M

[mMin1]
Measure=Calc
Formula=(mMin & 1) ? 1 : 0

[mMin2]
Measure=Calc
Formula=(mMin & 2) ? 1 : 0

[mMin4]
Measure=Calc
Formula=(mMin & 4) ? 1 : 0

[mMin8]
Measure=Calc
Formula=(mMin & 8) ? 1 : 0

[mMin16]
Measure=Calc
Formula=(mMin & 16) ? 1 : 0

[mMin32]
Measure=Calc
Formula=(mMin & 32) ? 1 : 0
