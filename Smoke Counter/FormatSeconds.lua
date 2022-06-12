function Initialize()

	measureSecondsDiff = SKIN:GetMeasure('MeasureSecondsDiff')

end

function Update()

	secondsDiff = measureSecondsDiff:GetValue()
	diffMonths, diffDays, diffHours, diffMinutes, diffSeconds = FormatSeconds(math.abs(secondsDiff))
	
	if diffMonths == 1 then
		outputMonth = diffMonths..' Month'
	else
		outputMonth = diffMonths..' Months'
	end
	
	if diffDays == 1 then
		outputDays = diffDays..' Day'
	else
		outputDays = diffDays..' Days'
	end
   
	if diffHours == 1 then
		outputHours = diffHours..' Hour'
	else
		outputHours = diffHours..' Hours'
	end
   
	if diffMinutes == 1 then
		outputMinutes = diffMinutes..' Minute'
	else
		outputMinutes = diffMinutes..' Minutes'
	end   
   
	if diffSeconds == 1 then
		outputSeconds = diffSeconds..' Second'
	else
		outputSeconds = diffSeconds..' Seconds'
	end
	
	if diffMonths > 0 then
		outputString = outputMonth..', '..outputDays..', '..outputHours
	elseif diffDays > 0 then
		outputString = outputDays..', '..outputHours
		-- ..'  '..outputMinutes..'  '..outputSeconds
	elseif diffHours > 0 then
		outputString = outputHours..', '..outputMinutes..', '..outputSeconds
	elseif diffMinutes > 0 then
		outputString = outputMinutes..', '..outputSeconds
	else
		outputString = outputSeconds
	end
   
   SKIN:Bang('!SetOption', 'tCounter', 'Text', outputString)	
	
	return secondsDiff

end

function FormatSeconds(secondsArg)

   local month =  math.floor(secondsArg / 2592000)
   local remainder = secondsArg % 2592000
   local days = math.floor(remainder / 86400)
   local remainder = secondsArg % 86400
   local hours = math.floor(remainder / 3600)
   local remainder = remainder % 3600
   local minutes = math.floor(remainder / 60)
   local seconds = remainder % 60
   
   return month, days, hours, minutes, seconds
   
end