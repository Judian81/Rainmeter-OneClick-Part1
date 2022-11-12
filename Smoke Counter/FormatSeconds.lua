function Initialize()

	measureSecondsDiff1 = SKIN:GetMeasure('MeasureSecondsDiff1')
	measureSecondsDiff2 = SKIN:GetMeasure('MeasureSecondsDiff2')

end

function Update()

	secondsDiff1 = measureSecondsDiff1:GetValue()
	diffMonths, diffWeeks, diffDays, diffHours, diffMinutes, diffSeconds = FormatSeconds(math.abs(secondsDiff1))
	
	if diffMonths == 1 then
		outputMonth = diffMonths..' Month '
	elseif diffMonths > 1 then 
		outputMonth = diffMonths..' Months '
	else
		outputMonth = ''
	end
	
	if diffWeeks == 1 then
		outputWeeks = diffWeeks..' Week '
	elseif diffWeeks > 1 then
		outputWeeks = diffWeeks..' Weeks '
	else
	    outputWeeks = ''
	end	
	
	if diffDays == 1 then
		outputDays = diffDays..' Day '
	elseif diffDays > 1 then
	    outputDays = diffDays..' Days '
	else
		outputDays = ''
	end
   
	if diffHours == 1 then
		outputHours = diffHours..' Hour '
	elseif diffHours > 1 then
	    outputHours = diffHours..' Hours '
	else
		outputHours = ''
	end
   
	if diffMinutes == 1 then
		outputMinutes = diffMinutes..' Minute '
	elseif diffMinutes > 1 then
		outputMinutes = diffMinutes..' Minutes '
	else 
	    outputMinutes = ''
	end   
   
	if diffSeconds == 1 then
		outputSeconds = diffSeconds..' Second'
	elseif diffSeconds > 1 then
		outputSeconds = diffSeconds..' Seconds'
	else
	    outputSeconds = ''
	end
	
	outputString = outputMonth..''..outputWeeks..''..outputDays..''..outputHours..''..outputMinutes..''..outputSeconds
   
	text1 = "Cigarette: "
	outputString = text1 .. outputString
	
    SKIN:Bang('!SetOption', 'tCounter1', 'Text', outputString)	
	
	secondsDiff2 = measureSecondsDiff2:GetValue()
	diffMonths, diffWeeks, diffDays, diffHours, diffMinutes, diffSeconds = FormatSeconds(math.abs(secondsDiff2))
	
	if diffMonths == 1 then
		outputMonth = diffMonths..' Month '
	elseif diffMonths > 1 then 
		outputMonth = diffMonths..' Months '
	else
		outputMonth = ''
	end
	
	if diffWeeks == 1 then
		outputWeeks = diffWeeks..' Week '
	elseif diffWeeks > 1 then
		outputWeeks = diffWeeks..' Weeks '
	else
	    outputWeeks = ''
	end	
	
	if diffDays == 1 then
		outputDays = diffDays..' Day '
	elseif diffDays > 1 then
	    outputDays = diffDays..' Days '
	else
		outputDays = ''
	end
   
	if diffHours == 1 then
		outputHours = diffHours..' Hour '
	elseif diffHours > 1 then
	    outputHours = diffHours..' Hours '
	else
		outputHours = ''
	end
   
	if diffMinutes == 1 then
		outputMinutes = diffMinutes..' Minute '
	elseif diffMinutes > 1 then
		outputMinutes = diffMinutes..' Minutes '
	else 
	    outputMinutes = ''
	end   
   
	if diffSeconds == 1 then
		outputSeconds = diffSeconds..' Second'
	elseif diffSeconds > 1 then
		outputSeconds = diffSeconds..' Seconds'
	else
	    outputSeconds = ''
	end
	
	outputString = outputMonth..''..outputWeeks..''..outputDays..''..outputHours..''..outputMinutes..''..outputSeconds
	
	text2 = "Alcohol: "
	outputString = text2 .. outputString
   
    SKIN:Bang('!SetOption', 'tCounter2', 'Text', outputString)	
	
end

function FormatSeconds(secondsArg)

   local month =  math.floor(secondsArg / 2592000)
   local remainder = secondsArg % 2592000
   local weeks = math.floor(remainder / 604800)
   local remainder = remainder % 604800
   local days = math.floor(remainder / 86400)
   local remainder = remainder % 86400
   local hours = math.floor(remainder / 3600)
   local remainder = remainder % 3600
   local minutes = math.floor(remainder / 60)
   local seconds = remainder % 60
   
   --return month, weeks, days, hours, minutes, seconds
   return month, weeks, 0, 0, 0, 0
   
end