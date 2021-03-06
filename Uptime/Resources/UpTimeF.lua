function Initialize()
	Format12H, FormatShowSec, FormatLeadingZeros, FormatAMPM, FormatLeadingZerosDate, FormatDateFormat, FormatDesc, ShowYesterdayToday, YesterdayLab, TodayLab = tonumber(SKIN:GetVariable('12H')), tonumber(SKIN:GetVariable('ShowSec')), tonumber(SKIN:GetVariable('LeadingZeros')), tonumber(SKIN:GetVariable('AMPM')), tonumber(SKIN:GetVariable('LeadingZerosDate')), tonumber(SKIN:GetVariable('DateFormat')), tonumber(SKIN:GetVariable('DateDivider')), tonumber(SKIN:GetVariable('YesterdayToday')), SKIN:GetVariable('YesterdayLabel'), SKIN:GetVariable('TodayLabel')
	JanS, FebS, MarS, AprS, MayS, JunS, JulS, AugS, SepS, OctS, NovS, DecS, AMS, PMS = tostring(SKIN:GetVariable('Jan')), tostring(SKIN:GetVariable('Feb')), tostring(SKIN:GetVariable('Mar')), tostring(SKIN:GetVariable('Apr')), tostring(SKIN:GetVariable('May')), tostring(SKIN:GetVariable('Jun')), tostring(SKIN:GetVariable('Jul')), tostring(SKIN:GetVariable('Aug')), tostring(SKIN:GetVariable('Sep')), tostring(SKIN:GetVariable('Oct')), tostring(SKIN:GetVariable('Nov')), tostring(SKIN:GetVariable('Dec')), tostring(SKIN:GetVariable('AM')), tostring(SKIN:GetVariable('PM'))
	if FormatDesc == 0 then
		Desc = '-'
	elseif FormatDesc == 1 then
		Desc = '.'
	elseif FormatDesc == 2 then
		Desc = ' '
	else
		Desc = '/'
	end
	msUptime = SKIN:GetMeasure('MeasureUpTime')
	sFormat = string.gsub(SELF:GetOption('Format'), '%%#', '#%%')
end

function Update()
	local iUptime = msUptime:GetValue()
	local restartFormat = os.date(os.time() - iUptime)
	restartFormat = string.gsub(restartFormat, '#0?', '')
	local Year4, Year2, Month, MonthAbr, Day, Hour24, Hour12, Min, AMPM = os.date('%Y', restartFormat), os.date('%y', restartFormat), os.date('%m', restartFormat), os.date('%b', restartFormat), os.date('%d', restartFormat), os.date('%H', restartFormat), os.date('%I', restartFormat), os.date('%M', restartFormat), os.date('%p', restartFormat)
	if FormatLeadingZeros == 0 then
		if Hour12:sub(1,1) == '0' then 
			Hour12 = Hour12:sub(2,2)
		end
		if Hour24:sub(1,1) == '0' then 
			Hour24 = Hour24:sub(2,2)
		end
	end

		if FormatLeadingZerosDate == 0 then
			if Month:sub(1,1) == '0' then 
				Month = Month:sub(2,2)
			end
			if Day:sub(1,1) == '0' then 
				Day = Day:sub(2,2)
			end
		end

	local RestartDateTime = ''

	if (ShowYesterdayToday >= 1) and (tonumber(Year4) == tonumber(os.date("%Y"))) and (tonumber(Month) == tonumber(os.date("%m"))) and (tonumber(Day) == tonumber(os.date("%d"))) then
		if Format12H > 0 then
			if FormatAMPM >= 1 then
				RestartDateTime = TodayLab..' '..Hour12..':'..Min..' '..AMPM
			else
				RestartDateTime = TodayLab..' '..Hour12..':'..Min
			end
		else
			RestartDateTime = TodayLab..' '..Hour24..':'..Min
		end
	elseif (ShowYesterdayToday >= 1) and (tonumber(Year4) == tonumber(os.date("%Y",os.time()-24*60*60))) and (tonumber(Month) == tonumber(os.date("%m",os.time()-24*60*60))) and (tonumber(Day) == tonumber(os.date("%d",os.time()-24*60*60))) then
		if Format12H > 0 then
			if FormatAMPM >= 1 then
				RestartDateTime = YesterdayLab..' '..Hour12..':'..Min..' '..AMPM
			else
				RestartDateTime = YesterdayLab..' '..Hour12..':'..Min
			end
		else
			RestartDateTime = YesterdayLab..' '..Hour24..':'..Min
		end
	elseif FormatDateFormat == 0 then
		if Format12H > 0 then
			if FormatAMPM >= 1 then
				RestartDateTime = Month..Desc..Day..Desc..Year2..' '..Hour12..':'..Min..' '..AMPM
			else
				RestartDateTime = Month..Desc..Day..Desc..Year2..' '..Hour12..':'..Min
			end
		else
			RestartDateTime = Month..Desc..Day..Desc..Year2..' '..Hour24..':'..Min
		end
	elseif FormatDateFormat == 1 then
		if Format12H > 0 then
			if FormatAMPM >= 1 then
				RestartDateTime = MonthAbr..Desc..Day..Desc..Year2..' '..Hour12..':'..Min..' '..AMPM
			else
				RestartDateTime = MonthAbr..Desc..Day..Desc..Year2..' '..Hour12..':'..Min
			end
		else
			RestartDateTime = MonthAbr..Desc..Day..Desc..Year2..' '..Hour24..':'..Min
		end
	elseif FormatDateFormat == 2 then
		if Format12H > 0 then
			if FormatAMPM >= 1 then
				RestartDateTime = Month..Desc..Day..Desc..Year4..' '..Hour12..':'..Min..' '..AMPM
			else
				RestartDateTime = Month..Desc..Day..Desc..Year4..' '..Hour12..':'..Min
			end
		else
			RestartDateTime = Month..Desc..Day..Desc..Year4..' '..Hour24..':'..Min
		end
	elseif FormatDateFormat == 3 then
		if Format12H > 0 then
			if FormatAMPM >= 1 then
				RestartDateTime = MonthAbr..Desc..Day..Desc..Year4..' '..Hour12..':'..Min..' '..AMPM
			else
				RestartDateTime = MonthAbr..Desc..Day..Desc..Year4..' '..Hour12..':'..Min
			end
		else
			RestartDateTime = MonthAbr..Desc..Day..Desc..Year4..' '..Hour24..':'..Min
		end
	elseif FormatDateFormat == 4 then
		if Format12H > 0 then
			if FormatAMPM >= 1 then
				RestartDateTime = Day..Desc..Month..Desc..Year2..' '..Hour12..':'..Min..' '..AMPM
			else
				RestartDateTime = Day..Desc..Month..Desc..Year2..' '..Hour12..':'..Min
			end
		else
			RestartDateTime = Day..Desc..Month..Desc..Year2..' '..Hour24..':'..Min
		end
	elseif FormatDateFormat == 5 then
		if Format12H > 0 then
			RestartDateTime = Day..Desc..MonthAbr..Desc..Year2..' '..Hour12..':'..Min
		else
			if FormatAMPM >= 1 then
				RestartDateTime = Day..Desc..MonthAbr..Desc..Year2..' '..Hour24..':'..Min..' '..AMPM
			else
				RestartDateTime = Day..Desc..MonthAbr..Desc..Year2..' '..Hour24..':'..Min
			end
		end
	elseif FormatDateFormat == 6 then
		if Format12H > 0 then
			if FormatAMPM >= 1 then
				RestartDateTime = Day..Desc..Month..Desc..Year4..' '..Hour12..':'..Min..' '..AMPM
			else
				RestartDateTime = Day..Desc..Month..Desc..Year4..' '..Hour12..':'..Min
			end
		else
			RestartDateTime = Day..Desc..Month..Desc..Year4..' '..Hour24..':'..Min
		end
	elseif FormatDateFormat == 7 then
		if Format12H > 0 then
			if FormatAMPM >= 1 then
				RestartDateTime = Day..Desc..MonthAbr..Desc..Year4..' '..Hour12..':'..Min..' '..AMPM
			else
				RestartDateTime = Day..Desc..MonthAbr..Desc..Year4..' '..Hour12..':'..Min
			end
		else
			RestartDateTime = Day..Desc..MonthAbr..Desc..Year4..' '..Hour24..':'..Min
		end
	elseif FormatDateFormat == 8 then
		if Format12H > 0 then
			if FormatAMPM >= 1 then
				RestartDateTime = Year2..Desc..Month..Desc..Day..' '..Hour12..':'..Min..' '..AMPM
			else
				RestartDateTime = Year2..Desc..Month..Desc..Day..' '..Hour12..':'..Min
			end
		else
			RestartDateTime = Year2..Desc..Month..Desc..Day..' '..Hour24..':'..Min
		end
	elseif FormatDateFormat == 9 then
		if Format12H > 0 then
			if FormatAMPM >= 1 then
				RestartDateTime = Year2..Desc..MonthAbr..Desc..Day..' '..Hour12..':'..Min..' '..AMPM
			else
				RestartDateTime = Year2..Desc..MonthAbr..Desc..Day..' '..Hour12..':'..Min
			end
		else
			RestartDateTime = Year2..Desc..MonthAbr..Desc..Day..' '..Hour24..':'..Min
		end
	elseif FormatDateFormat == 10 then
		if Format12H > 0 then
			if FormatAMPM >= 1 then
				RestartDateTime = Year4..Desc..Month..Desc..Day..' '..Hour12..':'..Min..' '..AMPM
			else
				RestartDateTime = Year4..Desc..Month..Desc..Day..' '..Hour12..':'..Min
			end
		else
			RestartDateTime = Year4..Desc..Month..Desc..Day..' '..Hour24..':'..Min
		end
	elseif FormatDateFormat == 11 then
		if Format12H > 0 then
			if FormatAMPM >= 1 then
				RestartDateTime = Year4..Desc..MonthAbr..Desc..Day..' '..Hour12..':'..Min..' '..AMPM
			else
				RestartDateTime = Year4..Desc..MonthAbr..Desc..Day..' '..Hour12..':'..Min
			end
		else
			RestartDateTime = Year4..Desc..MonthAbr..Desc..Day..' '..Hour24..':'..Min
		end
	end
	return RestartDateTime
end