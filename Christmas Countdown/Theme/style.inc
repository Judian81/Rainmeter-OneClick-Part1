[Rainmeter]
AccurateText=1
BackgroundMode=3
DynamicWindowSize=1

[sTextCenter]
FontColor=183,204,213,150
StringStyle=Normal
StringAlign=Center
FontFace=Trebuchet MS
FontSize=(10*#vSkinScale#)
AntiAlias=1
StringCase=None
StringEffect=Shadow
FontEffectColor=0,0,0,150

[sTextLeft]
FontColor=130,131,132,150
StringStyle=Bold
StringAlign=Left
FontFace=Trebuchet MS
FontSize=(10*#vSkinScale#)
AntiAlias=1
StringCase=None
StringEffect=Shadow
FontEffectColor=0,0,0,150
ClipString=1

[sTextRight]
FontColor=130,131,132,150
StringStyle=Bold
StringAlign=Right
FontFace=Trebuchet MS
FontSize=(10*#vSkinScale#)
AntiAlias=1
StringCase=None
StringEffect=Shadow
FontEffectColor=0,0,0,150

[sLine]
widthAndColor1=StrokeWidth (2*#vSkinScale#) | Stroke Color 183,204,213,150
widthAndColor2=StrokeWidth (2*#vSkinScale#) | Stroke Color 20,20,20,150

[sBar]
BarColor=235,170,0,150
BarOrientation=HORIZONTAL
SolidColor=183,204,213,150

[sSeperator]
SolidColor=183,204,213,150

;--------------------METER------------------

[tBG]
Meter=Shape
Shape=Rectangle (1*#vSkinScale#),(1*#vSkinScale#),(#vSkinWidth#*#vSkinScale#),(#vSkinHeight#*#vSkinScale#),5 | Fill Color 255,255,255,255 | StrokeWidth 0.5 | Extend StrokeAlpha
StrokeAlpha=Stroke Color 100,100,100,150
Padding=#paddingLeft#,#paddingTop#,#paddingRight#,#paddingBottom#