
[InfoIndex^1^]
Measure=WebParser
URL=https://www.cnbc.com/quotes/#Symbol^1^#
; URL=file://#@#stockfile^1^.xml
UserAgent=#MyUserAgent#
Header=Accept: text/html
Header2=Accept_Encoding: gzip, deflate, br
Header3=Accept_Language: en-US
Header4=Connection: close
Header5=Dnt: 1
Header6=Host: www.CNBC.com
Header7=Referer: https://wwww.google.com
RegExp=#ExpQuote#
Substitute= "":"   loading..."
StringIndex=1
UpdateRate=#UpdateQuotes#

[mIndex^1^_Price]
Measure=WebParser
Url=[InfoIndex^1^]
StringIndex=2
Substitute=",":""

[mIndex^1^_Change]
Measure=WebParser
Url=[InfoIndex^1^]
StringIndex=3
Substitute="UNCH":"0"
IfCondition=(#CURRENTSECTION# > 0)
IfTrueAction=[!SetVariable "PriceColor^1^" "#ColorUp#"]  [!SetOption "UpDownImage_^1^" "ImageName" "#@#Up.png"]
IfCondition2=(#CURRENTSECTION# = 0)
IfTrueAction2=[!SetVariable "PriceColor^1^" "#ColorSteady#"] [!SetOption "UpDownImage_^1^" "ImageName" "#@#Steady.png"]
IfCondition3=(#CURRENTSECTION# <0 )
IfTrueAction3=[!SetVariable "PriceColor^1^" "#ColorDown#"] [!SetOption "UpDownImage_^1^" "ImageName" "#@#Down.png"]
OnChangeAction=[!ShowMeterGroup PriceGroup^1^] [!UpdateMeterGroup PriceGroup^1^] [!Redraw]
DynamicVariables=1

[cDayLossGain^1^]
Measure=Calc
Formula= ( mIndex^1^_Change * #Units^1^#  )
RegExpSubstitute=1
Substitute="\-":"","^(\d{1,3})(\d{3})(\d{3})$":"\1,\2,\3","^(\d{1,3})(\d{3})$":"\1,\2"
DynamicVariables=1

[cChangeFromBuyPrice^1^]
Measure=Calc
Formula=  ( [mIndex^1^_Price] - #BuyPrice^1^# ) 
IfCondition=(#CURRENTSECTION# > 0)
IfTrueAction=[!SetVariable "OverallColor^1^" "#ColorUp#"] 
IfCondition2=(#CURRENTSECTION# = 0)
IfTrueAction2=[!SetVariable "OverallColor^1^" "#ColorSteady#"] 
IfCondition3=(#CURRENTSECTION# <0 )
IfTrueAction3=[!SetVariable "OverallColor^1^" "#ColorDown#"] 
OnChangeAction=[!ShowMeterGroup OverallGroup^1^] [!UpdateMeterGroup OverallGroup^1^] [!Redraw]
DynamicVariables=1

[cFromBuyPer^1^]
Measure=Calc
Formula=  ( cChangeFromBuyPrice^1^ / #BuyPrice^1^# ) * 100

[cGainLoss^1^]
Measure=Calc
Formula= ( #Units^1^# * [cChangeFromBuyPrice^1^] ) 
RegExpSubstitute=1
Substitute="\-":"","^(\d{1,3})(\d{3})(\d{3})$":"\1,\2,\3","^(\d{1,3})(\d{3})$":"\1,\2"
DynamicVariables=1

[cInvestment^1^]
Measure=Calc
Formula= ( #Units^1^# * #BuyPrice^1^# ) 
RegExpSubstitute=1
Substitute="\-":"","^(\d{1,3})(\d{3})(\d{3})$":"\1,\2,\3","^(\d{1,3})(\d{3})$":"\1,\2"
UpdateDivider=-1

[mIndex^1^_ChangePer]
Measure=Calc
Formula=( cDayLossGain^1^ / cInvestment^1^ * 100 )

;-------------- meters

[LabelIndex^1^]
Meter=STRING
MeasureName=InfoIndex^1^
MeterStyle=sTextLeft | sColorSetGray
LeftMouseUpAction=#Site##Symbol^1^#
ToolTipText="Show [InfoIndex^1^] on CNBC.com"
X=(#Col1Xpos#*#vSkinScale#)
Y=(#RowYspacing#*#vSkinScale#)

[InvestmentAmount^1^]
Meter=STRING
MeasureName=cInvestment^1^
MeterStyle= sTextRight | sColorSetGray
x=(#Col2Xpos#*#vSkinScale#)
UpdateDivider=-1

[LabelPrice^1^]
Meter=STRING
MeterStyle= sTextRight
FontColor=#PriceColor^1^#
x=(#Col3Xpos#*#vSkinScale#)
Text=[&mFormatValue:FormatPrice( [&mIndex^1^_Price] ) ]
UpdateDivider=-1
Group=PriceGroup^1^
Hidden=1

[UpDownImage_^1^]
Meter=Image
ImageName=#@#Steady.png
X=(#Col4Xpos#*#vSkinScale#)
y=-(6*#vSkinScale#)r
Group=Images

[DayValueChange-^1^]
Meter=STRING
MeasureName=cDayLossGain^1^
MeterStyle= sTextRight 
FontColor=#PriceColor^1^#
X=(#Col5Xpos#*#vSkinScale#)
Y=(6*#vSkinScale#)r
Group=PriceGroup^1^
Hidden=1

[LabelIndex^1^_ChangePer]
Meter=STRING
MeterStyle=sTextRight 
FontColor=#PriceColor^1^#
X=(#Col6Xpos#*#vSkinScale#)
Text=([mIndex^1^_ChangePer:/1,1]%)
Group=PriceGroup^1^
Hidden=1

[OverallGainLoss^1^]
Meter=STRING
MeterStyle= sTextRight 
FontColor=#OverallColor^1^#
x=(#Col8Xpos#*#vSkinScale#)
MeasureName=cGainLoss^1^
Group=OverallGroup^1^
Hidden=1

[ChangefromBuyPer^1^]
Meter=STRING
MeterStyle= sTextRight 
FontColor=#OverallColor^1^#
X=(#Col9Xpos#*#vSkinScale#)
Text=([cFromBuyPer^1^:/1,1]%)
Group=OverallGroup^1^
Hidden=1

; ------------------------------------
