function Initialize()
	Format12H, FormatShowSec, FormatLeadingZeros, FormatAMPM, FormatLeadingZerosDate, FormatDateFormat, FormatDesc, ShowYesterdayToday, YesterdayLab, TodayLab, MinsAgo, MinsAgoLimit = tonumber(SKIN:GetVariable('12H')), tonumber(SKIN:GetVariable('ShowSec')), tonumber(SKIN:GetVariable('LeadingZeros')), tonumber(SKIN:GetVariable('AMPM')), tonumber(SKIN:GetVariable('LeadingZerosDate')), tonumber(SKIN:GetVariable('DateFormat')), tonumber(SKIN:GetVariable('DateDivider')), tonumber(SKIN:GetVariable('YesterdayToday')), SKIN:GetVariable('YesterdayLabel'), SKIN:GetVariable('TodayLabel'), SKIN:GetVariable('MinsAgo'), SKIN:GetVariable('MinsAgoLimit')
	JanS, FebS, MarS, AprS, MayS, JunS, JulS, AugS, SepS, OctS, NovS, DecS, AMS, PMS, LessMinAgoS, OneMinAgoS, MoreMinsAgoS = tostring(SKIN:GetVariable('Jan')), tostring(SKIN:GetVariable('Feb')), tostring(SKIN:GetVariable('Mar')), tostring(SKIN:GetVariable('Apr')), tostring(SKIN:GetVariable('May')), tostring(SKIN:GetVariable('Jun')), tostring(SKIN:GetVariable('Jul')), tostring(SKIN:GetVariable('Aug')), tostring(SKIN:GetVariable('Sep')), tostring(SKIN:GetVariable('Oct')), tostring(SKIN:GetVariable('Nov')), tostring(SKIN:GetVariable('Dec')), tostring(SKIN:GetVariable('AM')), tostring(SKIN:GetVariable('PM')), tostring(SKIN:GetVariable('LessMinAgo')), tostring(SKIN:GetVariable('OneMinAgo')), tostring(SKIN:GetVariable('MoreMinsAgo'))
	if FormatDesc == 0 then
		Desc = '-'
	elseif FormatDesc == 1 then
		Desc = '.'
	elseif FormatDesc == 2 then
		Desc = ' '
	else
		Desc = '/'
	end
end

function ReplaceMonth(month)
	if month == 'Jan' then
		return JanS
	elseif month == 'Feb' then
		return FebS
	elseif month == 'Mar' then
		return MarS
	elseif month == 'Apr' then
		return AprS
	elseif month == 'May' then
		return MayS
	elseif month == 'Jun' then
		return JunS
	elseif month == 'Jul' then
		return JulS
	elseif month == 'Aug' then
		return AugS
	elseif month == 'Sep' then
		return SepS
	elseif month == 'Oct' then
		return OctS
	elseif month == 'Nov' then
		return NovS
	else
		return DecS
	end
end

function ReplaceAMPM(Str)
	if Str == 'AM' then
		return AMS
	else
		return PMS
	end
end

function Update()
	local Year, Month, Day, Hour, Minute, Second, MeasureYear, MeasureMonth, MeasureDay, MeasureHour, MeasureMinute, MeasureSecond = {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}
	local UpdateYear4, UpdateYear2, UpdateMonthNum2, UpdateDay2, UpdateHour242, UpdateHour122, UpdateMinute, UpdateSecond, UpdateMonthAbr = 0, 0, 0, 0, 0, 0, 0, 0, ''
	for i = 1,10 do
		Year[i], Month[i], Day[i], Hour[i], Minute[i], Second[i], MeasureYear[i], MeasureMonth[i], MeasureDay[i], MeasureHour[i], MeasureMinute[i], MeasureSecond[i] = '', '', '', '', '', '', 0, 0, 0, 0, 0, 0
	end
	Year4, Year2, MonthNum2, MonthAbr, Day2, Hour242, Hour122, UMinute, USecond = SKIN:GetMeasure('MeasureUpdateYear4'), SKIN:GetMeasure('MeasureUpdateYear2'), SKIN:GetMeasure('MeasureUpdateMonthNum2'), SKIN:GetMeasure('MeasureUpdateMonthAbr'), SKIN:GetMeasure('MeasureUpdateDay2'), SKIN:GetMeasure('MeasureUpdateHour242'), SKIN:GetMeasure('MeasureUpdateHour122'), SKIN:GetMeasure('MeasureUpdateMinute'), SKIN:GetMeasure('MeasureUpdateSecond')
	UpdateYear4, UpdateYear2, UpdateMonthNum2, UpdateMonthAbr, UpdateDay2, UpdateHour242, UpdateHour122, UpdateMinute, UpdateSecond = Year4:GetValue(), Year2:GetValue(), MonthNum2:GetValue(), MonthAbr:GetValue(), Day2:GetValue(), Hour242:GetValue(), Hour122:GetValue(), UMinute:GetValue(), USecond:GetValue()
	for i = 1,10 do
		Year[i] = SKIN:GetMeasure('MeasureYear'..tostring(i))
		Month[i] = SKIN:GetMeasure('MeasureMonth'..tostring(i))
		Day[i] = SKIN:GetMeasure('MeasureDay'..tostring(i))
		Hour[i] = SKIN:GetMeasure('MeasureHour'..tostring(i))
		Minute[i] = SKIN:GetMeasure('MeasureMinute'..tostring(i))
		Second[i] = 0
		MeasureYear[i] = Year[i]:GetValue()
		MeasureMonth[i] = Month[i]:GetValue()
		MeasureDay[i] = Day[i]:GetValue()
		MeasureHour[i] = Hour[i]:GetValue()
		MeasureMinute[i] = Minute[i]:GetValue()
		MeasureSecond[i] = 0
	end
	local UTC = os.date('!*t')
	local LocalTime = os.date('*t')
	local DaylightSavings = 0
	if LocalTime.isdst then
		DaylightSavings = 3600
	end
	local LocalOffset = os.time(LocalTime) - os.time(UTC) + DaylightSavings
	local TimeFormat = (1000*Format12H+100*FormatShowSec+10+FormatAMPM)
	local CurrTime = os.time()
	local Upd = (os.time({year=UpdateYear4, month=UpdateMonthNum2, day=UpdateDay2, hour=UpdateHour242, min=UpdateMinute, sec=UpdateSecond}))
	if Upd == nil then
		Upd = (os.time({year=os.date("%Y"), month=os.date("%m"), day=os.date("%d"), hour=os.date("%H"), min=os.date("%M"), sec=os.date("%S")}))
	end
	local Year2U, YearU, MonthU, MonthAU, DayU, Hour12U, Hour24U, MinuteU, SecondU, AMPMU = os.date("%y", Upd), os.date("%Y", Upd), os.date("%m", Upd), os.date("%b", Upd), os.date("%d", Upd), os.date("%I", Upd), os.date("%H", Upd), os.date("%M", Upd), os.date("%S", Upd), os.date("%p", Upd)
	MonthAU = ReplaceMonth(MonthAU)
	AMPMU = ReplaceAMPM(AMPMU)
	if FormatLeadingZerosDate == 0 then
		if MonthU:sub(1,1) == '0' then 
			MonthU = MonthU:sub(2,2)
		end
		if DayU:sub(1,1) == '0' then 
			DayU = DayU:sub(2,2)
		end
	end
	if FormatLeadingZeros == 0 then
		if Hour12U:sub(1,1) == '0' then 
			Hour12U = Hour12U:sub(2,2)
		end
		if Hour24U:sub(1,1) == '0' then 
			Hour24U = Hour24U:sub(2,2)
		end
	end

	if (tonumber(MinsAgo) >= 1) and (CurrTime - Upd < 60*tonumber(MinsAgoLimit)) and (CurrTime >= Upd) then
		if (CurrTime - Upd < 60) then
			SKIN:Bang('!SetVariable', 'UpdDateTime', LessMinAgoS)
		elseif (CurrTime - Upd >= 60) and (CurrTime - Upd < 120) then
			SKIN:Bang('!SetVariable', 'UpdDateTime', OneMinAgoS)
		else
			if (math.floor((CurrTime-Upd)/60) <= 9) and (FormatLeadingZeros >= 1) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', '0'..math.floor((CurrTime-Upd)/60)..' '..MoreMinsAgoS)
			else
				SKIN:Bang('!SetVariable', 'UpdDateTime', math.floor((CurrTime-Upd)/60)..' '..MoreMinsAgoS)
			end
		end
	else
		if (ShowYesterdayToday >= 1) and (tonumber(YearU) == tonumber(os.date("%Y"))) and (tonumber(MonthU) == tonumber(os.date("%m"))) and (tonumber(DayU) == tonumber(os.date("%d"))) then
			if TimeFormat <= 11 then
				SKIN:Bang('!SetVariable', 'UpdDateTime', TodayLab..' '..Hour24U..':'..MinuteU)
			end
			if (TimeFormat == 100) or (TimeFormat == 101) or (TimeFormat == 110) or (TimeFormat == 111) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', TodayLab..' '..Hour24U..':'..MinuteU..':'..SecondU)
			end
			if (TimeFormat == 1000) or (TimeFormat == 1010) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', TodayLab..' '..Hour12U..':'..MinuteU)
			end
			if (TimeFormat == 1001) or (TimeFormat == 1011) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', TodayLab..' '..Hour12U..':'..MinuteU..' '..AMPMU)
			end
			if (TimeFormat == 1100) or (TimeFormat == 1110) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', TodayLab..' '..Hour12U..':'..MinuteU..':'..SecondU)
			end
			if (TimeFormat == 1101) or (TimeFormat == 1111) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', TodayLab..' '..Hour12U..':'..MinuteU..':'..SecondU..' '..AMPMU)
			end
		elseif (ShowYesterdayToday >= 1) and (tonumber(YearU) == tonumber(os.date("%Y",os.time()-24*60*60))) and (tonumber(MonthU) == tonumber(os.date("%m",os.time()-24*60*60))) and (tonumber(DayU) == tonumber(os.date("%d",os.time()-24*60*60))) then
			if TimeFormat <= 11 then
				SKIN:Bang('!SetVariable', 'UpdDateTime', YesterdayLab..' '..Hour24U..':'..MinuteU)
			end
			if (TimeFormat == 100) or (TimeFormat == 101) or (TimeFormat == 110) or (TimeFormat == 111) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', YesterdayLab..' '..Hour24U..':'..MinuteU..':'..SecondU)
			end
			if (TimeFormat == 1000) or (TimeFormat == 1010) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', YesterdayLab..' '..Hour12U..':'..MinuteU)
			end
			if (TimeFormat == 1001) or (TimeFormat == 1011) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', YesterdayLab..' '..Hour12U..':'..MinuteU..' '..AMPMU)
			end
			if (TimeFormat == 1100) or (TimeFormat == 1110) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', YesterdayLab..' '..Hour12U..':'..MinuteU..':'..SecondU)
			end
			if (TimeFormat == 1101) or (TimeFormat == 1111) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', YesterdayLab..' '..Hour12U..':'..MinuteU..':'..SecondU..' '..AMPMU)
			end
		elseif FormatDateFormat == 0 then
			if TimeFormat <= 11 then
				SKIN:Bang('!SetVariable', 'UpdDateTime', MonthU..Desc..DayU..Desc..Year2U..' '..Hour24U..':'..MinuteU)
			end
			if (TimeFormat == 100) or (TimeFormat == 101) or (TimeFormat == 110) or (TimeFormat == 111) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', MonthU..Desc..DayU..Desc..Year2U..' '..Hour24U..':'..MinuteU..':'..SecondU)
			end
			if (TimeFormat == 1000) or (TimeFormat == 1010) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', MonthU..Desc..DayU..Desc..Year2U..' '..Hour12U..':'..MinuteU)
			end
			if (TimeFormat == 1001) or (TimeFormat == 1011) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', MonthU..Desc..DayU..Desc..Year2U..' '..Hour12U..':'..MinuteU..' '..AMPMU)
			end
			if (TimeFormat == 1100) or (TimeFormat == 1110) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', MonthU..Desc..DayU..Desc..Year2U..' '..Hour12U..':'..MinuteU..':'..SecondU)
			end
			if (TimeFormat == 1101) or (TimeFormat == 1111) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', MonthU..Desc..DayU..Desc..Year2U..' '..Hour12U..':'..MinuteU..':'..SecondU..' '..AMPMU)
			end
		elseif FormatDateFormat == 1 then
			if TimeFormat <= 11 then
				SKIN:Bang('!SetVariable', 'UpdDateTime', MonthAU..Desc..DayU..Desc..Year2U..' '..Hour24U..':'..MinuteU)
			end
			if (TimeFormat == 100) or (TimeFormat == 101) or (TimeFormat == 110) or (TimeFormat == 111) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', MonthAU..Desc..DayU..Desc..Year2U..' '..Hour24U..':'..MinuteU..':'..SecondU)
			end
			if (TimeFormat == 1000) or (TimeFormat == 1010) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', MonthAU..Desc..DayU..Desc..Year2U..' '..Hour12U..':'..MinuteU)
			end
			if (TimeFormat == 1001) or (TimeFormat == 1011) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', MonthAU..Desc..DayU..Desc..Year2U..' '..Hour12U..':'..MinuteU..' '..AMPMU)
			end
			if (TimeFormat == 1100) or (TimeFormat == 1110) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', MonthAU..Desc..DayU..Desc..Year2U..' '..Hour12U..':'..MinuteU..':'..SecondU)
			end
			if (TimeFormat == 1101) or (TimeFormat == 1111) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', MonthAU..Desc..DayU..Desc..Year2U..' '..Hour12U..':'..MinuteU..':'..SecondU..' '..AMPMU)
			end
		elseif FormatDateFormat == 2 then
			if TimeFormat <= 11 then
				SKIN:Bang('!SetVariable', 'UpdDateTime', MonthU..Desc..DayU..Desc..YearU..' '..Hour24U..':'..MinuteU)
			end
			if (TimeFormat == 100) or (TimeFormat == 101) or (TimeFormat == 110) or (TimeFormat == 111) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', MonthU..Desc..DayU..Desc..YearU..' '..Hour24U..':'..MinuteU..':'..SecondU)
			end
			if (TimeFormat == 1000) or (TimeFormat == 1010) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', MonthU..Desc..DayU..Desc..YearU..' '..Hour12U..':'..MinuteU)
			end
			if (TimeFormat == 1001) or (TimeFormat == 1011) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', MonthU..Desc..DayU..Desc..YearU..' '..Hour12U..':'..MinuteU..' '..AMPMU)
			end
			if (TimeFormat == 1100) or (TimeFormat == 1110) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', MonthU..Desc..DayU..Desc..YearU..' '..Hour12U..':'..MinuteU..':'..SecondU)
			end
			if (TimeFormat == 1101) or (TimeFormat == 1111) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', MonthU..Desc..DayU..Desc..YearU..' '..Hour12U..':'..MinuteU..':'..SecondU..' '..AMPMU)
			end
		elseif FormatDateFormat == 3 then
			if TimeFormat <= 11 then
				SKIN:Bang('!SetVariable', 'UpdDateTime', MonthAU..Desc..DayU..Desc..YearU..' '..Hour24U..':'..MinuteU)
			end
			if (TimeFormat == 100) or (TimeFormat == 101) or (TimeFormat == 110) or (TimeFormat == 111) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', MonthAU..Desc..DayU..Desc..YearU..' '..Hour24U..':'..MinuteU..':'..SecondU)
			end
			if (TimeFormat == 1000) or (TimeFormat == 1010) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', MonthAU..Desc..DayU..Desc..YearU..' '..Hour12U..':'..MinuteU)
			end
			if (TimeFormat == 1001) or (TimeFormat == 1011) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', MonthAU..Desc..DayU..Desc..YearU..' '..Hour12U..':'..MinuteU..' '..AMPMU)
			end
			if (TimeFormat == 1100) or (TimeFormat == 1110) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', MonthAU..Desc..DayU..Desc..YearU..' '..Hour12U..':'..MinuteU..':'..SecondU)
			end
			if (TimeFormat == 1101) or (TimeFormat == 1111) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', MonthAU..Desc..DayU..Desc..YearU..' '..Hour12U..':'..MinuteU..':'..SecondU..' '..AMPMU)
			end
		elseif FormatDateFormat == 4 then
			if TimeFormat <= 11 then
				SKIN:Bang('!SetVariable', 'UpdDateTime', DayU..Desc..MonthU..Desc..Year2U..' '..Hour24U..':'..MinuteU)
			end
			if (TimeFormat == 100) or (TimeFormat == 101) or (TimeFormat == 110) or (TimeFormat == 111) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', DayU..Desc..MonthU..Desc..Year2U..' '..Hour24U..':'..MinuteU..':'..SecondU)
			end
			if (TimeFormat == 1000) or (TimeFormat == 1010) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', DayU..Desc..MonthU..Desc..Year2U..' '..Hour12U..':'..MinuteU)
			end
			if (TimeFormat == 1001) or (TimeFormat == 1011) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', DayU..Desc..MonthU..Desc..Year2U..' '..Hour12U..':'..MinuteU..' '..AMPMU)
			end
			if (TimeFormat == 1100) or (TimeFormat == 1110) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', DayU..Desc..MonthU..Desc..Year2U..' '..Hour12U..':'..MinuteU..':'..SecondU)
			end
			if (TimeFormat == 1101) or (TimeFormat == 1111) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', DayU..Desc..MonthU..Desc..Year2U..' '..Hour12U..':'..MinuteU..':'..SecondU..' '..AMPMU)
			end
		elseif FormatDateFormat == 5 then
			if TimeFormat <= 11 then
				SKIN:Bang('!SetVariable', 'UpdDateTime', DayU..Desc..MonthAU..Desc..Year2U..' '..Hour24U..':'..MinuteU)
			end
			if (TimeFormat == 100) or (TimeFormat == 101) or (TimeFormat == 110) or (TimeFormat == 111) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', DayU..Desc..MonthAU..Desc..Year2U..' '..Hour24U..':'..MinuteU..':'..SecondU)
			end
			if (TimeFormat == 1000) or (TimeFormat == 1010) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', DayU..Desc..MonthAU..Desc..Year2U..' '..Hour12U..':'..MinuteU)
			end
			if (TimeFormat == 1001) or (TimeFormat == 1011) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', DayU..Desc..MonthAU..Desc..Year2U..' '..Hour12U..':'..MinuteU..' '..AMPMU)
			end
			if (TimeFormat == 1100) or (TimeFormat == 1110) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', DayU..Desc..MonthAU..Desc..Year2U..' '..Hour12U..':'..MinuteU..':'..SecondU)
			end
			if (TimeFormat == 1101) or (TimeFormat == 1111) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', DayU..Desc..MonthAU..Desc..Year2U..' '..Hour12U..':'..MinuteU..':'..SecondU..' '..AMPMU)
			end
		elseif FormatDateFormat == 6 then
			if TimeFormat <= 11 then
				SKIN:Bang('!SetVariable', 'UpdDateTime', DayU..Desc..MonthU..Desc..YearU..' '..Hour24U..':'..MinuteU)
			end
			if (TimeFormat == 100) or (TimeFormat == 101) or (TimeFormat == 110) or (TimeFormat == 111) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', DayU..Desc..MonthU..Desc..YearU..' '..Hour24U..':'..MinuteU..':'..SecondU)
			end
			if (TimeFormat == 1000) or (TimeFormat == 1010) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', DayU..Desc..MonthU..Desc..YearU..' '..Hour12U..':'..MinuteU)
			end
			if (TimeFormat == 1001) or (TimeFormat == 1011) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', DayU..Desc..MonthU..Desc..YearU..' '..Hour12U..':'..MinuteU..' '..AMPMU)
			end
			if (TimeFormat == 1100) or (TimeFormat == 1110) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', DayU..Desc..MonthU..Desc..YearU..' '..Hour12U..':'..MinuteU..':'..SecondU)
			end
			if (TimeFormat == 1101) or (TimeFormat == 1111) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', DayU..Desc..MonthU..Desc..YearU..' '..Hour12U..':'..MinuteU..':'..SecondU..' '..AMPMU)
			end
		elseif FormatDateFormat == 7 then
			if TimeFormat <= 11 then
				SKIN:Bang('!SetVariable', 'UpdDateTime', DayU..Desc..MonthAU..Desc..YearU..' '..Hour24U..':'..MinuteU)
			end
			if (TimeFormat == 100) or (TimeFormat == 101) or (TimeFormat == 110) or (TimeFormat == 111) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', DayU..Desc..MonthAU..Desc..YearU..' '..Hour24U..':'..MinuteU..':'..SecondU)
			end
			if (TimeFormat == 1000) or (TimeFormat == 1010) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', DayU..Desc..MonthAU..Desc..YearU..' '..Hour12U..':'..MinuteU)
			end
			if (TimeFormat == 1001) or (TimeFormat == 1011) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', DayU..Desc..MonthAU..Desc..YearU..' '..Hour12U..':'..MinuteU..' '..AMPMU)
			end
			if (TimeFormat == 1100) or (TimeFormat == 1110) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', DayU..Desc..MonthAU..Desc..YearU..' '..Hour12U..':'..MinuteU..':'..SecondU)
			end
			if (TimeFormat == 1101) or (TimeFormat == 1111) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', DayU..Desc..MonthAU..Desc..YearU..' '..Hour12U..':'..MinuteU..':'..SecondU..' '..AMPMU)
			end
		elseif FormatDateFormat == 8 then
			if TimeFormat <= 11 then
				SKIN:Bang('!SetVariable', 'UpdDateTime', Year2U..Desc..MonthU..Desc..DayU..' '..Hour24U..':'..MinuteU)
			end
			if (TimeFormat == 100) or (TimeFormat == 101) or (TimeFormat == 110) or (TimeFormat == 111) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', Year2U..Desc..MonthU..Desc..DayU..' '..Hour24U..':'..MinuteU..':'..SecondU)
			end
			if (TimeFormat == 1000) or (TimeFormat == 1010) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', Year2U..Desc..MonthU..Desc..DayU..' '..Hour12U..':'..MinuteU)
			end
			if (TimeFormat == 1001) or (TimeFormat == 1011) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', Year2U..Desc..MonthU..Desc..DayU..' '..Hour12U..':'..MinuteU..' '..AMPMU)
			end
			if (TimeFormat == 1100) or (TimeFormat == 1110) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', Year2U..Desc..MonthU..Desc..DayU..' '..Hour12U..':'..MinuteU..':'..SecondU)
			end
			if (TimeFormat == 1101) or (TimeFormat == 1111) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', Year2U..Desc..MonthU..Desc..DayU..' '..Hour12U..':'..MinuteU..':'..SecondU..' '..AMPMU)
			end
		elseif FormatDateFormat == 9 then
			if TimeFormat <= 11 then
				SKIN:Bang('!SetVariable', 'UpdDateTime', Year2U..Desc..MonthAU..Desc..DayU..' '..Hour24U..':'..MinuteU)
			end
			if (TimeFormat == 100) or (TimeFormat == 101) or (TimeFormat == 110) or (TimeFormat == 111) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', Year2U..Desc..MonthAU..Desc..DayU..' '..Hour24U..':'..MinuteU..':'..SecondU)
			end
			if (TimeFormat == 1000) or (TimeFormat == 1010) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', Year2U..Desc..MonthAU..Desc..DayU..' '..Hour12U..':'..MinuteU)
			end
			if (TimeFormat == 1001) or (TimeFormat == 1011) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', Year2U..Desc..MonthAU..Desc..DayU..' '..Hour12U..':'..MinuteU..' '..AMPMU)
			end
			if (TimeFormat == 1100) or (TimeFormat == 1110) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', Year2U..Desc..MonthAU..Desc..DayU..' '..Hour12U..':'..MinuteU..':'..SecondU)
			end
			if (TimeFormat == 1101) or (TimeFormat == 1111) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', Year2U..Desc..MonthAU..Desc..DayU..' '..Hour12U..':'..MinuteU..':'..SecondU..' '..AMPMU)
			end
		elseif FormatDateFormat == 10 then
			if TimeFormat <= 11 then
				SKIN:Bang('!SetVariable', 'UpdDateTime', YearU..Desc..MonthU..Desc..DayU..' '..Hour24U..':'..MinuteU)
			end
			if (TimeFormat == 100) or (TimeFormat == 101) or (TimeFormat == 110) or (TimeFormat == 111) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', YearU..Desc..MonthU..Desc..DayU..' '..Hour24U..':'..MinuteU..':'..SecondU)
			end
			if (TimeFormat == 1000) or (TimeFormat == 1010) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', YearU..Desc..MonthU..Desc..DayU..' '..Hour12U..':'..MinuteU)
			end
			if (TimeFormat == 1001) or (TimeFormat == 1011) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', YearU..Desc..MonthU..Desc..DayU..' '..Hour12U..':'..MinuteU..' '..AMPMU)
			end
			if (TimeFormat == 1100) or (TimeFormat == 1110) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', YearU..Desc..MonthU..Desc..DayU..' '..Hour12U..':'..MinuteU..':'..SecondU)
			end
			if (TimeFormat == 1101) or (TimeFormat == 1111) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', YearU..Desc..MonthU..Desc..DayU..' '..Hour12U..':'..MinuteU..':'..SecondU..' '..AMPMU)
			end
		elseif FormatDateFormat == 11 then
			if TimeFormat <= 11 then
				SKIN:Bang('!SetVariable', 'UpdDateTime', YearU..Desc..MonthAU..Desc..DayU..' '..Hour24U..':'..MinuteU)
			end
			if (TimeFormat == 100) or (TimeFormat == 101) or (TimeFormat == 110) or (TimeFormat == 111) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', YearU..Desc..MonthAU..Desc..DayU..' '..Hour24U..':'..MinuteU..':'..SecondU)
			end
			if (TimeFormat == 1000) or (TimeFormat == 1010) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', YearU..Desc..MonthAU..Desc..DayU..' '..Hour12U..':'..MinuteU)
			end
			if (TimeFormat == 1001) or (TimeFormat == 1011) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', YearU..Desc..MonthAU..Desc..DayU..' '..Hour12U..':'..MinuteU..' '..AMPMU)
			end
			if (TimeFormat == 1100) or (TimeFormat == 1110) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', YearU..Desc..MonthAU..Desc..DayU..' '..Hour12U..':'..MinuteU..':'..SecondU)
			end
			if (TimeFormat == 1101) or (TimeFormat == 1111) then
				SKIN:Bang('!SetVariable', 'UpdDateTime', YearU..Desc..MonthAU..Desc..DayU..' '..Hour12U..':'..MinuteU..':'..SecondU..' '..AMPMU)
			end
		end
	end

	for i = 1,10 do
		if (MeasureYear[i] > 0) and (MeasureMonth[i] > 0) then
			Tim = (os.time({year=MeasureYear[i], month=MeasureMonth[i], day=MeasureDay[i], hour=MeasureHour[i], min=MeasureMinute[i], sec=MeasureSecond[i]}) + LocalOffset)
		else
			Tim = (os.time({year=2019, month=2, day=9, hour=0, min=0, sec=0}) + LocalOffset)
		end

		if (tonumber(MinsAgo) >= 1) and (CurrTime - Tim < 60*tonumber(MinsAgoLimit)) and (CurrTime >= Tim) then
			if (CurrTime - Tim < 60) then
				SKIN:Bang('!SetVariable', 'DateTime'..i, LessMinAgoS)
			elseif (CurrTime - Tim >= 60) and (CurrTime - Tim < 120) then
				SKIN:Bang('!SetVariable', 'DateTime'..i, OneMinAgoS)
			else
				if (math.floor((CurrTime-Tim)/60) <= 9) and (FormatLeadingZeros >= 1) then
					SKIN:Bang('!SetVariable', 'DateTime'..i, '0'..math.floor((CurrTime-Tim)/60)..' '..MoreMinsAgoS)
				else
					SKIN:Bang('!SetVariable', 'DateTime'..i, math.floor((CurrTime-Tim)/60)..' '..MoreMinsAgoS)
				end
			end
		else
			local Year2T, YearT, MonthT, MonthAT, DayT, Hour12T, Hour24T, MinuteT, SecondT, AMPMT = os.date("%y", Tim), os.date("%Y", Tim), os.date("%m", Tim), os.date("%b", Tim), os.date("%d", Tim), os.date("%I", Tim), os.date("%H", Tim), os.date("%M", Tim), os.date("%S", Tim), os.date("%p", Tim)
			MonthAT = ReplaceMonth(MonthAT)
			AMPMT = ReplaceAMPM(AMPMT)
			if FormatLeadingZerosDate == 0 then
				if MonthT:sub(1,1) == '0' then 
					MonthT = MonthT:sub(2,2)
				end
				if DayT:sub(1,1) == '0' then 
					DayT = DayT:sub(2,2)
				end
			end
			if FormatLeadingZeros == 0 then
				if Hour12T:sub(1,1) == '0' then 
					Hour12T = Hour12T:sub(2,2)
				end
			if Hour24T:sub(1,1) == '0' then 
					Hour24T = Hour24T:sub(2,2)
				end
			end
			TimeFormat = (1000*Format12H+10+FormatAMPM)
			if (ShowYesterdayToday >= 1) and (tonumber(YearT) == tonumber(os.date("%Y"))) and (tonumber(MonthT) == tonumber(os.date("%m"))) and (tonumber(DayT) == tonumber(os.date("%d"))) then
				if TimeFormat <= 11 then
					SKIN:Bang('!SetVariable', 'DateTime'..i, TodayLab..' '..Hour24T..':'..MinuteT)
				end
				if (TimeFormat == 1000) or (TimeFormat == 1010) then
					SKIN:Bang('!SetVariable', 'DateTime'..i, TodayLab..' '..Hour12T..':'..MinuteT)
				end
				if (TimeFormat == 1001) or (TimeFormat == 1011) then
					SKIN:Bang('!SetVariable', 'DateTime'..i, TodayLab..' '..Hour12T..':'..MinuteT..' '..AMPMT)
				end
			elseif (ShowYesterdayToday >= 1) and (tonumber(YearT) == tonumber(os.date("%Y",os.time()-24*60*60))) and (tonumber(MonthT) == tonumber(os.date("%m",os.time()-24*60*60))) and (tonumber(DayT) == tonumber(os.date("%d",os.time()-24*60*60))) then
				if TimeFormat <= 11 then
					SKIN:Bang('!SetVariable', 'DateTime'..i, YesterdayLab..' '..Hour24T..':'..MinuteT)
				end
				if (TimeFormat == 1000) or (TimeFormat == 1010) then
					SKIN:Bang('!SetVariable', 'DateTime'..i, YesterdayLab..' '..Hour12T..':'..MinuteT)
				end
				if (TimeFormat == 1001) or (TimeFormat == 1011) then
					SKIN:Bang('!SetVariable', 'DateTime'..i, YesterdayLab..' '..Hour12T..':'..MinuteT..' '..AMPMT)
				end
			elseif FormatDateFormat == 0 then
				if TimeFormat <= 11 then
					SKIN:Bang('!SetVariable', 'DateTime'..i, MonthT..Desc..DayT..Desc..Year2T..' '..Hour24T..':'..MinuteT)
				end
				if (TimeFormat == 1000) or (TimeFormat == 1010) then
					SKIN:Bang('!SetVariable', 'DateTime'..i, MonthT..Desc..DayT..Desc..Year2T..' '..Hour12T..':'..MinuteT)
				end
				if (TimeFormat == 1001) or (TimeFormat == 1011) then
					SKIN:Bang('!SetVariable', 'DateTime'..i, MonthT..Desc..DayT..Desc..Year2T..' '..Hour12T..':'..MinuteT..' '..AMPMT)
				end
			elseif FormatDateFormat == 1 then
				if TimeFormat <= 11 then
					SKIN:Bang('!SetVariable', 'DateTime'..i, MonthAT..Desc..DayT..Desc..Year2T..' '..Hour24T..':'..MinuteT)
				end
				if (TimeFormat == 1000) or (TimeFormat == 1010) then
					SKIN:Bang('!SetVariable', 'DateTime'..i, MonthAT..Desc..DayT..Desc..Year2T..' '..Hour12T..':'..MinuteT)
				end
				if (TimeFormat == 1001) or (TimeFormat == 1011) then
					SKIN:Bang('!SetVariable', 'DateTime'..i, MonthAT..Desc..DayT..Desc..Year2T..' '..Hour12T..':'..MinuteT..' '..AMPMT)
				end
			elseif FormatDateFormat == 2 then
				if TimeFormat <= 11 then
					SKIN:Bang('!SetVariable', 'DateTime'..i, MonthT..Desc..DayT..Desc..YearT..' '..Hour24T..':'..MinuteT)
				end
				if (TimeFormat == 1000) or (TimeFormat == 1010) then
					SKIN:Bang('!SetVariable', 'DateTime'..i, MonthT..Desc..DayT..Desc..YearT..' '..Hour12T..':'..MinuteT)
				end
				if (TimeFormat == 1001) or (TimeFormat == 1011) then
					SKIN:Bang('!SetVariable', 'DateTime'..i, MonthT..Desc..DayT..Desc..YearT..' '..Hour12T..':'..MinuteT..' '..AMPMT)
				end
			elseif FormatDateFormat == 3 then
				if TimeFormat <= 11 then
					SKIN:Bang('!SetVariable', 'DateTime'..i, MonthAT..Desc..DayT..Desc..YearT..' '..Hour24T..':'..MinuteT)
				end
				if (TimeFormat == 1000) or (TimeFormat == 1010) then
					SKIN:Bang('!SetVariable', 'DateTime'..i, MonthAT..Desc..DayT..Desc..YearT..' '..Hour12T..':'..MinuteT)
				end
				if (TimeFormat == 1001) or (TimeFormat == 1011) then
					SKIN:Bang('!SetVariable', 'DateTime'..i, MonthAT..Desc..DayT..Desc..YearT..' '..Hour12T..':'..MinuteT..' '..AMPMT)
				end
			elseif FormatDateFormat == 4 then
				if TimeFormat <= 11 then
					SKIN:Bang('!SetVariable', 'DateTime'..i, DayT..Desc..MonthT..Desc..Year2T..' '..Hour24T..':'..MinuteT)
				end
				if (TimeFormat == 1000) or (TimeFormat == 1010) then
					SKIN:Bang('!SetVariable', 'DateTime'..i, DayT..Desc..MonthT..Desc..Year2T..' '..Hour12T..':'..MinuteT)
				end
				if (TimeFormat == 1001) or (TimeFormat == 1011) then
					SKIN:Bang('!SetVariable', 'DateTime'..i, DayT..Desc..MonthT..Desc..Year2T..' '..Hour12T..':'..MinuteT..' '..AMPMT)
				end
			elseif FormatDateFormat == 5 then
				if TimeFormat <= 11 then
					SKIN:Bang('!SetVariable', 'DateTime'..i, DayT..Desc..MonthAT..Desc..Year2T..' '..Hour24T..':'..MinuteT)
				end
				if (TimeFormat == 1000) or (TimeFormat == 1010) then
					SKIN:Bang('!SetVariable', 'DateTime'..i, DayT..Desc..MonthAT..Desc..Year2T..' '..Hour12T..':'..MinuteT)
				end
				if (TimeFormat == 1001) or (TimeFormat == 1011) then
					SKIN:Bang('!SetVariable', 'DateTime'..i, DayT..Desc..MonthAT..Desc..Year2T..' '..Hour12T..':'..MinuteT..' '..AMPMT)
				end
			elseif FormatDateFormat == 6 then
				if TimeFormat <= 11 then
					SKIN:Bang('!SetVariable', 'DateTime'..i, DayT..Desc..MonthT..Desc..YearT..' '..Hour24T..':'..MinuteT)
				end
				if (TimeFormat == 1000) or (TimeFormat == 1010) then
					SKIN:Bang('!SetVariable', 'DateTime'..i, DayT..Desc..MonthT..Desc..YearT..' '..Hour12T..':'..MinuteT)
				end
				if (TimeFormat == 1001) or (TimeFormat == 1011) then
					SKIN:Bang('!SetVariable', 'DateTime'..i, DayT..Desc..MonthT..Desc..YearT..' '..Hour12T..':'..MinuteT..' '..AMPMT)
				end
			elseif FormatDateFormat == 7 then
				if TimeFormat <= 11 then
					SKIN:Bang('!SetVariable', 'DateTime'..i, DayT..Desc..MonthAT..Desc..YearT..' '..Hour24T..':'..MinuteT)
				end
				if (TimeFormat == 1000) or (TimeFormat == 1010) then
					SKIN:Bang('!SetVariable', 'DateTime'..i, DayT..Desc..MonthAT..Desc..YearT..' '..Hour12T..':'..MinuteT)
				end
				if (TimeFormat == 1001) or (TimeFormat == 1011) then
					SKIN:Bang('!SetVariable', 'DateTime'..i, DayT..Desc..MonthAT..Desc..YearT..' '..Hour12T..':'..MinuteT..' '..AMPMT)
				end
			elseif FormatDateFormat == 8 then
				if TimeFormat <= 11 then
					SKIN:Bang('!SetVariable', 'DateTime'..i, Year2T..Desc..MonthT..Desc..DayT..' '..Hour24T..':'..MinuteT)
				end
				if (TimeFormat == 1000) or (TimeFormat == 1010) then
					SKIN:Bang('!SetVariable', 'DateTime'..i, Year2T..Desc..MonthT..Desc..DayT..' '..Hour12T..':'..MinuteT)
				end
				if (TimeFormat == 1001) or (TimeFormat == 1011) then
					SKIN:Bang('!SetVariable', 'DateTime'..i, Year2T..Desc..MonthT..Desc..DayT..' '..Hour12T..':'..MinuteT..' '..AMPMT)
				end
			elseif FormatDateFormat == 9 then
				if TimeFormat <= 11 then
					SKIN:Bang('!SetVariable', 'DateTime'..i, Year2T..Desc..MonthAT..Desc..DayT..' '..Hour24T..':'..MinuteT)
				end
				if (TimeFormat == 1000) or (TimeFormat == 1010) then
					SKIN:Bang('!SetVariable', 'DateTime'..i, Year2T..Desc..MonthAT..Desc..DayT..' '..Hour12T..':'..MinuteT)
				end
				if (TimeFormat == 1001) or (TimeFormat == 1011) then
					SKIN:Bang('!SetVariable', 'DateTime'..i, Year2T..Desc..MonthAT..Desc..DayT..' '..Hour12T..':'..MinuteT..' '..AMPMT)
				end
			elseif FormatDateFormat == 10 then
				if TimeFormat <= 11 then
					SKIN:Bang('!SetVariable', 'DateTime'..i, YearT..Desc..MonthT..Desc..DayT..' '..Hour24T..':'..MinuteT)
				end
				if (TimeFormat == 1000) or (TimeFormat == 1010) then
					SKIN:Bang('!SetVariable', 'DateTime'..i, YearT..Desc..MonthT..Desc..DayT..' '..Hour12T..':'..MinuteT)
				end
				if (TimeFormat == 1001) or (TimeFormat == 1011) then
					SKIN:Bang('!SetVariable', 'DateTime'..i, YearT..Desc..MonthT..Desc..DayT..' '..Hour12T..':'..MinuteT..' '..AMPMT)
				end
			elseif FormatDateFormat == 11 then
				if TimeFormat <= 11 then
					SKIN:Bang('!SetVariable', 'DateTime'..i, YearT..Desc..MonthAT..Desc..DayT..' '..Hour24T..':'..MinuteT)
				end
				if (TimeFormat == 1000) or (TimeFormat == 1010) then
					SKIN:Bang('!SetVariable', 'DateTime'..i, YearT..Desc..MonthAT..Desc..DayT..' '..Hour12T..':'..MinuteT)
				end
				if (TimeFormat == 1001) or (TimeFormat == 1011) then
					SKIN:Bang('!SetVariable', 'DateTime'..i, YearT..Desc..MonthAT..Desc..DayT..' '..Hour12T..':'..MinuteT..' '..AMPMT)
				end
			end
		end
	end
end