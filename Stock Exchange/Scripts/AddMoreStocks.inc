
[InfoIndex2]
Measure=WebParser
URL=https://www.cnbc.com/quotes/#Symbol2#
; URL=file://#CURRENTPATH#stockfile2.xml
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

[mIndex2_Price]
Measure=WebParser
Url=[InfoIndex2]
StringIndex=2
Substitute=",":""

[mIndex2_Change]
Measure=WebParser
Url=[InfoIndex2]
StringIndex=3
Substitute="UNCH":"0"
IfCondition=(#CURRENTSECTION# > 0)
IfTrueAction=[!SetVariable "PriceColor2" "#ColorUp#"]  [!SetOption "UpDownImage_2" "ImageName" "#CURRENTPATH#Scripts\Up.png"]
IfCondition2=(#CURRENTSECTION# = 0)
IfTrueAction2=[!SetVariable "PriceColor2" "#ColorSteady#"] [!SetOption "UpDownImage_2" "ImageName" "#CURRENTPATH#Scripts\Steady.png"]
IfCondition3=(#CURRENTSECTION# <0 )
IfTrueAction3=[!SetVariable "PriceColor2" "#ColorDown#"] [!SetOption "UpDownImage_2" "ImageName" "#CURRENTPATH#Scripts\Down.png"]
OnChangeAction=[!ShowMeterGroup PriceGroup2] [!UpdateMeterGroup PriceGroup2] [!Redraw]
DynamicVariables=1

[cDayLossGain2]
Measure=Calc
Formula= ( mIndex2_Change * #Units2#  )
RegExpSubstitute=1
Substitute="\-":"","^(\d{1,3})(\d{3})(\d{3})$":"\1,\2,\3","^(\d{1,3})(\d{3})$":"\1,\2"
DynamicVariables=1

[cChangeFromBuyPrice2]
Measure=Calc
Formula=  ( [mIndex2_Price] - #BuyPrice2# ) 
IfCondition=(#CURRENTSECTION# > 0)
IfTrueAction=[!SetVariable "OverallColor2" "#ColorUp#"] 
IfCondition2=(#CURRENTSECTION# = 0)
IfTrueAction2=[!SetVariable "OverallColor2" "#ColorSteady#"] 
IfCondition3=(#CURRENTSECTION# <0 )
IfTrueAction3=[!SetVariable "OverallColor2" "#ColorDown#"] 
OnChangeAction=[!ShowMeterGroup OverallGroup2] [!UpdateMeterGroup OverallGroup2] [!Redraw]
DynamicVariables=1

[cFromBuyPer2]
Measure=Calc
Formula=  ( cChangeFromBuyPrice2 / #BuyPrice2# ) * 100

[cGainLoss2]
Measure=Calc
Formula= ( #Units2# * [cChangeFromBuyPrice2] ) 
RegExpSubstitute=1
Substitute="\-":"","^(\d{1,3})(\d{3})(\d{3})$":"\1,\2,\3","^(\d{1,3})(\d{3})$":"\1,\2"
DynamicVariables=1

[cInvestment2]
Measure=Calc
Formula= ( #Units2# * #BuyPrice2# ) 
RegExpSubstitute=1
Substitute="\-":"","^(\d{1,3})(\d{3})(\d{3})$":"\1,\2,\3","^(\d{1,3})(\d{3})$":"\1,\2"
UpdateDivider=-1

[mIndex2_ChangePer]
Measure=Calc
Formula=( cDayLossGain2 / cInvestment2 * 100 )

;-------------- meters

[LabelIndex2]
Meter=STRING
MeasureName=InfoIndex2
MeterStyle=sTextLeft | sColorSetGray
LeftMouseUpAction=#Site##Symbol2#
ToolTipText="Show [InfoIndex2] on CNBC.com"
X=((#Col1Xpos#)*#vSkinScale#+#paddingLeft#)
Y=(65*#vSkinScale#+#paddingTop#)

[InvestmentAmount2]
Meter=STRING
MeasureName=cInvestment2
MeterStyle= sTextRight | sColorSetGray
x=(#Col2Xpos#*#vSkinScale#+#paddingLeft#)
Y=(65*#vSkinScale#+#paddingTop#)
UpdateDivider=-1

[LabelPrice2]
Meter=STRING
MeterStyle= sTextRight
FontColor=#PriceColor2#
x=(#Col3Xpos#*#vSkinScale#+#paddingLeft#)
Y=(65*#vSkinScale#+#paddingTop#)
Text=[&mFormatValue:FormatPrice( [&mIndex2_Price] ) ]
UpdateDivider=-1
Group=PriceGroup2
Hidden=1

[UpDownImage_2]
Meter=Image
ImageName=#CURRENTPATH#Scripts\Steady.png
X=(#Col4Xpos#*#vSkinScale#+#paddingLeft#)
Y=(69*#vSkinScale#+#paddingTop#)
Group=Images

[DayValueChange-2]
Meter=STRING
MeasureName=cDayLossGain2
MeterStyle= sTextRight 
FontColor=#PriceColor2#
X=(#Col5Xpos#*#vSkinScale#+#paddingLeft#)
Y=(65*#vSkinScale#+#paddingTop#)
Group=PriceGroup2
Hidden=1

[LabelIndex2_ChangePer]
Meter=STRING
MeterStyle=sTextRight 
FontColor=#PriceColor2#
X=(#Col6Xpos#*#vSkinScale#+#paddingLeft#)
Y=(65*#vSkinScale#+#paddingTop#)
Text=([mIndex2_ChangePer:/1,1]%)
Group=PriceGroup2
Hidden=1

[OverallGainLoss2]
Meter=STRING
MeterStyle= sTextRight 
FontColor=#OverallColor2#
x=(#Col8Xpos#*#vSkinScale#+#paddingLeft#)
Y=(65*#vSkinScale#+#paddingTop#)
MeasureName=cGainLoss2
Group=OverallGroup2
Hidden=1

[ChangefromBuyPer2]
Meter=STRING
MeterStyle= sTextRight 
FontColor=#OverallColor2#
X=(#Col9Xpos#*#vSkinScale#+#paddingLeft#)
Y=(65*#vSkinScale#+#paddingTop#)
Text=([cFromBuyPer2:/1,1]%)
Group=OverallGroup2
Hidden=1

; ------------------------------------

[InfoIndex3]
Measure=WebParser
URL=https://www.cnbc.com/quotes/#Symbol3#
; URL=file://#CURRENTPATH#stockfile3.xml
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

[mIndex3_Price]
Measure=WebParser
Url=[InfoIndex3]
StringIndex=2
Substitute=",":""

[mIndex3_Change]
Measure=WebParser
Url=[InfoIndex3]
StringIndex=3
Substitute="UNCH":"0"
IfCondition=(#CURRENTSECTION# > 0)
IfTrueAction=[!SetVariable "PriceColor3" "#ColorUp#"]  [!SetOption "UpDownImage_3" "ImageName" "#CURRENTPATH#Scripts\Up.png"]
IfCondition2=(#CURRENTSECTION# = 0)
IfTrueAction2=[!SetVariable "PriceColor3" "#ColorSteady#"] [!SetOption "UpDownImage_3" "ImageName" "#CURRENTPATH#Scripts\Steady.png"]
IfCondition3=(#CURRENTSECTION# <0 )
IfTrueAction3=[!SetVariable "PriceColor3" "#ColorDown#"] [!SetOption "UpDownImage_3" "ImageName" "#CURRENTPATH#Scripts\Down.png"]
OnChangeAction=[!ShowMeterGroup PriceGroup3] [!UpdateMeterGroup PriceGroup3] [!Redraw]
DynamicVariables=1

[cDayLossGain3]
Measure=Calc
Formula= ( mIndex3_Change * #Units3#  )
RegExpSubstitute=1
Substitute="\-":"","^(\d{1,3})(\d{3})(\d{3})$":"\1,\2,\3","^(\d{1,3})(\d{3})$":"\1,\2"
DynamicVariables=1

[cChangeFromBuyPrice3]
Measure=Calc
Formula=  ( [mIndex3_Price] - #BuyPrice3# ) 
IfCondition=(#CURRENTSECTION# > 0)
IfTrueAction=[!SetVariable "OverallColor3" "#ColorUp#"] 
IfCondition2=(#CURRENTSECTION# = 0)
IfTrueAction2=[!SetVariable "OverallColor3" "#ColorSteady#"] 
IfCondition3=(#CURRENTSECTION# <0 )
IfTrueAction3=[!SetVariable "OverallColor3" "#ColorDown#"] 
OnChangeAction=[!ShowMeterGroup OverallGroup3] [!UpdateMeterGroup OverallGroup3] [!Redraw]
DynamicVariables=1

[cFromBuyPer3]
Measure=Calc
Formula=  ( cChangeFromBuyPrice3 / #BuyPrice3# ) * 100

[cGainLoss3]
Measure=Calc
Formula= ( #Units3# * [cChangeFromBuyPrice3] ) 
RegExpSubstitute=1
Substitute="\-":"","^(\d{1,3})(\d{3})(\d{3})$":"\1,\2,\3","^(\d{1,3})(\d{3})$":"\1,\2"
DynamicVariables=1

[cInvestment3]
Measure=Calc
Formula= ( #Units3# * #BuyPrice3# ) 
RegExpSubstitute=1
Substitute="\-":"","^(\d{1,3})(\d{3})(\d{3})$":"\1,\2,\3","^(\d{1,3})(\d{3})$":"\1,\2"
UpdateDivider=-1

[mIndex3_ChangePer]
Measure=Calc
Formula=( cDayLossGain3 / cInvestment3 * 100 )

;-------------- meters

[LabelIndex3]
Meter=STRING
MeasureName=InfoIndex3
MeterStyle=sTextLeft | sColorSetGray
LeftMouseUpAction=#Site##Symbol3#
ToolTipText="Show [InfoIndex3] on CNBC.com"
X=((#Col1Xpos#)*#vSkinScale#+#paddingLeft#)
Y=(80*#vSkinScale#+#paddingTop#)

[InvestmentAmount3]
Meter=STRING
MeasureName=cInvestment3
MeterStyle= sTextRight | sColorSetGray
x=(#Col2Xpos#*#vSkinScale#+#paddingLeft#)
Y=(80*#vSkinScale#+#paddingTop#)
UpdateDivider=-1

[LabelPrice3]
Meter=STRING
MeterStyle= sTextRight
FontColor=#PriceColor3#
x=(#Col3Xpos#*#vSkinScale#+#paddingLeft#)
Y=(80*#vSkinScale#+#paddingTop#)
Text=[&mFormatValue:FormatPrice( [&mIndex3_Price] ) ]
UpdateDivider=-1
Group=PriceGroup3
Hidden=1

[UpDownImage_3]
Meter=Image
ImageName=#CURRENTPATH#Scripts\Steady.png
X=(#Col4Xpos#*#vSkinScale#+#paddingLeft#)
Y=(84*#vSkinScale#+#paddingTop#)
Group=Images

[DayValueChange-3]
Meter=STRING
MeasureName=cDayLossGain3
MeterStyle= sTextRight 
FontColor=#PriceColor3#
X=(#Col5Xpos#*#vSkinScale#+#paddingLeft#)
Y=(80*#vSkinScale#+#paddingTop#)
Group=PriceGroup3
Hidden=1

[LabelIndex3_ChangePer]
Meter=STRING
MeterStyle=sTextRight 
FontColor=#PriceColor3#
X=(#Col6Xpos#*#vSkinScale#+#paddingLeft#)
Y=(80*#vSkinScale#+#paddingTop#)
Text=([mIndex3_ChangePer:/1,1]%)
Group=PriceGroup3
Hidden=1

[OverallGainLoss3]
Meter=STRING
MeterStyle= sTextRight 
FontColor=#OverallColor3#
x=(#Col8Xpos#*#vSkinScale#+#paddingLeft#)
Y=(80*#vSkinScale#+#paddingTop#)
MeasureName=cGainLoss3
Group=OverallGroup3
Hidden=1

[ChangefromBuyPer3]
Meter=STRING
MeterStyle= sTextRight 
FontColor=#OverallColor3#
X=(#Col9Xpos#*#vSkinScale#+#paddingLeft#)
Y=(80*#vSkinScale#+#paddingTop#)
Text=([cFromBuyPer3:/1,1]%)
Group=OverallGroup3
Hidden=1

; ------------------------------------

[InfoIndex4]
Measure=WebParser
URL=https://www.cnbc.com/quotes/#Symbol4#
; URL=file://#CURRENTPATH#stockfile4.xml
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

[mIndex4_Price]
Measure=WebParser
Url=[InfoIndex4]
StringIndex=2
Substitute=",":""

[mIndex4_Change]
Measure=WebParser
Url=[InfoIndex4]
StringIndex=3
Substitute="UNCH":"0"
IfCondition=(#CURRENTSECTION# > 0)
IfTrueAction=[!SetVariable "PriceColor4" "#ColorUp#"]  [!SetOption "UpDownImage_4" "ImageName" "#CURRENTPATH#Scripts\Up.png"]
IfCondition2=(#CURRENTSECTION# = 0)
IfTrueAction2=[!SetVariable "PriceColor4" "#ColorSteady#"] [!SetOption "UpDownImage_4" "ImageName" "#CURRENTPATH#Scripts\Steady.png"]
IfCondition3=(#CURRENTSECTION# <0 )
IfTrueAction3=[!SetVariable "PriceColor4" "#ColorDown#"] [!SetOption "UpDownImage_4" "ImageName" "#CURRENTPATH#Scripts\Down.png"]
OnChangeAction=[!ShowMeterGroup PriceGroup4] [!UpdateMeterGroup PriceGroup4] [!Redraw]
DynamicVariables=1

[cDayLossGain4]
Measure=Calc
Formula= ( mIndex4_Change * #Units4#  )
RegExpSubstitute=1
Substitute="\-":"","^(\d{1,3})(\d{3})(\d{3})$":"\1,\2,\3","^(\d{1,3})(\d{3})$":"\1,\2"
DynamicVariables=1

[cChangeFromBuyPrice4]
Measure=Calc
Formula=  ( [mIndex4_Price] - #BuyPrice4# ) 
IfCondition=(#CURRENTSECTION# > 0)
IfTrueAction=[!SetVariable "OverallColor4" "#ColorUp#"] 
IfCondition2=(#CURRENTSECTION# = 0)
IfTrueAction2=[!SetVariable "OverallColor4" "#ColorSteady#"] 
IfCondition3=(#CURRENTSECTION# <0 )
IfTrueAction3=[!SetVariable "OverallColor4" "#ColorDown#"] 
OnChangeAction=[!ShowMeterGroup OverallGroup4] [!UpdateMeterGroup OverallGroup4] [!Redraw]
DynamicVariables=1

[cFromBuyPer4]
Measure=Calc
Formula=  ( cChangeFromBuyPrice4 / #BuyPrice4# ) * 100

[cGainLoss4]
Measure=Calc
Formula= ( #Units4# * [cChangeFromBuyPrice4] ) 
RegExpSubstitute=1
Substitute="\-":"","^(\d{1,3})(\d{3})(\d{3})$":"\1,\2,\3","^(\d{1,3})(\d{3})$":"\1,\2"
DynamicVariables=1

[cInvestment4]
Measure=Calc
Formula= ( #Units4# * #BuyPrice4# ) 
RegExpSubstitute=1
Substitute="\-":"","^(\d{1,3})(\d{3})(\d{3})$":"\1,\2,\3","^(\d{1,3})(\d{3})$":"\1,\2"
UpdateDivider=-1

[mIndex4_ChangePer]
Measure=Calc
Formula=( cDayLossGain4 / cInvestment4 * 100 )

;-------------- meters

[LabelIndex4]
Meter=STRING
MeasureName=InfoIndex4
MeterStyle=sTextLeft | sColorSetGray
LeftMouseUpAction=#Site##Symbol4#
ToolTipText="Show [InfoIndex4] on CNBC.com"
X=((#Col1Xpos#)*#vSkinScale#+#paddingLeft#)
Y=(95*#vSkinScale#+#paddingTop#)

[InvestmentAmount4]
Meter=STRING
MeasureName=cInvestment4
MeterStyle= sTextRight | sColorSetGray
x=(#Col2Xpos#*#vSkinScale#+#paddingLeft#)
Y=(95*#vSkinScale#+#paddingTop#)
UpdateDivider=-1

[LabelPrice4]
Meter=STRING
MeterStyle= sTextRight
FontColor=#PriceColor4#
x=(#Col3Xpos#*#vSkinScale#+#paddingLeft#)
Y=(95*#vSkinScale#+#paddingTop#)
Text=[&mFormatValue:FormatPrice( [&mIndex4_Price] ) ]
UpdateDivider=-1
Group=PriceGroup4
Hidden=1

[UpDownImage_4]
Meter=Image
ImageName=#CURRENTPATH#Scripts\Steady.png
X=(#Col4Xpos#*#vSkinScale#+#paddingLeft#)
Y=(99*#vSkinScale#+#paddingTop#)
Group=Images

[DayValueChange-4]
Meter=STRING
MeasureName=cDayLossGain4
MeterStyle= sTextRight 
FontColor=#PriceColor4#
X=(#Col5Xpos#*#vSkinScale#+#paddingLeft#)
Y=(95*#vSkinScale#+#paddingTop#)
Group=PriceGroup4
Hidden=1

[LabelIndex4_ChangePer]
Meter=STRING
MeterStyle=sTextRight 
FontColor=#PriceColor4#
X=(#Col6Xpos#*#vSkinScale#+#paddingLeft#)
Y=(95*#vSkinScale#+#paddingTop#)
Text=([mIndex4_ChangePer:/1,1]%)
Group=PriceGroup4
Hidden=1

[OverallGainLoss4]
Meter=STRING
MeterStyle= sTextRight 
FontColor=#OverallColor4#
x=(#Col8Xpos#*#vSkinScale#+#paddingLeft#)
Y=(95*#vSkinScale#+#paddingTop#)
MeasureName=cGainLoss4
Group=OverallGroup4
Hidden=1

[ChangefromBuyPer4]
Meter=STRING
MeterStyle= sTextRight 
FontColor=#OverallColor4#
X=(#Col9Xpos#*#vSkinScale#+#paddingLeft#)
Y=(95*#vSkinScale#+#paddingTop#)
Text=([cFromBuyPer4:/1,1]%)
Group=OverallGroup4
Hidden=1

; ------------------------------------

[InfoIndex5]
Measure=WebParser
URL=https://www.cnbc.com/quotes/#Symbol5#
; URL=file://#CURRENTPATH#stockfile5.xml
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

[mIndex5_Price]
Measure=WebParser
Url=[InfoIndex5]
StringIndex=2
Substitute=",":""

[mIndex5_Change]
Measure=WebParser
Url=[InfoIndex5]
StringIndex=3
Substitute="UNCH":"0"
IfCondition=(#CURRENTSECTION# > 0)
IfTrueAction=[!SetVariable "PriceColor5" "#ColorUp#"]  [!SetOption "UpDownImage_5" "ImageName" "#CURRENTPATH#Scripts\Up.png"]
IfCondition2=(#CURRENTSECTION# = 0)
IfTrueAction2=[!SetVariable "PriceColor5" "#ColorSteady#"] [!SetOption "UpDownImage_5" "ImageName" "#CURRENTPATH#Scripts\Steady.png"]
IfCondition3=(#CURRENTSECTION# <0 )
IfTrueAction3=[!SetVariable "PriceColor5" "#ColorDown#"] [!SetOption "UpDownImage_5" "ImageName" "#CURRENTPATH#Scripts\Down.png"]
OnChangeAction=[!ShowMeterGroup PriceGroup5] [!UpdateMeterGroup PriceGroup5] [!Redraw]
DynamicVariables=1

[cDayLossGain5]
Measure=Calc
Formula= ( mIndex5_Change * #Units5#  )
RegExpSubstitute=1
Substitute="\-":"","^(\d{1,3})(\d{3})(\d{3})$":"\1,\2,\3","^(\d{1,3})(\d{3})$":"\1,\2"
DynamicVariables=1

[cChangeFromBuyPrice5]
Measure=Calc
Formula=  ( [mIndex5_Price] - #BuyPrice5# ) 
IfCondition=(#CURRENTSECTION# > 0)
IfTrueAction=[!SetVariable "OverallColor5" "#ColorUp#"] 
IfCondition2=(#CURRENTSECTION# = 0)
IfTrueAction2=[!SetVariable "OverallColor5" "#ColorSteady#"] 
IfCondition3=(#CURRENTSECTION# <0 )
IfTrueAction3=[!SetVariable "OverallColor5" "#ColorDown#"] 
OnChangeAction=[!ShowMeterGroup OverallGroup5] [!UpdateMeterGroup OverallGroup5] [!Redraw]
DynamicVariables=1

[cFromBuyPer5]
Measure=Calc
Formula=  ( cChangeFromBuyPrice5 / #BuyPrice5# ) * 100

[cGainLoss5]
Measure=Calc
Formula= ( #Units5# * [cChangeFromBuyPrice5] ) 
RegExpSubstitute=1
Substitute="\-":"","^(\d{1,3})(\d{3})(\d{3})$":"\1,\2,\3","^(\d{1,3})(\d{3})$":"\1,\2"
DynamicVariables=1

[cInvestment5]
Measure=Calc
Formula= ( #Units5# * #BuyPrice5# ) 
RegExpSubstitute=1
Substitute="\-":"","^(\d{1,3})(\d{3})(\d{3})$":"\1,\2,\3","^(\d{1,3})(\d{3})$":"\1,\2"
UpdateDivider=-1

[mIndex5_ChangePer]
Measure=Calc
Formula=( cDayLossGain5 / cInvestment5 * 100 )

;-------------- meters

[LabelIndex5]
Meter=STRING
MeasureName=InfoIndex5
MeterStyle=sTextLeft | sColorSetGray
LeftMouseUpAction=#Site##Symbol5#
ToolTipText="Show [InfoIndex5] on CNBC.com"
X=((#Col1Xpos#)*#vSkinScale#+#paddingLeft#)
Y=(110*#vSkinScale#+#paddingTop#)

[InvestmentAmount5]
Meter=STRING
MeasureName=cInvestment5
MeterStyle= sTextRight | sColorSetGray
x=(#Col2Xpos#*#vSkinScale#+#paddingLeft#)
Y=(110*#vSkinScale#+#paddingTop#)
UpdateDivider=-1

[LabelPrice5]
Meter=STRING
MeterStyle= sTextRight
FontColor=#PriceColor5#
x=(#Col3Xpos#*#vSkinScale#+#paddingLeft#)
Y=(110*#vSkinScale#+#paddingTop#)
Text=[&mFormatValue:FormatPrice( [&mIndex5_Price] ) ]
UpdateDivider=-1
Group=PriceGroup5
Hidden=1

[UpDownImage_5]
Meter=Image
ImageName=#CURRENTPATH#Scripts\Steady.png
X=(#Col4Xpos#*#vSkinScale#+#paddingLeft#)
Y=(114*#vSkinScale#+#paddingTop#)
Group=Images

[DayValueChange-5]
Meter=STRING
MeasureName=cDayLossGain5
MeterStyle= sTextRight 
FontColor=#PriceColor5#
X=(#Col5Xpos#*#vSkinScale#+#paddingLeft#)
Y=(110*#vSkinScale#+#paddingTop#)
Group=PriceGroup5
Hidden=1

[LabelIndex5_ChangePer]
Meter=STRING
MeterStyle=sTextRight 
FontColor=#PriceColor5#
X=(#Col6Xpos#*#vSkinScale#+#paddingLeft#)
Y=(110*#vSkinScale#+#paddingTop#)
Text=([mIndex5_ChangePer:/1,1]%)
Group=PriceGroup5
Hidden=1

[OverallGainLoss5]
Meter=STRING
MeterStyle= sTextRight 
FontColor=#OverallColor5#
x=(#Col8Xpos#*#vSkinScale#+#paddingLeft#)
Y=(110*#vSkinScale#+#paddingTop#)
MeasureName=cGainLoss5
Group=OverallGroup5
Hidden=1

[ChangefromBuyPer5]
Meter=STRING
MeterStyle= sTextRight 
FontColor=#OverallColor5#
X=(#Col9Xpos#*#vSkinScale#+#paddingLeft#)
Y=(110*#vSkinScale#+#paddingTop#)
Text=([cFromBuyPer5:/1,1]%)
Group=OverallGroup5
Hidden=1

; ------------------------------------

[InfoIndex6]
Measure=WebParser
URL=https://www.cnbc.com/quotes/#Symbol6#
; URL=file://#CURRENTPATH#stockfile6.xml
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

[mIndex6_Price]
Measure=WebParser
Url=[InfoIndex6]
StringIndex=2
Substitute=",":""

[mIndex6_Change]
Measure=WebParser
Url=[InfoIndex6]
StringIndex=3
Substitute="UNCH":"0"
IfCondition=(#CURRENTSECTION# > 0)
IfTrueAction=[!SetVariable "PriceColor6" "#ColorUp#"]  [!SetOption "UpDownImage_6" "ImageName" "#CURRENTPATH#Scripts\Up.png"]
IfCondition2=(#CURRENTSECTION# = 0)
IfTrueAction2=[!SetVariable "PriceColor6" "#ColorSteady#"] [!SetOption "UpDownImage_6" "ImageName" "#CURRENTPATH#Scripts\Steady.png"]
IfCondition3=(#CURRENTSECTION# <0 )
IfTrueAction3=[!SetVariable "PriceColor6" "#ColorDown#"] [!SetOption "UpDownImage_6" "ImageName" "#CURRENTPATH#Scripts\Down.png"]
OnChangeAction=[!ShowMeterGroup PriceGroup6] [!UpdateMeterGroup PriceGroup6] [!Redraw]
DynamicVariables=1

[cDayLossGain6]
Measure=Calc
Formula= ( mIndex6_Change * #Units6#  )
RegExpSubstitute=1
Substitute="\-":"","^(\d{1,3})(\d{3})(\d{3})$":"\1,\2,\3","^(\d{1,3})(\d{3})$":"\1,\2"
DynamicVariables=1

[cChangeFromBuyPrice6]
Measure=Calc
Formula=  ( [mIndex6_Price] - #BuyPrice6# ) 
IfCondition=(#CURRENTSECTION# > 0)
IfTrueAction=[!SetVariable "OverallColor6" "#ColorUp#"] 
IfCondition2=(#CURRENTSECTION# = 0)
IfTrueAction2=[!SetVariable "OverallColor6" "#ColorSteady#"] 
IfCondition3=(#CURRENTSECTION# <0 )
IfTrueAction3=[!SetVariable "OverallColor6" "#ColorDown#"] 
OnChangeAction=[!ShowMeterGroup OverallGroup6] [!UpdateMeterGroup OverallGroup6] [!Redraw]
DynamicVariables=1

[cFromBuyPer6]
Measure=Calc
Formula=  ( cChangeFromBuyPrice6 / #BuyPrice6# ) * 100

[cGainLoss6]
Measure=Calc
Formula= ( #Units6# * [cChangeFromBuyPrice6] ) 
RegExpSubstitute=1
Substitute="\-":"","^(\d{1,3})(\d{3})(\d{3})$":"\1,\2,\3","^(\d{1,3})(\d{3})$":"\1,\2"
DynamicVariables=1

[cInvestment6]
Measure=Calc
Formula= ( #Units6# * #BuyPrice6# ) 
RegExpSubstitute=1
Substitute="\-":"","^(\d{1,3})(\d{3})(\d{3})$":"\1,\2,\3","^(\d{1,3})(\d{3})$":"\1,\2"
UpdateDivider=-1

[mIndex6_ChangePer]
Measure=Calc
Formula=( cDayLossGain6 / cInvestment6 * 100 )

;-------------- meters

[LabelIndex6]
Meter=STRING
MeasureName=InfoIndex6
MeterStyle=sTextLeft | sColorSetGray
LeftMouseUpAction=#Site##Symbol6#
ToolTipText="Show [InfoIndex6] on CNBC.com"
X=((#Col1Xpos#)*#vSkinScale#+#paddingLeft#)
Y=(125*#vSkinScale#+#paddingTop#)

[InvestmentAmount6]
Meter=STRING
MeasureName=cInvestment6
MeterStyle= sTextRight | sColorSetGray
x=(#Col2Xpos#*#vSkinScale#+#paddingLeft#)
Y=(125*#vSkinScale#+#paddingTop#)
UpdateDivider=-1

[LabelPrice6]
Meter=STRING
MeterStyle= sTextRight
FontColor=#PriceColor6#
x=(#Col3Xpos#*#vSkinScale#+#paddingLeft#)
Y=(125*#vSkinScale#+#paddingTop#)
Text=[&mFormatValue:FormatPrice( [&mIndex6_Price] ) ]
UpdateDivider=-1
Group=PriceGroup6
Hidden=1

[UpDownImage_6]
Meter=Image
ImageName=#CURRENTPATH#Scripts\Steady.png
X=(#Col4Xpos#*#vSkinScale#+#paddingLeft#)
Y=(129*#vSkinScale#+#paddingTop#)
Group=Images

[DayValueChange-6]
Meter=STRING
MeasureName=cDayLossGain6
MeterStyle= sTextRight 
FontColor=#PriceColor6#
X=(#Col5Xpos#*#vSkinScale#+#paddingLeft#)
Y=(125*#vSkinScale#+#paddingTop#)
Group=PriceGroup6
Hidden=1

[LabelIndex6_ChangePer]
Meter=STRING
MeterStyle=sTextRight 
FontColor=#PriceColor6#
X=(#Col6Xpos#*#vSkinScale#+#paddingLeft#)
Y=(125*#vSkinScale#+#paddingTop#)
Text=([mIndex6_ChangePer:/1,1]%)
Group=PriceGroup6
Hidden=1

[OverallGainLoss6]
Meter=STRING
MeterStyle= sTextRight 
FontColor=#OverallColor6#
x=(#Col8Xpos#*#vSkinScale#+#paddingLeft#)
Y=(125*#vSkinScale#+#paddingTop#)
MeasureName=cGainLoss6
Group=OverallGroup6
Hidden=1

[ChangefromBuyPer6]
Meter=STRING
MeterStyle= sTextRight 
FontColor=#OverallColor6#
X=(#Col9Xpos#*#vSkinScale#+#paddingLeft#)
Y=(125*#vSkinScale#+#paddingTop#)
Text=([cFromBuyPer6:/1,1]%)
Group=OverallGroup6
Hidden=1

; ------------------------------------

[InfoIndex7]
Measure=WebParser
URL=https://www.cnbc.com/quotes/#Symbol7#
; URL=file://#CURRENTPATH#stockfile7.xml
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

[mIndex7_Price]
Measure=WebParser
Url=[InfoIndex7]
StringIndex=2
Substitute=",":""

[mIndex7_Change]
Measure=WebParser
Url=[InfoIndex7]
StringIndex=3
Substitute="UNCH":"0"
IfCondition=(#CURRENTSECTION# > 0)
IfTrueAction=[!SetVariable "PriceColor7" "#ColorUp#"]  [!SetOption "UpDownImage_7" "ImageName" "#CURRENTPATH#Scripts\Up.png"]
IfCondition2=(#CURRENTSECTION# = 0)
IfTrueAction2=[!SetVariable "PriceColor7" "#ColorSteady#"] [!SetOption "UpDownImage_7" "ImageName" "#CURRENTPATH#Scripts\Steady.png"]
IfCondition3=(#CURRENTSECTION# <0 )
IfTrueAction3=[!SetVariable "PriceColor7" "#ColorDown#"] [!SetOption "UpDownImage_7" "ImageName" "#CURRENTPATH#Scripts\Down.png"]
OnChangeAction=[!ShowMeterGroup PriceGroup7] [!UpdateMeterGroup PriceGroup7] [!Redraw]
DynamicVariables=1

[cDayLossGain7]
Measure=Calc
Formula= ( mIndex7_Change * #Units7#  )
RegExpSubstitute=1
Substitute="\-":"","^(\d{1,3})(\d{3})(\d{3})$":"\1,\2,\3","^(\d{1,3})(\d{3})$":"\1,\2"
DynamicVariables=1

[cChangeFromBuyPrice7]
Measure=Calc
Formula=  ( [mIndex7_Price] - #BuyPrice7# ) 
IfCondition=(#CURRENTSECTION# > 0)
IfTrueAction=[!SetVariable "OverallColor7" "#ColorUp#"] 
IfCondition2=(#CURRENTSECTION# = 0)
IfTrueAction2=[!SetVariable "OverallColor7" "#ColorSteady#"] 
IfCondition3=(#CURRENTSECTION# <0 )
IfTrueAction3=[!SetVariable "OverallColor7" "#ColorDown#"] 
OnChangeAction=[!ShowMeterGroup OverallGroup7] [!UpdateMeterGroup OverallGroup7] [!Redraw]
DynamicVariables=1

[cFromBuyPer7]
Measure=Calc
Formula=  ( cChangeFromBuyPrice7 / #BuyPrice7# ) * 100

[cGainLoss7]
Measure=Calc
Formula= ( #Units7# * [cChangeFromBuyPrice7] ) 
RegExpSubstitute=1
Substitute="\-":"","^(\d{1,3})(\d{3})(\d{3})$":"\1,\2,\3","^(\d{1,3})(\d{3})$":"\1,\2"
DynamicVariables=1

[cInvestment7]
Measure=Calc
Formula= ( #Units7# * #BuyPrice7# ) 
RegExpSubstitute=1
Substitute="\-":"","^(\d{1,3})(\d{3})(\d{3})$":"\1,\2,\3","^(\d{1,3})(\d{3})$":"\1,\2"
UpdateDivider=-1

[mIndex7_ChangePer]
Measure=Calc
Formula=( cDayLossGain7 / cInvestment7 * 100 )

;-------------- meters

[LabelIndex7]
Meter=STRING
MeasureName=InfoIndex7
MeterStyle=sTextLeft | sColorSetGray
LeftMouseUpAction=#Site##Symbol7#
ToolTipText="Show [InfoIndex7] on CNBC.com"
X=((#Col1Xpos#)*#vSkinScale#+#paddingLeft#)
Y=(140*#vSkinScale#+#paddingTop#)

[InvestmentAmount7]
Meter=STRING
MeasureName=cInvestment7
MeterStyle= sTextRight | sColorSetGray
x=(#Col2Xpos#*#vSkinScale#+#paddingLeft#)
Y=(140*#vSkinScale#+#paddingTop#)
UpdateDivider=-1

[LabelPrice7]
Meter=STRING
MeterStyle= sTextRight
FontColor=#PriceColor7#
x=(#Col3Xpos#*#vSkinScale#+#paddingLeft#)
Y=(140*#vSkinScale#+#paddingTop#)
Text=[&mFormatValue:FormatPrice( [&mIndex7_Price] ) ]
UpdateDivider=-1
Group=PriceGroup7
Hidden=1

[UpDownImage_7]
Meter=Image
ImageName=#CURRENTPATH#Scripts\Steady.png
X=(#Col4Xpos#*#vSkinScale#+#paddingLeft#)
Y=(144*#vSkinScale#+#paddingTop#)
Group=Images

[DayValueChange-7]
Meter=STRING
MeasureName=cDayLossGain7
MeterStyle= sTextRight 
FontColor=#PriceColor7#
X=(#Col5Xpos#*#vSkinScale#+#paddingLeft#)
Y=(140*#vSkinScale#+#paddingTop#)
Group=PriceGroup7
Hidden=1

[LabelIndex7_ChangePer]
Meter=STRING
MeterStyle=sTextRight 
FontColor=#PriceColor7#
X=(#Col6Xpos#*#vSkinScale#+#paddingLeft#)
Y=(140*#vSkinScale#+#paddingTop#)
Text=([mIndex7_ChangePer:/1,1]%)
Group=PriceGroup7
Hidden=1

[OverallGainLoss7]
Meter=STRING
MeterStyle= sTextRight 
FontColor=#OverallColor7#
x=(#Col8Xpos#*#vSkinScale#+#paddingLeft#)
Y=(140*#vSkinScale#+#paddingTop#)
MeasureName=cGainLoss7
Group=OverallGroup7
Hidden=1

[ChangefromBuyPer7]
Meter=STRING
MeterStyle= sTextRight 
FontColor=#OverallColor7#
X=(#Col9Xpos#*#vSkinScale#+#paddingLeft#)
Y=(140*#vSkinScale#+#paddingTop#)
Text=([cFromBuyPer7:/1,1]%)
Group=OverallGroup7
Hidden=1

; ------------------------------------

[InfoIndex8]
Measure=WebParser
URL=https://www.cnbc.com/quotes/#Symbol8#
; URL=file://#CURRENTPATH#stockfile8.xml
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

[mIndex8_Price]
Measure=WebParser
Url=[InfoIndex8]
StringIndex=2
Substitute=",":""

[mIndex8_Change]
Measure=WebParser
Url=[InfoIndex8]
StringIndex=3
Substitute="UNCH":"0"
IfCondition=(#CURRENTSECTION# > 0)
IfTrueAction=[!SetVariable "PriceColor8" "#ColorUp#"]  [!SetOption "UpDownImage_8" "ImageName" "#CURRENTPATH#Scripts\Up.png"]
IfCondition2=(#CURRENTSECTION# = 0)
IfTrueAction2=[!SetVariable "PriceColor8" "#ColorSteady#"] [!SetOption "UpDownImage_8" "ImageName" "#CURRENTPATH#Scripts\Steady.png"]
IfCondition3=(#CURRENTSECTION# <0 )
IfTrueAction3=[!SetVariable "PriceColor8" "#ColorDown#"] [!SetOption "UpDownImage_8" "ImageName" "#CURRENTPATH#Scripts\Down.png"]
OnChangeAction=[!ShowMeterGroup PriceGroup8] [!UpdateMeterGroup PriceGroup8] [!Redraw]
DynamicVariables=1

[cDayLossGain8]
Measure=Calc
Formula= ( mIndex8_Change * #Units8#  )
RegExpSubstitute=1
Substitute="\-":"","^(\d{1,3})(\d{3})(\d{3})$":"\1,\2,\3","^(\d{1,3})(\d{3})$":"\1,\2"
DynamicVariables=1

[cChangeFromBuyPrice8]
Measure=Calc
Formula=  ( [mIndex8_Price] - #BuyPrice8# ) 
IfCondition=(#CURRENTSECTION# > 0)
IfTrueAction=[!SetVariable "OverallColor8" "#ColorUp#"] 
IfCondition2=(#CURRENTSECTION# = 0)
IfTrueAction2=[!SetVariable "OverallColor8" "#ColorSteady#"] 
IfCondition3=(#CURRENTSECTION# <0 )
IfTrueAction3=[!SetVariable "OverallColor8" "#ColorDown#"] 
OnChangeAction=[!ShowMeterGroup OverallGroup8] [!UpdateMeterGroup OverallGroup8] [!Redraw]
DynamicVariables=1

[cFromBuyPer8]
Measure=Calc
Formula=  ( cChangeFromBuyPrice8 / #BuyPrice8# ) * 100

[cGainLoss8]
Measure=Calc
Formula= ( #Units8# * [cChangeFromBuyPrice8] ) 
RegExpSubstitute=1
Substitute="\-":"","^(\d{1,3})(\d{3})(\d{3})$":"\1,\2,\3","^(\d{1,3})(\d{3})$":"\1,\2"
DynamicVariables=1

[cInvestment8]
Measure=Calc
Formula= ( #Units8# * #BuyPrice8# ) 
RegExpSubstitute=1
Substitute="\-":"","^(\d{1,3})(\d{3})(\d{3})$":"\1,\2,\3","^(\d{1,3})(\d{3})$":"\1,\2"
UpdateDivider=-1

[mIndex8_ChangePer]
Measure=Calc
Formula=( cDayLossGain8 / cInvestment8 * 100 )

;-------------- meters

[LabelIndex8]

Meter=STRING
MeasureName=InfoIndex8
MeterStyle=sTextLeft | sColorSetGray
LeftMouseUpAction=#Site##Symbol8#
ToolTipText="Show [InfoIndex8] on CNBC.com"
X=((#Col1Xpos#)*#vSkinScale#+#paddingLeft#)
Y=(155*#vSkinScale#+#paddingTop#)

[InvestmentAmount8]
Meter=STRING
MeasureName=cInvestment8
MeterStyle= sTextRight | sColorSetGray
x=(#Col2Xpos#*#vSkinScale#+#paddingLeft#)
Y=(155*#vSkinScale#+#paddingTop#)
UpdateDivider=-1

[LabelPrice8]
Meter=STRING
MeterStyle= sTextRight
FontColor=#PriceColor8#
x=(#Col3Xpos#*#vSkinScale#+#paddingLeft#)
Y=(155*#vSkinScale#+#paddingTop#)
Text=[&mFormatValue:FormatPrice( [&mIndex8_Price] ) ]
UpdateDivider=-1
Group=PriceGroup8
Hidden=1

[UpDownImage_8]
Meter=Image
ImageName=#CURRENTPATH#Scripts\Steady.png
X=(#Col4Xpos#*#vSkinScale#+#paddingLeft#)
Y=(159*#vSkinScale#+#paddingTop#)
Group=Images

[DayValueChange-8]
Meter=STRING
MeasureName=cDayLossGain8
MeterStyle= sTextRight 
FontColor=#PriceColor8#
X=(#Col5Xpos#*#vSkinScale#+#paddingLeft#)
Y=(155*#vSkinScale#+#paddingTop#)
Group=PriceGroup8
Hidden=1

[LabelIndex8_ChangePer]
Meter=STRING
MeterStyle=sTextRight 
FontColor=#PriceColor8#
X=(#Col6Xpos#*#vSkinScale#+#paddingLeft#)
Y=(155*#vSkinScale#+#paddingTop#)
Text=([mIndex8_ChangePer:/1,1]%)
Group=PriceGroup8
Hidden=1

[OverallGainLoss8]
Meter=STRING
MeterStyle= sTextRight 
FontColor=#OverallColor8#
x=(#Col8Xpos#*#vSkinScale#+#paddingLeft#)
Y=(155*#vSkinScale#+#paddingTop#)
MeasureName=cGainLoss8
Group=OverallGroup8
Hidden=1

[ChangefromBuyPer8]
Meter=STRING
MeterStyle= sTextRight 
FontColor=#OverallColor8#
X=(#Col9Xpos#*#vSkinScale#+#paddingLeft#)
Y=(155*#vSkinScale#+#paddingTop#)
Text=([cFromBuyPer8:/1,1]%)
Group=OverallGroup8
Hidden=1

; ------------------------------------