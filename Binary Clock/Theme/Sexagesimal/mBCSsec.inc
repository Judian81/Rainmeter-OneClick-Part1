;Measures Seconds===============================================================

[mSec]
Measure=Time
Format=%S

[mSec1]
Measure=Calc
Formula=(mSec & 1) ? 1 : 0

[mSec2]
Measure=Calc
Formula=(mSec & 2) ? 1 : 0

[mSec4]
Measure=Calc
Formula=(mSec & 4) ? 1 : 0

[mSec8]
Measure=Calc
Formula=(mSec & 8) ? 1 : 0

[mSec16]
Measure=Calc
Formula=(mSec & 16) ? 1 : 0

[mSec32]
Measure=Calc
Formula=(mSec & 32) ? 1 : 0
