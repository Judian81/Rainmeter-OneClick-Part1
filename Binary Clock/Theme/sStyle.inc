;Style==========================================================================

[Variables]
scale.Skin=1.25

size.Base=(15 * #scale.Skin#)
space.Base=(6 * #scale.Skin#)

space.Delimiter=(#space.Base# * 1.0)

shape.Style=Ellipse #size.Base#,#size.Base#,#size.Base#
;shape.Style=Rectangle 0,0,#size.Base#,#size.Base#,7
;shape.Style=Path Path1

[sShape]
X=r
Y=#space.Base#R
AntiAlias=1
DynamicVariables=1
Shape=[#shape.Style] | Extend myStrokeWidth | Extend myStrokeColor | Extend myColor | Extend myGradient | Extend myStrokeGradient
myStrokeWidth=StrokeWidth 1
myGradient=""
myStrokeGradient=""

;Shape2 = Path Path2 | fill color 224,144,40 | StrokeWidth 0
;Path1 = 35, 39.4 | CurveTo 19, 54.3, 35, 47.6, 27.8, 54.3 | CurveTo 3, 39.4, 10.2, 54.3, 3, 47.6 | CurveTo 19, 6.3, 3, 31.2, 19, 6.3 | CurveTo 35, 39.4, 19, 6.3, 35, 31.2 | ClosePath 1
;Path2 = 18.9, 37.7 | CurveTo 7.2, 37.7, 10.2, 31.5, 7.2, 37.7 | CurveTo 7, 39, 7, 38.1, 7, 38.6 | CurveTo 19, 50.2, 7, 45.2, 12.4, 50.2 | CurveTo 31, 39, 25.6, 50.2, 31, 45.2 | CurveTo 30.9, 37.7, 31, 38.6, 30.9, 38.2 | CurveTo 18.9, 37.7, 30.9, 37.7, 27.5, 43.9 | ClosePath 1

[sShapeEmpty]
UpdateDivider=-1
DynamicVariables=0
;Shape2 = Path Path2 | Extend myStrokeColor | Extend myColor
myColor=Fill Color 0,0,0,0
myStrokeColor=Stroke Color 0,0,0,0
myGradient=""
myStrokeGradient=""

;Remove [multilineComment] here and in vColor.inc to enable gradient

[sHour]
myColor=Fill Color [#color.Hour[&m[#CURRENTSECTION]:]]
myStrokeColor=Stroke Color [#color.StrokeHour[&m[#CURRENTSECTION]:]]
[multilineComment]
myGradient=Fill RadialGradient myGradientHour[&m[#CURRENTSECTION]:]
myGradientHour0=#gradient.Hour0#
myGradientHour1=#gradient.Hour1#
myStrokeGradient=Stroke RadialGradient myStrokeGradientHour[&m[#CURRENTSECTION]:]
myStrokeGradientHour0=#gradient.StrokeHour0#
myStrokeGradientHour1=#gradient.StrokeHour1#

[sMin]
myColor=Fill Color [#color.Min[&m[#CURRENTSECTION]:]]
myStrokeColor=Stroke Color [#color.StrokeMin[&m[#CURRENTSECTION]:]]
[multilineComment]
myGradient=Fill RadialGradient myGradientMin[&m[#CURRENTSECTION]:]
myGradientMin0=#gradient.Min0#
myGradientMin1=#gradient.Min1#
myStrokeGradient=Stroke RadialGradient myStrokeGradientMin[&m[#CURRENTSECTION]:]
myStrokeGradientMin0=#gradient.StrokeMin0#
myStrokeGradientMin1=#gradient.StrokeMin1#

[sSec]
myColor=Fill Color [#color.Sec[&m[#CURRENTSECTION]:]]
myStrokeColor=Stroke Color [#color.StrokeSec[&m[#CURRENTSECTION]:]]
[multilineComment]
myGradient=Fill RadialGradient myGradientSec[&m[#CURRENTSECTION]:]
myGradientSec0=#gradient.Sec0#
myGradientSec1=#gradient.Sec1#
myStrokeGradient=Stroke RadialGradient myStrokeGradientSec[&m[#CURRENTSECTION]:]
myStrokeGradientSec0=#gradient.StrokeSec0#
myStrokeGradientSec1=#gradient.StrokeSec1#

[sPos]
X=#space.Base#R
Y=#space.Base#

[sPosDelimiter]
X=#space.Delimiter#R
Y=#space.Base#

[sPos60]
X=r
Y=#space.Base#R

[sPos60Delimiter]
X=#space.Delimiter#R
Y=#space.Base#

[sGap]
X=#space.Base#R
Y=#space.Base#R
SolidColor=0,0,0,1
AntiAlias=1
