[Rainmeter]
AccurateText=1
BackgroundMode=3
DynamicWindowSize=1

;--------------------METADATA---------------

[Metadata]
Name=Judian81
Version=0.1
License=Creative Commons Attribution-Non-Commercial-Share Alike 3.0

;--------------------VARIABLE---------------

[Variables]

;--------------------MEASURE----------------


;--------------------STYLE------------------

[sTextCenter]
FontColor=183,204,213,230
StringStyle=Normal
StringAlign=Center
FontFace=Trebuchet MS
FontSize=(10*#vSkinScale#)
AntiAlias=1
StringCase=None
StringEffect=Shadow
FontEffectColor=0,0,0,50

[sTextLeft]
FontColor=130,131,132,255
StringStyle=Normal
StringAlign=Left
FontFace=Trebuchet MS
FontSize=(10*#vSkinScale#)
AntiAlias=1
StringCase=None
StringEffect=Shadow
FontEffectColor=0,0,0,50
ClipString=1

[sTextRight]
FontColor=130,131,132,255
StringStyle=Normal
StringAlign=Right
FontFace=Trebuchet MS
FontSize=(10*#vSkinScale#)
AntiAlias=1
StringCase=None
StringEffect=Shadow
FontEffectColor=0,0,0,50

[sLine]
widthAndColor1=StrokeWidth (2*#vSkinScale#) | Stroke Color 183,204,213,150
widthAndColor2=StrokeWidth (2*#vSkinScale#) | Stroke Color 20,20,20,150

[sBar]
BarColor=180,180,180,255
BarOrientation=HORIZONTAL
SolidColor=183,204,213,100

[sSeperator]
SolidColor=183,204,213,100

;--------------------METER------------------

[tBG]
Meter=Shape
Shape=Rectangle (1*#vSkinScale#),(1*#vSkinScale#),(#vSkinWidth#*#vSkinScale#),(#vSkinHeight#*#vSkinScale#),5 | Fill Color 30,32,37,255 | StrokeWidth 0.5 | Extend StrokeAlpha
StrokeAlpha=Stroke Color 100,100,100,255
Shape2=Rectangle (2*#vSkinScale#),(2*#vSkinScale#),((#vSkinWidth#-2)*#vSkinScale#),(34*#vSkinScale#),5 | Fill Color 67, 73, 83, 255 | StrokeWidth 0.5 | Extend StrokeAlpha2
StrokeAlpha2=Stroke Color 10,9,9,255
Padding=#paddingLeft#,#paddingTop#,#paddingRight#,#paddingBottom#

[tLineTop]
Meter=Shape
MeterStyle=sLine
X=(#paddingLeft#+(4*#vSkinScale#))
Y=(#paddingTop#+(35*#vSkinScale#))
Shape=Line 0,0,((#vSkinWidth#*#vSkinScale#)-(7*#vSkinScale#)),0  | Extend widthAndColor1
Shape2=Line (2*#vSkinScale#),(1*#vSkinScale#),((#vSkinWidth#*#vSkinScale#)-(7*#vSkinScale#)),1  | Extend widthAndColor2

[tLineTop2]
Meter=Shape
MeterStyle=sLine
X=(#paddingLeft#+(4*#vSkinScale#))
Y=((#vSkinHeight#*#vSkinScale#)+#paddingTop#-(4*#vSkinScale#))
Shape=Line 0,0,((#vSkinWidth#*#vSkinScale#)-(7*#vSkinScale#)),0  | Extend widthAndColor1
Shape2=Line 2,1,((#vSkinWidth#*#vSkinScale#)-(7*#vSkinScale#)),1  | Extend widthAndColor2