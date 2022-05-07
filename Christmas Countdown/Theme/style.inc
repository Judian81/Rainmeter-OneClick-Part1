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
StringStyle=Bold
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
StringStyle=Bold
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
BarColor=235,170,0,255
BarOrientation=HORIZONTAL
SolidColor=183,204,213,100

[sSeperator]
SolidColor=183,204,213,50

;--------------------METER------------------

[tBG]
Meter=Shape
;Shape=Rectangle (1*#vSkinScale#),(1*#vSkinScale#),(#vSkinWidth#*#vSkinScale#),(#vSkinHeight#*#vSkinScale#),5 | Fill Color 30,32,37,255 | StrokeWidth 0.5 | Extend StrokeAlpha
Shape=Rectangle (1*#vSkinScale#),(1*#vSkinScale#),(#vSkinWidth#*#vSkinScale#),(#vSkinHeight#*#vSkinScale#),5 | Fill Color 255,255,255,255 | StrokeWidth 0.5 | Extend StrokeAlpha
StrokeAlpha=Stroke Color 100,100,100,255
Padding=#paddingLeft#,#paddingTop#,#paddingRight#,#paddingBottom#