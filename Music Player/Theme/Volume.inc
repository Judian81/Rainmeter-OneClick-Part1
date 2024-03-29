[StringStyle]
FontColor=220,220,220
FontEffectColor=0,0,0
SolidColor=0,0,0,1
StringEffect=Shadow
FontFace=#FontName#
StringStyle=BOLD
AntiAlias=1
DynamicVariables=1

[MenuFieldStringStyle]
FontColor=0,0,0
FontEffectColor=220,220,220
StringEffect=Shadow
FontFace=#FontName#
StringStyle=BOLD
AntiAlias=1
Hidden=1

[InactiveStringStyle]
Meter=String
FontColor=220,220,220,80
FontEffectColor=0,0,0,80
SolidColor=0,0,0,1
StringEffect=Shadow
FontFace=#FontName#
StringStyle=BOLD
AntiAlias=1
Hidden=1

[CheckBoxStyle]
Shape=Rectangle 0,0,13,13 | Extend CheckModifiers1, CheckModifiers2, CheckModifiers3
CheckModifiers1=Fill Color 255,255,255
CheckModifiers2=StrokeWidth 1
CheckModifiers3=Stroke Color #CheckStrokeColor#
DynamicVariables=1
Hidden=1

[RadioButtonStyle]
Shape=Rectangle 0,0,14,14,7 | Extend RadioButtonModifiers
RadioButtonModifiers=Fill Color 255,255,255 | StrokeWidth 1 | Stroke Color #CheckStrokeColor#
DynamicVariables=1
Hidden=1

[RadioButtonCheckStyle]
X=3r
Y=3r
Shape=Rectangle 0,0,8,8,4 | Extend RadioButtonModifiers
RadioButtonModifiers=Fill Color 51,51,51 | StrokeWidth 1 | Stroke Color 51,51,51
DynamicVariables=1
Hidden=1

[BackgroundStyle]
MyModifiers=StrokeWidth 2 | Stroke Color #StrokeColorRed#,#StrokeColorGreen#,#StrokeColorBlue#,#StrokeColorAlpha#
MyFillGradient=-#BackgroundAngle# | #BackgroundColor1Red#,#BackgroundColor1Green#,#BackgroundColor1Blue#,#BackgroundColor1Alpha# ; 0 | #BackgroundColor2Red#,#BackgroundColor2Green#,#BackgroundColor2Blue#,#BackgroundColor2Alpha# ; 0.5 | #BackgroundColor1Red#,#BackgroundColor1Green#,#BackgroundColor1Blue#,#BackgroundColor1Alpha# ; 1
UpdateDivider=-1

[MenuButtonStyle]
MyModifiers1=Fill Color #ButtonColor#
MyModifiers2=StrokeWidth 1
MyModifiers3=Stroke Color #ButtonStrokeColor#
MouseOverAction=[!SetVariable ButtonColor "120,120,120,150"][!SetVariable ButtonStrokeColor "100,100,100"][!UpdateMeter "#CURRENTSECTION#"][!Redraw]
MouseLeaveAction=[!SetVariable ButtonColor "80,80,80,150"][!SetVariable ButtonStrokeColor "160,160,160"][!SetOption #CURRENTSECTION#Label FontColor "220,220,220"][!SetOption #CURRENTSECTION#Label FontEffectColor "0,0,0"][!UpdateMeter "#CURRENTSECTION#"][!UpdateMeter "#CURRENTSECTION#Label"][!Redraw]
LeftMouseDownAction=[!SetVariable ButtonColor "40,40,40,150"][!SetVariable ButtonStrokeColor "200,200,200"][!SetOption #CURRENTSECTION#Label FontColor "0,0,0"][!SetOption #CURRENTSECTION#Label FontEffectColor "220,220,220"][!UpdateMeter "#CURRENTSECTION#"][!UpdateMeter "#CURRENTSECTION#Label"][!Redraw]
ToolTipWidth=#ToolTipWidth#
DynamicVariables=1
UpdateDivider=-1

[MenuStyle]
X=0r
Y=1R
CheckModifiers=Fill Color 255,255,255 | StrokeWidth 0 | Stroke Color #CheckStrokeColor#
MouseOverAction=[!SetOption #CURRENTSECTION# CheckModifiers "Fill Color 16,124,214 | StrokeWidth 0 | Stroke Color #CheckStrokeColor#"][!SetOption #CURRENTSECTION#Label FontColor "255,255,255"][!UpdateMeter "#CURRENTSECTION#"][!UpdateMeter "#CURRENTSECTION#Label"][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# CheckModifiers "Fill Color 255,255,255 | StrokeWidth 0 | Stroke Color #CheckStrokeColor#"][!SetOption #CURRENTSECTION#Label FontColor "53,0,96"][!UpdateMeter "#CURRENTSECTION#"][!UpdateMeter "#CURRENTSECTION#Label"][!Redraw]
Hidden=1

[InactiveButtonStyle]
X=0r
Y=0r
MyModifiers1=Fill Color 80,80,80,80
MyModifiers2=StrokeWidth 1
MyModifiers3=Stroke Color 160,160,160,80
UpdateDivider=-1
Hidden=1

[HingeStyle]
Shape=Ellipse 5,5,5 | Extend MyModifiers | Fill LinearGradient MyFillGradient
Shape2=Ellipse 5,20,5 | Extend MyModifiers | Fill LinearGradient MyFillGradient
Shape3=Rectangle 0,5,10,15 | Extend MyModifiers | Fill LinearGradient MyFillGradient
Shape4=Combine Shape | Union Shape2 | Union Shape3
MyModifiers=StrokeWidth 1 | Stroke Color 0,0,0,200
MyFillGradient=90 | 150,150,150,200 ; 0 | 80,80,80,200 ; 1
Group=Date | Today
UpdateDivider=-1

[LineStyle]
MyModifiers1=StrokeWidth 2 | Stroke Color 220,220,220
MyModifiers2=StrokeWidth 2 | Stroke Color 0,0,0,80
UpdateDivider=-1

[HorBarTotalStyle]
Shape=Ellipse (1+#vBarHeight#/2),(1+#vBarHeight#/2),(1+#vBarHeight#/2) | Extend ProgressBackgroundModifiers
Shape2=Rectangle (1+#vBarHeight#/2),0,(#vBarWidth#-#vBarHeight#+8),(2+#vBarHeight#) | Extend ProgressBackgroundModifiers
Shape3=Ellipse (1+#vBarWidth#+#vBarHeight#/2-#vBarHeight#+8),(1+#vBarHeight#/2),(1+#vBarHeight#/2) | Extend ProgressBackgroundModifiers
Shape4=Combine Shape | Union Shape2 | Union Shape3
ProgressBackgroundModifiers=Fill Color 120,120,120 | StrokeWidth 1 | Stroke Color 0,0,0
UpdateDivider=-1

[HorBarLeftStyle]
X=1r
Y=0r
Shape=Ellipse (1+#vBarHeight#/2),(1+#vBarHeight#/2),(#vBarHeight#/2) | Extend BarModifiers
Shape2=Rectangle (1+#vBarHeight#/2),0,(1+#vBarHeight#/2),(2+#vBarHeight#) | Extend BarModifiers
Shape3=Combine Shape | Exclude Shape2 
BarModifiers=Fill Color #vBarColorStart# | StrokeWidth 0 | Stroke Color 255,255,255,0
DynamicVariables=1

[HorBarRightStyle]
Y=-1r
Shape=Rectangle (-2-#vBarHeight#/2),0,(1+#vBarHeight#/2),(2+#vBarHeight#) | Extend BarModifiers
Shape2=Ellipse -1,(1+#vBarHeight#/2),(#vBarHeight#/2) | Extend BarModifiers
Shape3=Combine Shape2 | Exclude Shape
DynamicVariables=1

[HorBarStyle]
BarOrientation=Horizontal
BarImage=#CURRENTPATH#Theme\Bar.png
SolidColor=0,0,0,1
X=-1R
Y=1r
W=#vBarWidth#
H=#vBarHeight#
DynamicVariables=1
TransformationMatrix=(((#vBarWidth#-#vBarHeight#+8)/#vBarWidth#)*(0.01+#vBarWidth#/100));0;0;(#vBarHeight#/8);([#CURRENTSECTION#:X]*(0.99-(#vBarWidth#-#vBarHeight#+8)/100));([#CURRENTSECTION#:Y]-(#vBarHeight#/8)*[#CURRENTSECTION#:Y])

[VerBarTotalStyle]
X=-6r
Y=20r
Shape=Ellipse (1+#vBarWidth#/2),(1+#vBarWidth#/2),(1+#vBarWidth#/2) | Extend ProgressBackgroundModifiers
Shape2=Rectangle 0,(1+#vBarWidth#/2),(2+#vBarWidth#),#vBarHeight# | Extend ProgressBackgroundModifiers
Shape3=Ellipse (1+#vBarWidth#/2),(#vBarHeight#+(1+#vBarWidth#/2)),(1+#vBarWidth#/2) | Extend ProgressBackgroundModifiers
Shape4=Combine Shape | Union Shape2 | Union Shape3
ProgressBackgroundModifiers=Fill Color 120,120,120 | StrokeWidth 1 | Stroke Color 0,0,0
UpdateDivider=-1

[VerBarDownStyle]
X=0r
Y=0r
Shape=Ellipse (1+#vBarWidth#/2),(#vBarHeight#+#vBarWidth#/2+1),(#vBarWidth#/2-0.5) | Extend BarModifiers
Shape2=Rectangle 1,(#vBarHeight#-#vBarWidth#/2-1),#vBarWidth#,(2+#vBarWidth#) | Extend BarModifiers
Shape3=Combine Shape | Exclude Shape2 
BarModifiers=Fill Color #vBarColorStart# | StrokeWidth 0 | Stroke Color 255,255,255,0
DynamicVariables=1
UpdateDivider=-1

[VerBarUpStyle]
Shape=Ellipse (#vBarWidth#/2),(#vBarWidth#/2),(#vBarWidth#/2-0.5) | Extend BarModifiers
Shape2=Rectangle 0,(#vBarWidth#/2),#vBarWidth#,(#vBarWidth#/2) | Extend BarModifiers
Shape3=Combine Shape | Exclude Shape2
DynamicVariables=1

[VerBarStyle]
BarOrientation=Vertical
BarImage=#CURRENTPATH#Theme\Bar.png
ImageRotate=90
SolidColor=0,0,0,1
X=1r
Y=0r
W=#vBarWidth#
H=#vBarHeight#
DynamicVariables=1
TransformationMatrix=(#vBarWidth#/8);0;0;(0.01+#vBarHeight#/100);([#CURRENTSECTION#:X]-(#vBarWidth#/8)*[#CURRENTSECTION#:X]);([#CURRENTSECTION#:Y]*(0.99-#vBarHeight#/100)+0+#vBarWidth#/2)

[MessageBackgroundStyle]
MyModifiers1=StrokeWidth 2 | Stroke Color #StrokeColorRed#,#StrokeColorGreen#,#StrokeColorBlue#,#StrokeColorAlpha#
MyModifiers2=Fill Color 80,80,80,180
UpdateDivider=-1
Hidden=1

[FieldStyle]
CheckModifiers=Fill Color 225,225,225 | StrokeWidth 1 | Stroke Color #CheckStrokeColor#
MouseOverAction=[!SetOption #CURRENTSECTION# CheckModifiers "Fill Color 229,241,251 | StrokeWidth 1 | Stroke Color #CheckStrokeColor#"][!UpdateMeter "#CURRENTSECTION#"][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# CheckModifiers "Fill Color 225,225,225 | StrokeWidth 1 | Stroke Color #CheckStrokeColor#"][!UpdateMeter "#CURRENTSECTION#"][!Redraw]
Hidden=1

[HighlightStyle]
SolidColor=80,80,80,1
MouseOverAction=[!SetOption #CURRENTSECTION# SolidColor "80,80,80,180"][!UpdateMeter "#CURRENTSECTION#"][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# SolidColor "80,80,80,1"][!UpdateMeter "#CURRENTSECTION#"][!Redraw]
Group=Highlight
ToolTipHidden=(1-Clamp(#ShowToolTip#,0,1))

[mMouse]
Measure=Plugin
Plugin=Mouse
RelativeToSkin=1
DynamicVariables=1

[mWin7Audio]
Measure=Plugin
Plugin=Win7AudioPlugin
OnChangeAction=[!UpdateMeasure "mVolume"]

[mCalcVolume]
Measure=Calc
Formula=#vVolumeLevel#
OnChangeAction=[!CommandMeasure "mWin7Audio" "SetVolume [#CURRENTSECTION#]"]
DynamicVariables=1
UpdateDivider=-1

[mVolume]
Measure=Calc
Formula=mWin7Audio
MinValue=0
MaxValue=100
OnChangeAction=[!WriteKeyValue Variables vVolumeLevel "(([#CURRENTSECTION#]>0)?[#CURRENTSECTION#]:#vVolumeLevel#)"][!SetVariable vVolumeLevel "(([#CURRENTSECTION#]>0)?[#CURRENTSECTION#]:#vVolumeLevel#)"][!UpdateMeasureGroup "gVolumeBar"][!UpdateMeterGroup "Bar"][!Redraw]
DynamicVariables=1

[mVolumeMute]
Measure=Calc
Formula=#vVolumeLevel#
MinValue=0
MaxValue=100
UpdateDivider=-1
DynamicVariables=1
Group=gVolumeBar

[mBinAction]
Measure=Calc
Formula=mWin7Audio
IfCondition=(#CURRENTSECTION#>=0)


;(Clamp((-32.14+8.19*(((#vBarWidth#-#vBarHeight#+8)/#vBarWidth#)*[*mVolumeMute*])),0,255)),(Clamp((663.11-7.23*(((#vBarWidth#-#vBarHeight#+8)/#vBarWidth#)*[*mVolumeMute*])),0,255)),0 


IfTrueAction=[!SetOption tProgressBarVolume MeasureName "mVolume"][!SetOption tProgressBarLeftVolume BarModifiers "Fill Color #vBarColorStart# | StrokeWidth 0 | Stroke Color 255,255,255,0"][!SetOption tProgressBarRightVolume BarModifiers "Fill Color (Clamp((-32.14+8.19*(((#vBarWidth#-#vBarHeight#+8)/#vBarWidth#)*[*mVolumeMute*])),#vBarColorGreen#,#vBarColorBlue#)),(Clamp((663.11-7.23*(((#vBarWidth#-#vBarHeight#+8)/#vBarWidth#)*[*mVolumeMute*])),#vBarColorGreen#,#vBarColorBlue#)),#vBarColorBlue# | StrokeWidth 0 | Stroke Color 255,255,255,0"][!SetOption tBarTotalVolume ProgressBackgroundModifiers "Fill Color 120,120,120 | StrokeWidth 1 | Stroke Color 0,0,0"][!SetOption tProgressBarVolume ImageAlpha "255"][!UpdateMeter "tProgressBarLeftVolume"][!UpdateMeter "tBarTotalVolume"][!UpdateMeter "tProgressBarRightVolume"][!UpdateMeter "tProgressBarVolume"][!Redraw]
IfFalseAction=[!SetOption tProgressBarVolume MeasureName "mVolumeMute"][!SetOption tProgressBarLeftVolume BarModifiers "Fill Color #vBarColorStart#,#vMuteTransp# | StrokeWidth 0 | Stroke Color 255,255,255,0"][!SetOption tProgressBarRightVolume BarModifiers "Fill Color (Clamp((-40.14+8.19*[*mVolumeMute*]),0,255)),(Clamp((663.11-7.23*[*mVolumeMute*]),0,255)),0,#vMuteTransp# | StrokeWidth 0 | Stroke Color 255,255,255,0"][!SetOption tBarTotalVolume ProgressBackgroundModifiers "Fill Color 120,120,120,#vMuteTransp# | StrokeWidth 1 | Stroke Color 0,0,0,#vMuteTransp#"][!SetOption tProgressBarVolume ImageAlpha "#vMuteTransp#"][!UpdateMeter "tBarTotalVolume"][!UpdateMeter "tProgressBarLeftVolume"][!UpdateMeter "tBarTotalVolume"][!UpdateMeter "tProgressBarRightVolume"][!UpdateMeter "tProgressBarVolume"][!Redraw]
Group=gVolumeBar

[mBinAction2]
Measure=Calc
Formula=mWin7Audio
IfCondition=(#CURRENTSECTION#>=0)
IfTrueAction=[!UpdateMeasure "mVolumeMute"][!SetOption tProgressBarRightVolume X "(1+#vBarWidth#*(1-(#vBarHeight#-8)/#vBarWidth#)*[mVolume]/100)r"]
IfFalseAction=[!SetOption tProgressBarRightVolume X "(#vBarWidth#*(1-(#vBarHeight#-8)/#vBarWidth#)*[mVolumeMute]/100)r"]
IfConditionMode=1
Group=gVolumeBar


; [mBinAction3]
; Measure=Calc
; Formula=1
; IfCondition=(#CURRENTSECTION#>=0)
; IfTrueAction=[!SetOption tProgressBarLeftMusic BarModifiers "Fill Color #vBarColorStart# | StrokeWidth 0 | Stroke Color 255,255,255,0"][!SetOption tProgressBarRightMusic BarModifiers "Fill Color (Clamp((-32.14+8.19*(((#vBarWidth#-#vBarHeight#+8)/#vBarWidth#)*[*mProgressMusic*])),#vBarColorGreen#,#vBarColorBlue#)),(Clamp((663.11-7.23*(((#vBarWidth#-#vBarHeight#+8)/#vBarWidth#)*[*mProgressMusic*])),#vBarColorGreen#,#vBarColorBlue#)),#vBarColorBlue# | StrokeWidth 0 | Stroke Color 255,255,255,0"][!SetOption tBarTotalMusic ProgressBackgroundModifiers "Fill Color 120,120,120 | StrokeWidth 1 | Stroke Color 0,0,0"][!SetOption tProgressBarMusic ImageAlpha "255"][!UpdateMeter "tProgressBarLeftMusic"][!UpdateMeter "tBarTotalMusic"][!UpdateMeter "tProgressBarRightMusic"][!UpdateMeter "tProgressBarMusic"][!Redraw]
; Group=gMusicBar

; [mBinAction4]
; Measure=Calc
; Formula=1
; IfCondition=(#CURRENTSECTION#>=0)
; IfTrueAction=[!SetOption tProgressBarRightMusic X "((19*#vSkinScale#+#paddingLeft#)+((#vBarWidth#)/100*[mProgressMusic]))"]
; IfConditionMode=1
; Group=gMusicBar